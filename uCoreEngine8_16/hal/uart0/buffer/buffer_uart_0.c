/****************************************************************************
* Title                 :   uCore UART 0 Buffers
* Filename              :   buffer_uart_0.c
* Author                :   Jamie Starling
* Origin Date           :   2025/05/06
* Version               :   1.0.0
* Compiler              :   XC8 
* Target                :   PIC16F MCUs 
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
#include "buffer_uart_0.h"

#if UC_PROCESSOR_HAL_UART_0

uart_0_rx_buffer_t uart_rx_buffer = {0};
uart_0_tx_buffer_t uart_tx_buffer = {0};


/******************************************************************************
***** Buffer Interface
*******************************************************************************/
const uc_uart_0_buffer_interface_t UART_0_BUFFER_RX = {
    .data_available = &uc_uart_0_rx_data_available,   
    .is_full = &uc_uart_0_rx_check_buffer_full,
    .read = &uc_uart_0_rx_read_byte,
    .write = &uc_uart_0_rx_write_byte,
    .overflow_count = &uc_uart_0_rx_get_overflow_count,
    .reset = &uc_uart_0_rx_reset,
};

const uc_uart_0_buffer_interface_t UART_0_BUFFER_TX = {
    .data_available = &uc_uart_0_tx_data_available,   
    .is_full = &uc_uart_0_tx_check_buffer_full,
    .read = &uc_uart_0_tx_read_byte,
    .write = &uc_uart_0_tx_write_byte,
    .overflow_count = NULL,
    .reset = &uc_uart_0_tx_reset,
};


/******************************************************************************
* Local Function Prototypes 
*******************************************************************************/
void uc_uart_0_rx_increase_overflow_counter(void);

/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : uc_uart_0_rx_data_available
* @brief Check if new UART RX data is available.:
* 
* This function checks whether the UART receive buffer contains any unread data.
* It compares the write and read indices in the circular buffer. If they are not equal,
* it means that at least one byte has been received and is waiting to be read.
*
* @return uc_logic_t
*         - UC_TRUE  : Data is available to read.
*         - UC_FALSE : No data available (buffer is empty).
*
*******************************************************************************/
uc_logic_t uc_uart_0_rx_data_available(void) {
    return uart_rx_buffer.write_index != uart_rx_buffer.read_index;
}

/******************************************************************************
* Function : uc_uart_0_rx_read_byte
* @brief Read a single byte from the UART receive buffer.
*
* This function retrieves the next available byte from the UART RX circular buffer.
* It first checks whether any data is available by comparing the write and read indices.
* If the buffer is empty, it returns 0 (you may choose to return a sentinel value or handle error differently).
*
* After reading, the read index is advanced, wrapping around if needed (circular buffer logic).
*
* @return uint8_t
*         - The next byte from the RX buffer if data is available.
*         - 0 if the buffer is empty (NOTE: distinguishable only if 0 is not valid data).
*******************************************************************************/
uint8_t uc_uart_0_rx_read_byte(void) {
    
  if (uart_rx_buffer.write_index == uart_rx_buffer.read_index) {
        return 0; // or return an error code, or block
    }   
    uint8_t byte = uart_rx_buffer.buffer[uart_rx_buffer.read_index];
    uart_rx_buffer.read_index = (uart_rx_buffer.read_index + 1) % UC_UART_0_RX_BUFFER_SIZE;
    return byte;
}

/******************************************************************************
* Function : uc_uart_0_rx_check_buffer_full
* @brief Check if the UART receive buffer is full.
*
*******************************************************************************/
uc_logic_t uc_uart_0_rx_check_buffer_full(void){
    uint8_t next_index = (uart_rx_buffer.write_index + 1) % UC_UART_0_RX_BUFFER_SIZE;
    return (next_index == uart_rx_buffer.read_index);
}

/******************************************************************************
* Function : uc_uart_0_rx_write_byte
* @brief Write a single byte to the UART receive buffer.
* 
* This function is typically called from the UART receive ISR when a new byte is received.
* It attempts to store the incoming byte in the RX circular buffer.
*
* Before writing, it checks whether the buffer is full using `uc_uart_0_rx_check_buffer_full()`.
* If the buffer is full, the function returns `UC_STATUS_FAILED`, and the byte is not written.
* Otherwise, it stores the byte at the current write index and advances the index,
* wrapping around using modulo logic to maintain the circular buffer behavior.
*
* @param byte The byte to write into the RX buffer.
*
* @return uc_logic_t
*         - UC_STATUS_OK     : The byte was successfully written to the buffer.
*         - UC_STATUS_FAILED : The buffer is full; byte was not written.
*******************************************************************************/
uc_return_status_t uc_uart_0_rx_write_byte(uint8_t byte) {
  
  if (uc_uart_0_rx_check_buffer_full()) {
      uc_uart_0_rx_increase_overflow_counter();
      return UC_STATUS_FAILED;
    }
  
  uart_rx_buffer.buffer[uart_rx_buffer.write_index] = byte;
  uart_rx_buffer.write_index = (uart_rx_buffer.write_index + 1) % UC_UART_0_RX_BUFFER_SIZE;
  return UC_STATUS_OK;
}

