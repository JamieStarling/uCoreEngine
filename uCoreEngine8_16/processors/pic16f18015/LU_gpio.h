/****************************************************************************
* Title                 :   uCore Device GPIO Lookup
* Filename              :   LU_gpio.h
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
#include "pic16f18015.h"

#ifdef UC_SYSTEM_PROCESSOR_16F18015

#ifndef _UC_PROCESSOR_LU_GPIO_H
#define _UC_PROCESSOR_LU_GPIO_H

/******************************************************************************
****** Lookup : GPIO 
*******************************************************************************/
/* Defines the Max IO Pin Count on the Device
* Used for reading the GPIO Configuration Table.*/ 

#define UC_DEVICE_MAX_GPIO_PIN_COUNT 6

/******************************************************************************
* Port Pin Table Lookup Maps Port Pin Name to a value for later lookup.
******************************************************************************/
typedef enum
{    
    UC_PORTA0,
    UC_PORTA1,
    UC_PORTA2,
    UC_PORTA3,
    UC_PORTA4,
    UC_PORTA5,
    UC_MAX_IOPINS
}uc_gpio_portpins_t;


/******************************************************************************
 *Defines the IO Pin Mode on the Device* 
 * Used for setting the IO Pin Direction/Mode. 
 *******************************************************************************/
typedef enum
{
    UC_OUTPUT          = 0x0U,	
    UC_INPUT           = 0x1U,
    UC_PULLUP          = 0x2U,
    UC_ANALOG          = 0x3U,
    UC_OPEN_DRAIN      = 0x4U
}uc_gpio_pin_mode_t;


/******************************************************************************
* GPIO Register Lookup
*******************************************************************************/
typedef struct {
    volatile unsigned char *gpio_direction_reg;
    volatile unsigned char *gpio_write_reg;
    volatile unsigned char *gpio_read_reg;
    volatile unsigned char *gpio_wpu_reg;
    volatile unsigned char *gpio_analog_reg;
    volatile unsigned char *gpio_odcon_reg;
    volatile unsigned char gpio_pinmask;   
} uc_gpio_registers_t;

extern const uc_gpio_registers_t gpio_register_lu[];

#endif /*_UC_DEVICE_LU_GPIO_H*/
#endif /* #ifdef UC_SYSTEM_DEVICE_16F15313 */
/*** End of File **************************************************************/
