/**
  ******************************************************************************
  * @file    font16.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    18-February-2014
  * @brief   This file provides text font16 for STM32xx-EVAL's LCD driver. 
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "fonts.h"

// 
//  Font data for Courier New 12pt
// 

const uint8_t Teko16_Table[] = 
{
	
	// @38 '"' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //       

// @0 '!' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x00, 0x00, //          
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @38 '"' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x34, 0x00, //   ## #   
	0x34, 0x00, //   ## #   
	0x34, 0x00, //   ## #   
	0x34, 0x00, //   ## #   
	0x34, 0x00, //   ## #   
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @76 '#' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x33, 0x00, //   ##  ## 
	0x33, 0x00, //   ##  ## 
	0x33, 0x00, //   ##  ## 
	0xFF, 0x80, // #########
	0x22, 0x00, //   #   #  
	0x62, 0x00, //  ##   #  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0xFF, 0x00, // ######## 
	0x44, 0x00, //  #   #   
	0x44, 0x00, //  #   #   
	0xCC, 0x00, // ##  ##   
	0xCC, 0x00, // ##  ##   
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @1026 '?' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x7C, 0x00, //  #####   
	0xEC, 0x00, // ### ##   
	0xCC, 0x00, // ##  ##   
	0xCC, 0x00, // ##  ##   
	0x0C, 0x00, //     ##   
	0x0C, 0x00, //     ##   
	0x3C, 0x00, //   ####   
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x00, 0x00, //          
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

		// @1026 '?' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x7C, 0x00, //  #####   
	0xEC, 0x00, // ### ##   
	0xCC, 0x00, // ##  ##   
	0xCC, 0x00, // ##  ##   
	0x0C, 0x00, //     ##   
	0x0C, 0x00, //     ##   
	0x3C, 0x00, //   ####   
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x00, 0x00, //          
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

		// @1026 '?' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x7C, 0x00, //  #####   
	0xEC, 0x00, // ### ##   
	0xCC, 0x00, // ##  ##   
	0xCC, 0x00, // ##  ##   
	0x0C, 0x00, //     ##   
	0x0C, 0x00, //     ##   
	0x3C, 0x00, //   ####   
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x00, 0x00, //          
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @114 ''' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @152 '(' (9 pixels wide)
	0x0E, 0x00, //     ###  
	0x1C, 0x00, //    ###   
	0x18, 0x00, //    ##    
	0x10, 0x00, //    #     
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x10, 0x00, //    #     
	0x18, 0x00, //    ##    
	0x1C, 0x00, //    ###   
	0x0E, 0x00, //     ###  

	// @190 ')' (9 pixels wide)
	0x60, 0x00, //  ##      
	0x30, 0x00, //   ##     
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x08, 0x00, //     #    
	0x0C, 0x00, //     ##   
	0x0C, 0x00, //     ##   
	0x0C, 0x00, //     ##   
	0x0C, 0x00, //     ##   
	0x0C, 0x00, //     ##   
	0x08, 0x00, //     #    
	0x08, 0x00, //     #    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x30, 0x00, //   ##     
	0x60, 0x00, //  ##      

	// @228 '*' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x08, 0x00, //     #    
	0x2A, 0x00, //   # # #  
	0x7E, 0x00, //  ######  
	0x1C, 0x00, //    ###   
	0x36, 0x00, //   ## ##  
	0x14, 0x00, //    # #   
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @266 '+' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0xFF, 0x00, // ######## 
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @304 ',' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x0C, 0x00, //     ##   
	0x0C, 0x00, //     ##   
	0x08, 0x00, //     #    
	0x08, 0x00, //     #    
	0x08, 0x00, //     #    

	// @342 '-' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x3E, 0x00, //   #####  
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @380 '.' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x0C, 0x00, //     ##   
	0x0C, 0x00, //     ##   
	0x0C, 0x00, //     ##   
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @418 '/' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x03, 0x00, //       ## 
	0x06, 0x00, //      ##  
	0x06, 0x00, //      ##  
	0x04, 0x00, //      #   
	0x0C, 0x00, //     ##   
	0x0C, 0x00, //     ##   
	0x08, 0x00, //     #    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x10, 0x00, //    #     
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x20, 0x00, //   #      
	0x60, 0x00, //  ##      
	0x60, 0x00, //  ##      
	0x40, 0x00, //  #       
	0xC0, 0x00, // ##       

	// @456 '0' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x7E, 0x00, //  ######  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x7E, 0x00, //  ######  
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @494 '1' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x78, 0x00, //  ####    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @532 '2' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x7C, 0x00, //  #####   
	0x6C, 0x00, //  ## ##   
	0x4C, 0x00, //  #  ##   
	0x4C, 0x00, //  #  ##   
	0x0C, 0x00, //     ##   
	0x0C, 0x00, //     ##   
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x60, 0x00, //  ##      
	0x60, 0x00, //  ##      
	0x7C, 0x00, //  #####   
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @570 '3' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x3E, 0x00, //   #####  
	0x36, 0x00, //   ## ##  
	0x32, 0x00, //   ##  #  
	0x32, 0x00, //   ##  #  
	0x02, 0x00, //       #  
	0x02, 0x00, //       #  
	0x1E, 0x00, //    ####  
	0x02, 0x00, //       #  
	0x02, 0x00, //       #  
	0x32, 0x00, //   ##  #  
	0x32, 0x00, //   ##  #  
	0x3E, 0x00, //   #####  
	0x3E, 0x00, //   #####  
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @608 '4' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x0C, 0x00, //     ##   
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x20, 0x00, //   #      
	0x64, 0x00, //  ##  #   
	0x64, 0x00, //  ##  #   
	0xC4, 0x00, // ##   #   
	0xFF, 0x00, // ######## 
	0xFF, 0x00, // ######## 
	0x04, 0x00, //      #   
	0x04, 0x00, //      #   
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @646 '5' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x7E, 0x00, //  ######  
	0x60, 0x00, //  ##      
	0x60, 0x00, //  ##      
	0x60, 0x00, //  ##      
	0x60, 0x00, //  ##      
	0x7C, 0x00, //  #####   
	0x06, 0x00, //      ##  
	0x06, 0x00, //      ##  
	0x06, 0x00, //      ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x7E, 0x00, //  ######  
	0x7C, 0x00, //  #####   
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @684 '6' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x7E, 0x00, //  ######  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x60, 0x00, //  ##      
	0x60, 0x00, //  ##      
	0x7E, 0x00, //  ######  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x7E, 0x00, //  ######  
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @722 '7' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x7E, 0x00, //  ######  
	0x06, 0x00, //      ##  
	0x06, 0x00, //      ##  
	0x0C, 0x00, //     ##   
	0x0C, 0x00, //     ##   
	0x0C, 0x00, //     ##   
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x18, 0x00, //    ##    
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @760 '8' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x7E, 0x00, //  ######  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x3E, 0x00, //   #####  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x7E, 0x00, //  ######  
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @798 '9' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x7E, 0x00, //  ######  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x7E, 0x00, //  ######  
	0x06, 0x00, //      ##  
	0x06, 0x00, //      ##  
	0x66, 0x00, //  ##  ##  
	0x66, 0x00, //  ##  ##  
	0x7E, 0x00, //  ######  
	0x7E, 0x00, //  ######  
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @836 ':' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x0C, 0x00, //     ##   
	0x0C, 0x00, //     ##   
	0x0C, 0x00, //     ##   
	0x00, 0x00, //          
	0x0C, 0x00, //     ##   
	0x0C, 0x00, //     ##   
	0x0C, 0x00, //     ##   
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @874 ';' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x0C, 0x00, //     ##   
	0x0C, 0x00, //     ##   
	0x0C, 0x00, //     ##   
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x0C, 0x00, //     ##   
	0x0C, 0x00, //     ##   
	0x08, 0x00, //     #    
	0x08, 0x00, //     #    
	0x08, 0x00, //     #    

	// @912 '<' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x02, 0x00, //       #  
	0x1E, 0x00, //    ####  
	0xF8, 0x00, // #####    
	0xC0, 0x00, // ##       
	0xF0, 0x00, // ####     
	0x1E, 0x00, //    ####  
	0x02, 0x00, //       #  
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @950 '=' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0xFE, 0x00, // #######  
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0xFE, 0x00, // #######  
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @988 '>' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x80, 0x00, // #        
	0xF0, 0x00, // ####     
	0x3E, 0x00, //   #####  
	0x06, 0x00, //      ##  
	0x3E, 0x00, //   #####  
	0xF0, 0x00, // ####     
	0x80, 0x00, // #        
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	// @1026 '?' (9 pixels wide)
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x7C, 0x00, //  #####   
	0xEC, 0x00, // ### ##   
	0xCC, 0x00, // ##  ##   
	0xCC, 0x00, // ##  ##   
	0x0C, 0x00, //     ##   
	0x0C, 0x00, //     ##   
	0x3C, 0x00, //   ####   
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x00, 0x00, //          
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x30, 0x00, //   ##     
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          


};

sFONT Teko16 = {
  Teko16_Table,
  9, /* Width */
  19, /* Height */
};

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