/******************************************************************************
* Function : uc_uart_0_rx_increase_overflow_counter
* @brief Increments the overflow counter in the RX Buffer
*******************************************************************************/ 
void uc_uart_0_rx_increase_overflow_counter(void)
{
    uart_rx_buffer.overrun_count++;
}

/******************************************************************************
* Function : uc_uart_0_rx_get_overflow_count
* @brief Returns the count of overflows in the RX buffer.
*******************************************************************************/ 
uint8_t uc_uart_0_rx_get_overflow_count(void)
{
    return uart_rx_buffer.overrun_count;
}

/******************************************************************************
* Function : uc_uart_0_rx_clear
* @brief Resets /Clears the RX buffer
*******************************************************************************/ 
void uc_uart_0_rx_reset(void) {
  uart_rx_buffer.read_index = 0;
  uart_rx_buffer.write_index = 0;
}


/******************************************************************************
* Functions for TX  ***************************
*******************************************************************************/

/******************************************************************************
* Function : uc_uart_0_tx_data_available
* @brief Check if new UART TX data is available.:
* 
* This function checks whether the UART receive buffer contains any unread data.
* It compares the write and read indices in the circular buffer. If they are not equal,
* it means that at least one byte has been received and is waiting to be read.
*
* @return uc_logic_t
*         - UC_TRUE  : Data is available to read.
*         - UC_FALSE : No data available (buffer is empty).
*
*******************************************************************************/
uc_logic_t uc_uart_0_tx_data_available(void) {
    return uart_tx_buffer.write_index != uart_tx_buffer.read_index;
}

/******************************************************************************
* Function : uc_uart_0_tx_read_byte
* @brief Read a single byte from the UART Transmit buffer.
*
* This function retrieves the next available byte from the UART TX circular buffer.
* It first checks whether any data is available by comparing the write and read indices.
* If the buffer is empty, it returns 0 (you may choose to return a sentinel value or handle error differently).
*
* After reading, the read index is advanced, wrapping around if needed (circular buffer logic).
*
* @return uint8_t
*         - The next byte from the TX buffer if data is available.
*         - 0 if the buffer is empty (NOTE: distinguishable only if 0 is not valid data).
*******************************************************************************/
uint8_t uc_uart_0_tx_read_byte(void) {
    
  if (uart_tx_buffer.write_index == uart_tx_buffer.read_index) {
        return 0; // or return an error code, or block
    }   
    uint8_t byte = uart_tx_buffer.buffer[uart_tx_buffer.read_index];
    uart_tx_buffer.read_index = (uart_tx_buffer.read_index + 1) % UC_UART_0_TX_BUFFER_SIZE;
    return byte;
}

/******************************************************************************
* Function : uc_uart_0_tx_check_buffer_full
* @brief Check if the UART transmit buffer is full.
*
*******************************************************************************/
uc_logic_t uc_uart_0_tx_check_buffer_full(void){
    uint8_t next_index = (uart_tx_buffer.write_index + 1) % UC_UART_0_TX_BUFFER_SIZE;
    return (next_index == uart_tx_buffer.read_index);
}

/******************************************************************************
* Function : uc_uart_0_tx_write_byte
* @brief Write a single byte to the UART transmit buffer.
* 
*
* Before writing, it checks whether the buffer is full using `uc_uart_0_tx_check_buffer_full()`.
* If the buffer is full, the function returns `UC_STATUS_FAILED`, and the byte is not written.
* Otherwise, it stores the byte at the current write index and advances the index,
* wrapping around using modulo logic to maintain the circular buffer behavior.
*
* @param byte The byte to write into the TX buffer.
*
* @return uc_logic_t
*         - UC_STATUS_OK     : The byte was successfully written to the buffer.
*         - UC_STATUS_FAILED : The buffer is full; byte was not written.
*******************************************************************************/
uc_return_status_t uc_uart_0_tx_write_byte(uint8_t byte) {
  //Optional: set overflow error flag here  
  if (uc_uart_0_tx_check_buffer_full()) {return UC_STATUS_FAILED;} 
  
  uart_tx_buffer.buffer[uart_tx_buffer.write_index] = byte;
  uart_tx_buffer.write_index = (uart_tx_buffer.write_index + 1) % UC_UART_0_TX_BUFFER_SIZE;
  UART_0.tx_enable(); //Enable TX Interrupt 
  return UC_STATUS_OK;
}

/******************************************************************************
* Function : uc_uart_0_tx_reset
* @brief Resets /Clears the TX buffer
*******************************************************************************/ 
void uc_uart_0_tx_reset(void) {
  uart_tx_buffer.read_index = 0;
  uart_tx_buffer.write_index = 0;
}

#endif 
/*** End of File **************************************************************/
