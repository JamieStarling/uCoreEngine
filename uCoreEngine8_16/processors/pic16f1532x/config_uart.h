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
#include "pic16f1532x.h"

#ifdef UC_SYSTEM_PROCESSOR_16F1532X

#ifndef UC_DEVICE_CONFIG_UART_H
#define UC_DEVICE_CONFIG_UART_H

#if UC_PROCESSOR_HAL_UART_0



/******************************************************************************
***** Configuration for UART_0
*******************************************************************************/

#define UC_UART_0_RX_BUFFER_SIZE 8
#define UC_UART_0_TX_BUFFER_SIZE 8

#define UC_UART_0_TIMEOUT_VALUE 1025

#define UC_UART_0_INPUT_PIN UC_PORTA5      //Defines the EUSART RX Pin
#define UC_UART_0_OUTPUT_PIN UC_PORTA4     //Defines the EUSART TX Pin


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
 * SERIAL1 Configuration Structure
 * This structure defines the settings for the SERIAL1 module, such as baud rate and control options.
 ********************************************************************************/
typedef struct
{
    uint16_t SP1BRG_Value; 
    uc_logic_t BRG16_Enable; 
    uc_logic_t SYNC_Enable;
    uc_logic_t BRGH_Enable;
    uc_logic_t CREN_Enable;
    uc_logic_t TXEN_Enable;
    uc_logic_t SPEN_Enable;
}uc_uart_0_config_t;

/******************************************************************************
 * SERIAL1 Configuration Lookup Table
 ********************************************************************************/
/*Config for 32Mhz*/
#if _XTAL_FREQ == 32000000
const uc_uart_0_config_t uc_uart_0_config[]=
{        
    {832,UC_ENABLED,UC_DISABLED,UC_ENABLED,UC_ENABLED,UC_ENABLED,UC_ENABLED},  //9600Baud @32Mhz
    {416,UC_ENABLED,UC_DISABLED,UC_ENABLED,UC_ENABLED,UC_ENABLED,UC_ENABLED},  //19200 Baud @32Mhz
    {34,UC_DISABLED,UC_DISABLED,UC_ENABLED,UC_ENABLED,UC_ENABLED,UC_ENABLED}  //57600 Baud @32Mhz
};
#endif


#endif /* UC_DEVICE_CONFIG_UART_H */
#endif /* UC_DEVICE_HAL_UART */
#endif /* #ifdef UC_SYSTEM_DEVICE_16F1532X */
/*** End of File **************************************************************/
