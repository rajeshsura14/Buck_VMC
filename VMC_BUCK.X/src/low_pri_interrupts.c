/*$T indentinput.c GC 1.140 12/13/17 19:41:49 */

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
 * @file control: CONTROL.c @brief This is the source file for ;
 * Include
 */
#include <xc.h> /* include processor files - each processor file is guarded. */
#include "low_pri_interrupts.h"

/*
 * Module Preprocessor Constants ;
 * Module Preprocessor Macros ;
 * Module Typedefs ;
 * Module Variable Definitions
 */



//flags sf;
system_flags sf;
kdb_ctr ctr_ref_change, ctr_load_change, ctr_system_on;
int8_t test = 0;
int16_t test1 = 0;


void __attribute__((__interrupt__,no_auto_psv)) _T1Interrupt(void)
{

 /* Key de-bounce for entry and exit for system on*/

    switch(ON_OFF_Switch)
    {
        case 1:
                ctr_system_on.exit = 0;         
                if(ctr_system_on.entry < STEP_SYS_ON_CMND_KDB_COUNTS)
                {
                    ctr_system_on.entry++;
                    test1 = ctr_system_on.entry;
                     
                }
                else
                {
                  //  sf.f_system_on = 1;
                    sf.sf_bits.f_system_on =1;      
                }                 
                break;
        case 0:
                ctr_system_on.entry = 0;
                if(ctr_system_on.exit < STEP_SYS_ON_CMND_KDB_COUNTS)
                {
                      ctr_system_on.exit++;
                }
                else
                {
                   // sf.f_system_on = 0;
                    sf.sf_bits.f_system_on = 0;
                }           
               break;
    }   
 /* Key de-bounce for entry and exit for load ref change*/
    
    switch(Step_Load_Cmnd)
    {
        case 1:
            
                ctr_load_change.exit = 0;      
                if(ctr_load_change.entry < STEP_LOAD_CMND_KDB_COUNTS)
                {
                    ctr_load_change.entry++;
                }
                else
                {
                    Step_Load = 1;
                }
                break;
                
        case 0:
            
                ctr_load_change.entry = 0;       
                if(ctr_load_change.exit < STEP_LOAD_CMND_KDB_COUNTS)
                {
                    ctr_load_change.exit++;
                }
                else
                {
                    Step_Load = 0;
                    
                }
                break;          
    }
    
   
/* Key de-bounce for entry and exit for Ref change */   
    
    switch(Step_Ref_Cmnd)
    {
        case 1:
            ctr_ref_change.exit  = 0;        
            if(ctr_ref_change.entry < STEP_REF_CMND_KDB_COUNTS)
            {
                ctr_ref_change.entry++;
            }
            else
            {
                Step_Ref = 1;
            }
            break;
        case 0:
            ctr_ref_change.entry  = 0;          
            if(ctr_ref_change.exit < STEP_REF_CMND_KDB_COUNTS)
            {
                ctr_ref_change.exit++;
            }
            else
            {
                Step_Ref = 0;
            }
            break;
    }
IFS0bits.T1IF = 0;

}


/* END OF FUNCTIONS */
