/****************************************************************************
* Title                 :   uCore Engine HAL GPIO Digital Functions
* Filename              :   gpio.c
* Author                :   Jamie Starling
* Origin Date           :   2024/12/20
* Version               :   1.0.0
* Compiler              :   XC8 
* Target                :   
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

/******************************************************************************
* Includes
*******************************************************************************/
#include "gpio.h"

/******************************************************************************
* Interface
*******************************************************************************/
const uc_hal_gpio_interface_t GPIO = {
    .mode = &uc_hal_gpio_mode,
    .pin_write = &uc_hal_gpio_pin_write,
    #if (UC_HAL_GPIO_FUNCTION_PIN_TOGGLE)
        .pin_toggle = &uc_hal_gpio_pin_toggle,
    #endif
    .pin_read =  &uc_hal_gpio_pin_read
};

/******************************************************************************
***** Local Function Prototypes
*******************************************************************************/
void uc_hal_gpio_set_wpua(uc_gpio_portpins_t port_pin, uint8_t gpio_pinmask);

/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : uc_hal_gpio_mode()
* Description: Configures the direction and mode of a specified GPIO pin. The pin can be 
* set as input, output, input with pull-up, analog input, or open-drain output.
*
* Parameters:
*   - port_pin (uc_gpio_portpins_t): The GPIO pin to configure.
*   - pin_mode (uc_gpio_pin_mode_t): The desired pin direction or mode.
* 
*******************************************************************************/
void uc_hal_gpio_mode(uc_gpio_portpins_t port_pin, uc_gpio_pin_mode_t pin_mode)
{           
  volatile uint8_t *dir_reg = gpio_register_lu[port_pin].gpio_direction_reg;
  volatile uint8_t *analog_reg = gpio_register_lu[port_pin].gpio_analog_reg;
  volatile uint8_t gpio_pinmask = gpio_register_lu[port_pin].gpio_pinmask;
  
  switch (pin_mode) {
    //If PIN is to be set as Input - Set the associated Register Bit    
    case UC_INPUT:      
        *dir_reg |= gpio_pinmask;    //Set the bit in the Direction Register with OR       
        *analog_reg &= ~(gpio_pinmask);     //Invert the Pin Mask to clear the Analog Register with AND                
        break;
   
    //If PIN is to be set as OUTPUT - Clear the associated Register Bit     
    case UC_OUTPUT:     
        *dir_reg &= ~(gpio_pinmask);  //Invert the Mask - Clear the bit in the Direction Register and Analog Register
        *analog_reg &= ~(gpio_pinmask);
        break;
    
    //If PIN is to be set as INPUT with PullUp 
    case UC_PULLUP:   
       *dir_reg |= gpio_pinmask;   //Set the bit in the Direction Register with OR
       *analog_reg &= ~(gpio_pinmask);     //Invert the Pin Mask to clear the Analog Register with AND  
       uc_hal_gpio_set_wpua(port_pin, gpio_pinmask );
       break;
       
    //If Pin is to be set as analog input
    case UC_ANALOG: 
       *dir_reg |= gpio_pinmask;  //Set the bit in the Direction Register with OR Along with Analog  
       *analog_reg |= gpio_pinmask;
       break;
       
    //If PIN is to be set as OPEN_DRAIN - Clear the associated Register Bit
    case UC_OPEN_DRAIN: 
      *(gpio_register_lu[port_pin].gpio_odcon_reg) |= gpio_pinmask; 
      *dir_reg &= ~(gpio_pinmask);  //Invert the Mask - Clear the bit in the Direction Register and Analog Register
      *analog_reg &= ~(gpio_pinmask);              
       break;
    
    //For whatever reason something doesn't match we end up here.   
    default:
        break;      
    }     
}

/******************************************************************************
* Function : uc_hal_gpio_set_wpua()
* Description: Enables the weak pull-up resistor for a specified GPIO pin by setting the 
* appropriate bit in the weak pull-up register.
*
* Parameters:
*   - port_pin (uc_gpio_portpins_t): The GPIO pin to enable the pull-up for.
*******************************************************************************/
void uc_hal_gpio_set_wpua(uc_gpio_portpins_t port_pin, uint8_t gpio_pinmask)
{      
   *(gpio_register_lu[port_pin].gpio_wpu_reg) |= gpio_pinmask; //Set the bit in the WPU with OR          
}	

