/****************************************************************************
* Title                 :   PPS Peripheral Pin Select functions
* Filename              :   pps.c
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
*   2024/12/20  1.0.0      Jamie Starling  Initial Version
*  
*****************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "16f_pps.h"

#if (UC_PROCESSOR_HAL_PPS && UC_UCORE_MCU_16F)

/******************************************************************************
* PPS Interface
*******************************************************************************/
const PPS_Interface_t PPS = {
    .map_output = &uc_hal_pps_map_output,
    #if UC_HAL_PPS_FUNCTION_MAP_BIDIRECTIONAL
        .map_bidirectional = &uc_hal_pps_map_bidirectional,
    #endif
    #if UC_HAL_PPS_FUNCTION_MAP_INPUT
        .map_input = &uc_hal_pps_map_input
    #endif
};

/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : uc_hal_pps_map_output()
* Description: Maps a Peripheral Pin Select (PPS) device to a specified output pin, allowing 
*   peripherals like UART, SPI, or PWM to be assigned to different output pins.
*
* Parameters:
*   - port_pin (uc_gpio_portpins_t): The GPIO pin to map the peripheral to (e.g., PORTC_4).
*   - pps_device (uc_pps_output_peripheral_t): The peripheral to map (e.g., PPSOUT_TX1_CK1).
*
*******************************************************************************/
void uc_hal_pps_map_output(uc_gpio_portpins_t port_pin, uc_pps_output_peripheral_t pps_device)
{   
   GPIO.mode(port_pin,UC_OUTPUT);
   *(pps_register_lu[port_pin].gpio_pps_output_reg) = (uint8_t)pps_device;   
}

/******************************************************************************
* Function : uc_hal_pps_map_bidirectional()
* Description: Maps a Peripheral Pin Select (PPS) device to a specified GPIO pin for 
* bi-directional communication. Configures both input and output registers 
* for peripherals requiring both directions (e.g., I2C, SPI).
*
* Parameters:
*   - port_pin (uc_gpio_portpins_t): The GPIO pin to map (e.g., PORTC_4).
*   - pps_device (uc_pps_output_peripheral_t): The peripheral to map (e.g., PPSOUT_TX1_CK1).
*   - regPPC_Input_ptr (volatile uint8_t*): Pointer to the PPS input register for mapping.
*
*******************************************************************************/
#if UC_HAL_PPS_FUNCTION_MAP_BIDIRECTIONAL
void uc_hal_pps_map_bidirectional(uc_gpio_portpins_t port_pin, uc_pps_output_peripheral_t pps_device, volatile uint8_t *regPPC_Input_ptr)
{   
   *(pps_register_lu[port_pin].gpio_pps_output_reg) = (uint8_t)pps_device;
   
    // Check if regPPC_Input_ptr is valid before setting input mapping
    if (regPPC_Input_ptr != NULL)
    {
        *regPPC_Input_ptr = (pps_register_lu[port_pin].gpio_ps_inputpin);
    }
}
#endif
/******************************************************************************
* Function : uc_hal_pps_map_input()
* Description: Maps a GPIO pin to a specified Peripheral Pin Select (PPS) input peripheral,
* allowing the pin to act as an input for peripherals like UART RX or SPI MISO.
*
* Parameters:
*   - port_pin (uc_gpio_portpins_t): The GPIO pin to map (e.g., PORTC_4).
*   - regPPC_Input_ptr (volatile uint8_t*): Pointer to the PPS input register.
*
*
*******************************************************************************/
#if UC_HAL_PPS_FUNCTION_MAP_INPUT
void uc_hal_pps_map_input(uc_gpio_portpins_t port_pin, volatile uint8_t *regPPC_Input_ptr)
{
    // Check if regPPC_Input_ptr is valid 
    if (regPPC_Input_ptr != NULL)
    {
        *regPPC_Input_ptr = (pps_register_lu[port_pin].gpio_ps_inputpin);
    }
}
#endif
#endif //#if UC_PROCESSOR_HAL_PPS
/*** End of File **************************************************************/
