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
/** @file control: CONTROL.h
 *  @brief This module control: WHAT DO I DO?
 *
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef CONTROL_H_
#define CONTROL_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include <xc.h> // include processor files - each processor file is guarded.
#include "init_adc.h"
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define LATCHOUT_TIME 0.0001
#define LATCHOUT_TIME_COUNTS (int16_t)(LATCHOUT_TIME * INTERRUPT_FREQ)//

#define RESET_LCD_TIME 1
#define MAX_COUNTS     10000
#define MAX_COUNTS_TIME  (float)(MAX_COUNTS *1.0 / INTERRUPT_FREQ )
#define RESET_LCD_LOOP_COUNTS (int)(RESET_LCD_TIME/MAX_COUNTS_TIME)

#define MAINS_SWOVER_TIME_mS  2.5
#define MAINS_SWOVER_TIME_COUNTS (int)(MAINS_SWOVER_TIME_mS*1000*0.000001*INTERRUPT_FREQ)   //

/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/

typedef struct
{
		uint8_t v_mains_sense    : 1;
		uint8_t lcd_reset        : 1;
		uint8_t sc_shutdown      : 1;
		uint8_t over_temp        : 1;
		uint8_t batt_ov          : 1;
		uint8_t v_dc_link        : 1;
		uint8_t precharge_relay  : 1;
		uint8_t initiate_latchout: 1;
		uint8_t mains_off        : 1;
		uint8_t short_circuit    : 1;
		uint8_t reset            : 1;
		uint8_t charger_on       : 1;
		uint8_t spare_flag_3     : 1;
		uint8_t spare_flag_2     : 1;
		uint8_t spare_flag_1     : 1;
		uint8_t spare_flag_0     : 1;

}flags_t ;
/******************************************************************************
* Variables
*******************************************************************************/

extern flags_t sys_flags_t;

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif



#ifdef __cplusplus
} // extern "C"
#endif

//TODO: UPDATE COMMENT BELOW
#endif /*File_H_*/

/*** End of File **************************************************************/