/******************************************************************************
* Function : GPIO_Writeport_pin()
* Description: Sets the logic level (HIGH or LOW) of a specified GPIO pin by writing to 
* the port latch register.
*
* Parameters:
*   - port_pin (uc_gpio_portpins_t): The GPIO pin to set (e.g., PORTA_0, PORTC_1).
*   - pin_value (uc_logic_t): The logic level to apply (HIGH or LOW).
*
*******************************************************************************/
void uc_hal_gpio_pin_write(uc_gpio_portpins_t port_pin, uc_logic_t pin_value)
{    
  //If PIN is to be set HIGH 
  if (pin_value == UC_HIGH) 
    {
       *(gpio_register_lu[port_pin].gpio_write_reg) |= (gpio_register_lu[port_pin].gpio_pinmask);  //Set the bit in the Latch Register with OR
    }    
  //Everything else set- LOW 
  else 
    {
       *(gpio_register_lu[port_pin].gpio_write_reg) &= ~(gpio_register_lu[port_pin].gpio_pinmask);  //Invert the Mask - Clear the bit in the Latch Register with AND       
    }  
}

/******************************************************************************
* Function : uc_hal_gpio_pin_read()
* Description: Reads the current logic level (HIGH or LOW) from a specified GPIO pin.
*
* Parameters:
*   - port_pin (uc_gpio_portpins_t): The GPIO pin to read (e.g., PORTA_0, PORTC_1).
*
* Returns:
*   - uc_logic_t: HIGH (logic 1) if the pin is high, LOW (logic 0) if the pin is low.
*******************************************************************************/
uc_logic_t uc_hal_gpio_pin_read(uc_gpio_portpins_t port_pin)
{     
  return (*(gpio_register_lu[port_pin].gpio_read_reg) & (gpio_register_lu[port_pin].gpio_pinmask)) ? UC_HIGH : UC_LOW;     
}

/******************************************************************************
* Function : uc_hal_gpio_pin_toggle()
* Description:Toggles the logic level of a specified GPIO pin. If the pin is HIGH, it will
* be set to LOW, and if it is LOW, it will be set to HIGH.
*
* Parameters:
*   - port_pin (uc_gpio_portpins_t): The GPIO pin to toggle (e.g., PORTA_0, PORTC_1).
*******************************************************************************/
#if (UC_HAL_GPIO_FUNCTION_PIN_TOGGLE)
void uc_hal_gpio_pin_toggle(uc_gpio_portpins_t port_pin)
{    
   *(gpio_register_lu[port_pin].gpio_write_reg) ^= (gpio_register_lu[port_pin].gpio_pinmask);    //Flip the Bit with XOR
}
#endif /*#if (UC_HAL_GPIO_FUNCTION_PIN_TOGGLE)*/

/******************************************************************************
* Function : GPIO_Init()
* Description: Initializes GPIO pins based on a provided configuration table, setting each 
* pin's direction and initial level as specified.
*
* Parameters:
*   - Config (const GPIO_Config_t*): Pointer to the GPIO configuration table, 
*     which contains settings for each pin.
*******************************************************************************/
#if UC_PROCESSOR_HAL_GPIO_CONFIG
void uc_hal_gpio_init(const uc_hal_gpio_config_t* gpio_config)
{
    uint8_t config_index  = 0;
    
    for (config_index  = 0; config_index  < UC_DEVICE_MAX_GPIO_PIN_COUNT; config_index ++)
    {
       uc_hal_gpio_mode(gpio_config[config_index].port_pin,gpio_config[config_index].mode);
       
       if (gpio_config[config_index].mode == UC_OUTPUT)
       {
           uc_hal_gpio_pin_write(gpio_config[config_index].port_pin,gpio_config[config_index].pin_value);
       }       
    }    
}
#endif /*UC_DEVICE_HAL_GPIO_CONFIG*/


/*** End of File **************************************************************/



