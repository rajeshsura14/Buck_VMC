/* Microchip Technology Inc. and its subsidiaries.  You may use this software
 * and any derivatives exclusively with Microchip products.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
 * TERMS.
 */

/*
 * File:
 * Author:
 * Comments:
 * Revision history:
 */

// This is a guard condition so that contents of this file are not included
// more than once.
#ifndef GPIO_H
#define	GPIO_H

#include <xc.h> // include processor files - each processor file is guarded.

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>

    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>

    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

//#define                         //PGEC1
#define	Step_Load       _LATC4	//Step_Load
#define	Step_Ref        _LATC5	//Step_Ref
#define	Reset           _RC6	//Reset
#define	SC_Fault_BAR	_RC3    //-SC_Fault
//#define                         //Supply
//#define                         //Vcap
//#define                         //Gate_Psw_DIG
//#define                         //PWM_Buck_Diode
//#define                         //RX
//#define                         //TX
//#define                         //NotAssigned
//#define                         //NotAssigned
//#define                         //NotAssigned
//#define                         //NotAssigned
//#define                         //Supply
//#define                         //Supply
//#define                         //MCLR
//#define                         //NotAssigned
//#define                         //NotAssigned
//#define                         //Vo_sense
//#define                         //Vin_Sense
//#define                         //Io_Sense_Peak
//#define                         //Iin_Sense
//#define                         //Temperature_Sense
#define	GPIO_Ctrl2      _RB10	//GPIO_Ctrl2
#define	GPIO_Ctrl1      _RC9	//GPIO_Ctrl1
#define	ON_OFF_Switch   _RC10   //ON/OFF Switch
//#define                         //Supply
//#define                         //Supply
#define	Sys_SD_Cmnd 	_RC1	//Sys_SD_Cmnd
#define	Step_Load_Cmnd	_RB1    //Step_Load_Cmnd
#define	Step_Ref_Cmnd	_RB2    //Step_Ref_Cmnd
//#define                         //NotAssigned
#define	LCD_EN          _LATB4  //LCD_EN
#define	LCD_RS	        _LATC2  //LCD_RS
#define	LCD_DB0	        _LATC7  //LCD_DB0
//#define                         //NotAssigned
//#define                         //Supply
//#define                         //Supply
#define	LCD_DB1         _LATB8  //LCD_DB1
#define	LCD_DB2         _LATB15 //LCD_DB2
#define	LCD_DB3         _LATB5  //LCD_DB3
//#define                         //PGED1




    // TODO If C++ is being used, regular C code needs function names to have C
    // linkage so the functions can be used by the c code.

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */
