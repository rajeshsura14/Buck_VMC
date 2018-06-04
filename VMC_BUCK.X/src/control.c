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
#include <stdint.h>
#include "control.h"

/*
 * Module Preprocessor Constants ;
 * Module Preprocessor Macros ;
 * Module Typedefs ;
 * Module Variable Definitions
 */

int16_t duty = 0, duty_temp = 0;
int16_t duty_demand = 0;

int16_t v_out_sense = 0, v_out_scaled = 0;
int16_t v_in_sense  = 0, v_in_scaled = 0;
int16_t i_out_sense = 0, i_out_scaled = 0;
int16_t i_in_sense  = 0, i_in_scaled = 0; 

//VMC variables
int16_t v_out_error = 0;
int16_t duty_p_n = 0;
int16_t duty_i_n = 0, duty_i_n_1 = 0;



void __attribute__ ((interrupt, no_auto_psv))
/*
 =======================================================================================================================
 =======================================================================================================================
 */
_ADCAN3Interrupt(void)
{
      Reset = 1;
    v_out_sense  = ADCBUF0;
    v_in_sense   = ADCBUF1;
    i_out_sense  = ADCBUF2;
    i_in_sense   = ADCBUF3;
    
    
    
    
    if(sf.sf_bits.f_system_on)//if(sf.f_system_on) //
    {
//        if (v_in_sense > V_IN_OV_COUNT) {sf.sf_bits.f_input_OV = 1;}
//    else {sf.sf_bits.f_input_OV = 0;}
//    
//    if (v_out_sense> V_OUT_OV_COUNT) { sf.sf_bits.f_output_OV = 1;}
//    else {sf.sf_bits.f_output_OV = 0;}
    
     //scaled sense values
    v_out_scaled = (v_out_sense<<3);
    v_in_scaled  = (v_in_sense<<3);
    i_out_scaled = (i_out_sense<<3);
    i_in_scaled  = (i_in_sense<<3);
    
    switch(CONTROL_METHOD)
    {
        case OPENLOOP:      
            duty_demand = OPENLOOP_DUTY;
            break;
        case VMC:
            v_out_error = ( V_OUT_REF_COUNT - v_out_scaled);
            //duty_p_n = ((__builtin_mulss(v_out_error, )) >> 15)          
            break;
        case ACMC:
            break;
        case PCMC:
            break;
    }
    
   
 switch(sf.sf_bits.f_soft_start )//   switch(sf.f_soft_start )
    {
        case SOFT_START:
            if(duty_temp < duty_demand)
            {
                duty_temp = duty_temp + SOFT_START_STEP;
                duty_demand = duty_temp;
             
            }
            else
            {   
                sf.sf_bits.f_soft_start = 1;
                duty_temp = 0;
                duty_demand = duty_demand;
            }         
            break;
        case MODE_HANDOVER:
            duty_demand = duty_demand;
            break;         
    }
  
    
 PDC3= duty_demand;
    }
    else
    {
        sf.sf_all = 0;
        PDC3= 0;
    }
    
    
_ADCAN3IF = 0;	/* clear interrupt flag */
    Reset = 0;
}

/* END OF FUNCTIONS */
