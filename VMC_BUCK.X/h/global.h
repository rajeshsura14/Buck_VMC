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
#ifndef GLOBAL_H_
#define GLOBAL_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include <xc.h> // include processor files - each processor file is guarded.

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

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
    int16_t f_system_on   :1;
    int16_t f_ref_change  :1;
    int16_t f_load_change :1;
    int16_t f_soft_start  :1;  
    int16_t f_input_OV    :1;
    int16_t f_output_OV   :1;
    int16_t f_load_OL     :1;
    int16_t f_dummy       :9;
}flags;

//extern flags sf;
//extern int8_t test;

typedef union 
{
    flags sf_bits;
    int16_t sf_all;
}system_flags;

extern system_flags sf;

typedef struct 
{   int16_t entry;
    int16_t exit;   
}kdb_ctr;



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
