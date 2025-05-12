/****************************************************************************
* Title                 :   uCore Engine - 18F Series Main ISR Function
* Filename              :   main_isr.c
* Author                :   Jamie Starling
* Origin Date           :   2025/01/03
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
*   2025/01/03  1.0.0       Jamie Starling  Initial Version
*  
*****************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "18f_vector_isr_control.h"

#if (UC_UCORE_MCU_18F && UC_PROCESSOR_HAL_ISR)

/******************************************************************************
* Functions
*******************************************************************************/


/******************************************************************************
* ISR for : Default ISR for unhandled interrupts
*******************************************************************************/
void __interrupt(irq(default), base(UC_ISR_BASE_ADDRESS)) DEFAULT_ISR(void)
{
 
}

/******************************************************************************
* ISR for : Timer 0 - System Timer Interrupt function 
*******************************************************************************/
void __interrupt(irq(TMR0), base(UC_ISR_BASE_ADDRESS)) isr_irq_tmr0(void)
{
  if (uc_vector_handlers[IRQ_TMR0])uc_vector_handlers[IRQ_TMR0](); 
  PIR3bits.TMR0IF = 0; //Clear Timer0 Interrupt Flag
}

/******************************************************************************
* ISR for : UART 0 - or U1 for TX
*******************************************************************************/
void __interrupt(irq(U1TX), base(UC_ISR_BASE_ADDRESS)) isr_irq_u1tx(void)
{
   if (uc_vector_handlers[IRQ_U1TX])uc_vector_handlers[IRQ_U1TX]();
}

/******************************************************************************
* ISR for : UART 0 - or U1 for RX
*******************************************************************************/
void __interrupt(irq(U1RX), base(UC_ISR_BASE_ADDRESS)) isr_irq_u1rx(void)
{
    if (uc_vector_handlers[IRQ_U1RX])uc_vector_handlers[IRQ_U1RX]();
}

/******************************************************************************
* ISR for : I2C 0 
*******************************************************************************/
void __interrupt(irq(I2C1TX), base(UC_ISR_BASE_ADDRESS)) isr_irq_i2c1_tx(void)
{
  if (uc_vector_handlers[IRQ_I2C1TX])uc_vector_handlers[IRQ_I2C1TX]();
}

/******************************************************************************
* ISR for : I2C 0 
*******************************************************************************/
void __interrupt(irq(I2C1), base(UC_ISR_BASE_ADDRESS)) isr_irq_i2c1(void)
{
  if (uc_vector_handlers[IRQ_I2C1])uc_vector_handlers[IRQ_I2C1]();
  
}

/******************************************************************************
* ISR for : I2C 0 
*******************************************************************************/
void __interrupt(irq(I2C1RX), base(UC_ISR_BASE_ADDRESS)) isr_irq_i2c1_rx(void)
{
  if (uc_vector_handlers[IRQ_I2C1RX])uc_vector_handlers[IRQ_I2C1RX]();
  
}



#endif /*#if UC_UCORE8_18F */


/*** End of File **************************************************************/

