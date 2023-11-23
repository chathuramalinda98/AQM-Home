#include <WiFi.h>
#include "time.h"
#include <Wire.h>
#include <SPI.h>
#include <SensirionI2CScd4x.h>
#include <HTTPClient.h>
#include <WebServer.h>
#include <EEPROM.h>
#include <ESPmDNS.h>
#include "src/epd/EPD_2in9_V2.h"
#include "src/gfx/gui_paint.h"
#include "src/gfx/graphs.h"
#include"image.h"

const char* ssid[] = {"Tony iPhone"}; // Array of WiFi SSIDs
const char* password[] = {"c34874455"}; // Array of WiFi passwords

int statusCode;
//const char* ssid = "Default_SSID";
const char* passphrase = "Default_passord";
const char* macAddress = "3C:61:05:3D:F7:FE";
String st;
String content;
String esid;
String epass = "";

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 19800;    // 5hr 30 min 
const int   daylightOffset_sec = 0;

char timeStr[20];
char timeOnlyStr[10];

uint16_t co2 = 0;
float temperature = 0.0f;
float humidity = 0.0f;

float temperatureOffset = 2.8f;
float humidityOffset = 12.0f;

float temparr[24];
float humidarr[24];
float co2arr[24];


#define spiP1 SPI
SensirionI2CScd4x scd4x;

const char* serverName = "http://aqs.c3dss.com/api/Aqsdata/AddData";
unsigned long lastTime = 0;
unsigned long timerDelay = 60000; // Set timer to 60 seconds

int previous_state;
int currentWiFiIndex = 0;
int numWiFiCredentials = 2;

int current_state;

//Function Decalration
bool Wificonnect(void);
void Weblaunch(void);
void setupAP(void);

bool hotspotStarted = false;

WebServer server(80);


void setup() {
 
  pinMode(EPDCEN, OUTPUT);
  pinMode(EPDDCP, OUTPUT);
  pinMode(EPDRST, OUTPUT);
  pinMode(EPDBSY, INPUT);

  EPROM();
  wifi1();

  //ReadCo2Sensor();
  print_image();
  printLocalTime();
  

  Serial.begin(115200);
  //delay(3000);
  Wire.begin();
  //wifi();
  
  initCo2Sensor();
  ReadCo2Sensor();
}


void loop() {
  
    

  if (WiFi.status() != WL_CONNECTED && previous_state == 0 ) {
     wifi2();
     Serial.println("if1");
      previous_state = 0;
     
     
  }

  if (WiFi.status() == WL_CONNECTED && previous_state == 0 ) {
    //ReadCo2Sensor();
    printLocalTime();
    print_image();
    previous_state = 1;
    Serial.println("if2");
    //wifi2();
  }

  if (WiFi.status() != WL_CONNECTED && previous_state == 1 ) {
    //ReadCo2Sensor();
    print_image();
    previous_state = 0;
    Serial.println("if3");
  }
  

  Serial.println("looping...");
  delay(2000);
  ReadCo2Sensor();
  

  // Send an HTTP POST request every 60 seconds
  if ((millis() - lastTime) > timerDelay) {
    //
    //ReadCo2Sensor(); 
    printLocalTime();
    print_image();

    //Check WiFi connection status
    if (WiFi.status() == WL_CONNECTED) {
      WiFiClient client;
      HTTPClient http;

      // Your Domain name with URL path or IP address with path
      http.begin(client, serverName);

      // Specify content-type header
      http.addHeader("Content-Type", "text/plain");

      // CO2 data with device number, CO2, temperature, and humidity
      String co2Data = formatCO2Data("272", co2, temperature, humidity);

      // Send HTTP POST request
      int httpResponseCode = http.POST(co2Data);

      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);

      // Free resources
      http.end();
    } else {
      Serial.println("WiFi Disconnected");
      //wifi(); // Attempt to connect to the next available WiFi network
    }
    lastTime = millis();
  }

}

void initCo2Sensor() {
  uint16_t error;
  char errorMessage[256];

  scd4x.begin(Wire);

  // stop potentially previously started measurement
  error = scd4x.stopPeriodicMeasurement();
  if (error) {
    Serial.print("Error trying to execute stopPeriodicMeasurement(): ");
    errorToString(error, errorMessage, 256);
    Serial.println(errorMessage);
  } else {
    Serial.println("Success CO2 Sensor");
  }

  error = scd4x.startPeriodicMeasurement();
  if (error) {
    Serial.print("Error trying to execute startPeriodicMeasurement(): ");
    errorToString(error, errorMessage, 256);
    Serial.println(errorMessage);
  }

  Serial.println("Waiting for first measurement... (5 sec)");
}


