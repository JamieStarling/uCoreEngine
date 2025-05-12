/****************************************************************************
* Title                 :   uCore Engine HAL TMR0 for Microchip devices
* Filename              :   tmr0.h
* Author                :   Jamie Starling
* Origin Date           :   2024/12/20
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
*****************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "../tmr0.h"

#ifndef _UC_HAL_18F_TMR0_H
#define _UC_HAL_18F_TMR0_H

#if (UC_DEVICE_HAL_TMR0 || UC_SYSTEM_TIMER && UC_UCORE_MCU_18F)


/******************************************************************************
* Function Prototypes
*******************************************************************************/
void uc_hal_tmr0_enable(uc_logic_t set_state);
void uc_hal_tmr0_set_mode_16bit(uc_logic_t set_state);
#if UC_HAL_TMR0_FUNCTION_SET_OUTPUT_POSTSCALER
    void uc_hal_tmr0_set_output_postscaler(uc_tmr0_post_scale_t value);
#endif
void uc_hal_tmr0_set_clock_source(uc_tmr0_clock_source_t value);

#if UC_HAL_TMR0_FUNCTION_SET_INPUT_MODE_ASYNC
    void uc_hal_tmr0_set_input_mode_async(uc_logic_t set_state);
#endif

void uc_hal_tmr0_set_prescaler_rate(uc_tmr0_prescaler_t value);

    #if UC_HAL_TMR0_FUNCTION_READ_VALUE_8BIT
        uint8_t uc_hal_tmr0_read_value_8bit(void);
    #endif
    
    #if UC_HAL_TMR0_FUNCTION_READ_VALUE_16BIT
        uint16_t uc_hal_tmr0_read_value_16bit(void);
    #endif

inline void uc_hal_tmr0_interrupt_flag_clear(void);
void uc_hal_tmr0_interrupt_enable(uc_logic_t set_state);
#if UC_HAL_TMR0_FUNCTION_IS_INTERRUPT_SET
inline uc_logic_t uc_hal_tmr0_is_interrupt_set(void);
#endif

#endif /*UC_HAL_TMR0_H*/
#endif /* (UC_DEVICE_HAL_TMR0 || UC_SYSTEM_TIMER ) */
/*** End of File **************************************************************/
