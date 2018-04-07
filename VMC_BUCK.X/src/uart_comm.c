/*******************************************************************************
* Title                 :
* Filename              :
* Author                :   Rajesh Sura
* Origin Date           :   07/12/2017
* Version               :
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
*******************************************************************************/
/****************************************************************************
*
* Feel free to use this Template at your own risk for your own
* purposes.
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Template.
*
*****************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author         Description
* 07/12/2017  1.0.0   Rajesh Sura   Initial Release.
*
*******************************************************************************/
/** @file TODO: MODULE.c
 *  @brief This is the source file for
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include <xc.h> // include processor files - each processor file is guarded.
#include "uart_comm.h"

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/
// SERIAL TRANSMISSION
uint16_t tx_buffer[TX_BUF_LEN+1];
uint8_t *tx_bbuffer = (uint8_t*)&tx_buffer[0];
int16_t tx_ptr = TX_MAX_BUF_PTR;
int16_t txActive = 0;

// SERIAL RECEPTION
uint16_t rx_buffer[RX_BUF_LEN+1];
uint8_t *rx_bbuffer = (uint8_t *)&rx_buffer[0];
int16_t rx_ptr = 0;

const uint16_t crc_tab[] = {
0x0000U, 0xC0C1U, 0xC181U, 0x0140U, 0xC301U, 0x03C0U, 0x0280U, 0xC241U,
0xC601U, 0x06C0U, 0x0780U, 0xC741U, 0x0500U, 0xC5C1U, 0xC481U, 0x0440U,
0xCC01U, 0x0CC0U, 0x0D80U, 0xCD41U, 0x0F00U, 0xCFC1U, 0xCE81U, 0x0E40U,
0x0A00U, 0xCAC1U, 0xCB81U, 0x0B40U, 0xC901U, 0x09C0U, 0x0880U, 0xC841U,
0xD801U, 0x18C0U, 0x1980U, 0xD941U, 0x1B00U, 0xDBC1U, 0xDA81U, 0x1A40U,
0x1E00U, 0xDEC1U, 0xDF81U, 0x1F40U, 0xDD01U, 0x1DC0U, 0x1C80U, 0xDC41U,
0x1400U, 0xD4C1U, 0xD581U, 0x1540U, 0xD701U, 0x17C0U, 0x1680U, 0xD641U,
0xD201U, 0x12C0U, 0x1380U, 0xD341U, 0x1100U, 0xD1C1U, 0xD081U, 0x1040U,
0xF001U, 0x30C0U, 0x3180U, 0xF141U, 0x3300U, 0xF3C1U, 0xF281U, 0x3240U,
0x3600U, 0xF6C1U, 0xF781U, 0x3740U, 0xF501U, 0x35C0U, 0x3480U, 0xF441U,
0x3C00U, 0xFCC1U, 0xFD81U, 0x3D40U, 0xFF01U, 0x3FC0U, 0x3E80U, 0xFE41U,
0xFA01U, 0x3AC0U, 0x3B80U, 0xFB41U, 0x3900U, 0xF9C1U, 0xF881U, 0x3840U,
0x2800U, 0xE8C1U, 0xE981U, 0x2940U, 0xEB01U, 0x2BC0U, 0x2A80U, 0xEA41U,
0xEE01U, 0x2EC0U, 0x2F80U, 0xEF41U, 0x2D00U, 0xEDC1U, 0xEC81U, 0x2C40U,
0xE401U, 0x24C0U, 0x2580U, 0xE541U, 0x2700U, 0xE7C1U, 0xE681U, 0x2640U,
0x2200U, 0xE2C1U, 0xE381U, 0x2340U, 0xE101U, 0x21C0U, 0x2080U, 0xE041U,
0xA001U, 0x60C0U, 0x6180U, 0xA141U, 0x6300U, 0xA3C1U, 0xA281U, 0x6240U,
0x6600U, 0xA6C1U, 0xA781U, 0x6740U, 0xA501U, 0x65C0U, 0x6480U, 0xA441U,
0x6C00U, 0xACC1U, 0xAD81U, 0x6D40U, 0xAF01U, 0x6FC0U, 0x6E80U, 0xAE41U,
0xAA01U, 0x6AC0U, 0x6B80U, 0xAB41U, 0x6900U, 0xA9C1U, 0xA881U, 0x6840U,
0x7800U, 0xB8C1U, 0xB981U, 0x7940U, 0xBB01U, 0x7BC0U, 0x7A80U, 0xBA41U,
0xBE01U, 0x7EC0U, 0x7F80U, 0xBF41U, 0x7D00U, 0xBDC1U, 0xBC81U, 0x7C40U,
0xB401U, 0x74C0U, 0x7580U, 0xB541U, 0x7700U, 0xB7C1U, 0xB681U, 0x7640U,
0x7200U, 0xB2C1U, 0xB381U, 0x7340U, 0xB101U, 0x71C0U, 0x7080U, 0xB041U,
0x5000U, 0x90C1U, 0x9181U, 0x5140U, 0x9301U, 0x53C0U, 0x5280U, 0x9241U,
0x9601U, 0x56C0U, 0x5780U, 0x9741U, 0x5500U, 0x95C1U, 0x9481U, 0x5440U,
0x9C01U, 0x5CC0U, 0x5D80U, 0x9D41U, 0x5F00U, 0x9FC1U, 0x9E81U, 0x5E40U,
0x5A00U, 0x9AC1U, 0x9B81U, 0x5B40U, 0x9901U, 0x59C0U, 0x5880U, 0x9841U,
0x8801U, 0x48C0U, 0x4980U, 0x8941U, 0x4B00U, 0x8BC1U, 0x8A81U, 0x4A40U,
0x4E00U, 0x8EC1U, 0x8F81U, 0x4F40U, 0x8D01U, 0x4DC0U, 0x4C80U, 0x8C41U,
0x4400U, 0x84C1U, 0x8581U, 0x4540U, 0x8701U, 0x47C0U, 0x4680U, 0x8641U,
0x8201U, 0x42C0U, 0x4380U, 0x8341U, 0x4100U, 0x81C1U, 0x8081U, 0x4040U};


/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
// TODO: UPDATE AND COPY THESE FOR EACH NON_TRIVIAL FUNCTION
/******************************************************************************
* Function : Dio_Init()
*//**
* \b Description:
*
* This function is used to initialize the Dio based on the configuration table
*  defined in dio_cfg module.
*
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
*
* POST-CONDITION: A constant pointer to the first member of the configuration
* table will be returned.
*
* @return 		A pointer to the configuration table.
*
* \b Example Example:
* @code
* 	const Dio_ConfigType *DioConfig = Dio_GetConfig();
*
* 	Dio_Init(DioConfig);
* @endcode
*
* @see Dio_Init
*
* <br><b> - HISTORY OF CHANGES - </b>
*
* <table align="left" style="width:800px">
* <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
* <tr><td> 09/01/2015 </td><td> 0.5.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/
/*******************************************************************************
ISR: 		U1RXInterrupt
Description:	UART1 receive interrupt
*******************************************************************************/
void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void)
{
    uint16_t RxValue;

    RxValue = U1RXREG;

    if(U1STA&0x0006)
    {
        U1STAbits.OERR = 0;
        U1STAbits.FERR = 0;
    }
    else if(rx_ptr < RX_MAX_BUF_PTR)
    {
        if(RxValue >= 0x0100u)
        {
            rx_bbuffer[0] = RxValue&0x00FFu;
            rx_ptr = 1;
        }
        else if(rx_ptr > 0)
        {
            rx_bbuffer[rx_ptr] = RxValue&0x00FFu;
            ++rx_ptr;
        }
    }

    IFS0bits.U1RXIF = 0; // clear RX interrupt flag
}
/*******************************************************************************
End of ISR
*******************************************************************************/