void print_image(){

  spiP1.begin();
  Serial.println("...EPD Test...");

  EPD_2IN9_V2_Init();
  Serial.println("...EPD Init...");
  //EPD_2IN9_V2_Clear();
  
  //Create a new image cache
  uint8_t *BlackImage;
  uint16_t Imagesize = ((EPD_2IN9_V2_WIDTH % 8 == 0)? (EPD_2IN9_V2_WIDTH / 8 ): (EPD_2IN9_V2_WIDTH / 8 + 1)) * EPD_2IN9_V2_HEIGHT;
  Serial.print("Imagesize:"); Serial.println(Imagesize);
  
  if((BlackImage = (uint8_t *)malloc(Imagesize)) == NULL) {
      Serial.print("Failed to apply for black memory...\r\n");
      return;
  }
  Serial.print("Paint_NewImage\r\n");
  paint_NewImage(BlackImage, EPD_2IN9_V2_WIDTH, EPD_2IN9_V2_HEIGHT, 270, WHITE);
  paint_SelectImage(BlackImage);
  paint_Clear(WHITE);
  
  paint_DrawBitMap(gImage_blank);//Background

  for(int i = 0; i<11; i++){
    temparr[i]=temparr[i+1];
  }
  temparr[11]=temperature;

  for(int i = 0; i<11; i++){
    humidarr[i]=humidarr[i+1];
  }
  humidarr[11]=humidity;;

  for(int i = 0; i<23; i++){
    co2arr[i]=co2arr[i+1];
  }
  co2arr[23]=co2;


  //find max co2
  int noofbars = 24;
  float Co2max = co2arr[0];
  
  for (int i = 1; i < noofbars; i++) {
    if (co2arr[i] > Co2max) {
       Co2max = co2arr[i]; // Update max if a larger element is found
    }
  }


  if(Co2max<=1000){
    paint_DrawBitMap(gImage_1000NEW);//Background
    graphs_bar_propo(118, 89, 4, 55, 3, 24, 1000, co2arr, false); 
    //graphs_bar(121, 88, 4, 56, 3, 24, co2arr, false);
  }

  if(1000<Co2max && Co2max<=2000){
    paint_DrawBitMap(gImage_2000NEW);//Background
    graphs_bar_propo(118, 89, 4, 55, 3, 24, 2000, co2arr, false);
    //graphs_bar(121, 88, 4, 56, 3, 24, co2arr, false);
  }

  if(2000<Co2max && Co2max<=3000){
    paint_DrawBitMap(gImage_3000NEW);//Background
    graphs_bar_propo(118, 89, 4, 55, 3, 24, 3000, co2arr, false);
    //graphs_bar(121, 88, 4, 56, 3, 24, co2arr, false);
  }

  if(3000<Co2max && Co2max<=4000){
    paint_DrawBitMap(gImage_4000NEW);//Background
    graphs_bar_propo(118, 89, 4, 55, 3, 24, 4000, co2arr, false);
    //graphs_bar(121, 88, 4, 56, 3, 24, co2arr, false);
  }

  if(4000<Co2max && Co2max<=5000){
    paint_DrawBitMap(gImage_5000NEW);//Background
    graphs_bar_propo(118, 89, 4, 55, 3, 24, 5000, co2arr, false);
    //graphs_bar(121, 88, 4, 56, 3, 24, co2arr, false);
  }


   /*Temp*/
  int tempi = temperature*10;
  paint_DrawNum(18, 10, tempi/10 , &Teko32, BLACK, WHITE);
  paint_DrawNum(56, 25, tempi%10, &Teko16, BLACK, WHITE);
  paint_DrawRectangle(52, 39, 54, 41, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL); //point
  graphs_bar(14, 54, 3, 10, 2, 12, temparr, false);  
  Serial.println("test");

  /*Humid*/
  int humidi = humidity*10;
  paint_DrawNum(18, 73, humidi/10, &Teko32, BLACK, WHITE);
  paint_DrawNum(56, 88, humidi%10, &Teko16, BLACK, WHITE);
  paint_DrawRectangle(52, 102, 54, 104, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);//point
  graphs_bar(14, 117, 3, 10, 2, 12, humidarr, false);
  Serial.println("test2");

  /*co2*/
  paint_DrawNum(203, 91, co2, &Teko26, BLACK, WHITE);
  //graphs_bar_propo(121, 88, 4, 56, 3, 24, 4000, co2arr, false);

  /*date and time*/
  paint_DrawString_EN(145,5, timeStr,&Font12, WHITE, BLACK);
  paint_DrawString_EN(228,5, timeOnlyStr,&Font12, WHITE, BLACK);
  
  /*wifi*/
  if (WiFi.status() == WL_CONNECTED) {
  paint_DrawBitMap_Paste(gImage_wifi_connected, 270, 3, 19, 16, 0);
  //paint_DrawBitMap_Paste(gImage_wifi, 240, 1, 22, 18, 0);
  }
  else
  //paint_DrawString_EN(104,5, " WIFI NOT CONNECTED ",&Font12, WHITE, BLACK);
  paint_DrawBitMap_Paste(gImage_not_connected, 270, 3, 19, 16, 0);


  if(co2 < 700){
    paint_DrawBitMap_Paste(gImage_good, 86, 89, 84, 33, 0);
    Serial.println("good");
  }
  else if (700<= co2 && co2 < 800){
    paint_DrawBitMap_Paste(gImage_moderate, 86, 89, 84, 33, 0);
    Serial.println("moderate");
  }
  else if (800<= co2 && co2< 1100){
    paint_DrawBitMap_Paste(gImage_poor, 86, 89, 84, 33, 0);
    Serial.println("poor");
  }
  else if (1100<= co2 && co2< 1500){
    paint_DrawBitMap_Paste(gImage_unhealthy, 86, 89, 84, 33, 0);
    Serial.println("unhealthy");
  }
  else if (1500<= co2 && co2< 2000){
    paint_DrawBitMap_Paste(gImage_Vunhealthy, 86, 89, 84, 33, 0);
    //graphs_bar_propo(121, 88, 4, 56, 3, 24, 2000, co2arr, false);
    
    Serial.println("V.unhealthy");
  }
  else if (2000<= co2 && co2< 3000){
    paint_DrawBitMap_Paste(gImage_hazardous, 86, 89, 84, 33, 0);
    Serial.println("hazardous");
  }
  else if (3000<= co2 && co2 < 5000){
    paint_DrawBitMap_Paste(gImage_extreme, 86, 89, 84, 33, 0);
    Serial.println("extreme");
  }

  EPD_2IN9_V2_Display_Base(BlackImage);
  EPD_2IN9_V2_Sleep();
  free(BlackImage);
  BlackImage = NULL;
}



