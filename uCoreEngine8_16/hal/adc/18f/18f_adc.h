/****************************************************************************
* Title                 :   18F Analog Functions
* Filename              :   18f_adc.h
* Author                :   Jamie Starling
* Origin Date           :   2025/01/05
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
*   2025/01/05  1.0.0       Jamie Starling  Initial Version
*  
*
*****************************************************************************/


/******************************************************************************
* Includes
*******************************************************************************/
#include "../adc.h"

#if (UC_UCORE_MCU_18F && UC_PROCESSOR_HAL_ADC)

#ifndef _UC_HAL_18F_ANALOG_H
#define _UC_HAL_18F_ANALOG_H


/******************************************************************************
* Function Prototypes
*******************************************************************************/
void uc_hal_adc_init(uc_adc_channels_t channel);
void uc_hal_adc_select_channel(uc_adc_channels_t channel);
void uc_hal_adc_set_pin_analog(uc_gpio_portpins_t port_pin, uc_adc_channels_t channel);
uint16_t uc_hal_adc_read_channel(void);

#endif /* UC_HAL_ANALOG_H */
#endif /* #if UC_DEVICE_HAL_ADC */

/*** End of File **************************************************************/
