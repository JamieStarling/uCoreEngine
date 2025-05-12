/****************************************************************************
* Title                 :   Device ISR Control Functions
* Filename              :   isr_control.c
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

uc_isr_handler_t uc_vector_handlers[UC_ISR_MAX_VECTORS] = { 0 };

/******************************************************************************
* Interface
*******************************************************************************/
const uc_system_isr_control_interface_t ISR_CONTROL = {
    .global_interrupt = &uc_isr_global_interrupt,
    .low_priority_interrupt = &uc_isr_global_low_priority_interrupt,
    .enable_system_default =  &uc_isr_enable_system_default,
    .register_handler = &uc_isr_register_vector_handler,
    .unregister_handler = &uc_isr_unregister_vector_handler,
};

/******************************************************************************
* Functions
*******************************************************************************/

void uc_isr_global_interrupt(uc_logic_t set_state)
{
  INTCON0bits.GIE = (bool)set_state;
}

/*************************************/
void uc_isr_global_low_priority_interrupt(uc_logic_t set_state)
{
  INTCON0bits.GIEL = (bool)set_state;
}

/*************************************/
void uc_isr_interrupt_priority_enable(uc_logic_t set_state)
{
  INTCON0bits.IPEN = (bool)set_state;  
}

/*************************************/
uc_isr_interrupt_state_t uc_isr_interrupt_status(void)
{
  return INTCON1 >> 6;  
}
        
/*************************************/
void uc_isr_enable_system_default(void)
{
  if(UC_ENABLE_LOW_PRIORITY_INTERRUPTS){uc_isr_global_low_priority_interrupt(UC_ENABLED);}
  if(UC_ENABLE_INTERRUPT_PRIORITY){uc_isr_interrupt_priority_enable(UC_ENABLED);}
  uc_isr_global_interrupt(UC_ENABLED);  
}

/*************************************/

uc_return_status_t uc_isr_register_vector_handler(uint8_t irq_vector, uc_isr_handler_t handler)
{
    if (irq_vector >= UC_ISR_MAX_VECTORS) return UC_STATUS_FAILED;

    if (uc_vector_handlers[irq_vector] == 0) {
        uc_vector_handlers[irq_vector] = handler;
        return UC_STATUS_OK;
    }

    return UC_STATUS_FAILED;  // Slot already occupied
}

/*************************************/
uc_return_status_t uc_isr_unregister_vector_handler(uint8_t irq_vector, uc_isr_handler_t handler)
{
    if (irq_vector >= UC_ISR_MAX_VECTORS) return UC_STATUS_FAILED;

    if (uc_vector_handlers[irq_vector] == handler) {
        uc_vector_handlers[irq_vector] = 0;
        return UC_STATUS_OK;
    }

    return UC_STATUS_FAILED;  // Not found
}


#endif /* #if UC_UCORE8_18F */


/*** End of File **************************************************************/