void ReadCo2Sensor() {
  // Read Measurement
  uint16_t error;
  bool isDataReady = false;
  error = scd4x.getDataReadyFlag(isDataReady);
  if (error) {
    Serial.print("Error trying to execute getDataReadyFlag(): ");
    // errorToString(error, errorMessage, 256);
    // Serial.println(errorMessage);
    return;
  }
  if (!isDataReady) {
    return;
  }
  error = scd4x.readMeasurement(co2, temperature, humidity);
  if (error) {
    Serial.print("Error trying to execute readMeasurement(): ");
    // errorToString(error, errorMessage, 256);
    // Serial.println(errorMessage);
  } else if (co2 == 0) {
    Serial.println("Invalid sample detected, skipping.");
  } else {

    temperature = temperature - 3;

    Serial.print("Co2:");
    Serial.print(co2);
    Serial.print("\t");
    Serial.print("Temperature:");
    Serial.print(temperature);
    Serial.print("\t");
    Serial.print("Humidity:");
    Serial.println(humidity);
  }
}


void printLocalTime()
{
  struct tm timeinfo;                             //Declare a tm structure variable named timeinfo to store the obtained time.
  if(!getLocalTime(&timeinfo)){                   //  get time from the internal RTC
    Serial.println("Failed to obtain time");
    return;
  }
  //Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  
  sprintf(timeStr, "%02d/%02d/%04d", timeinfo.tm_mday, timeinfo.tm_mon + 1, timeinfo.tm_year + 1900);
  Serial.println(timeStr);
  
  
  // sprintf(timeOnlyStr, "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
  // Serial.println(timeOnlyStr);

  sprintf(timeOnlyStr, "%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min);
  Serial.println(timeOnlyStr);
}

String formatCO2Data(const String& deviceNumber, uint16_t co2, float temperature, float humidity) {
  
  //temperature -= temperatureOffset;
  //humidity += humidityOffset;

  String formattedData = deviceNumber + " | 0 | 0 | 0 | 0 | " + String(humidity) + " | " + String(temperature) + " | 0 | 0 | " + String(co2) + " | 0";
  Serial.println(formattedData);
  return formattedData;
}

void EPROM(){

  //Initialising if(DEBUG)Serial Monitor
  Serial.begin(115200); 
  Serial.println("Disconnecting current wifi connection");
  WiFi.disconnect();
  EEPROM.begin(512); //Initialasing EEPROM
  delay(10);
  //pinMode(15, INPUT);
  Serial.println("Startup");
  //EEPROM.write(i, 0);
   

  //Read eeprom for ssid and pass
  Serial.println("Reading EEPROM ssid");
  
  for (int i = 0; i < 32; ++i)
  {
    esid += char(EEPROM.read(i));
  }

  Serial.println();
  Serial.print("SSID: ");
  Serial.println(esid);
  Serial.println("Reading EEPROM pass");

  for (int i = 32; i < 96; ++i)
  {
    epass += char(EEPROM.read(i));
  }

  Serial.print("PASS: ");
  Serial.println(epass);
  WiFi.begin(esid.c_str(), epass.c_str());
}




void wifi1()
{
  if ((WiFi.status() == WL_CONNECTED))
  {
      Serial.print("Connected to ");
      Serial.print(esid);
      Serial.println(" Successfully");
      delay(100); 
  }
  else
  {
  }

  if (Wificonnect())
  {
    Serial.println(" connection status positive");
    //init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();
  previous_state = 1;
    return;
  }
  else
  {
    wificheck();


  }
  //delay(1000);
  
}
// Fuctions used for WiFi credentials saving and connecting to it which you do not need to change

void wifi2(){

  WiFi.begin(esid.c_str(), epass.c_str());

   int a = 0;
  //Serial.println("Waiting for Wifi to connect");
  while ( a < 8 ) {
    if (WiFi.status() == WL_CONNECTED)
    {
      Serial.println("connected");
      return ;
    }
    // delay(500);
    // Serial.print("*");
    // a++;
  else{
      wifi3();
  }

  }
  
}

void wifi3(){

  while(currentWiFiIndex < numWiFiCredentials) {

    WiFi.begin(ssid[currentWiFiIndex], password[currentWiFiIndex]);

    unsigned long startTime = millis();
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    
    Serial.println("Connecting to WiFi...");
    if (millis() - startTime >= 5000) {
      //print_image();
      
      break; // Timeout after 10 seconds of connection attempt
    }
  }

  if (WiFi.status() == WL_CONNECTED) {
    return;
    

  } else {
    
    currentWiFiIndex++; // Try the next WiFi network
    previous_state == 0;
    
  }

  }
}

