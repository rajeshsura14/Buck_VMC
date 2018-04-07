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
/** @file TODO: MODULE.h
 *  @brief This module TODO: WHAT DO I DO?
 *
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef ADC_H_
#define ADC_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include <xc.h> // include processor files - each processor file is guarded.
#include <stdint.h>
#include <math.h>
#include "init_gpio.h"
#include "main.h"
#include "compensator.h"
#include "init_pwm.h"

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define    V_DClink_ADC_GAIN          1230.0303
#define    V_DClink_DIVIDER_GAIN     (3.0/(360))
#define    V_DClink_CODES_PER_VOLT    (int16_t)(V_DClink_ADC_GAIN* V_DClink_DIVIDER_GAIN)
#define    V_DClink_CODES_PER_VOLT_X10 (int16_t)(V_DClink_CODES_PER_VOLT*10)


#define	   MAINS_ADC_GAIN	1230.03003
#define    MAINS_ADC_SCALING_FACTOR	1
#define    MAINS_OPAMP_GAIN	0.00375
#define    MAINS_SENSE_CODES_PER_VOLT	(2048/360)
#define    MAINS_SENSE_CODES_PER_VOLT_X10 (int16_t)(MAINS_SENSE_CODES_PER_VOLT*10)
#define    MAINS_SENSE_OFFSET_VOLTS	1.66
#define    MAINS_SENSE_OFFSET_COUNTS	(int16_t)(2041.84985)
#define    MAINS_SENSE_FLAG_COUNTER_LIMIT 10
#define    MAINS_SENSE_TEMP_SHIFT 4                  //Shifting by 5 bits

#define    MAINS_PEAK_THRU_AVG   0
#define    MAINS_PEAK_THRU_DIFF  1

#define    AC_MAINS_FREQUENCY_HZ       50
//#define     MAINS_SENSE_BYPASS_COUNTER_LIMIT 10
//#define     MAINS_SENSE_COUNTER_LIMIT   (int16_t)(SWITCH_FREQUENCY/(AC_MAINS_FREQUENCY_HZ*MAINS_SENSE_BYPASS_COUNTER_LIMIT))
#define    MAINS_SENSE_SAMPLE_SIZE     200
#define    MAINS_SENSE_POSSIBLE_SIZE   (int16_t)((1.0/AC_MAINS_FREQUENCY_HZ)*(SWITCH_FREQUENCY)) //For Push pull mode sensig is done 2* switching freq
#define    MAINS_SENSE_COUNTER_LIMIT   MAINS_SENSE_SAMPLE_SIZE
#define    MAINS_SENSE_BYPASS_COUNTER_LIMIT (int16_t)(MAINS_SENSE_POSSIBLE_SIZE/MAINS_SENSE_COUNTER_LIMIT)


#define    V_DCLink_PERCENT            90
#define    V_DCLink_PRECHARGE_LIMIT   (int16_t)(V_DCLink_PERCENT/100.0*32767)
#define    V_DCLink_SAMPLE_SIZE        10
#define    V_DCLink_BYPASS_COUNTER_LIMIT     100   //Stores sample every 100 cycles
#define    V_DCLink_MAXNUMBER_SET      32000

#define    V_Batt_ADC_GAIN   (4096/3.33)
#define    V_Batt_DIVIDER_GAIN    (2.2/35.5)    // Resistor divider gain
#define    V_Batt_SENSE_GAIN  (int16_t)(V_Batt_ADC_GAIN * V_Batt_DIVIDER_GAIN)
#define    V_BATT_X_Intercept 4087     //0.998*4096
#define    V_BATT_Y_Intercept -54.813

#define    I_Batt_ADC_GAIN   (float)(4096/3.33)
#define    I_Batt_SHUNT_GAIN  0.005
#define    I_Batt_OPAMP_GAIN   (30.0)
#define    I_Batt_SENSE_GAIN    (int16_t)(I_Batt_ADC_GAIN * I_Batt_SHUNT_GAIN* I_Batt_OPAMP_GAIN)

#define    DISPLAY_RESET_TIME_SEC                   10
#define    DISPLAY_RESET_TIME_IN_BIT_SEC            0.5
#define    DISPLAY_RESET_COUNTER_LIMIT             (int16_t)((DISPLAY_RESET_TIME_IN_BIT_SEC*SWITCH_FREQUENCY))
#define    DISPLAY_RESET_COUNTER_MULTIPLE_LIMIT    (int16_t)((DISPLAY_RESET_TIME_SEC/DISPLAY_RESET_TIME_IN_BIT_SEC))

#define    STARTUP_DELAY_S        (0.5)
#define    INTERRUPT_FREQ          50000
#define    STARTUP_DELAY_COUNTS    (int16_t)(INTERRUPT_FREQ*STARTUP_DELAY_S )

#define    RELAYON_DELAY_S        (0.5)
#define    RELAYON_DELAY_COUNTS    (int16_t)(INTERRUPT_FREQ*RELAYON_DELAY_S )

#define    FIRST_PASS_BYPASS_CYCLES 2
#define    FIRST_PASS_BYPASS_CYCLES_COUNTER (int16_t)(FIRST_PASS_BYPASS_CYCLES * INTERRUPT_FREQ / AC_MAINS_FREQUENCY_HZ)
#define    RELAY_TURNON_DELAY_SEC   0.6
#define    MAINSBASED_RELAY_TURNON_COUNTS   (int16_t)(RELAY_TURNON_DELAY_SEC * INTERRUPT_FREQ)

#define    DUTY_PERCENT  27
#define    DUTY_COUNTS_MAX (int16_t)(2*DUTY_PERCENT/100.0*PTPERVALUE)
#define    DUTY_INCREMENT_FIXEDDUTY 1

#define    mS_20_COUNT 1000
#define    TEMPERATURE_SHUTDOWN_COUNTS  3500//2855//3577
#define    TEMPERATURE_RESTART_COUNTS  2200

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
extern int16_t  V_Mains_Sense_Avg; // Variable to store ADC AN16
extern int16_t  V_Mains_Sense_RMS; //
extern int16_t  V_DC_Link_sense_avg;  // Variable to store ADC AN11 Data
extern int16_t  VBatt_Sense;      // Variable to store ADC AN1 Data
extern int16_t  IBatt_SR_Sense;   // Variable to store ADC AN3 Data


/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

void EnableAndCalibrate(void );
void ADC_Samp_Conv(void);

#ifdef __cplusplus
} // extern "C"
#endif

//TODO: UPDATE COMMENT BELOW
#endif /*File_H_*/

/*** End of File **************************************************************/
