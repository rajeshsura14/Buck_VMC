/*$T indentinput.c GC 1.140 12/13/17 19:41:17 */

/*
 * File: configurationbits.c Author: Rajesh Sura Created on December 29, 2016,
 * 7:58 PM ;
 * DSPIC33EP16GS506 Configuration Bit Settings ;
 * 'C' source line config statements ;
 * FSEC
 */
#pragma config BWRP = OFF			/* Boot Segment Write-Protect bit (Boot Segment may be written) */
#pragma config BSS = DISABLED		/* Boot Segment Code-Protect Level bits (No Protection (other than BWRP)) */
#pragma config BSEN = OFF			/* Boot Segment Control bit (No Boot Segment) */
#pragma config GWRP = OFF			/* General Segment Write-Protect bit (General Segment may be written) */
#pragma config GSS = DISABLED		/* General Segment Code-Protect Level bits (No Protection (other than GWRP)) */
#pragma config CWRP = OFF			/* Configuration Segment Write-Protect bit (Configuration Segment may be written) */
#pragma config CSS = DISABLED		/* Configuration Segment Code-Protect Level bits (No Protection (other than CWRP)) */
#pragma config AIVTDIS = OFF		/* Alternate Interrupt Vector Table bit (Disabled AIVT) */

/* FBSLIM */
#pragma config BSLIM = 0x1FFF		/* Boot Segment Flash Page Address Limit bits (Boot Segment Flash page address
									 * limit) */

/*
 * FSIGN ;
 * FOSCSEL
 */
#pragma config FNOSC = FRC			/* Oscillator Source Selection (Internal Fast RC (FRC)) */
#pragma config IESO = OFF			/* Two-speed Oscillator Start-up Enable bit (Start up device with FRC, then switch
									 * to user-selected oscillator source) */

/* FOSC */
#pragma config POSCMD = NONE		/* Primary Oscillator Mode Select bits (Primary Oscillator disabled) */
#pragma config OSCIOFNC = ON		/* OSC2 Pin Function bit (OSC2 is clock output) */
#pragma config IOL1WAY = OFF		/* Peripheral pin select configuration bit (Allow multiple reconfigurations) */
#pragma config FCKSM = CSECMD		/* Clock Switching Mode bits (Clock switching is enabled,Fail-safe Clock Monitor is
									 * disabled) */
#pragma config PLLKEN = ON			/* PLL Lock Enable Bit (Clock switch to PLL source will wait until the PLL lock
									 * signal is valid) */

/* FWDT */
#pragma config WDTPOST = PS32768	/* Watchdog Timer Postscaler bits (1:32,768) */
#pragma config WDTPRE = PR128		/* Watchdog Timer Prescaler bit (1:128) */
#pragma config WDTEN = OFF			/* Watchdog Timer Enable bits (WDT and SWDTEN disabled) */
#pragma config WINDIS = OFF			/* Watchdog Timer Window Enable bit (Watchdog Timer in Non-Window mode) */
#pragma config WDTWIN = WIN25		/* Watchdog Timer Window Select bits (WDT Window is 25% of WDT period) */

/*
 * FPOR ;
 * FICD
 */
#pragma config ICS = PGD1			/* ICD Communication Channel Select bits (Communicate on PGEC1 and PGED1) */
#pragma config JTAGEN = OFF			/* JTAG Enable bit (JTAG is disabled) */
#pragma config BTSWP = OFF			/* BOOTSWP Instruction Enable/Disable bit (BOOTSWP instruction is disabled) */

/* FDEVOPT */
#pragma config PWMLOCK = OFF		/* PWMx Lock Enable bit (PWM registers may be written without key sequence) */
#pragma config ALTI2C1 = OFF		/* Alternate I2C1 Pin bit (I2C1 mapped to SDA1/SCL1 pins) */
#pragma config ALTI2C2 = OFF		/* Alternate I2C2 Pin bit (I2C2 mapped to SDA2/SCL2 pins) */
#pragma config DBCC = OFF			/* DACx Output Cross Connection bit (No Cross Connection between DAC outputs) */

/* FALTREG */
#pragma config CTXT1 = OFF			/* Specifies Interrupt Priority Level (IPL) Associated to Alternate Working
									 * Register 1 bits (Not Assigned) */
#pragma config CTXT2 = OFF			/* Specifies Interrupt Priority Level (IPL) Associated to Alternate Working
									 * Register 2 bits (Not Assigned) */

/*
 * #pragma config statements should precede project file includes. ;
 * Use project enums instead of #define for ON and OFF.
 */
#include <xc.h>
