/****************************************************************************
* Title                 :
* Filename              :
* Author                :   Rajesh Sura
* Origin Date           :   07/12/2017
* Version               :   1.0.0
* Compiler              :
* Target                :   DSPIC33EP16GS506
* Notes                 :   None
*
* THIS SOFTWARE IS PROVIDED BY INNERVE POWER SOLUTIONS "AS IS" AND ANY EXPRESSED
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL INNERVE POWER SOLUTIONS OR ITS CONTRIBUTORS BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*
*****************************************************************************/

/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author         Description
* 07/12/2017  1.0.0   Rajesh Sura   Initial Release.
*
*******************************************************************************/
/** @file lcd: lcd.h
 *  @brief This module lcd: WHAT DO I DO?
 *
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef LCD_H_
#define LCD_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include <xc.h> // include processor files - each processor file is guarded.
#include<stdio.h>
#include<stdlib.h>
#include<init_gpio.h>
#include<control.h>
#include "libpic30.h"

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
// LCD Commands
#define LCD_CMD_8BIT_1LINE              0x30
#define LCD_CMD_8BIT_2LINE              0x38
#define LCD_CMD_4BIT_1LINE              0x20
#define LCD_CMD_4BIT_2LINE              0x28
#define LCD_CMD_ENTRY_MODE              0x06
#define LCD_CMD_CURSOR_OFF_DDR_ON       0x08
#define LCD_CMD_CURSOR_ON               0x0E
#define LCD_CMD_CURSOR_OFF              0x0C
#define LCD_CMD_CURSOR_BLINK            0x0F
#define LCD_CMD_DISP_SHIFT_L            0x18
#define LCD_CMD_DISP_SHIFT_R            0x1C
#define LCD_CMD_MOV_CUR_L               0x10
#define LCD_CMD_MOV_CUR_R               0x14
#define LCD_CMD_DISP_CLEAR              0x01
#define LCD_CMD_SET_CUR_POS(addr)       (0x80 + addr)
#define LCD_CMD_SET_CGRAM_ADDR(addr)    (0x40 + addr)

#define EN _LATC5       //EN
#define RS _LATD5       //RS
#define RW _LATC6       //R/W
////#define RW LATBbits.LATB6           //RW
//#define EN LATBbits.LATB5   //EN
//#define RS LATBbits.LATB7   //RS
//#define RW LATBbits.LATB6   //RW


/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

void command_lcd(unsigned char );
void data_string_lcd(unsigned char *);
void data_lcd(unsigned char );
void Init_LCD(void);
void nybble(void);

#ifdef __cplusplus
} // extern "C"
#endif

//TODO: UPDATE COMMENT BELOW
#endif /*File_H_*/

/*** End of File **************************************************************/