bool Wificonnect(void)
{
  int c = 0;
  //Serial.println("Waiting for Wifi to connect");
  while ( c < 8 ) {
    if (WiFi.status() == WL_CONNECTED)
    {
      return true;
    }
    delay(500);
    Serial.print("*");
    c++;
  }
  Serial.println("");
  Serial.println("Connect timed out, opening AP");
  return false;
}


void Weblaunch()
{
  Serial.println("");
  if (WiFi.status() == WL_CONNECTED)
    Serial.println("WiFi connected");
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("SoftAP IP: ");
  Serial.println(WiFi.softAPIP());
  createWebServer();
  server.begin(); // Start the server
  Serial.println("Server started");

}


void setupAP(void)
{
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0)
    Serial.println("no networks found");
  else
  {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i)
    {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      //Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*");
      delay(10);
    }
  }
  Serial.println("");
  st = "<ol>";
  for (int i = 0; i < n; ++i)
  {
    // Print SSID and RSSI for each network found
    st += "<li>";
    st += WiFi.SSID(i);
    st += " (";
    st += WiFi.RSSI(i);
    st += ")";
    //st += (WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*";
    st += "</li>";
  }
  st += "</ol>";
  delay(100);
  WiFi.softAP("C3 AQM", "");
  Serial.println("Initializing_softap_for_wifi credentials_modification");
  Weblaunch();
    if (MDNS.begin("MYAQM")) { //myaqm.local/
    Serial.println("MDNS responder started");
  }

  Serial.println("over");
}



