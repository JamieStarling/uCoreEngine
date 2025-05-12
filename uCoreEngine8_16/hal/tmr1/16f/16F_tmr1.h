/****************************************************************************
* Title                 :   uCore Engine Timer1 Functions
* Filename              :   tmr1.h
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
*
*****************************************************************************/


/******************************************************************************
* Includes
*******************************************************************************/
#include "../tmr1.h"

#ifndef _UC_HAL_16F_TMR1_H
#define _UC_HAL_16F_TMR1_H

#if (UC_PROCESSOR_HAL_TMR1 && UC_UCORE_MCU_16F)


/******************************************************************************
* Function Prototypes
*******************************************************************************/
void uc_hal_tmr1_enable(uc_logic_t set_state);
void uc_hal_tmr1_set_mode_16bit_read_write(uc_logic_t set_state);
void uc_hal_tmr1_set_prescaler_rate(uc_tmr1_prescaler_t prescale_value);
void uc_hal_tmr1_set_clock_source(uc_tmr1_clock_source_t clock_value);
uint8_t uc_hal_tmr1_read_8bit_value(void);
uint16_t uc_hal_tmr1_read_16bit_value(void);
void uc_hal_tmr1_clear_interrupt_flag(void);
void uc_hal_tmr1_enable_interrupt(uc_logic_t set_state);
uc_logic_t uc_hal_tmr1_is_interrupt_flag_set(void);


#endif /* UC_HAL_TMR1_H */
#endif /* UC_DEVICE_HAL_TMR1 */

/*** End of File **************************************************************/
