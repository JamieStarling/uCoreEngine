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
#include "../tmr2.h"

#ifndef _UC_HAL_16F_TMR2_H
#define _UC_HAL_16F_TMR2_H

#if (UC_PROCESSOR_HAL_TMR2 || UC_PROCESSOR_HAL_PWM_TIMER && UC_UCORE_MCU_16F)


/******************************************************************************
* Function Prototypes
*******************************************************************************/
void uc_hal_tmr2_enable(uc_logic_t set_state);
void uc_hal_tmr2_set_prescaler_rate(uc_tmr2_prescaler_t value);
void uc_hal_tmr2_set_clock_source(uc_tmr2_clock_source_t value);
void uc_hal_tmr2_set_output_postscaler(uc_tmr2_post_scaler_t value);
uint8_t uc_hal_tmr2_read_value_8bit(void);
void uc_hal_tmr2_interrupt_flag_clear(void);
void uc_hal_tmr2_interrupt_enable(uc_logic_t set_state);
uc_logic_t uc_hal_tmr2_is_interrupt_set(void);

#endif /* UC_HAL_TMR2_H */
#endif /*#if UC_DEVICE_HAL_TMR2 */

/*** End of File **************************************************************/
