/****************************************************************************
* Title                 :   uCore Engine HAL TMR0 for Microchip devices
* Filename              :   tmr0.c
* Author                :   Jamie Starling
* Origin Date           :   2024/12/21
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
*
*****************************************************************************/

/******************************************************************************
****** Includes
*******************************************************************************/
#include "16f_tmr0.h"

/******************************************************************************
* Defines / Options
*******************************************************************************/
#if (UC_DEVICE_HAL_TMR0 || UC_SYSTEM_TIMER && UC_UCORE_MCU_16F)


/******************************************************************************
* TMR0 Interface
*******************************************************************************/
const uc_hal_tmr0_interface_t TIMER0 = {
    .enable = &uc_hal_tmr0_enable,
    .set_mode_16bit = &uc_hal_tmr0_set_mode_16bit,
    #if UC_HAL_TMR0_FUNCTION_SET_OUTPUT_POSTSCALER
        .set_output_postscaler = &uc_hal_tmr0_set_output_postscaler,
    #endif
    .set_clock_source =  &uc_hal_tmr0_set_clock_source,
    #if UC_HAL_TMR0_FUNCTION_SET_INPUT_MODE_ASYNC
        .set_input_mode_async =  &uc_hal_tmr0_set_input_mode_async,
    #endif
    .set_prescaler_rate =  &uc_hal_tmr0_set_prescaler_rate,
    #if UC_HAL_TMR0_FUNCTION_READ_VALUE_8BIT
        .read_value_8bit =  &uc_hal_tmr0_read_value_8bit,
    #endif
    #if UC_HAL_TMR0_FUNCTION_READ_VALUE_16BIT
    .read_value_16bit =  &uc_hal_tmr0_read_value_16bit,
    #endif
    .interrupt_flag_clear =  &uc_hal_tmr0_interrupt_flag_clear,
    .interrupt_enable =  &uc_hal_tmr0_interrupt_enable,
    #if UC_HAL_TMR0_FUNCTION_IS_INTERRUPT_SET
    .is_interrupt_flag_set =  &uc_hal_tmr0_is_interrupt_set
    #endif
};

/******************************************************************************
***** Functions
*******************************************************************************/
/******************************************************************************
* Function : uc_hal_tmr0_enable()
* Description: Enables or disables the TMR0 module based on the input parameter.
*
* Parameters:
*   - set_state (uc_logic_t): UC_ENABLED to enable TMR0, UC_DISABLED to disable it.
*
*******************************************************************************/
void uc_hal_tmr0_enable(uc_logic_t set_state)
{
    T0CON0bits.T0EN = (set_state != 0) ? 1 : 0; // Set TMR0 enable/disable bit
}

/******************************************************************************
* Function : uc_hal_tmr0_set_mode_16bit()
* Description: Enables or disables 16-bit mode for the TMR0 module.
*
* Parameters:
*   - set_state (uc_logic_t): UC_ENABLED to enable 16-bit mode, UC_DISABLED to disable it.
*
*******************************************************************************/
void uc_hal_tmr0_set_mode_16bit(uc_logic_t set_state)
{
    T0CON0bits.T016BIT = (set_state != 0) ? 1 : 0; // Set TMR0 16-bit mode based on the parameter
}

/******************************************************************************
* Function : uc_hal_tmr0_set_output_postscaler()
* Description: Sets the postscaler value for the TMR0 module.
*
* Parameters:
*   - value (uc_tmr0_post_scale_t): The postscaler value to set (refer to device lookup table).
*
*******************************************************************************/
#if UC_HAL_TMR0_FUNCTION_SET_OUTPUT_POSTSCALER
void uc_hal_tmr0_set_output_postscaler(uc_tmr0_post_scale_t value)
{  
  T0CON0bits.T0OUTPS = (uint8_t)value; // Set the TMR0 postscaler
}
#endif
/******************************************************************************
* Function : uc_hal_tmr0_set_clock_source()
* Description: Sets the clock source for the TMR0 module.
*
* Parameters:
*   - value (uc_tmr0_clock_source_t): The clock source to set (refer to device lookup table).
*
*******************************************************************************/
void uc_hal_tmr0_set_clock_source(uc_tmr0_clock_source_t value)
{
    T0CON1bits.T0CS = (uint8_t)value; // Set the TMR0 clock source
}

