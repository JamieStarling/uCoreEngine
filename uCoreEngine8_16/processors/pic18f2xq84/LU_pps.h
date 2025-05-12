/****************************************************************************
* Title                 :   uCore 8 Engine PPS Lookup Tables
* Filename              :   LU_pps.h
* Author                :   Jamie Starling
* Origin Date           :   2024/12/20
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
*   Date        Version     Author          Description 
*   2024/12/20  1.0.0       Jamie Starling  Initial Version
*  
*****************************************************************************/


/******************************************************************************
* Includes
*******************************************************************************/
#include "pic18f2xq84.h"

#ifdef UC_SYSTEM_PROCESSOR_18F2xQ84

#ifndef _UC_PROCESSOR_HAL_PPS_H
#define _UC_PROCESSOR_HAL_PPS_H

#if UC_PROCESSOR_HAL_PPS




/******************************************************************************
*PPS Peripheral Output Enum * This enum defines the PPS Peripheral Output available for selection on the device.
*******************************************************************************/
typedef enum
{
    UC_PSSOUT_LATxy            = 0x00U,
    UC_PPSOUT_CLC1OUT          = 0x01U,      
    UC_PPSOUT_CLC2OUT          = 0x02U,
    UC_PPSOUT_CLC3OUT          = 0x03U,
    UC_PPSOUT_CLC4OUT          = 0x04U,
    UC_PPSOUT_CLC5OUT          = 0x05U,
    UC_PPSOUT_CLC6OUT          = 0x06U,
    UC_PPSOUT_CLC7OUT          = 0x07U,
    UC_PPSOUT_CLC8OUT          = 0x08U,
    UC_PPSOUT_CWG1A            = 0x09U,
    UC_PPSOUT_CWG1B            = 0x0AU,
    UC_PPSOUT_CWG1C            = 0x0BU,
    UC_PPSOUT_CWG1D            = 0x0CU,
    UC_PPSOUT_CWG2A            = 0x0DU,
    UC_PPSOUT_CWG2B            = 0x0EU,
    UC_PPSOUT_CWG2C            = 0x0FU,
    UC_PPSOUT_CWG2D            = 0x10U,
    UC_PPSOUT_CWG3A            = 0x11U,
    UC_PPSOUT_CWG3B            = 0x12U,
    UC_PPSOUT_CWG3C            = 0x13U,
    UC_PPSOUT_CWG3D            = 0x14U,
    UC_PPSOUT_CCP1             = 0x15U,
    UC_PPSOUT_CCP2             = 0x16U,
    UC_PPSOUT_CCP3             = 0x17U,
    UC_PPSOUT_PWM1S1P1_OUT     = 0x18U,
    UC_PPSOUT_PWM1S1P2_OUT     = 0x19U,
    UC_PPSOUT_PWM2S1P1_OUT     = 0x1AU,
    UC_PPSOUT_PWM2S1P2_OUT     = 0x1BU,
    UC_PPSOUT_PWM3S1P1_OUT     = 0x1CU,
    UC_PPSOUT_PWM3S1P2_OUT     = 0x1DU,
    UC_PPSOUT_PWM4S1P1_OUT     = 0x1EU,
    UC_PPSOUT_PWM4S1P2_OUT     = 0x1FU,
    UC_PPSOUT_UART1_TX         = 0x20U,
    UC_PPSOUT_UART1_TXDE       = 0x21U,
    UC_PPSOUT_UART1_RTS        = 0x22U,
    UC_PPSOUT_UART2_TX         = 0x23U,
    UC_PPSOUT_UART2_TXDE       = 0x24U,
    UC_PPSOUT_UART2_RTS        = 0x25U,  
    UC_PPSOUT_UART3_TX         = 0x26U,
    UC_PPSOUT_UART3_TXDE       = 0x27U,
    UC_PPSOUT_UART3_RTS        = 0x28U,
    UC_PPSOUT_UART4_TX         = 0x29U,
    UC_PPSOUT_UART4_TXDE       = 0x2AU, 
    UC_PPSOUT_UART4_RTS        = 0x2BU,
    UC_PPSOUT_UART5_TX         = 0x2CU,
    UC_PPSOUT_UART5_TXDE       = 0x2DU,
    UC_PPSOUT_UART5_RTS        = 0x2EU,
    UC_PPSOUT_C1OUT            = 0x2FU,
    UC_PPSOUT_C2OUT            = 0x30U,
    UC_PPSOUT_SPI1_SCK         = 0x31U,
    UC_PPSOUT_SPI1_SDO         = 0x32U,
    UC_PPSOUT_SPI1_SS          = 0x33U,
    UC_PPSOUT_SPI2_SCK         = 0x34U,
    UC_PPSOUT_SPI2_SDO         = 0x35U,
    UC_PPSOUT_SPI2_SS          = 0x36U,
    UC_PPSOUT_I2C1_SCL         = 0x37U,
    UC_PPSOUT_I2C1_SDA         = 0x38U,
    UC_PPSOUT_TMR0             = 0x39U,
    UC_PPSOUT_TU16A            = 0x3AU,
    UC_PPSOUT_TU16B            = 0x3BU,
    UC_PPSOUT_NCO1             = 0x3FU,
    UC_PPSOUT_NCO2             = 0x40U,
    UC_PPSOUT_NCO3             = 0x41U,
    UC_PPSOUT_CLKR             = 0x42U,
    UC_PPSOUT_DSM1             = 0x43U,
    UC_PPSOUT_ADGRDA           = 0x44U,
    UC_PPSOUT_ADGRDB           = 0x45U,
    UC_PPSOUT_CANTX            = 0x46U          
}uc_pps_output_peripheral_t;

/******************************************************************************
* PPS Register Lookup
*******************************************************************************/
typedef struct {
    volatile UC_POINTER_REGISTER_SIZE gpio_ps_inputpin;
    volatile UC_POINTER_REGISTER_SIZE *gpio_pps_output_reg;    
} uc_pps_registers_t;

extern const uc_pps_registers_t pps_register_lu[];



#endif /*UC_DEVICE_HAL_PPS_H*/
#endif /* #ifdef UC_DEVICE_PIC18F2xQ84_H */
#endif 
/*** End of File **************************************************************/