/*******************************************************************************
ISR: 		U1TXInterrupt
Description:	UART1 transmit interrupt
*******************************************************************************/
void __attribute__((interrupt, no_auto_psv)) _U1TXInterrupt(void)
{
    uint8_t TxValue;

	while((tx_ptr < TX_MAX_BUF_PTR) && (U1STAbits.UTXBF == 0))
    {
		TxValue = tx_bbuffer[tx_ptr];
		++tx_ptr;
		U1TXREG = TxValue;
	}

    if(tx_ptr >= TX_MAX_BUF_PTR)
    {
		txActive = 0;
	}

    IFS0bits.U1TXIF = 0; // clear TX interrupt flag
}
/*******************************************************************************
End of ISR
*******************************************************************************/

/*******************************************************************************
Function: 	get_datablock
Description:    Received data checked with CRC and written to data buffer
*******************************************************************************/
int16_t get_datablock(uint16_t *data)
{
	int16_t getDataCnt;
	uint16_t crcReceive;

	if(rx_ptr < RX_MAX_BUF_PTR)
		return(0); // return code: no data.

    // Verify crc is correct
	crcReceive = CRC_START;
	for(getDataCnt=0; getDataCnt < RX_MAX_BUF_PTR; ++getDataCnt)
    {
		MACRO_CRC_STEP(crcReceive, rx_bbuffer[getDataCnt]);
	}

    if(crcReceive != 0)
    {
		rx_ptr = 0;	// invalid data packet
		return(-1); // return code: crc error!
	}

    // Copy data block
	for(getDataCnt=0; getDataCnt < RX_BUF_LEN; ++getDataCnt)
    {
		data[getDataCnt] = rx_buffer[getDataCnt];
	}

    rx_ptr = 0;	// reset pointer

    return(RX_BUF_LEN); // return # of words received
}
/*******************************************************************************
End of Function
*******************************************************************************/

/*******************************************************************************
Function: 	write_datablock
Description:	Data to be transmitted passed through CRC and loaded into temp
                transmit buffer, write sequence then initiated
*******************************************************************************/
int16_t write_datablock(uint16_t *data)
{
	uint16_t writeDataCnt;
	uint16_t crcTransmit;
	uint8_t tempDataWrite; uint8_t *cpData;

	// Exit if transmission is in progress
	if(txActive) return(0);

	IFS0bits.U1TXIF = 0;    // clear TX interrupt flag
	txActive = -1;         // set transmit active flag

	// Copy data to transmit buffer
	cpData = (unsigned char*)&data[0];
	crcTransmit = CRC_START;

    for(writeDataCnt = 0; writeDataCnt < (TX_MAX_BUF_PTR-2); ++writeDataCnt) 
    {
		tempDataWrite = cpData[writeDataCnt];
		MACRO_CRC_STEP(crcTransmit, tempDataWrite);
		tx_bbuffer[writeDataCnt] = tempDataWrite;
	}

    tx_bbuffer[TX_MAX_BUF_PTR-2] = crcTransmit&0x00FF;
	tx_bbuffer[TX_MAX_BUF_PTR-1] = (crcTransmit>>8);;

	// Send 1st byte|0x100 to start transmission
	tx_ptr = 1;
	U1TXREG = 0x0100u|(unsigned int)tx_bbuffer[0];

	return(1);
}
/*******************************************************************************
End of Function
*******************************************************************************/

/*************** END OF FUNCTIONS ***************************************************************************/
