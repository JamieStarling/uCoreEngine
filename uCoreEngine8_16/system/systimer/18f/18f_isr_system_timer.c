/****************************************************************************
* Title                 :   Core MCU System Timer Functions
* Filename              :   isr_core18F_system_timer.c
* Author                :   Jamie Starling
* Origin Date           :   2025/01/03
* Version               :   1.0.0
* Compiler              :   XC8
* Target                :   Microchip PIC18F series  
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
*   2025/01/03  1.0.0   Jamie Starling  Initial Version
*
*****************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "18f_isr_system_timer.h"

#if (UC_SYSTEM_TIMER && UC_UCORE_MCU_18F)   

/******************************************************************************
* Interface
*******************************************************************************/
const uc_system_timer_interface_t SYSTEM_TIMER = {
    .initialize = &uc_isr_18f_system_timer_init,
    .isr = &uc_isr_18f_systerm_timer_isr,
    .get_time =  &uc_isr_18f_system_timer_get_millis
};


/******************************************************************************
* Constants
*******************************************************************************/
#define _CORE18F_SYSTEM_TIMER_MILLIS_INC 1

/******************************************************************************
* Variables
*******************************************************************************/
//volatile uint32_t CORE18F_SYSTEM_TIMER_Overflow_Count = 0;
volatile uint32_t CORE18F_SYSTEM_TIMER_Millis = 0;


/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : ISR_CORE18F_SYSTEM_TIMER_Init()
* Description: Initializes Timer0 to generate 1ms ticks at 32MHz, setting up the timer 
* mode, clock source, prescaler, and enabling interrupts.
*
*******************************************************************************/
void uc_isr_18f_system_timer_init(void)
{
    //Using TMR0  
    //Disable 16 Bit timer
    TIMER0.set_mode_16bit(UC_DISABLED);
    TIMER0.set_output_postscaler(UC_TMR0_POST_SCALE_1_1);    
    
    //Timing for ~1ms at 64Mhz
    TIMER0.set_clock_source(UC_TMR0_FOSC_D4); //Clock Source Select FOSC/4
    TIMER0.set_prescaler_rate(UC_TMR0_PRESCALER_1_64); //Prescaler Rate 1:64       
    
    ISR_CONTROL.register_handler(IRQ_TMR0,uc_isr_18f_systerm_timer_isr);
    TIMER0.interrupt_flag_clear();
    TIMER0.interrupt_enable(UC_ENABLED);
    ISR_CONTROL.enable_system_default();     
    TIMER0.enable(UC_ENABLED); //Enable TMR0  
}

/******************************************************************************
* Function : ISR_CORE18F_SYSTEM_TIMER_ISR()
* Description: Interrupt Service Routine for Timer0 that increments the millisecond counter
* whenever the Timer0 overflow flag is set. 
*
* - HISTORY OF CHANGES - 
* 2024/10/28 1.0.1 Optimized ISR Function
*******************************************************************************/
void uc_isr_18f_systerm_timer_isr(void)
{  
  CORE18F_SYSTEM_TIMER_Millis += _CORE18F_SYSTEM_TIMER_MILLIS_INC;
 }   


/******************************************************************************
* Function : ISR_CORE18F_SYSTEM_TIMER_GetMillis()
* Description: Returns the number of milliseconds elapsed since the system timer was 
* initialized. Disables global interrupts momentarily to ensure a consistent 
* read of the `CORE16F_SYSTEM_TIMER_Millis` variable.
*
* Returns:
*   - (uint32_t): The elapsed time in milliseconds.
*******************************************************************************/
uint32_t uc_isr_18f_system_timer_get_millis(void)
{
    uint32_t time;
	
    // disable interrupts while we read timer0_millis or we might get an
    // inconsistent value (e.g. in the middle of a write to timer0_millis)
	
    ISR_CONTROL.global_interrupt(UC_DISABLED);
    time = CORE18F_SYSTEM_TIMER_Millis;
    ISR_CONTROL.global_interrupt(UC_ENABLED);
	
    return time;
}

#endif /* #if (UC_SYSTEM_TIMER && UC_UCORE8_18F)   */


/*** End of File **************************************************************/
