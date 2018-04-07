/*$T indentinput.c GC 1.140 12/13/17 19:43:17 */

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
 * Includes
 */
#include <xc.h> /* include processor files - each processor file is guarded. */
#include "globalvariables.h"
#include "init_pwm.h"

/*
 =======================================================================================================================
    Module Preprocessor Constants ;
    Module Preprocessor Macros ;
    Module Typedefs ;
    Module Variable Definitions ;
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
int Init_PWM(void)
{

	/*
	 * Clock for PWM Module ;
	 * Setup for the Auxiliary clock to use the FRC as the REFCLK ;
	 * ((FRC* 16) / APSTSCLR) = (7.37 * 16) / 1 = 117.92 MHz
	 */
	ACLKCONbits.FRCSEL = 1;			/* FRC is input to Auxiliary PLL */
	ACLKCONbits.SELACLK = 1;		/* Auxiliary Oscillator provides the clock source */
	ACLKCONbits.APSTSCLR = 7;		/* Divide Auxiliary clock by 1 */
	ACLKCONbits.ENAPLL = 1;			/* Enable Auxiliary PLL */
	while(ACLKCONbits.APLLCK != 1);
	__delay_us(50);

	/* PRIMARY PWM module initialization */
	PWMCON3bits.ITB = CLEAR;		/* PTPER/STPER registers provide timing for this PWM generator */
	PWMCON3bits.MDCS = CLEAR;		/* MDC register provides duty cycle information for this PWM generator */
	PWMCON3bits.DTC = 0b00;		/* Positive dead time is actively applied for all output modes */
	PWMCON3bits.MTBS = CLEAR;		/* PWM generator uses primary master time base for synchro and as the clock source
									 * for the PWM generation logic */
	PWMCON3bits.CAM = CLEAR;		/* Edge-Aligned mode is enabled */
	PWMCON3bits.IUE = CLEAR;		/* Updates to the active MDC/PDCx/SDCx/PHASEx/SPHASEx registers are synchronized to
									 * the local PWM time base */

	IOCON3bits.POLH = CLEAR;		/* PWMxH pin is active-high */
	IOCON3bits.POLL = CLEAR;		/* PWMxL pin is active-high */

	/*
	 * IOCON3bits.PMOD = 0b00;
	 * PWM I/O pin pair is in the Complementary PWM Output mode
	 */
	IOCON3bits.PMOD = 0b10;		/* PWM I/O pin pair is in the Push-Pull PWM Output mode */

	/*
	 * IOCON3bits.OVRENH = CLEAR;
	 * PWM generator provides data for the PWMxH pin
	 */
	FCLCON3bits.FLTMOD = 0b11;		/* Fault input is disabled */
	ALTDTR3 = DEADT_nSEC_COUNTS;	/* Deadtime value is 750nSEC */
	DTR3 = DEADT_nSEC_COUNTS;		/* Deadtime value is 750nSEC */

	PWMCON5bits.ITB = CLEAR;		/* PTPER/STPER registers provide timing for this PWM generator */
	PWMCON5bits.MDCS = CLEAR;		/* MDC register provides duty cycle information for this PWM generator */
	PWMCON5bits.DTC = 0b00;		/* Positive dead time is actively applied for all output modes */
	PWMCON5bits.MTBS = CLEAR;		/* PWM generator uses primary master time base for synchro and as the clock source
									 * for the PWM generation logic */
	PWMCON5bits.CAM = CLEAR;		/* Edge-Aligned mode is enabled */
	PWMCON5bits.IUE = CLEAR;		/* Updates to the active MDC/PDCx/SDCx/PHASEx/SPHASEx registers are synchronized to
									 * the local PWM time base */

	IOCON5bits.POLH = CLEAR;		/* PWMxH pin is active-high */
	IOCON5bits.POLL = CLEAR;		/* PWMxL pin is active-high */

	/*
	 * IOCON5bits.PMOD = 0b00;
	 * PWM I/O pin pair is in the Complementary PWM Output mode
	 */
	IOCON5bits.PMOD = 0b10;		/* PWM I/O pin pair is in the Push-Pull Output mode */

	/*
	 * IOCON5bits.OVRENH = CLEAR;
	 * PWM generator provides data for the PWMxH pin
	 */
	FCLCON5bits.FLTMOD = 0b11;		/* Fault input is disabled */
	ALTDTR5 = DEADT_nSEC_COUNTS;	/* Deadtime value is 750nSEC */
	DTR5 = DEADT_nSEC_COUNTS;		/* Deadtime value is 750nSEC */

	/*
	 * SECONDARY SIDE PWM CONTROL ;
	 * Configuring PWM1 pins as GPIO pins
	 */
	IOCON1 = 0;

	PTPER = PTPERVALUE;

	/*
	 * PDC2 = PTPER;
	 */
	PDC3 = 100;			/* 5424;
						 * //PTPER*0.34;
						 * */
	PDC5 = 100;			/* 5424;
						 * - */
	PDC2 = 5000;

	TRGCON3bits.TRGSTRT = 2;
	TRGCON3bits.TRGDIV = 1;

	/*
	 * MDC= 2467;
	 */
	PHASE3 = PTPER;		/* left leg */
	TRIG3 = PDC3 >> 1;	/* ADCAN3 trigger point */
	PHASE5 = 0;			/* right */

	/* PWM3 current limit mode configuration */
	FCLCON3bits.IFLTMOD = 0;		/* Normal Fault mode: Current-Limit mode maps CLDAT<1:0> bits to the PWMxH and
									 * PWMxL
									 * outputs;
									 * the PWM Fault mode maps FLTDAT<1:0> to the PWMxH and PWMxL outputs */
	FCLCON3bits.FLTSRC = 0b00000;	/* FLT is diabled */
	FCLCON3bits.CLSRC = 0;			
								    /* Current-limit input source is Analog Comparator 2 */
	FCLCON3bits.CLPOL = 0;			/* Current-limit source is active-low */
	FCLCON3bits.CLMOD = 0;			/* Enable current-limit function */
	FCLCON3bits.FLTMOD = 3;			/* Enable Cycle-by-Cycle Fault mode */
	IOCON3bits.CLDAT = 0b00;		/* PWMxH and PWMxL are driven inactive on occurrence of current-limit */

	/*
	 * LEBCON3 -->
	 * PHR,PHF,PLR,PLF,FLTLEBEN,CLLEBEN,X,X,X,X,BCH,BCL,BPHH,BPHL,BPLH,BPLL ;
	 * LEBDLY3 = X,X,X,X,LEB<8:0>,X,X,X ;
	 * LEBCON3bits.PHR = 1;
	 * * LEBCON3bits.CLLEBEN = 1;
	 */
	LEBCON3 = 0xA400;
	LEBDLY3 = 1000;

	/* PWM5 current limit mode configuration */
	FCLCON5bits.IFLTMOD = 0;		/* Normal Fault mode: Current-Limit mode maps CLDAT<1:0> bits to the PWMxH and
									 * PWMxL
									 * outputs;
									 * the PWM Fault mode maps FLTDAT<1:0> to the PWMxH and PWMxL outputs */
	FCLCON5bits.FLTSRC = 0b00000;	/* Current-limit input source is Analog Comparator 2 */
	FCLCON5bits.CLSRC = 0;			/* 0b01110;
									 * */
	FCLCON5bits.CLPOL = 0;			/* Current-limit source is active-low */
	FCLCON5bits.CLMOD = 0;			
								    /* Enable current-limit function */
	FCLCON5bits.FLTMOD = 3;			/* Enable Cycle-by-Cycle Fault mode */
	IOCON5bits.CLDAT = 0b00;		/* PWMxH and PWMxL are driven inactive on occurrence of current-limit */

	/*
	 * LEBCON5 -->
	 * PHR,PHF,PLR,PLF,FLTLEBEN,CLLEBEN,X,X,X,X,BCH,BCL,BPHH,BPHL,BPLH,BPLL ;
	 * LEBDLY5 = X,X,X,X,LEB<8:0>,X,X,X ;
	 * LEBCON5bits.PHR = 1;
	 * * LEBCON5bits.CLLEBEN = 1;
	 */
	LEBCON5 = 0xA400;
	LEBDLY5 = 1000;			/* Delay ~1.04us */

	/* Errata #7 work around */
	IOCON3bits.PENH = 0;	/* Assign pin ownership of PWM3H/RA4 to GPIO module */
	IOCON3bits.PENL = 0;	/* Assign pin ownership of PWM3L/RA3 to GPIO module */
	IOCON5bits.PENH = 0;	/* Assign pin ownership of PWM5H/RA4 to GPIO module */
	IOCON5bits.PENL = 0;	/* Assign pin ownership of PWM5L/RA3 to GPIO module */

	IOCON3bits.OVRDAT = 0;	/* Configure PWM outputs override state to the desired safe state */
	IOCON3bits.OVRENH = 1;	/* Override PWM3H output */
	IOCON3bits.OVRENL = 1;	/* Override PWM3L output */
	IOCON5bits.OVRDAT = 0;	/* Configure PWM outputs override state to the desired safe state */
	IOCON5bits.OVRENH = 1;	/* Override PWM5H output */
	IOCON5bits.OVRENL = 1;	/* Override PWM5L output */

	PTCONbits.PTEN = 1;		/* Enable PWM module */

	__delay_us(100);

	IOCON3bits.OVRENH = 0;	/* Remove override for PWM3H output */
	IOCON3bits.OVRENL = 0;	/* Remove override for PWM3L output */
	IOCON5bits.OVRENH = 0;	/* Remove override for PWM5H output */
	IOCON5bits.OVRENL = 0;	/* Remove override for PWM5L output */

	IOCON3bits.PENH = 1;	/* Assign pin ownership of PWM3H/RA4 to PWM module */
	IOCON3bits.PENL = 1;	/* Assign pin ownership of PWM3L/RA3 to PWM module */
	IOCON5bits.PENH = 1;	/* Assign pin ownership of PWM5H/RA4 to PWM module */
	IOCON5bits.PENL = 1;	/* Assign pin ownership of PWM5L/RA3 to PWM module */

	return 0;
}

/* END OF FUNCTIONS */
