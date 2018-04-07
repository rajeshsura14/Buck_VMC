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
/** @file MAIN: main.h
 *  @brief This module MAIN: WHAT DO I DO?
 *
 *  This is the header file for the definition MAIN: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef MAIN_H_
#define MAIN_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include <xc.h> // include processor files - each processor file is guarded.
#include "lcd.h"
#include "lcd_display.h"
#include "init_adc.h"
#include "control.h"
#include "init_uart.h"
#include "uart_comm.h"
#include "init_timer.h"
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define     FCY 60000000UL
#define     MAINS_PEAK_THRU_AVG   0
#define     MAINS_PEAK_THRU_DIFF  1

#define     HYSTERISIS 0
#define     CONTROL_LOOP 1
#define     FIXED_DUTY 2

#define     POINTONEPERCENT   33
#define     POINT25PERCENT    82
#define     POINTFIVEPERCENT 164
#define     ONEPERCENT   329
#define     TWOPERCENT   658
#define     FIVEPERCENT 1638
#define     TENPERCENT  3276

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
extern int16_t V_Mains_Sense_Method;
extern int8_t Entry_After_Reset;
extern int8_t Control_Method;
extern int16_t  MainsVoltage ;


/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

extern void Init_OSC(void);
extern void Init_GPIO(void);
extern void Init_PWM(void);
extern void Init_ADC(void);
extern void Init_LCD(void);

#ifdef __cplusplus
} // extern "C"
#endif

//TODO: UPDATE COMMENT BELOW
#endif /*File_H_*/

/*** End of File **************************************************************/
