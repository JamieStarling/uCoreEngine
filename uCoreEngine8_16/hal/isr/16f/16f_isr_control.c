/****************************************************************************
* Title                 :   Microchip PIC16F series ISR Control Functions
* Filename              :   isr_control.c
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
#include "16f_isr_control.h"

#if (UC_UCORE_MCU_16F && UC_PROCESSOR_HAL_ISR)


//Table for ISR Handlers
uc_isr_handler_t uc_isr_handlers[UC_ISR_MAX_HANDLERS] = { 0 }; // <- actual memory is here!




/******************************************************************************
* Interface
*******************************************************************************/
const uc_system_isr_control_interface_t ISR_CONTROL = {
    .global_interrupt = &uc_isr_global_interrupt,
    .peripheral_interrupt = &uc_isr_peripheral_interrupt,
    .enable_system_default =  &uc_isr_enable_system_default,
    .register_handler = &uc_isr_register_handler,
    .unregister_handler = &uc_isr_unregister_handler
};

/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : uc_isr_global_interrupt()
* Description: Enables or disables global interrupts by setting or clearing the GIE bit 
*   in the INTCON register, based on the `setState` parameter.
*
* Parameters:
*   - set_state (uc_logic_t): Set to ENABLED to enable global interrupts or 
*     DISABLED to disable them.
*  
*******************************************************************************/
void uc_isr_global_interrupt(uc_logic_t set_state)
{
  INTCONbits.GIE = (set_state != 0) ? 1 : 0;
}

/******************************************************************************
* Function : uc_isr_peripheral_interrupt
* Description: Enables or disables peripheral interrupts by setting or clearing the PEIE 
*   bit in the INTCON register, based on the `setState` parameter.
*
* Parameters:
*   - set_state (uc_logic_t): Set to ENABLED to enable peripheral interrupts or 
*     DISABLED to disable them.
* 
*******************************************************************************/
void uc_isr_peripheral_interrupt(uc_logic_t set_state)
{
  INTCONbits.PEIE = (set_state != 0) ? 1 : 0;
}

/******************************************************************************
* Function : uc_isr_enable_system_default()
* Description: Enables global interrupts and, if configured, peripheral interrupts by 
* calling `ISR_Global_Interrupt` and `ISR_Peripheral_Interrupt`.
*
*******************************************************************************/
void uc_isr_enable_system_default(void)
{  
    #ifdef UC_DEFAULT_ISR_ENABLE_PERIPHERAL_INTERRUPT
        uc_isr_peripheral_interrupt(UC_ENABLED);
    #endif /* UC_DEFAULT_ISR_ENABLE_PERIPHERAL_INTERRUPT*/
    
    uc_isr_global_interrupt(UC_ENABLED);  
}

/******************************************************************************
* Function : uc_isr_register_handler
* Description: 
*
*******************************************************************************/
uc_return_status_t uc_isr_register_handler(uc_isr_handler_t handler)
{
    for (uint8_t i = 0; i < UC_ISR_MAX_HANDLERS; i++) {
        if (uc_isr_handlers[i] == 0) {
            uc_isr_handlers[i] = handler;
            return UC_STATUS_OK;
        }
    }
    return UC_STATUS_FAILED;  // No empty slot
}

/******************************************************************************
* Function : uc_isr_unregister_handler
* Description: 
*
*******************************************************************************/
uc_return_status_t uc_isr_unregister_handler(uc_isr_handler_t handler)
{
    for (uint8_t i = 0; i < UC_ISR_MAX_HANDLERS; i++) {
        if (uc_isr_handlers[i] == handler) {
            uc_isr_handlers[i] = 0;
            return UC_STATUS_OK;
        }
    }
    return UC_STATUS_FAILED;  // Not found
}
#endif /* #if UC_UCORE8_16F */
/*** End of File **************************************************************/
