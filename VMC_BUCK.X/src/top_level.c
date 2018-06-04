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

int16_t storevalue = 0;

void __attribute__ ((interrupt, no_auto_psv))
/*
 =======================================================================================================================
 =======================================================================================================================
 */
_ADCAN3Interrupt(void)
{
    PDC3 = (PTPERVALUE>>1);  
    storevalue = ADCBUF3;
_ADCAN3IF = 0;	/* clear interrupt flag */
}

/* END OF FUNCTIONS */
