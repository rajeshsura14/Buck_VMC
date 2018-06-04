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
 * @file TODO: adcm.c @brief This is the source file for ;
 * Include
 */
#include <xc.h> /* include processor files - each processor file is guarded. */
#include <stdint.h>
#include "init_adc.h"

/*
 * Module Preprocessor Constants ;
 * Module Preprocessor Macros ;
 * Module Typedefs ;
 * Module Variable Definitions ;
 * Function Prototypes ;
 * Function Definitions ;
 * TODO: UPDATE AND COPY THESE FOR EACH NON_TRIVIAL FUNCTION ;
 * Function:: Dio_Init() ;
 * \b Description: This function is used to initialize the Dio based on the
 * configuration table defined in dio_cfg module. PRE-CONDITION: Configuration
 * table needs to populated (sizeof > 0) POST-CONDITION: A constant pointer to the
 * first member of the configuration table will be returned. @return A pointer to
 * the configuration table. \b Example Example: @code const Dio_ConfigType
 * DioConfig = Dio_GetConfig();
 * Dio_Init(DioConfig);
 * @endcode @see Dio_Init <br><b> - HISTORY OF CHANGES - </b> <table align="left"
 * style="width:800px"> <tr><td> Date </td><td> Software Version </td><td>
 * Initials </td><td> Description </td></tr> <tr><td> 09/01/2015 </td><td> 0.5.0
 * </td><td> JWB </td><td> Interface Created </td></tr> </table><br><br> <hr
 */
