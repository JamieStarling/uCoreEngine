/****************************************************************************
* Title                 :   uCore 18F UART 0 HAL
* Filename              :   18f_uart.c
* Author                :   Jamie Starling
* Origin Date           :   2025/05/08
* Version               :   1.0.0
* Compiler              :   XC8 
* Target                :    
* Copyright             :   Jamie Starling
* All Rights Reserved
*
* THIS SOFTWARE IS PROVIDED BY JAMIE STARLING "AS IS" AND ANY EXPRESSED
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL JAMIE STARLING OR ITS CONTRIBUTORS BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*
*******************************************************************************/

/******************************************************************************
*                     LICENSED FOR NON-COMMERCIAL USE
*                Visit http://jamiestarling.com/corelicense
*                           for details 
*******************************************************************************/

/*************** CHANGE LOG ***************************************************
*
*    Date    Version   Author         Description 
*
*******************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "18f_uart0.h"

#if (UC_PROCESSOR_HAL_UART_0 && UC_UCORE_MCU_18F)

/******************************************************************************
***** SERIAL1 Interface
*******************************************************************************/
const uc_uart_0_interface_t UART_0 = {
    .initialize = &uc_hal_uart_0_init,
    .tx_enable = &uc_hal_uart_0_tx_interrupt_enable,
    .rx_enable = &uc_hal_uart_0_rx_interrupt_enable,
    .check_for_hw_errors = &uc_hal_uart_0_check_for_errors,
    .clear_hw_errors = &uc_hal_uart_0_clear_errors,   
    .read = &uc_uart_0_rx_read_byte,
    .write = &uc_uart_0_tx_write_byte,
    .data_available = &uc_uart_0_rx_data_available,
};

/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : <NAME>
*//** 
* \b Description:
*
*******************************************************************************/
uc_return_status_t uc_hal_uart_0_init(uc_uart_baud_t baud_select)
{  
  U1CON0bits.MODE = uc_uart_0_config[baud_select].ESUART_Mode; //Asynchronous 8-bit UART mode
  U1BRG = uc_uart_0_config[baud_select].BRG_Value;
   
  U1CON0bits.BRGS = (bool)uc_uart_0_config[baud_select].BRGS_Enable;  
  
  GPIO.mode(UC_UART_0_INPUT_PIN,UC_INPUT);   //Set as input -> Serial In
  
  PPS.map_output(UC_UART_0_OUTPUT_PIN,UC_PPSOUT_UART1_TX);  //Map TX to ->Serial Out    
  
  U1CON0bits.RXEN = (bool)uc_uart_0_config[baud_select].RXEN_Enable; //Receive Enable
  U1CON0bits.TXEN = (bool)uc_uart_0_config[baud_select].TXEN_Enable; //Transmit Enable
  U1CON1bits.ON = (bool)uc_uart_0_config[baud_select].SPEN_Enable; //Serial Port Enable
  
  //Set ISR up
  if (ISR_CONTROL.register_handler(IRQ_U1RX,uc_hal_uart_0_isr_rx)!= UC_STATUS_OK){return UC_STATUS_FAILED;}
  if (ISR_CONTROL.register_handler(IRQ_U1TX,uc_hal_uart_0_isr_tx)!= UC_STATUS_OK){return UC_STATUS_FAILED;}
  
  uc_hal_uart_0_rx_interrupt_enable();  //Enable Receive Interrupt
  
  return UC_STATUS_OK;   
}


/******************************************************************************
* Function : uc_hal_uart_0_isr_rx()
* UART 0 Receive ISR - received data placed data into buffer. 
*******************************************************************************/
void uc_hal_uart_0_isr_rx(void)
{
  uint8_t received_byte = U1RXB;  
  // Try to write received byte into buffer
  if (UART_0_BUFFER_RX.write(received_byte) != UC_STATUS_OK) {}  
}

/******************************************************************************
* Function : uc_hal_uart_0_isr_tx()
* UART 0 Transmit ISR - sends data from buffer 
*******************************************************************************/
void uc_hal_uart_0_isr_tx(void) {
    if (UART_0_BUFFER_TX.data_available()) {
        uint8_t byte = UART_0_BUFFER_TX.read();
        U1TXB = byte; // Replace with your correct UART TX register
    } else {
        uc_hal_uart_0_tx_interrupt_disable(); // No more data, disable TX interrupt
    }
}

/******************************************************************************
* Function : uc_hal_uart_0_tx_interrupt_enable()
* Enables Interrupt on empty transmitt buffer
*******************************************************************************/
void uc_hal_uart_0_tx_interrupt_enable(void)
{
  // Enable TX interrupt to begin sending
    PIE4bits.U1TXIE = 1; 
}

/******************************************************************************
* Function : uc_hal_uart_0_tx_interrupt_disable()
* Enables Interrupt on empty transmitt buffer
*******************************************************************************/
void uc_hal_uart_0_tx_interrupt_disable(void)
{  
  PIE4bits.U1TXIE = 0; // Disable TX interrupt
}


/******************************************************************************
* Function : uc_hal_uart_0_rx_interrupt_enable()
* Enables Interrupt on received data
*******************************************************************************/
void uc_hal_uart_0_rx_interrupt_enable(void)
{
  // Enable RX interrupt to begin sending
    PIE4bits.U1RXIE = 1; 
}


/******************************************************************************
* Function : uc_hal_uart_check_for_errors()
* Description: Checks if the UART 0 has any errors
*
* Returns:
*   - uc_uart_status_t: Error Code or UC_UART_OK
*
*******************************************************************************/
uc_uart_status_t uc_hal_uart_0_check_for_errors(void)
{
  if (U1ERRIRbits.FERIF){return UC_UART_FRAMMING_ERROR;}
  if (U1ERRIRbits.RXFOIF){return UC_UART_OVERRUN_ERROR;}
  return UC_UART_OK;
}

/******************************************************************************
* Function : SERIAL1_Clear_Error()
* Description: Clears SERIAL1 of any errors.
*******************************************************************************/
void uc_hal_uart_0_clear_errors(void)
{
  uint8_t temp = U1RXB;
  U1CON0bits.RXEN = UC_CLEAR;
  NOP();
  U1CON0bits.RXEN = UC_SET;
}

#endif
/*** End of File **************************************************************/
