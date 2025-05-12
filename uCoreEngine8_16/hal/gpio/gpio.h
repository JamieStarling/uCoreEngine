/****************************************************************************
* Title                 :   uCore Engine GPIO Functions
* Filename              :   gpio.h
* Author                :   Jamie Starling
* Origin Date           :   2024/12/20
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
*   2024/12/20  1.0.0       Jamie Starling  Initial Version
*  
*****************************************************************************/

#ifndef _UC_HAL_GPIO_H
#define _UC_HAL_GPIO_H
/******************************************************************************
***** Includes
*******************************************************************************/
#include "../hal.h"

/******************************************************************************
***** GPIO Options
*******************************************************************************/
#define UC_HAL_GPIO_FUNCTION_PIN_TOGGLE     UC_SYSTEM_ENABLE     /* uc_hal_gpio_pin_toggle */

/******************************************************************************
***** GPIO API INTERFACE
*******************************************************************************/
typedef struct {
    void(*mode)(uc_gpio_portpins_t port_pin, uc_gpio_pin_mode_t pin_mode);   
    void(*pin_write)(uc_gpio_portpins_t port_pin, uc_logic_t pin_value);
  
    #if (UC_HAL_GPIO_FUNCTION_PIN_TOGGLE)
        void(*pin_toggle)(uc_gpio_portpins_t port_pin);
    #endif  
    
    uc_logic_t(*pin_read)(uc_gpio_portpins_t port_pin);
  
    #if UC_PROCESSOR_HAL_GPIO_CONFIG
        void (*configure)(const GPIO_Config_t* Config);
    #endif
}uc_hal_gpio_interface_t;

extern const uc_hal_gpio_interface_t GPIO;


/******************************************************************************
***** Function Prototypes
*******************************************************************************/
void uc_hal_gpio_mode(uc_gpio_portpins_t port_pin, uc_gpio_pin_mode_t pin_mode);
void uc_hal_gpio_pin_write(uc_gpio_portpins_t port_pin, uc_logic_t pin_value);
uc_logic_t uc_hal_gpio_pin_read(uc_gpio_portpins_t port_pin);

#if (UC_HAL_GPIO_FUNCTION_PIN_TOGGLE)
    void uc_hal_gpio_pin_toggle(uc_gpio_portpins_t port_pin);
#endif

#if UC_DEVICE_HAL_GPIO_CONFIG
    void uc_hal_gpio_init(const uc_hal_gpio_config_t* gpio_config);
#endif

#endif /*UC_HAL_GPIO_H*/

/*** End of File **************************************************************/