void createWebServer()
{
  {
    server.on("/", []() {
      IPAddress ip = WiFi.softAPIP();
      String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
      content = "<!DOCTYPE HTML>\r\n<html>";
      content += "<head>";
      content += "<title> WIFI CREDENTIALS UPDATE</title>";
      content += "<style>";

      content += "body {";
      content += "  font-family: Arial, sans-serif;";
      content += "  background-color: #F5FBFF;";
      content += "  padding: 20px;";
      content += "  text-align: left;";
      content += "  margin: 0px;";
      content += "  font-size: 15px;";
      content += "}";
      
      content += "h1 {";
      //content += "  text-align: left;";  // Align the <h1> heading to the left
      content += "  background-color: #033f8a;"; // Background color for the <h1> element
      content += "  color: #fff;";
      content += "  font-size: 50px;";
      content += "  padding: 0px;";
      content += "  width: 100%;";
      content += "  font-weight: bold;"; // Make the font weight bold
      content += "  font-family: sans-serif;";
      content += "}";


      content += "form {";
      content += "  display: inline-block;";
      //content += "  background-color: #fff;";
      //content += "  display: flex;";
     // content += "  flex-direction: column;";
      content += "  justify-content: center;";
      content += "  margin: 50px 50px;";
      content += "  text-align: center;";
      content += "  padding: 40px;";
      content += "  width: 75%;";
      content += "  border-radius: 5px;";
      content += "  font-size: 30px;";
      content += "  box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);";
      content += "}";


      content += "input[type=\"submit\"] {";
      content += "  padding: 10px 20px;";
      content += "  background-color: #4CAF50;";
      content += "  color: #fff;";
      content += "  border: none;";
      content += "  border-radius: 4px;";
      content += "  length: 300;";
      content += "  cursor: pointer;";
      content += "  font-size: 30px;";   // Modified font size
      content += "   width: 50%;";    
      content += "}";

      content += "input[type=\"submit\"]:hover {";
      content += "  background-color: #45a049;";
      content += "}";

      // content += "#st {";
      // content += "  text-align: left;"; // Align the 'st' paragraph text to the left
      // content += "}";

       content += "#space {";
       content += "  height: 200px;"; // Adjust the height for the desired space
       content += "}";
      // content += "#ipstr {";
      // content += "  text-align: left;"; // Align the 'st' paragraph text to the left
      // content += "}";
      content += "input[name='ssid'] {";
      content += "  font-size: 24px;";
      content += "  width: 60%;";  // Font size for the SSID input field
      content += "}";

      content += "input[name='pass'] {";
      content += "  font-size: 24px;";   // Font size for the password input field
      content += "  width: 60%;";    // Increased width for the password input field
      content += "}";
      
      content += "form > * {";
      content += "  margin-bottom: 20px;";  // Add spacing between form elements
      content += "}";
      
      content += "label {";
      content += "  display: inline-block;";
      content += "  width: 200px;";
      content += "  text-align: left;"; // Adjust the width value as needed
      //content += "  margin-right: 10px;"; // Adjust the margin-right value as needed
      content += "}";

      content += "</style>";
      content += "</head>";
      content += "<body>";
      content += "<h1 style='text-align: center;'>Please Enter Your Wifi Credentials Below</h1>";
      // content += "<form action=\"/scan\" method=\"POST\">";
      // content += "<input type=\"submit\" value=\"Scan\">";
      // content += "</form>";
      //content += <!--"<p id=\"ipstr\">"< + ipStr +  "</p>";
     // content += "<p id=\"st\">" + st + "</p>";
      content += "<div id=\"space\"></div>";
      content += "<form method='get' action='setting'>";
      content += "<label>SSID : </label><input name='ssid' length=64>";
      content += "<br>";      
      content += "<label>PASSWORD: </label><input name='pass' length=64>";
      content += "<br>";
      content += "<input type='submit'>";
      content += "</form>";
      content += "</body>";
      content += "</html>";
      server.send(200, "text/html", content);
    });

    server.on("/scan", []() {
      //setupAP();
      IPAddress ip = WiFi.softAPIP();
      String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
      content = "<!DOCTYPE HTML>\r\n<html>go back";
      server.send(200, "text/html", content);
    });
    
    server.on("/setting", []() {
      String qsid = server.arg("ssid");
      String qpass = server.arg("pass");
      //EEPROM.write(i, 0);
      if (qsid.length() > 0 && qpass.length() > 0) {
        Serial.println("clearing eeprom");
        for (int i = 0; i < 96; ++i) {
          EEPROM.write(i, 0);
        }
        Serial.println(qsid);
        Serial.println("");
        Serial.println(qpass);
        Serial.println("");
        Serial.println("writing eeprom ssid:");
        for (int i = 0; i < qsid.length(); ++i)
        {
          EEPROM.write(i, qsid[i]);
          Serial.print("Wrote: ");
          Serial.println(qsid[i]);
        }
        Serial.println("writing eeprom pass:");
        for (int i = 0; i < qpass.length(); ++i)
        {
          EEPROM.write(32 + i, qpass[i]);
          Serial.print("Wrote: ");
          Serial.println(qpass[i]);
        }
        EEPROM.commit();
        content = "{\"Success\":\"saved to eeprom... reset to boot into new wifi\"}";
        statusCode = 200;
        server.send(200, "text/plain", "WiFi configured successfully. Rebooting...");
        delay(2000);
        ESP.restart();
      } else {
        content = "{\"Error\":\"404 not found\"}";
        statusCode = 404;
        Serial.println("Sending 404");
      }
      server.sendHeader("Access-Control-Allow-Origin", "*");
      server.send(statusCode, "application/json", content);
    });
  }
}