/******************************************************************************
* Function :  uc_hal_tmr0_set_input_mode_async()
* Description: Enables or disables the asynchronous mode for TMR0.
*
* Parameters:
*   - set_state (uc_logic_t): UC_ENABLED to enable async mode, UC_DISABLED to disable it.
*
*******************************************************************************/
#if UC_HAL_TMR0_FUNCTION_SET_INPUT_MODE_ASYNC
void uc_hal_tmr0_set_input_mode_async(uc_logic_t set_state)
{
    T0CON1bits.T0ASYNC = set_state; // Set TMR0 async mode based on the parameter
}
#endif
/******************************************************************************
* Function : uc_hal_tmr0_set_set_prescaler_rate()
* Description: Sets the prescaler value for the TMR0 module.
*
* Parameters:
*   - value (uc_tmr0_prescaler_t): The prescaler value to set (refer to device lookup table).
*
*******************************************************************************/
void uc_hal_tmr0_set_prescaler_rate(uc_tmr0_prescaler_t value)
{
  T0CON1bits.T0CKPS = (uint8_t)value; // Set the TMR0 prescaler value
}

/******************************************************************************
* Function :  uc_hal_tmr0_read_value_8bit()
* Description: Returns the current 8-bit value of the TMR0L register.
*
* Returns:
*   - uint8_t: The value of the TMR0L register.
*
*******************************************************************************/
#if UC_HAL_TMR0_FUNCTION_READ_VALUE_8BIT
uint8_t uc_hal_tmr0_read_value_8bit(void)
{
    return TMR0L; // Return the 8-bit value of the TMR0L register
}
#endif
/******************************************************************************
* Function :  uc_hal_tmr0_read_value_16bit()
* Description: Returns the current 16-bit value of TMR0 by combining the TMR0H and TMR0L registers.
*
* Parameters:
*   - None
*
* Returns:
*   - uint16_t: The combined 16-bit value from TMR0H and TMR0L.
*******************************************************************************/
#if UC_HAL_TMR0_FUNCTION_READ_VALUE_16BIT
uint16_t uc_hal_tmr0_read_value_16bit(void)
{
  return UC_UTILS.make_16(TMR0H,TMR0L); // Combine TMR0H and TMR0L to return a 16-bit value
}
#endif
/******************************************************************************
* Function :  uc_hal_tmr0_interrupt_flag_clear()
* Description: Clears the TMR0 interrupt flag.
*
*******************************************************************************/
inline void uc_hal_tmr0_interrupt_flag_clear(void)        
{ 
  
 PIR0bits.TMR0IF = 0;

  
    #if UC_UCORE8_18F
        PIR3bits.TMR0IF = 0;
    #endif
}

/******************************************************************************
* Function : uc_hal_tmr0_interrupt_enable()
* Description: Enables or disables the TMR0 interrupt.
*
* Parameters:
*   - set_state (uc_logic_t): UC_ENABLED to enable the interrupt, UC_DISABLED to disable it.
*
*******************************************************************************/
void uc_hal_tmr0_interrupt_enable(uc_logic_t set_state)
{
   PIE0bits.TMR0IE = (set_state != 0) ? 1 : 0; // Set the TMR0 interrupt enable bit based on setState
   
    #if UC_UCORE8_18F
        PIE3bits.TMR0IE = (bool)set_state; // Set the TMR0 interrupt enable bit based on setState
    #endif
}
      
/******************************************************************************
* Function : uc_hal_tmr0_is_interrupt_set()
* Description: Checks if the TMR0 interrupt flag is set.
*
*
* Returns:
*   - LogicEnum_t: TRUE if the TMR0 interrupt flag is set, FALSE otherwise.
*
*
*******************************************************************************/
#if UC_HAL_TMR0_FUNCTION_IS_INTERRUPT_SET
inline uc_logic_t uc_hal_tmr0_is_interrupt_set(void)
{
  
  return PIR0bits.TMR0IF; // Return the state of the TMR0 interrupt flag
  
    #if UC_UCORE8_18F
        return PIR3bits.TMR0IF; // Return the state of the TMR0 interrupt flag
    #endif    
}
#endif
#endif /* (UC_UCORE8_16F && (UC_DEVICE_HAL_TMR0 || UC_SYSTEM_TIMER )) */
/*** End of File **************************************************************/
