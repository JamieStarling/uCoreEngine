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
#include "../hal.h"

#ifndef _UC_HAL_TMR0_H
#define _UC_HAL_TMR0_H

#if (UC_DEVICE_HAL_TMR0 || UC_SYSTEM_TIMER )

/******************************************************************************
* Defines / Options
*******************************************************************************/
#define UC_HAL_TMR0_FUNCTION_READ_VALUE_8BIT        UC_SYSTEM_DISABLE  
#define UC_HAL_TMR0_FUNCTION_READ_VALUE_16BIT       UC_SYSTEM_DISABLE  
#define UC_HAL_TMR0_FUNCTION_SET_OUTPUT_POSTSCALER  UC_SYSTEM_ENABLE 
#define UC_HAL_TMR0_FUNCTION_SET_INPUT_MODE_ASYNC   UC_SYSTEM_DISABLE 
#define UC_HAL_TMR0_FUNCTION_IS_INTERRUPT_SET       UC_SYSTEM_DISABLE


/******************************************************************************
***** TMR0 Interface
*******************************************************************************/
typedef struct {
    void (*enable)(uc_logic_t set_state);
    void (*set_mode_16bit)(uc_logic_t set_state);
    void (*set_prescaler_rate)(uc_tmr0_prescaler_t value);
    void (*set_clock_source)(uc_tmr0_clock_source_t value);
    void (*interrupt_flag_clear)(void);
    void (*interrupt_enable)(uc_logic_t set_state);
    
    #if UC_HAL_TMR0_FUNCTION_SET_OUTPUT_POSTSCALER
        void (*set_output_postscaler)(uc_tmr0_post_scale_t value);
    #endif
    #if UC_HAL_TMR0_FUNCTION_SET_INPUT_MODE_ASYNC
        void (*set_input_mode_async)(uc_logic_t set_state);
    #endif
    #if UC_HAL_TMR0_FUNCTION_READ_VALUE_8BIT
        uint8_t (*read_value_8bit)(void);
    #endif
    #if UC_HAL_TMR0_FUNCTION_READ_VALUE_16BIT
        uint16_t (*read_value_16bit)(void);
    #endif      
    #if UC_HAL_TMR0_FUNCTION_IS_INTERRUPT_SET
        uc_logic_t (*is_interrupt_flag_set)(void);
    #endif
}uc_hal_tmr0_interface_t;

extern const uc_hal_tmr0_interface_t TIMER0;

#if UC_UCORE_MCU_16F
    #include "16f/16f_tmr0.h"
#endif

#if UC_UCORE_MCU_18F
    #include "18f/18f_tmr0.h"
#endif


#endif /*UC_HAL_TMR0_H*/
#endif /* (UC_DEVICE_HAL_TMR0 || UC_SYSTEM_TIMER ) */
/*** End of File **************************************************************/
