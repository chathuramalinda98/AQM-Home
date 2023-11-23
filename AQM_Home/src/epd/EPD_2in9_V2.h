/*****************************************************************************
* | File      	:   EPD_2in9_V2.h
* | Author      :   Waveshare team
* | Function    :   2.9inch e-paper V2
* | Info        :
*----------------
* |	This version:   V1.0
* | Date        :   2020-12-09
* | Info        :
* -----------------------------------------------------------------------------
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#ifndef __EPD_2IN9_V2_H_
#define __EPD_2IN9_V2_H_

#include <Arduino.h>
#include "config.h"

#ifdef __cplusplus
extern "C" {
#endif

//// Pin definition
#define EPDCEN 5//CS
#define EPDDCP 25//DC
#define EPDRST 16//rst
#define EPDBSY 17//busy     CLK- 18   DIN- 23

// Display resolution
#define EPD_2IN9_V2_WIDTH       128
#define EPD_2IN9_V2_HEIGHT      296

void EPD_2IN9_V2_Init(void);
void EPD_2IN9_V2_Clear(void);
void EPD_2IN9_V2_Display(uint8_t *Image);
void EPD_2IN9_V2_Display_Base(uint8_t *Image);
void EPD_2IN9_V2_Display_Partial(uint8_t *Image);
void EPD_2IN9_V2_Sleep(void);
// user defined functions for SPI communication 
void openSpi(uint8_t cspin);
void closeSpi(uint8_t cspin);
void transferSpi(uint8_t data);

#ifdef __cplusplus
}
#endif

#endif
