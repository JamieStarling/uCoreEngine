/****************************************************************************
* Title                 :   uCore Engine PPS Lookup Tables
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
#include "pic16f1532x.h"

#ifdef UC_SYSTEM_PROCESSOR_16F1532X 

#ifndef _UC_PROCESSOR_HAL_PPS_H
#define _UC_PROCESSOR_HAL_PPS_H

#if UC_PROCESSOR_HAL_PPS



/******************************************************************************
*PPS Peripheral Output Enum * This enum defines the PPS Peripheral Output available for selection on the device.
*******************************************************************************/
typedef enum 
{
    UC_PPSOUT_CLKR = 0x1BU,			    
    UC_PPSOUT_NCO1OUT = 0x1AU, 
    UC_PPSOUT_TMR0 = 0x19U,
    UC_PPSOUT_SDO1_SDA1 = 0x16U,
    UC_PPSOUT_SCK1_SCL1 = 0x15U,    
    UC_PPSOUT_C2OUT = 0x14U,
    UC_PPSOUT_C1OUT = 0x13U,
    UC_PPSOUT_DT1 = 0x10U,
    UC_PPSOUT_TX1_CK1 = 0x0FU,
    UC_PPSOUT_PWM6OUT = 0x0EU,
    UC_PPSOUT_PWM5OUT = 0x0DU,
    UC_PPSOUT_PWM4OUT = 0x0CU,
    UC_PPSOUT_PWM3OUT = 0x0BU,
    UC_PPSOUT_CCP2 = 0x0AU,
    UC_PPSOUT_CCP1 = 0x09U,
    UC_PPSOUT_CWG1D = 0x08U,
    UC_PPSOUT_CWG1C = 0x07U,
    UC_PPSOUT_CWG1B = 0x06U,
    UC_PPSOUT_CWG1A = 0x05U,
    UC_PPSOUT_CLC4OUT = 0x04U,
    UC_PPSOUT_CLC3OUT = 0x03U,
    UC_PPSOUT_CLC2OUT = 0x02U,
    UC_PPSOUT_CLC1OUT = 0x01U,           
}uc_pps_output_peripheral_t;


/******************************************************************************
* PPS Register Lookup
*******************************************************************************/
typedef struct {
    volatile UC_POINTER_REGISTER_SIZE gpio_ps_inputpin;
    volatile UC_POINTER_REGISTER_SIZE *gpio_pps_output_reg;    
} uc_pps_registers_t;

extern const uc_pps_registers_t pps_register_lu[];



#endif 
#endif 
#endif 
/*** End of File **************************************************************/
