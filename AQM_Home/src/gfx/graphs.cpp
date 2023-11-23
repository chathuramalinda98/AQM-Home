#include "graphs.h"

void graphs_bar(int right, int bottom, int width, int hight, int space, int noofbars, float arr[],bool numon){
  
  int data[noofbars];

  //find max

  float max = arr[0];
  
  for (int i = 1; i < noofbars; i++) {
    if (arr[i] > max) {
       max = arr[i]; // Update max if a larger element is found
    }
  }

  //find min

  float min = arr[0]; // Assume the first element is the maximum

  for (int i = 1; i < noofbars; i++) {
    if (arr[i] < min) {
       min = arr[i]; // Update max if a larger element is found
    }
  }

  for (int i = 0; i < noofbars; i++) {
      data[i] = arr[i]*((hight-1)/(max-min))+(1-min*((hight-1)/(max-min))); // Divide each element by the divisor
  }

  for(int i=0; i<noofbars;i++){
    
    paint_DrawRectangle(width*i+space*i+right, bottom-data[i], width*(i+1)+space*i+right, bottom, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    if(numon){
      paint_DrawNum((width+space)*i+right, (bottom - 9)-data[i], data[i], &Font8, BLACK, WHITE);
    }
  }
}

void graphs_bar_propo(int right, int bottom, int width, int hight, int space, int noofbars, float max, float arr[],bool numon){
  
  int data[noofbars];

  for (int i = 0; i < noofbars; i++) {
      data[i] = arr[i]*(hight/max); // Divide each element by the divisor
  }

  for(int i=0; i<noofbars;i++){
    
    paint_DrawRectangle(width*i+space*i+right, bottom - data[i], width*(i+1)+space*i+right, bottom, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    if(numon){
      paint_DrawNum((width+space)*i+right, (bottom - 9)-data[i], data[i], &Font8, BLACK, WHITE);
    }
  }
}