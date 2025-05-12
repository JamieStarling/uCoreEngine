/****************************************************************************
* Title                 :   Microchip PIC16F series ISR Control Functions
* Filename              :   isr_control.h
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
#include "../isr.h"

#ifndef _UC_HAL_ISR_CONTROL_H
#define _UC_HAL_ISR_CONTROL_H

#if (UC_UCORE_MCU_16F && UC_PROCESSOR_HAL_ISR)


typedef void (*uc_isr_handler_t)(void);
extern uc_isr_handler_t uc_isr_handlers[UC_ISR_MAX_HANDLERS];

/******************************************************************************
***** uCore ISR Control Interface
*******************************************************************************/
typedef struct {
  void (*global_interrupt)(uc_logic_t set_state);
  void (*peripheral_interrupt)(uc_logic_t set_state);
  void (*enable_system_default)(void); 
  uc_return_status_t (*register_handler)(uc_isr_handler_t handler);
  uc_return_status_t (*unregister_handler)(uc_isr_handler_t handler);
}uc_system_isr_control_interface_t;

extern const uc_system_isr_control_interface_t ISR_CONTROL;


/******************************************************************************
* Function Prototypes
*******************************************************************************/
void uc_isr_global_interrupt(uc_logic_t set_state);
void uc_isr_peripheral_interrupt(uc_logic_t set_state);
void uc_isr_enable_system_default(void);
uc_return_status_t uc_isr_register_handler(uc_isr_handler_t handler);
uc_return_status_t uc_isr_unregister_handler(uc_isr_handler_t handler);
#endif /*UC_ISR_CONTROL_H*/
#endif /*UC_UCORE8_16F*/
/*** End of File **************************************************************/
