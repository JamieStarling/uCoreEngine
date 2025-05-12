/****************************************************************************
* Title                 :   uCore UART 0 Buffers
* Filename              :   buffer_uart_0.h
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

/***************  CHANGE LIST *************************************************
*
*    Date    Version   Author         Description 
*  
*
*****************************************************************************/

#ifndef _BUFFER_UART_0_H
#define _BUFFER_UART_0_H

/******************************************************************************
* Includes
*******************************************************************************/
#include "../uart0.h"

#if UC_PROCESSOR_HAL_UART_0

/******************************************************************************
***** Buffer Interface
*******************************************************************************/
typedef struct {
  uc_logic_t (*data_available)(void);
  uc_logic_t (*is_full)(void);
  uint8_t (*read)(void);
  uc_return_status_t (*write)(uint8_t byte);
  uint8_t (*overflow_count)(void);  
  void (*reset)(void);
   
}uc_uart_0_buffer_interface_t;

extern const uc_uart_0_buffer_interface_t UART_0_BUFFER_RX;
extern const uc_uart_0_buffer_interface_t UART_0_BUFFER_TX;


typedef struct {
    volatile uint8_t buffer[UC_UART_0_RX_BUFFER_SIZE];
    volatile uint8_t write_index;  // Write index
    volatile uint8_t read_index;  // Read index     
    volatile uint8_t overrun_count; //Buffer Overrun Count
} uart_0_rx_buffer_t;

typedef struct {
    volatile uint8_t buffer[UC_UART_0_TX_BUFFER_SIZE];
    volatile uint8_t write_index;  // Write index
    volatile uint8_t read_index;  // Read index    
} uart_0_tx_buffer_t;

/******************************************************************************
* Function Prototypes
*******************************************************************************/
uc_logic_t uc_uart_0_rx_data_available(void);
uint8_t uc_uart_0_rx_read_byte(void);
uc_logic_t uc_uart_0_rx_check_buffer_full(void);
uc_return_status_t uc_uart_0_rx_write_byte(uint8_t byte);
uint8_t uc_uart_0_rx_get_overflow_count(void);
void uc_uart_0_rx_reset(void);

uc_logic_t uc_uart_0_tx_data_available(void);
uint8_t uc_uart_0_tx_read_byte(void);
uc_logic_t uc_uart_0_tx_check_buffer_full(void);
uc_return_status_t uc_uart_0_tx_write_byte(uint8_t byte);
void uc_uart_0_tx_reset(void);
#endif /*_H_*/
#endif 
/*** End of File **************************************************************/
