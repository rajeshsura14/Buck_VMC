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
/** @file timer_init: TIMER_INIT.h
 *  @brief This module timer_init: WHAT DO I DO?
 *
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef TIMER_INIT_H_
#define TIMER_INIT_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include <xc.h> // include processor files - each processor file is guarded.
#include <stdio.h>
#include <stdint.h>
#include "init_gpio.h"
#include "uart_comm.h"
#include "init_uart.h"
#include "main.h"
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define MIPS                60
#define TIMER_FREQ_kHz      10
#define TIMER_PERIOD_us     (1000/TIMER_FREQ_kHz)
#define TIMER_PERIOD_COUNT  (TIMER_PERIOD_us*MIPS)

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
        uint16_t    dcdc            :1;     // DCDC On/Off bit
        uint16_t    inverter        :1;     // Inverter On/Off bit
        uint16_t    fan             :1;     // Fan On/Off bit
        uint16_t    dcUV            :1;     // DC Under Voltage
        uint16_t    oLShutdown      :1;     // Over Load Shutdown
        uint16_t    oL              :1;     // Over Load
        uint16_t    oLWarning       :1;     // Over Load Warning
        uint16_t    batOV           :1;     // Battery Over Voltage
        uint16_t    batUVShutdown   :1;     // Battery Under Voltage Shutdown
        uint16_t    batUV           :1;     // Battery Under Voltage
        uint16_t    batUVWarning    :1;     // Battery Under Voltage Warning
        uint16_t    sc              :1;     // Short Circuit
        uint16_t    empty           :4;
    } flagStruct_t;
typedef union {
	     flagStruct_t bit;
	     uint16_t all;
	 }systemStatus_t;
//
//systemStatus_t receiveStatus;     
/******************************************************************************
* Variables
*******************************************************************************/
extern uint16_t writeData2;
extern systemStatus_t receiveStatus;

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

void Init_TIMER (void);

#ifdef __cplusplus
} // extern "C"
#endif

//TODO: UPDATE COMMENT BELOW
#endif /*File_H_*/

/*** End of File **************************************************************/
