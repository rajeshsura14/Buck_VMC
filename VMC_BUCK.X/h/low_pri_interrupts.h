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
#ifndef LOW_PRI_INTERRUPTS_H_
#define LOW_PRI_INTERRUPTS_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include <xc.h> // include processor files - each processor file is guarded.
#include "init_gpio.h"
#include "top_level.h"
#include "global.h"
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define STEP_SYS_ON_CMND_KDB 0.01 // Key debounce for Sys_ON in seconds
#define STEP_REF_CMND_KDB    0.01 // Key debounce for Voltage Reference Change in seconds
#define STEP_LOAD_CMND_KDB   0.01 // Key debounce for Load Reference Change in seconds


// Calculations 
#define STEP_SYS_ON_CMND_KDB_COUNTS  (int)(STEP_SYS_ON_CMND_KDB * SWITCH_FREQUENCY)
#define STEP_REF_CMND_KDB_COUNTS  (int)(STEP_REF_CMND_KDB * SWITCH_FREQUENCY)
#define STEP_LOAD_CMND_KDB_COUNTS (int)(STEP_LOAD_CMND_KDB * SWITCH_FREQUENCY)


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



#ifdef __cplusplus
} // extern "C"
#endif

//TODO: UPDATE COMMENT BELOW
#endif /*File_H_*/

/*** End of File **************************************************************/
