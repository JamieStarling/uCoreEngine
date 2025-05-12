/****************************************************************************
* Title                 :   UART Chooser Header
* Filename              :   uart.h
* Author                :   Jamie Starling
* Origin Date           :   2025/01/04
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

/***************  CHANGE LIST *************************************************
*
*    Date    Version   Author         Description 
*  
*  
*
*****************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "../hal.h"

#ifndef _UC_UART_0_H
#define _UC_UART_0_H

#if UC_PROCESSOR_HAL_UART_0

/******************************************************************************
* Serial Error Codes
******************************************************************************/
typedef enum
{    
  UC_UART_OK,
  UC_UART_FRAMMING_ERROR,
  UC_UART_OVERRUN_ERROR,
  UC_UART_TIMEOUT,
}uc_uart_status_t;


/******************************************************************************
***** UART Interface
*******************************************************************************/
typedef struct {
  uc_return_status_t (*initialize)(uc_uart_baud_t baud_select);   
  void (*tx_enable)(void);
  void (*rx_enable)(void);
  uc_uart_status_t (*check_for_hw_errors)(void);
  void (*clear_hw_errors)(void);
  uint8_t (*read)(void);
  uc_return_status_t (*write)(uint8_t byte); 
  uc_logic_t (*data_available)(void);
}uc_uart_0_interface_t;

extern const uc_uart_0_interface_t UART_0;


#if UC_UCORE_MCU_16F /*16F Devices*/        
    #include "buffer/buffer_uart_0.h"    
    #include "16f/16f_uart0.h"    
#endif

#if UC_UCORE_MCU_18F/*18F Devices*/    
    #include "buffer/buffer_uart_0.h" 
    #include "18f/18f_uart0.h" 
#endif



#endif /*UC_UART_H*/
#endif 

/*** End of File **************************************************************/
