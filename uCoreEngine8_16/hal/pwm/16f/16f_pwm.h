/****************************************************************************
* Title                 :   uCore Engine Functions
* Filename              :   pwm3.h
* Author                :   Jamie Starling
* Origin Date           :   2024/12/23
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
*   2024/12/23 1.0.0       Jamie Starling  Initial Version
*  
*
*****************************************************************************/


/******************************************************************************
* Includes
*******************************************************************************/
#include "../pwm.h"

#ifndef _UC_HAL_16F_PWM_H
#define _UC_HAL_16F_PWM_H

#if UC_UCORE_MCU_16F


/******************************************************************************
* Function Prototypes PWM3
*******************************************************************************/
#if UC_PROCESSOR_HAL_PWM3
void uc_hal_pwm3_init(uc_gpio_portpins_t port_pin,uc_hal_pwm_configuration_t pwm_config_select);
void uc_hal_pwm3_output_enable(uc_logic_t set_state);
void uc_hal_pwm3_set_duty_cycle(uint16_t duty_value);
#endif 

/******************************************************************************
* Function Prototypes PWM4
*******************************************************************************/
#if UC_PROCESSOR_HAL_PWM4
void uc_hal_pwm4_init(uc_gpio_portpins_t port_pin,uc_hal_pwm_configuration_t pwm_config_select);
void uc_hal_pwm4_output_enable(uc_logic_t set_state);
void uc_hal_pwm4_set_duty_cycle(uint16_t duty_value);
#endif 

/******************************************************************************
* Function Prototypes PWM5
*******************************************************************************/
#if UC_PROCESSOR_HAL_PWM5
void uc_hal_pwm5_init(uc_gpio_portpins_t port_pin,uc_hal_pwm_configuration_t pwm_config_select);
void uc_hal_pwm5_output_enable(uc_logic_t set_state);
void uc_hal_pwm5_set_duty_cycle(uint16_t duty_value);
#endif 

/******************************************************************************
* Function Prototypes PWM6
*******************************************************************************/
#if UC_PROCESSOR_HAL_PWM6
void uc_hal_pwm6_init(uc_gpio_portpins_t port_pin,uc_hal_pwm_configuration_t pwm_config_select);
void uc_hal_pwm6_output_enable(uc_logic_t set_state);
void uc_hal_pwm6_set_duty_cycle(uint16_t duty_value);
#endif 


#endif /* UC_HAL_PWM_H */
#endif /* #if UC_DEVICE_HAL_PWM */
/*** End of File **************************************************************/
