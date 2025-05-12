/****************************************************************************
* Title                 :   uCore Engine Config for UART
* Filename              :   config_uart.h
* Author                :   Jamie Starling
* Origin Date           :   2024/12/24
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
*   Date        Version     Author         Description 
*   2024/12/24  1.0.0       Jamie Starling  Initial Version
*  
*****************************************************************************/


/******************************************************************************
* Includes
*******************************************************************************/
#include "pic18f2xq84.h"

#ifdef UC_SYSTEM_PROCESSOR_18F2xQ84

#ifndef _UC_PROCERSSOR_CONFIG_UART_H
#define _UC_PROCERSSOR_CONFIG_UART_H

#if UC_PROCESSOR_HAL_UART_0


/******************************************************************************
***** Configuration for UART 0
*******************************************************************************/

#define UC_UART_0_RX_BUFFER_SIZE 8
#define UC_UART_0_TX_BUFFER_SIZE 8

#define UC_UART_0_TIMEOUT_VALUE 1025

#define UC_UART_0_INPUT_PIN UC_PORTC7      //Defines the EUSART Input Pin
#define UC_UART_0_OUTPUT_PIN UC_PORTC6    //Defines the EUSART Ouput Pin

/******************************************************************************
 * Baud Rate Selection  
 ********************************************************************************/
typedef enum
{
    UC_BAUD_9600,
    UC_BAUD_19200,
    UC_BAUD_57600 
}uc_uart_baud_t;

/******************************************************************************
 * UART1 Configuration Structure
 * This structure defines the settings for the SERIAL1 module, such as baud rate and control options.
 ********************************************************************************/
typedef struct
{
    uint8_t ESUART_Mode;    
    uint16_t BRG_Value;         //Desired Baud Rate Value
    uc_logic_t BRGS_Enable;    //Desired Baud Rate Multiplier
    uc_logic_t RXEN_Enable;    //Receive Enable Control
    uc_logic_t TXEN_Enable;    //Transmit Enable Control
    uc_logic_t SPEN_Enable;    //Serial Port Enable
}uc_uart_0_config_t;

/******************************************************************************
 * SERIAL1 Configuration Lookup Table
 ********************************************************************************/
/*UART Config for 64Mhz*/
#if _XTAL_FREQ == 64000000
const uc_uart_0_config_t uc_uart_0_config[]=
{        
    {0b0000,0x682,UC_ENABLED,UC_ENABLED,UC_ENABLED,UC_ENABLED},  //9600Baud @64Mhz
    {0b0000,0x340,UC_ENABLED,UC_ENABLED,UC_ENABLED,UC_ENABLED},  //19200Baud @64Mhz
    {0b0000,0x115,UC_ENABLED,UC_ENABLED,UC_ENABLED,UC_ENABLED}  //57600Baud @64Mhz
};
#endif


#endif /* UC_DEVICE_CONFIG_UART_H */
#endif /* UC_DEVICE_HAL_UART */
#endif /* #ifdef UC_SYSTEM_DEVICE_16F1532X */
/*** End of File **************************************************************/