void Init_ADC (void)
{
	ADC_Samp_Conv();
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void ADC_Samp_Conv(void)
{

	/*
	 * ADC INITIALIZATION for A0 ;
	 * Configure the I/O pins to be used as analog inputs.
	 */
	TRISAbits.TRISA0 = 1;		/* AN0/RA0 connected the dedicated core 0 */
	ANSELAbits.ANSA0 = 1;
	TRISAbits.TRISA1 = 1;		/* AN1/RA1 configured for VBatt_Sense */
	ANSELAbits.ANSA1 = 1;
	TRISAbits.TRISA2 = 1;		/* AN2/RA2 Configured for IBatt_SR_Sense */
	ANSELAbits.ANSA2 = 1;
	TRISBbits.TRISB0 = 1;		/* AN3/RB0 Configured for V_DC_Link_sense */
	ANSELBbits.ANSB0 = 1;
	TRISBbits.TRISB9 = 1;		/* AN4/RB9 Configured for Mains_Sense */
	ANSELBbits.ANSB9 = 1;
	
	

	/* Configure the common ADC clock. */
	ADCON3Hbits.CLKSEL = 1;		/* clock from Fosc */
	ADCON3Hbits.CLKDIV = 0;		/* no clock divider (1:1) */
	ADCON3Lbits.REFSEL = 0;		/* AVdd as voltage reference */

	/* Configure the integer output format. */
	ADCON1Hbits.FORM = 0;		/* integer format */

	/* ADC INITIALIZATION for Shared core */
	ADCON2Lbits.SHRADCS = 0;	/* 2 source clock periods */
	ADCON1Hbits.SHRRES = 3;		/* 12 bit resolution */
	ADCON2Hbits.SHRSAMC = 15;
	ADMOD0Lbits.SIGN4 = 0;		/* AN4/RB9 */
	ADMOD0Lbits.DIFF4 = 0;		/* AN4/RB9 */

	/*
	 * ADMOD1Lbits. ;
	 * ADC INITIALIZATION for AN0 ;
	 * Configure the cores? ADC clo
	 */
	ADCORE0Hbits.ADCS = 0;		/* clock divider (1:2) */
	ADCORE0Hbits.RES = 3;		/* 12 bit resolution */

	/* Select single-ended input configuration and unsigned output format. */
	ADMOD0Lbits.SIGN0 = 0;		/* AN0/RA0 */
	ADMOD0Lbits.DIFF0 = 0;		/* AN0/RA0 */

	/* Set the input channel to the core */
	ADCON4Hbits.C0CHS = 1; /* Dedicated ADC core 0 Input channel is AN0 */

	/*
	 * ADC INITIALIZATION for AN2 ;
	 * Configure the cores? ADC clock
	 */
	ADCORE2Hbits.ADCS = 0;		/* clock divider (1:2) */
	ADCORE2Hbits.RES = 3;		/* 12 bit resolution */

	/* Select single-ended input configuration and unsigned output format. */
	ADMOD0Lbits.SIGN2 = 0;		/* AN11/RC9 */
	ADMOD0Lbits.DIFF2 = 0;		/* AN11/RC9 */

	/* Set the Input channel to the core */
	ADCON4Hbits.C2CHS = 0b00;	/* Dedicated ADC Core 2 Input Channel IS AN2 */

	/*
	 * ADC INITIALIZATION for AN1 ;
	 * Configure the cores? ADC clock
	 */
	ADCORE1Hbits.ADCS = 0;		/* clock divider (1:2) */
	ADCORE1Hbits.RES = 3;		/* 12 bit resolution */

	/* Select single-ended input configuration and unsigned output format. */
	ADMOD0Lbits.SIGN1 = 0;		/* AN1 */
	ADMOD0Lbits.DIFF1 = 0;		/* AN1 */

	/* Set the Input channel to the core */
	ADCON4Hbits.C1CHS = 0b00;	/* Dedicated ADC Core 1 Input Channel IS AN1 */

	/*
	 * ADC INITIALIZATION for AN3 ;
	 * Configure the cores? ADC clock
	 */
	ADCORE3Hbits.ADCS = 0;		/* clock divider (1:2) */
	ADCORE3Hbits.RES = 3;		/* 12 bit resolution */

	/* Select single-ended input configuration and unsigned output format. */
	ADMOD0Lbits.SIGN3 = 0;		/* AN3 */
	ADMOD0Lbits.DIFF3 = 0;		/* AN3 */

	/* Set the Input channel to the core */
	ADCON4Hbits.C3CHS = 0b00;	/* Dedicated ADC Core 3 Input Channel IS AN3 */

	EnableAndCalibrate();

	/*
	 * Interrupt enable for all cores ;
	 * Configure and enable ADC interrupts.
	 */
	ADIELbits.IE0 = 0;			/* enable interrupt for AN0 */
	_ADCAN0IF = 0;		        /* clear interrupt flag for AN0 */
	_ADCAN0IE = 0;              /* clear interrupt flag for */

	/* Configure and enable ADC interrupts. */
	ADIELbits.IE1 = 0;          /* enable interrupt for AN1 */
	_ADCAN1IF = 0;              /* clear interrupt flag for AN1 */
	_ADCAN1IE = 0;              /* clear interrupt flag for AN1 */

	/* Configure and enable ADC interrupts. */
	ADIELbits.IE2 = 0;          /* enable interrupt for AN2 */
	_ADCAN2IF = 0;              /* clear interrupt flag for AN2 */
	_ADCAN2IE = 1;              /* clear interrupt flag for AN 2*/
    _ADCAN2IP = 7;              /* Highest Interrupt Priority Enabled*/

	/* Configure and enable ADC interrupts. */
	ADIELbits.IE3 = 1;          /* enable interrupt for AN3 */
	_ADCAN3IF = 0;              /* clear interrupt flag for AN3 */
	_ADCAN3IE = 1;              /* clear interrupt flag for AN3 */
	_ADCAN3IP = 6;              /* 2nd Highest Priority */

	/*
	 * Setting trigger sources for all cores ;
	 * Set same trigger source for all inputs to sample signals simultaneously for all
	 * core
	 */
	ADTRIG0Lbits.TRGSRC0 = 7;	/* PWM Generator 3 primary trigger for Core0 */
	ADTRIG0Lbits.TRGSRC1 = 7;	/* PWM Generator 3 primary trigger for Core1 */
	ADTRIG0Hbits.TRGSRC2 = 7;	/* PWM Generator 3 primary trigger for Core2 */
	ADTRIG0Hbits.TRGSRC3 = 7;	/* PWM Generator 3 primary trigger for Core3 */
	ADTRIG1Lbits.TRGSRC4= 17;   /* PWM Generator 3 primary trigger for Shared Core */
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
void EnableAndCalibrate(void)
{

	/* Set initialization time to maximum */
	ADCON5Hbits.WARMTIME = 15;	/* Set the WARMTIME<3:0> bits to provide at least 10 �S for the ADC cores
								 * initialization */
	ADCON1Lbits.ADON = 1;		/* Turn on ADC module */

	/* Turn on the module 0 power start */
	ADCON5Lbits.SHRPWR = 1;		/* Turn on analog power for shared core */
	while(ADCON5Lbits.SHRRDY == 0);

	/* Wait when the shared core is ready for operation */
	ADCON3Hbits.SHREN = 1;		/* Turn on digital power to enable triggers to the shared core */

	/* Calibration for SHARED core */
	ADCAL1Hbits.CSHREN = 1;		/* Enable calibration for the shared core */
	ADCAL1Hbits.CSHRDIFF = 0;	/* Single-ended input calibration */
	ADCAL1Hbits.CSHRRUN = 1;	/* Start calibration */
	while(ADCAL1Hbits.CSHRRDY == 0);

	/* Poll for the calibration end */
	ADCAL1Hbits.CSHREN = 0;		/* End the shared core calibration */

	/*
	 * Turn on the module 0 power end ;
	 * Turn on the module 0 power start
	 */
	ADCON5Lbits.C0PWR = 1;		/* Turn on analog power for dedicated core 0 */
	while(ADCON5Lbits.C0RDY == 0);

	/* Wait when the core 0 is ready for operation */
	ADCON3Hbits.C0EN = 1;		/* Turn on digital power to enable triggers to the core 0 */

	/* Calibration for module 0 */
	ADCAL0Lbits.CAL0DIFF = 0;	/* Single-ended input calibration */
	ADCAL0Lbits.CAL0EN = 1;		/* End the core 0 calibration */
	ADCAL0Lbits.CAL0RUN = 1;	/* Start calibration */
	ADCAL0Lbits.CAL0SKIP = 0;
	while(ADCAL0Lbits.CAL0RDY == 0);

	/*
	 * Poll for the calibration end ;
	 * Turn on the module 0 power end ;
	 * Turn on the module 2 power start
	 */
	ADCON5Lbits.C2PWR = 1;		/* Turn on analog power for dedicated core 2 */
	while(ADCON5Lbits.C2RDY == 0);

	/* Wait when the core 2 is ready for operation */
	ADCON3Hbits.C2EN = 1;		/* Turn on digital power to enable triggers to the core 2 */

	/* Calibration for module2 */
	ADCAL0Hbits.CAL2DIFF = 0;	/* Single-ended input calibration */
	ADCAL0Hbits.CAL2EN = 1;		/* End the core 2 calibration */
	ADCAL0Hbits.CAL2RUN = 1;	/* Start calibration */
	ADCAL0Hbits.CAL2SKIP = 0;
	while(ADCAL0Hbits.CAL2RDY == 0);

	/*
	 * Poll for the calibration end ;
	 * Turn on the module 2 power end ;
	 * Turn on the module 1 power start
	 */
	ADCON5Lbits.C1PWR = 1;		/* Turn on analog power for dedicated core 1 */
	while(ADCON5Lbits.C1RDY == 0);

	/* Wait when the core 1 is ready for operation */
	ADCON3Hbits.C1EN = 1;		/* Turn on digital power to enable triggers to the core 1 */

	/* Calibration for module 1 */
	ADCAL0Lbits.CAL1DIFF = 0;	/* Single-ended input calibration */
	ADCAL0Lbits.CAL1EN = 1;		/* End the core 1 calibration */
	ADCAL0Lbits.CAL1RUN = 1;	/* Start calibration */
	ADCAL0Lbits.CAL1SKIP = 0;
	while(ADCAL0Lbits.CAL1RDY == 0);

	/*
	 * Poll for the calibration end ;
	 * Turn on the module power end ;
	 * Turn on the module 3 power star
	 */
	ADCON5Lbits.C3PWR = 1;		/* Turn on analog power for dedicated core 3 */
	while(ADCON5Lbits.C3RDY == 0);

	/* Wait when the core 3 is ready for operation */
	ADCON3Hbits.C3EN = 1;		/* Turn on digital power to enable triggers to the core 3 */

	/* Calibration for module 3 */
	ADCAL0Hbits.CAL3DIFF = 0;	/* Single-ended input calibration */
	ADCAL0Hbits.CAL3EN = 1;		/* End the core 3 calibration */
	ADCAL0Hbits.CAL3RUN = 1;	/* Start calibration */
	ADCAL0Hbits.CAL3SKIP = 0;
	while(ADCAL0Hbits.CAL3RDY == 0);

	/*
	 * Poll for the calibration end ;
	 * Turn on the module power en
	 */
}

/* END OF FUNCTIONS */
