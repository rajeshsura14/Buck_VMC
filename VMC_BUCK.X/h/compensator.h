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
/** @file compensator: COMPENSATOR.h
 *  @brief This module compensator:
 *
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef COMPENSATOR_H
#define	COMPENSATOR_H

/******************************************************************************
* Includes
*******************************************************************************/
#include <xc.h> // include processor files - each processor file is guarded.
#include "init_pwm.h"
#include "init_adc.h"
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
//#define SAMPLING_CL 40000
//#define T_SAMP_CL   (1.0/SAMPLING_CL)
//#define Kp_CL       1
//#define Ki_CL       1256
//#define Kp_FACT_CL  Kp_CL
//#define Ki_FACT_CL  (Ki_CL*T_SAMP_CL)
//#define Kp_INT_CL   (Kp_FACT_CL*32767)
//#define Ki_INT_CL   (Ki_FACT_CL*32767)
//#define PDC_MAX_CL  (0.9*PTPERVALUE)
//#define PDC_MIN_CL  (0.1*PTPERVALUE)

#define    SAMPLING_CL	50000
#define    T_SAMP_CL   	(1.0/SAMPLING_CL)
#define    SHUNT      	0.02
#define    OPAMP_GAIN 	10
#define    I_FB_GAIN  	 (SHUNT * OPAMP_GAIN)
#define    I_PU_GAIN 	 (3.3 / I_FB_GAIN)
#define    Kp_CL       	0.0225	// Bandwidth	4000
#define    Ki_CL   	141.3
#define    Kp_CL_SCALED	(Kp_CL * I_PU_GAIN)
#define    Ki_CL_SCALED 	(Ki_CL * I_PU_GAIN)
#define    MAXDECIMAL_CL 	1
#define    Kp_INT_CL     	(int16_t)(Kp_CL_SCALED / MAXDECIMAL_CL * 32767)
#define    Ki_INT_CL     	(int16_t)(Ki_CL_SCALED / MAXDECIMAL_CL * 32767 * T_SAMP_CL)

#define    PDC_MAX_CL 	    (int16_t)(0.9*PTPERVALUE)
#define    PDC_MIN_CL  	(int16_t)(0.1*PTPERVALUE)



//#define Kp_INT_CL   21491
//#define Ki_INT_CL   3379


//#define     V_FB_GAIN  	0.06
//#define 	V_PU_GAIN   	(3.3 / V_FB_GAIN)
//#define 	Kp_VL  	1.6863		//Bandwidth 	400	Hz
//#define 	Ki_VL       	10590
//#define 	Kp_VL_SCALED	 (Kp_VL * V_PU_GAIN)
//#define 	Ki_VL_SCALED	 (Ki_VL * V_PU_GAIN)
//#define 	MAXDECIMAL_VL 	8
//#define 	Kp_INT_VL     	((Kp_VL_SCALED / (MAXDECIMAL_VL*I_PU_GAIN )) * 32767 )
//#define 	Ki_INT_VL     	(Ki_VL_SCALED /( MAXDECIMAL_VL *  I_PU_GAIN)*32767 * T_SAMP_CL )

#define    V_FB_GAIN   	0.06
#define    V_PU_GAIN   	(3.3 / V_FB_GAIN)
#define    Kp_VL       	0.1686		//Bandwidth 	10	Hz
#define    Ki_VL       	1059.235669
#define    Kp_VL_SCALED	 (Kp_VL * V_PU_GAIN)
#define    Ki_VL_SCALED	 (Ki_VL * V_PU_GAIN)
#define    MAXDECIMAL_VL 	1
#define    Kp_INT_VL     	((Kp_VL_SCALED / (MAXDECIMAL_VL*I_PU_GAIN )) * 32767 )
#define    Ki_INT_VL     	(Ki_VL_SCALED /( MAXDECIMAL_VL *  I_PU_GAIN)*32767 * T_SAMP_CL )


//#define Kp_INT_VL   9436
//#define Ki_INT_VL   1479

#define    IREF            15
#define    IREF_INT      (IREF * I_Batt_SENSE_GAIN)
#define    IREF_MAX_CLAMP 16.8

#define    IREF_MAX_INT   (IREF_MAX_CLAMP * I_Batt_SENSE_GAIN  )
#define    VREF           45
#define    VREF_INT      (VREF * V_Batt_SENSE_GAIN)
#define    BATT_OVLIMIT   47
#define    BATT_OVLIMIT_CODES   (BATT_OVLIMIT * V_Batt_SENSE_GAIN)

#define    VDC_LINK_REF    200
#define    VDC_LINK_REF_INT (VDC_LINK_REF * V_DClink_CODES_PER_VOLT)

#define    SS_TIME_mS       0.025
#define    SS_STEP_TIME_uS  0.000025//(1/SWITCH_FREQUENCY)
#define    SS_STEP_COUNTS   (int16_t)(SS_TIME_mS/SS_STEP_TIME_uS)
#define    SS_STEP_IREF     (int16_t)(IREF_MAX_INT/SS_STEP_COUNTS)

#define    V_MAINS_RMS_REF  45
#define    V_MAINS_PEAK_REF (int16_t)(V_MAINS_RMS_REF*1.414)
#define    V_MAINS_AVG_REF  (int16_t)(2*V_MAINS_PEAK_REF/3.14)


#define    V_MAINS_RMS_REF_INT  (int16_t)(V_MAINS_RMS_REF*  MAINS_SENSE_CODES_PER_VOLT)
#define    V_MAINS_PEAK_REF_INT (int16_t)(V_MAINS_PEAK_REF* MAINS_SENSE_CODES_PER_VOLT)
#define    V_MAINS_AVG_REF_INT  (int16_t)(V_MAINS_AVG_REF*  MAINS_SENSE_CODES_PER_VOLT)
#define    V_MAINS_PEAK_REF_INT_CUTOFF (int16_t)(V_MAINS_PEAK_REF* MAINS_SENSE_CODES_PER_VOLT*0.38) // SIN22.5




//#define Kp_FACT_CL  Kp_CL
//#define Ki_FACT_CL  (Ki_CL*T_SAMP_CL)
//#define Kp_INT_CL   (Kp_FACT_CL*32767)
//#define Ki_INT_CL   (Ki_FACT_CL*32767)



/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/

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
