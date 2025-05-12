/****************************************************************************
* Title                 :   uCore Engine PWM Functions
* Filename              :   %<%NAME%>%.%<%EXTENSION%>%
* Author                :   %<%USER%>%
* Origin Date           :   %<%DATE%>%, %<%TIME%>%
* Version               :   1.0.0
* Compiler              :   
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


#ifndef _UC_HAL_PWM_H
#define _UC_HAL_PWM_H

#if (UC_PROCESSOR_HAL_PWM_TIMER && UC_UCORE_MCU_16F)
    #include "16f/16f_pwm.h"
#endif

/******************************************************************************
***** PWM3 Interface
*******************************************************************************/
#if UC_PROCESSOR_HAL_PWM3
typedef struct {
  void (*initialize)(uc_gpio_portpins_t port_pin, uc_hal_pwm_configuration_t pwm_config_select);   
  void (*output)(uc_logic_t set_state);
  void (*set_duty_cycle)(uint16_t duty_value);
}uc_hal_pwm3_interface_t;

extern const uc_hal_pwm3_interface_t PWM3;
#endif 


/******************************************************************************
***** PWM4 Interface
*******************************************************************************/
#if UC_PROCESSOR_HAL_PWM4
typedef struct {
  void (*initialize)(uc_gpio_portpins_t port_pin, uc_hal_pwm_configuration_t pwm_config_select);   
  void (*output)(uc_logic_t set_state);
  void (*set_duty_cycle)(uint16_t duty_value);
}uc_hal_pwm4_interface_t;

extern const uc_hal_pwm4_interface_t PWM4;
#endif 

/******************************************************************************
***** PWM5 Interface
*******************************************************************************/
#if UC_PROCESSOR_HAL_PWM5
typedef struct {
  void (*initialize)(uc_gpio_portpins_t port_pin, uc_hal_pwm_configuration_t pwm_config_select);   
  void (*output)(uc_logic_t set_state);
  void (*set_duty_cycle)(uint16_t duty_value);
}uc_hal_pwm5_interface_t;

extern const uc_hal_pwm5_interface_t PWM5;
#endif 

/******************************************************************************
***** PWM5 Interface
*******************************************************************************/
#if UC_PROCESSOR_HAL_PWM6
typedef struct {
  void (*initialize)(uc_gpio_portpins_t port_pin, uc_hal_pwm_configuration_t pwm_config_select);   
  void (*output)(uc_logic_t set_state);
  void (*set_duty_cycle)(uint16_t duty_value);
}uc_hal_pwm6_interface_t;

extern const uc_hal_pwm6_interface_t PWM6;
#endif 


#endif /*_H_*/

/*** End of File **************************************************************/
