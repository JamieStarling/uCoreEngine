/****************************************************************************
* Title                 :   uCore Engine Timer2 Functions
* Filename              :   tmr2.h
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
#include "../hal.h"

#ifndef _UC_HAL_TMR2_H
#define _UC_HAL_TMR2_H

#if (UC_PROCESSOR_HAL_TMR2 || UC_PROCESSOR_HAL_PWM_TIMER)

/******************************************************************************
***** TMR2 Interface
*******************************************************************************/
typedef struct {
  void (*enable)(uc_logic_t set_state);
  void (*set_output_postscaler)(uc_tmr2_post_scaler_t value);
  void (*set_clock_source)(uc_tmr2_clock_source_t value);  
  void (*set_prescaler_rate)(uc_tmr2_prescaler_t value);
  uint8_t (*read_value_8bit)(void);  
  void (*interrupt_flag_clear)(void);
  void (*interrupt_enable)(uc_logic_t set_state);
  uc_logic_t (*is_interrupt_flag_set)(void);
}uc_hal_tmr2_interface_t;

extern const uc_hal_tmr2_interface_t TIMER2;

#if UC_UCORE_MCU_16F
    #include "16f/16f_tmr2.h"
#endif

#endif /* UC_HAL_TMR2_H */
#endif /*#if UC_DEVICE_HAL_TMR2 */

/*** End of File **************************************************************/
