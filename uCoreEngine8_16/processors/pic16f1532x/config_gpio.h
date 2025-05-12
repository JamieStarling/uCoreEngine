/****************************************************************************
* Title                 :   uCore Engine GPIO Configuration
* Filename              :   congi_gpio.h
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

#ifndef _UC_PROCESSOR_HAL_GPIO_CONFIG_H
#define _UC_PROCESSOR_HAL_GPIO_CONFIG_H

/******************************************************************************
***** Configuration for GPIO - Used only if Enabled
*******************************************************************************/
#if UC_PROCESSOR_HAL_GPIO_CONFIG

/*GPIO Configuration Structure */
typedef struct
{
    uc_gpio_portpins_t port_pin;    /** < The I/ O pin*/
    uc_gpio_pin_mode_t mode;        /** < OUTPUT or INPUT*/
    uc_logic_t pin_value;           /** < HIGH or LOW*/
}uc_hal_gpio_config_t;

extern const uc_hal_gpio_config_t uc_gpio_config[];

#endif //UC_DEVICE_HAL_GPIO_CONFIG

#endif /*UC_DEVICE_HAL_GPIO_CONFIG_H*/
#endif /* #ifdef UC_SYSTEM_DEVICE_16F15313 */
/*** End of File **************************************************************/
