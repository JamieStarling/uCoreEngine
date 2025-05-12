/****************************************************************************
* Title                 :   uCore Engine System Timer Functions for 16Fs
* Filename              :   16f_isr_system_timer.c
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
*   2024/12/23  1.0.0   Jamie Starling  Initial Version
* 
*
*****************************************************************************/

/******************************************************************************
***** Includes
*******************************************************************************/
#include "16f_isr_system_timer.h"

#if (UC_SYSTEM_TIMER && UC_UCORE_MCU_16F)   

/******************************************************************************
* Interface
*******************************************************************************/
const uc_system_timer_interface_t SYSTEM_TIMER = {
    .initialize = &uc_isr_16f_system_timer_init,
    .isr = &uc_isr_16f_systerm_timer_isr,
    .get_time =  &uc_isr_16f_system_timer_get_millis
};

/******************************************************************************
***** Constants
*******************************************************************************/
#define UC_SYSTEM_TIMER_MILLIS_INC 1  //Defines the time that each interrupt repersents.

/******************************************************************************
***** Variables
*******************************************************************************/
volatile uint32_t UC_SYSTEM_TIMER_Millis = 0;

/******************************************************************************
***** Functions
*******************************************************************************/
/******************************************************************************
* Function : uc_isr_16f_system_timer_init()
* Description: Initializes Timer0 to generate 1ms ticks at 32MHz, setting up the timer 
* mode, clock source, prescaler, and enabling interrupts.
*
*******************************************************************************/
void uc_isr_16f_system_timer_init(void)
{
    TIMER0.set_mode_16bit(UC_DISABLED);  //Disable 16 Bit timer    
    
    //Timing for ~1ms at 32Mhz
    TIMER0.set_clock_source(UC_TMR0_FOSC_D4); //Source Select FOSC/4
    TIMER0.set_prescaler_rate(UC_TMR0_PRESCALER_1_32); //Prescaler Rate 1:32
    
    TIMER0.interrupt_flag_clear();
    TIMER0.interrupt_enable(UC_ENABLED);             
   
    ISR_CONTROL.register_handler(uc_isr_16f_systerm_timer_isr);
    ISR_CONTROL.peripheral_interrupt(UC_ENABLED);
    ISR_CONTROL.global_interrupt(UC_ENABLED);    
    TIMER0.enable(UC_ENABLED);
   
}

/******************************************************************************
* Function : uc_isr_16f_systerm_timer_isr()
* Description: Interrupt Service Routine for Timer0 that increments the millisecond counter
* whenever the Timer0 overflow flag is set. 
*
*******************************************************************************/
void uc_isr_16f_systerm_timer_isr(void)
{
    if (PIR0bits.TMR0IF){
            PIR0bits.TMR0IF = 0;  //Clear Timer0 Interrupt Flag
            UC_SYSTEM_TIMER_Millis += UC_SYSTEM_TIMER_MILLIS_INC;
        }    
} 

/******************************************************************************
* Function : ISR_CORE16F_SYSTEM_TIMER_GetMillis()
* Description: Returns the number of milliseconds elapsed since the system timer was 
* initialized. Disables global interrupts momentarily to ensure a consistent 
* read of the `CORE16F_SYSTEM_TIMER_Millis` variable.
*
* Returns:
*   - (uint32_t): The elapsed time in milliseconds.
*******************************************************************************/
uint32_t uc_isr_16f_system_timer_get_millis(void)
{
    uint32_t time;
    
    // Disable interrupts temporarily to read the timer value safely
    ISR_CONTROL.global_interrupt(UC_DISABLED);   
    time = UC_SYSTEM_TIMER_Millis;
    ISR_CONTROL.global_interrupt(UC_ENABLED);   
    
    return time;
}

#endif /* #if (UC_SYSTEM_TIMER && UC_UCORE8_16F)   */

/*** End of File **************************************************************/
