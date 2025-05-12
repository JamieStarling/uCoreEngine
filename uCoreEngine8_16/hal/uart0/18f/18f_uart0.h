/****************************************************************************
* Title                 :   UART1 Functions - Enhanced Universal Synchronous
*                           Asynchronous Receiver Transmitter
* Filename              :   18f_uart.h
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
#include "../uart0.h"

#if (UC_PROCESSOR_HAL_UART_0 && UC_UCORE_MCU_18F)

#ifndef UC_HAL_18F_UART_0_H
#define UC_HAL_18F_UART_0_H

/******************************************************************************
* Defines
*******************************************************************************/


/******************************************************************************
* Function Prototypes
*******************************************************************************/
uc_return_status_t uc_hal_uart_0_init(uc_uart_baud_t baud_select);
void uc_hal_uart_0_isr_rx(void);
void uc_hal_uart_0_isr_tx(void);
void uc_hal_uart_0_tx_interrupt_enable(void);
void uc_hal_uart_0_rx_interrupt_enable(void);
uc_uart_status_t uc_hal_uart_0_check_for_errors(void);
void uc_hal_uart_0_clear_errors(void);
void uc_hal_uart_0_tx_interrupt_disable(void);

#endif /*_UC_HAL_18F_UART_H*/
#endif /* #if UC_DEVICE_HAL_UART */

/*** End of File **************************************************************/
