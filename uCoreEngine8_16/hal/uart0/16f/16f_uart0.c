/****************************************************************************
* Title                 :   uCore 16F UART 0 HAL
* Filename              :   16f_uart.h
* Author                :   Jamie Starling
* Origin Date           :   2024/12/25
* Version               :   1.0.0
* Compiler              :   XC8 
* Target                :   Microchip PIC16F series
* Copyright             :   © 2024 Jamie Starling
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

/***************  CHANGE LIST *************************************************
*
*   Date        Version     Author          Description 
*   2024/12/25  1.0.0       Jamie Starling  Initial Version
*  
*
*****************************************************************************/

/******************************************************************************
***** Includes
*******************************************************************************/
#include "16f_uart0.h"

#if (UC_PROCESSOR_HAL_UART_0 && UC_UCORE_MCU_16F)

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
***** Functions
*******************************************************************************/
/******************************************************************************
* Function : uc_hal_uart_init()
* Description: Initializes the SERIAL1 module with the selected baud rate and configuration 
* settings. Configures the baud rate registers, input/output pins, and enables 
* the transmitter and receiver.
*
* Parameters:
*   - baud_select (uc_uart_baud_t): The baud rate configuration from the UART 
*     lookup table (e.g., BAUD_9600).
*******************************************************************************/
uc_return_status_t uc_hal_uart_0_init(uc_uart_baud_t baud_select)
{  
  SP1BRG = uc_uart_0_config[baud_select].SP1BRG_Value;
  BAUD1CONbits.BRG16 = (bool)uc_uart_0_config[baud_select].BRG16_Enable;
  TX1STAbits.SYNC = (bool)uc_uart_0_config[baud_select].SYNC_Enable;
  TX1STAbits.BRGH = (bool)uc_uart_0_config[baud_select].BRGH_Enable;
  
  // Configure the serial input pin as an input
  GPIO.mode(UC_UART_0_INPUT_PIN,UC_INPUT);  
  
  // Map TX output pin
  PPS.map_output(UC_UART_0_OUTPUT_PIN, UC_PPSOUT_TX1_CK1);  
    
  // Enable receiver and transmitter
  RC1STAbits.CREN = (bool)uc_uart_0_config[baud_select].CREN_Enable;
  TX1STAbits.TXEN = (bool)uc_uart_0_config[baud_select].TXEN_Enable;
  RC1STAbits.SPEN = (bool)uc_uart_0_config[baud_select].SPEN_Enable;    
  
  //Set ISR up
  if (ISR_CONTROL.register_handler(uc_hal_uart_0_isr_rx)!= UC_STATUS_OK){return UC_STATUS_FAILED;}
  if (ISR_CONTROL.register_handler(uc_hal_uart_0_isr_tx)!= UC_STATUS_OK){return UC_STATUS_FAILED;}
  
  uc_hal_uart_0_rx_interrupt_enable();  //Enable Receive Interrupt
  
  return UC_STATUS_OK;
}

/******************************************************************************
* Function : uc_hal_uart_0_isr_rx()
* UART 0 Receive ISR - received data placed data into buffer. 
*******************************************************************************/
void uc_hal_uart_0_isr_rx(void)
{
  if (PIR3bits.RC1IF) {
      uint8_t received_byte = RC1REG;
       
      // Try to write received byte into buffer
      if (UART_0_BUFFER_RX.write(received_byte) != UC_STATUS_OK) {
        // Optional: set overflow error flag here
        // uart_rx_overflow_flag = true;
        }
    }
}

/******************************************************************************
* Function : uc_hal_uart_0_isr_tx()
* UART 0 Transmit ISR - sends data from buffer 
*******************************************************************************/
void uc_hal_uart_0_isr_tx(void) {
    if (UART_0_BUFFER_TX.data_available()) {
        uint8_t byte = UART_0_BUFFER_TX.read();
        TX1REG = byte; // Replace with your correct UART TX register
    } else {
       uc_hal_uart_0_tx_interrupt_enable(void); // No more data, disable TX interrupt
    }
}

/******************************************************************************
* Function : uc_hal_uart_0_tx_interrupt_enable()
* Enables Interrupt on empty transmitt buffer
*******************************************************************************/
void uc_hal_uart_0_tx_interrupt_enable(void)
{
  // Enable TX interrupt to begin sending
    PIE3bits.TX1IE = 1; // Use appropriate PIE/TXxIE bit for your setup
}

/******************************************************************************
* Function : uc_hal_uart_0_tx_interrupt_disable()
* Disables Interrupt on empty transmitt buffer
*******************************************************************************/
void uc_hal_uart_0_tx_interrupt_enable(void)
{
  // Disable TX interrupt 
    PIE3bits.TX1IE = 0; 
}

/******************************************************************************
* Function : uc_hal_uart_0_rx_interrupt_enable()
* Enables Interrupt on received data
*******************************************************************************/
void uc_hal_uart_0_rx_interrupt_enable(void)
{
  // Enable RX interrupt to begin sending
    PIE3bits.RX1IE = 1; 
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
  if (RC1STAbits.FERR){return UC_UART_FRAMMING_ERROR;}
  if (RC1STAbits.OERR){return UC_UART_OVERRUN_ERROR;}
  return UC_UART_OK;
}

/******************************************************************************
* Function : SERIAL1_Clear_Error()
* Description: Clears SERIAL1 of any errors.
*******************************************************************************/
void uc_hal_uart_0_clear_errors(void)
{
  uint8_t temp = RC1REG;
  RC1STAbits.CREN = UC_CLEAR;
  NOP();
  RC1STAbits.CREN = UC_SET;
}


#endif /* #if UC_DEVICE_HAL_UART */

/*** End of File **************************************************************/