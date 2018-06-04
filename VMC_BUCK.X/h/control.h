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
#include "init_pwm.h"
#include "init_gpio.h"
#include "top_level.h"
#include "global.h"

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/



// Calculations 



/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/
#define SOFT_START 0
#define MODE_HANDOVER 1

#define SOFT_START_STEP   ((1000 * PTPERVALUE/SWITCH_FREQUENCY)/SOFTSTART_TIME_ms)

#define OPENLOOP_DUTY  (int)((OPENLOOP_DUTYP)*(PTPERVALUE/100))

#define V_OUT_ADC_GAIN 1228
#define V_OUT_SENSE_GAIN (float)(0.05)
#define V_OUT_SENSE_OP_AMP_GAIN 1
#define V_OUT_SENSE_CHANNEL_GAIN (int)(V_OUT_ADC_GAIN * V_OUT_SENSE_GAIN * V_OUT_SENSE_OP_AMP_GAIN)
#define V_OUT_OV_COUNT (int)(V_OUT_SENSE_CHANNEL_GAIN* V_OUT_OV_LIMIT)

#define V_IN_ADC_GAIN 1228
#define V_IN_SENSE_GAIN (float)(0.05)
#define V_IN_SENSE_OP_AMP_GAIN 1
#define V_IN_SENSE_CHANNEL_GAIN (int)(V_IN_ADC_GAIN * V_IN_SENSE_GAIN * V_IN_SENSE_OP_AMP_GAIN)
#define V_IN_OV_COUNT (int)(V_IN_SENSE_CHANNEL_GAIN * V_IN_OV_LIMIT)

#define V_OUT_REF_COUNT (int)( V_OUT_REF * V_OUT_SENSE_CHANNEL_GAIN)

/* VMC defines*/




/******************************************************************************
* Variables
*******************************************************************************/


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