void QR(){

  spiP1.begin();
  Serial.println("...EPD Test...");

  EPD_2IN9_V2_Init();
  Serial.println("...EPD Init...");
  EPD_2IN9_V2_Clear();
  
  //Create a new image cache
  uint8_t *BlackImage;
  uint16_t Imagesize = ((EPD_2IN9_V2_WIDTH % 8 == 0)? (EPD_2IN9_V2_WIDTH / 8 ): (EPD_2IN9_V2_WIDTH / 8 + 1)) * EPD_2IN9_V2_HEIGHT;
  Serial.print("Imagesize:"); Serial.println(Imagesize);
  
  if((BlackImage = (uint8_t *)malloc(Imagesize)) == NULL) {
      Serial.print("Failed to apply for black memory...\r\n");
      return;
  }
  Serial.print("Paint_NewImage\r\n");
  paint_NewImage(BlackImage, EPD_2IN9_V2_WIDTH, EPD_2IN9_V2_HEIGHT, 270, WHITE);
  paint_SelectImage(BlackImage);
  paint_Clear(WHITE);
  
  paint_DrawBitMap(gImage_QRNew4);
 // paint_DrawString_EN(11,108, macAddress,&calibri10, WHITE, BLACK);

  EPD_2IN9_V2_Display_Base(BlackImage);
  EPD_2IN9_V2_Sleep();
  free(BlackImage);
  BlackImage = NULL;
}



void wificheck(){

 while (currentWiFiIndex < numWiFiCredentials) {

  Serial.print("Connecting to WiFi ");
  Serial.println(ssid[currentWiFiIndex]);

  WiFi.begin(ssid[currentWiFiIndex], password[currentWiFiIndex]);

  unsigned long startTime = millis();
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    
    Serial.println("Connecting to WiFi...");
    if (millis() - startTime >= 5000) {
      //print_image();
      
      break; // Timeout after 10 seconds of connection attempt
    }
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    printLocalTime();
    //print_image();
    previous_state = 1;
    return;
    

  } else {
    Serial.println("Failed to connect to WiFi");
    currentWiFiIndex++; // Try the next WiFi network
   Serial.println("Connection Status Negative");
    
    
  }

 }

    Serial.println("Connection Status Negative");
    Serial.println("Turning the HotSpot On");
    QR();
    setupAP();  // Setup HotSpot
    Weblaunch();
    previous_state = 0;

  Serial.println();
  Serial.println("Waiting.");

  while ((WiFi.status() != WL_CONNECTED))
  {
    for(int i = 0; i<25; i++){
        Serial.println("wait 25 seconds to connect");
        delay(1000);
        server.handleClient();
        //configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
        //printLocalTime();
    }
    
    int connectedDevices = WiFi.softAPgetStationNum();
  
  if (connectedDevices > 0) {
    Serial.println("device connected");
    
  } else {
    Serial.println("No device connected, turning off hotspot");
    WiFi.softAPdisconnect(true);
  
    break;
  }

 
  }

}



void openSpi(uint8_t cspin) {
  spiP1.beginTransaction(SPISettings(5000000, MSBFIRST, SPI_MODE0));
  digitalWrite(cspin, 0);
  delayMicroseconds(1);   // 5ns
}

void closeSpi(uint8_t cspin) {
  delayMicroseconds(1);   // 5ns
  digitalWrite(cspin, 1);
  spiP1.endTransaction();
}

void transferSpi(uint8_t data) {
  spiP1.transfer(data);
}
