/****************************************************************************
* Title                 :   uCore Engine Timer1 Functions
* Filename              :   tmr1.c
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
*   2024/12/23  1.0.0       Jamie Starling  Initial Version
*  
*****************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "16F_tmr1.h"

#if (UC_PROCERSSOR_HAL_TMR1 && UC_UCORE_MCU_16F)

/******************************************************************************
* TMR1 Interface
*******************************************************************************/
const uc_hal_tmr1_interface_t TIMER1 = {
  .enable = &uc_hal_tmr1_enable,
  .set_mode_rw_16bit = &uc_hal_tmr1_set_mode_16bit_read_write,
  .set_clock_source =  &uc_hal_tmr1_set_clock_source,  
  .set_prescaler_rate =  &uc_hal_tmr1_set_prescaler_rate,
  .read_value_8bit =  &uc_hal_tmr1_read_8bit_value,
  .read_value_16bit =  &uc_hal_tmr1_read_16bit_value,
  .interrupt_flag_clear =  &uc_hal_tmr1_clear_interrupt_flag,
  .interrupt_enable =  &uc_hal_tmr1_enable_interrupt,
  .is_interrupt_flag_set =  &uc_hal_tmr1_is_interrupt_flag_set
};

/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : uc_hal_tmr1_enable()
* Description: Enables or disables Timer1 based on the input state.
*
* Parameters:
*   - set_state (uc_logic_t): ENABLED to start Timer1, DISABLED to stop it.
*
*******************************************************************************/
void uc_hal_tmr1_enable(uc_logic_t set_state)
{
    T1CONbits.ON = set_state; // Enable or disable Timer1 based on setState
}

/******************************************************************************
* Function : uc_hal_tmr1_set_mode_16bit_read_write()
* Description: Configures Timer1 for 16-bit or 8-bit read/write operations.
*
* Parameters:
*   - set_state (uc_logic_t): ENABLED for 16-bit mode, DISABLED for 8-bit mode.
*
*******************************************************************************/
void uc_hal_tmr1_set_mode_16bit_read_write(uc_logic_t set_state)
{
  T1CONbits.RD16 = set_state; // Set Timer1 read/write mode based on setState
}

/******************************************************************************
* Function : uc_hal_tmr1_set_prescaler_rate()
* Description: Sets the prescaler rate for Timer1, which divides the input clock to control 
* the timer's counting speed.
*
* Parameters:
*   - prescale_value (uc_tmr1_prescaler_t): The prescaler rate, such as 1:1, 1:2, 1:4, etc.
*
*******************************************************************************/
void uc_hal_tmr1_set_prescaler_rate(uc_tmr1_prescaler_t prescale_value)
{  
  T1CONbits.CKPS = prescale_value;  // Set the prescaler rate for Timer1
}

/******************************************************************************
* Function : uc_hal_tmr1_set_clock_source()
* Description: Sets the clock source for Timer1, determining the input signal used for counting.
*
* Parameters:
*   - clock_value (uc_tmr1_clock_source_t): The desired clock source.
*
*******************************************************************************/
void uc_hal_tmr1_set_clock_source(uc_tmr1_clock_source_t clock_value)
{
  T1CLKbits.CS = clock_value; // Set the clock source for Timer1
}

/******************************************************************************
* Function : uc_hal_tmr1_read_8bit_value()
* Description: Retrieves the current 8-bit value from the Timer1 low byte (TMR1L).
*
*
* Returns:
*   - uint8_t: The lower 8 bits of the Timer1 counter (TMR1L).
*
*******************************************************************************/
uint8_t uc_hal_tmr1_read_8bit_value(void)
{
  return TMR1L; // Return the current value of the Timer1 low byte
}

/******************************************************************************
* Function : uc_hal_tmr1_read_16bit_value()
* Description: Retrieves the full 16-bit value from Timer1 by reading `TMR1H` and `TMR1L` 
*   and combining them.
*
* Returns:
*   - uint16_t: The 16-bit Timer1 counter value.
*
*******************************************************************************/
uint16_t uc_hal_tmr1_read_16bit_value(void)
{
  return UC_UTILS.make_16(TMR1H,TMR1L); // Combine high and low bytes into 16-bit value
}

/******************************************************************************
* Function : uc_hal_tmr1_clear_interrupt_flag()
* Description: Clears the Timer1 interrupt flag (`TMR1IF`) to allow new Timer1 interrupts.
* 
*******************************************************************************/
void uc_hal_tmr1_clear_interrupt_flag(void)        
{  
    #if UC_UCORE8_16F  
        PIR4bits.TMR1IF = 0;  // Clear the Timer1 interrupt flag
    #endif
  
    #if UC_UCORE8_18F
        PIR3bits.TMR1IF = 0;  // Clear the Timer1 interrupt flag
    #endif
}

/******************************************************************************
* Function : uc_hal_tmr1_enable_interrupt()
* Description:  Enables or disables the Timer1 interrupt by setting or clearing the `TMR1IE` bit.
*
* Parameters:
*   - set_state: `UC_ENABLED` to enable the interrupt, `UC_DISABLED` to disable it.
*
*******************************************************************************/
void uc_hal_tmr1_enable_interrupt(uc_logic_t set_state)
{
    #if UC_UCORE8_16F    
        PIE4bits.TMR1IE = set_state; // Enable or disable Timer1 interrupt
    #endif

    #if UC_UCORE8_18F
        PIE3bits.TMR1IE = set_state; // Enable or disable Timer1 interrupt
    #endif        
}

/******************************************************************************
* Function : TMR1_Interrupt_Flag_Set()
* Description:  Checks if the Timer1 interrupt flag (`TMR1IF`) is set.
*
* Returns:
*   - `ENABLED` if `TMR1IF` is set (interrupt occurred).
*   - `DISABLED` if `TMR1IF` is clear.
*
*******************************************************************************/
uc_logic_t uc_hal_tmr1_is_interrupt_flag_set(void)
{
    #if UC_UCORE8_16F  
        return PIR4bits.TMR1IF;  // Return the status of the Timer1 interrupt flag
    #endif

    #if UC_UCORE8_18F
        return PIR3bits.TMR1IF;  // Return the status of the Timer1 interrupt flag
    #endif
    
}

#endif /* UC_DEVICE_HAL_TMR1 */
/*** End of File **************************************************************/
