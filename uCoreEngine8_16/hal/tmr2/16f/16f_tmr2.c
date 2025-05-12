/****************************************************************************
* Title                 :   uCore Engine Timer2 Functions
* Filename              :   tmr2.c
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
*****************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "16f_tmr2.h"

#if (UC_PROCESSOR_HAL_TMR2 || UC_PROCESSOR_HAL_PWM_TIMER && UC_UCORE_MCU_16F)

/******************************************************************************
* TMR2 Interface
*******************************************************************************/
const uc_hal_tmr2_interface_t TIMER2 = {
  .enable = &uc_hal_tmr2_enable,
  .set_output_postscaler = &uc_hal_tmr2_set_output_postscaler,
  .set_clock_source =  &uc_hal_tmr2_set_clock_source,  
  .set_prescaler_rate =  &uc_hal_tmr2_set_prescaler_rate,
  .read_value_8bit =  &uc_hal_tmr2_read_value_8bit,
  .interrupt_flag_clear =  &uc_hal_tmr2_interrupt_flag_clear,
  .interrupt_enable =  &uc_hal_tmr2_interrupt_enable,
  .is_interrupt_flag_set =  &uc_hal_tmr2_is_interrupt_set
};


/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : uc_hal_tmr2_enable()
* Description: Starts or stops Timer2 based on the input parameter.
*
* Parameters:
*   - setState: `ENABLED` to start Timer2, `DISABLED` to stop it.
*
*******************************************************************************/
void uc_hal_tmr2_enable(uc_logic_t set_state)
{
  T2CONbits.ON = (bool)set_state; // Set or clear the ON bit to control Timer2
}

/******************************************************************************
* Function : uc_hal_tmr2_set_prescaler_rate()
* Description: Sets the prescaler rate for Timer2, which controls the counting rate.
*
* Parameters:
*   - value: Prescaler rate from `uc_tmr2_prescaler_t`.
*
*******************************************************************************/
void uc_hal_tmr2_set_prescaler_rate(uc_tmr2_prescaler_t value)
{  
  T2CONbits.CKPS = (uint8_t)value;  // Set Timer2 prescaler rate
}

/******************************************************************************
* Function : uc_hal_tmr2_set_clock_source()
* Description: Sets the clock source for Timer2. The selected clock source controls how 
* Timer2 increments its counter.
*
* Parameters:
*   - value: The clock source, selected from `uc_tmr2_clock_source_t`.
*
*
*******************************************************************************/
void uc_hal_tmr2_set_clock_source(uc_tmr2_clock_source_t value)
{
  T2CLKCONbits.CS = (uint8_t)value;  // Set Timer2 clock source
}

/******************************************************************************
* Function : uc_hal_tmr2_set_output_postscaler()
* Description: Configures the output postscaler for Timer2. The postscaler determines how 
* many Timer2 overflows are needed before triggering an event or changing the 
* output.
*
* Parameters:
*   - value: The postscaler setting, from `uc_tmr2_post_scaler_t`.
*
*******************************************************************************/
void uc_hal_tmr2_set_output_postscaler(uc_tmr2_post_scaler_t value)
{  
  T2CONbits.OUTPS = (uint8_t)value; // Set Timer2 postscaler
}

/******************************************************************************
* Function : uc_hal_tmr2_set_mode()
* Description: Sets the operational mode for Timer2 by configuring the `T2HLTbits.MODE` register.
* Timer2 can be set to modes such as free-running, monostable, or retriggerable.
*
* Parameters:
*   - mode_value: The mode for Timer2, chosen from `uc_tmr2_mode_select_t`.
*
*******************************************************************************/
void uc_hal_tmr2_set_mode(uc_tmr2_mode_select_t mode_value)
{
  T2HLTbits.MODE = (uint8_t)mode_value;  // Configure Timer2 mode
}

/******************************************************************************
* Function : uc_hal_tmr2_read_value_8bit()
* Description: Returns the current 8-bit value from the Timer2 counter (`TMR2` register).
*
*
* Post-Condition:
*   - Returns the current 8-bit Timer2 value.
*
*******************************************************************************/
uint8_t uc_hal_tmr2_read_value_8bit(void)
{
  return TMR2; // Return the current Timer2 counter value
}

/******************************************************************************
* Function : uc_hal_tmr2_interrupt_flag_clear()
* Description: Clears the Timer2 interrupt flag (`TMR2IF`) in the `PIR4` register, allowing
* Timer2 to generate new interrupts.
*
*******************************************************************************/
void uc_hal_tmr2_interrupt_flag_clear(void)        
{  
  TMR2_PIR_REGISTER.TMR2IF = 0; // Clear the Timer2 interrupt flag
}

/******************************************************************************
* Function : uc_hal_tmr0_interrupt_enable()
* Description: Enables or disables the Timer2 interrupt by setting or clearing the `TMR2IE` bit in `PIE4`.
* Timer2 will continue counting even if the interrupt is disabled.
*
* Parameters:
*   - set_state: `ENABLED` to enable the interrupt, `DISABLED` to disable it.
* 
*******************************************************************************/
void uc_hal_tmr2_interrupt_enable(uc_logic_t set_state)
{
    TMR2_PIE_REGISTER.TMR2IE = (bool)set_state; // Set or clear the Timer2 interrupt enable bit
}

/******************************************************************************
* Function : uc_hal_tmr0_is_interrupt_set()
* Description: Checks if the Timer2 interrupt flag (`TMR2IF`) is set, indicating an overflow event.
*
* * Returns:
*   - `TRUE` if `TMR2IF` is set (interrupt occurred).
*   - `FALSE` if `TMR2IF` is clear.
*******************************************************************************/
uc_logic_t uc_hal_tmr2_is_interrupt_set(void)
{
  return TMR2_PIR_REGISTER.TMR2IF;
}

#endif /* #if UC_DEVICE_HAL_TMR2 */

/*** End of File **************************************************************/