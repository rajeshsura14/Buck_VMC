/*$T indentinput.c GC 1.140 12/13/17 19:42:23 */

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
#include "init_uart.h"

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
void Init_UART(void)
{
	TRISBbits.TRISB4 = 0;	/* RB4-RP36 */

	TRISCbits.TRISC15 = 1;	/* RC15-RP63 */

	/* Configure UART PINS */
	RPINR18bits.U1RXR = 63; /* Pin31 of device (RP63,RC15) = U1RX */
	RPOR2bits.RP36R = 1;	/* Pin33 of device (RP36,RB4) = U1TX */

	/* Configure receive interrupt */
	U1STAbits.URXISEL = 0;	/* Interrupt after one RX character */
	IPC2bits.U1RXIP = 2;	/* Set U1RX interrupt priority */
	IEC0bits.U1RXIE = 1;	/* Enable UART RX interrupt */

	/* Configure transmit interrupt */
	U1STAbits.UTXISEL1 = 1; /* Interrupt when TX buffer becomes empty */
	U1STAbits.UTXISEL0 = 0;
	IPC3bits.U1TXIP = 2;	/* Set U1TX interrupt priority */
	IEC0bits.U1TXIE = 1;	/* Enable UART TX interrupt */

	/* Configure UART */
	U1MODEbits.STSEL = 0;	/* 1 stop bit */
	U1MODEbits.PDSEL = 3;	/* 9 data bits, no parity */
	U1MODEbits.ABAUD = 0;	/* Auto-baud disabled */
	U1MODEbits.BRGH = 0;	/* Low speed mode */

	U1MODEbits.UEN = 0;		/* UxTX and UxRX pins are enabled and used */

	U1BRG = BAUD_DIV;
	U1MODEbits.UARTEN = 1;	/* Enable UART */
	U1STAbits.UTXEN = 1;	/* Enable UART TX */
}

/* END OF FUNCTIONS */
