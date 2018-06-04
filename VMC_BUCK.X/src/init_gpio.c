/*******************************************************************************
* Title                 :
* Filename              :
* Author                :   Rajesh Sura
* Origin Date           :   07/12/2017
* Version               :
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
*******************************************************************************/
/****************************************************************************
*
* Feel free to use this Template at your own risk for your own
* purposes.
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Template.
*
*****************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author         Description
* 07/12/2017  1.0.0   Rajesh Sura   Initial Release.
*
*******************************************************************************/
/** @file TODO: MODULE.c
 *  @brief This is the source file for
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include <xc.h> // include processor files - each processor file is guarded.
#include "init_gpio.h"
/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
// TODO: UPDATE AND COPY THESE FOR EACH NON_TRIVIAL FUNCTION
/******************************************************************************
* Function : Dio_Init()
*//**
* \b Description:
*
* This function is used to initialize the Dio based on the configuration table
*  defined in dio_cfg module.
*
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
*
* POST-CONDITION: A constant pointer to the first member of the configuration
* table will be returned.
*
* @return 		A pointer to the configuration table.
*
* \b Example Example:
* @code
* 	const Dio_ConfigType *DioConfig = Dio_GetConfig();
*
* 	Dio_Init(DioConfig);
* @endcode
*
* @see Dio_Init
*
* <br><b> - HISTORY OF CHANGES - </b>
*
* <table align="left" style="width:800px">
* <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
* <tr><td> 09/01/2015 </td><td> 0.5.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/
void Init_GPIO(void)
{
    //GPIO's Configuring
    							    	//PGEC1
_ANSC4	=	0	;	_TRISC4	=	0	;	//Step_Load
_ANSC5	=	0	;	_TRISC5	=	0	;	//Step_Ref
_ANSC6	=	0	;	_TRISC6	=	0	;	//Reset
				    _TRISC3 =	1	;	//-SC_Fault
							        	//Supply
							        	//Vcap
				    _TRISB11 =	0	;	//Gate_Psw_DIG
				    _TRISB12 =	0	;	//PWM_Buck_Diode
				    _TRISB13 =	1	;	//RX
				    _TRISB14 =	0	;	//TX
							        	//NotAssigned
							        	//NotAssigned
							        	//NotAssigned
							        	//NotAssigned
							        	//Supply
							        	//Supply
					        			//MCLR
					        			//NotAssigned
					        			//NotAssigned
_ANSA0	=	1	;					    //Vo_sense
_ANSA1	=	1	;					    //Vin_Sense
_ANSA2	=	1	;					    //Io_Sense_Peak
_ANSB0	=	1	;					    //Iin_Sense
_ANSB9	=	1	;					    //Temperature_Sense
_ANSB10	=	0	;	_TRISB10 =	1	;	//GPIO_Ctrl2
_ANSC9	=	0	;	_TRISC9  = 	1	;	//GPIO_Ctrl1
_ANSC10	=	0	;	_TRISC10 =	1	;	//ON/OFF Switch
							        	//Supply
							        	//Supply
_ANSC1	=	0	;	_TRISC1	=	1	;	//Sys_SD_Cmnd
_ANSB1	=	0	;	_TRISB1	=	1	;	//Step_Load_Cmnd
_ANSB2	=	0	;	_TRISB2	=	1	;	//Step_Ref_Cmnd
							        	//NotAssigned
				    _TRISB4	=	0	;	//LCD_EN
_ANSC2	=	0	;	_TRISC2	=	0	;	//LCD_RS
				    _TRISC7	=	0	;	//LCD_DB0
							        	//NotAssigned
								        //Supply
								        //Supply
				    _TRISB8	=	0	;	//LCD_DB1
				    _TRISB15=	0	;	//LCD_DB2
_ANSB5	=	0	;	_TRISB5	=	0	;	//LCD_DB3
								        //PGED1
}

/*************** END OF FUNCTIONS ***************************************************************************/
