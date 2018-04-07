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
/** @file lcdmc: LCDMC.h
 *  @brief This module TODO: WHAT DO I DO?
 *
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef LCD_MC_H_
#define LCD_MC_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include <xc.h> // include processor files - each processor file is guarded.
#include <stdint.h>
#include <string.h>
#include  "lcd.h"
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define Example 			32

/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/

typedef void (*FPGeneric_t)(void);

typedef enum
{
    DISP_START                         = ((uint8_t)0),
    DISP_ORG_AND_INV                   = ((uint8_t)1),
    DISP_GRID_ON                       = ((uint8_t)2),
    DISP_GRID_OFF_INV_OFF              = ((uint8_t)3),
    DISP_GRID_OFF_INV_ON               = ((uint8_t)4),
    DISP_GRID_OFF_INV_ON_INFO_AC       = ((uint8_t)5),
    DISP_GRID_OFF_INV_ON_INFO_BATT     = ((uint8_t)6),
    DISP_GRID_OFF_INV_ON_INFO_BATT_BKP = ((uint8_t)7)
}DispState_t;


/******************************************************************************
* Variables
*******************************************************************************/


/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

void Display_IBatt(uint16_t);
void Display_VBatt(uint16_t);
void Display_VDClink(uint16_t);
void Display_VMains(int16_t);
void Display_ChargerSC(void);
void Display_Dytech(void);
void Display_ChargerOn(void);
void Display_GridOff(void);
void Display_Standby(void);

#ifdef __cplusplus
} // extern "C"
#endif

//TODO: UPDATE COMMENT BELOW
#endif /*File_H_*/

/*** End of File **************************************************************/
