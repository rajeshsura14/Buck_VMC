/*$T indentinput.c GC 1.140 12/13/17 19:43:01 */

/*
 * Title : Filename : Author : Rajesh Sura Origin Date : 07/12/2017 Version :
 * Compiler : Target : DSPIC33EP16GS506 Notes : None THIS SOFTWARE IS PROVIDED BY
 * INNERVE POWER SOLUTIONS "AS IS" AND ANY EXPRESSED OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL INNERVE
 * POWER SOLUTIONS OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE. ;
 * Feel free to use this Template at your own risk for your own purposes. The
 * above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Template. ;
 * SOURCE REVISION LOG Date Version Author Description 07/12/2017 1.0.0 Rajesh
 * Sura Initial Release. ;
 * @file TODO: MODULE.c @brief This is the source file for ;
 * Include
 */
#include <xc.h> /* include processor files - each processor file is guarded. */
#include <stdio.h>
#include <stdint.h>
#include "main.h"


/*
 * Module Preprocessor Constants ;
 * Module Preprocessor Macros ;
 * Module Typedefs ;
 * Module Variable Definitions
 */



/*
 =======================================================================================================================
    Function Prototypes ;
    Function Definitions ;
    TODO: UPDATE AND COPY THESE FOR EACH NON_TRIVIAL FUNCTION ;
    Function:: Dio_Init() ;
    \b Description: This function is used to initialize the Dio based on the configuration table defined in dio_cfg
    module. PRE-CONDITION: Configuration table needs to populated (sizeof > 0) POST-CONDITION: A constant pointer to
    the first member of the configuration table will be returned. @return A pointer to the configuration table. \b
    Example Example: @code const Dio_ConfigType *DioConfig = Dio_GetConfig();
    Dio_Init(DioConfig);
    @endcode @see Dio_Init <br><b> - HISTORY OF CHANGES - </b> <table align="left" style="width:800px"> <tr><td> Date
    </td><td> Software Version </td><td> Initials </td><td> Description </td></tr> <tr><td> 09/01/2015 </td><td> 0.5.0
    </td><td> JWB </td><td> Interface Created </td></tr> </table><br><br> <hr>
 =======================================================================================================================
 */


int main(void)
{
	Init_OSC();
	Init_GPIO();
    Init_PWM();
    Init_ADC();
    Init_TIMER();
	//Init_UART();
	//Init_LCD();
    
    
            
	while(1)
	{		
           Reset = 0;
	}
	return 0;
}

/* END OF FUNCTIONS */
