/****************************************************************************
* Title                 :   uCore Device TMR2 Lookup
* Filename              :   LU_tmr2.h
* Author                :   Jamie Starling
* Origin Date           :   2024/12/23
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
*   2024/12/23  1.0.0       Jamie Starling  Initial Version
*  
*****************************************************************************/


/******************************************************************************
* Includes
*******************************************************************************/
#include "pic16f18015.h"

#ifdef UC_SYSTEM_PROCESSOR_16F18015

#ifndef _UC_PROCESSOR_LU_TMR2_H
#define _UC_PROCESSOR_LU_TMR2_H

/******************************************************************************
****** Lookup : Timer2
*******************************************************************************/
/******************************************************************************
* Timer2 Pre-Scaler Select Enum * This enum selects the Pre-Scaler value for Timer2 on the PIC16F1532x devices.
*******************************************************************************/
typedef enum
{
  UC_TMR2_PRESCALER_1_128 = 0b111,
  UC_TMR2_PRESCALER_1_64 = 0b110,
  UC_TMR2_PRESCALER_1_32 = 0b101,
  UC_TMR2_PRESCALER_1_16 = 0b100,
  UC_TMR2_PRESCALER_1_8 = 0b011,
  UC_TMR2_PRESCALER_1_4 = 0b010,
  UC_TMR2_PRESCALER_1_2 = 0b001,
  UC_TMR2_PRESCALER_1_1 = 0b000
}uc_tmr2_prescaler_t;


/******************************************************************************
* Timer2 Mode Select Enum * This enum selects the mode value for Timer2 on the PIC16F1532x devices.
*******************************************************************************/
typedef enum
{
  UC_TMR2_FREE_RUN_PERIOD_PULSE_SOFTWARE_GATE =            0b00000,
  UC_TMR2_FREE_RUN_PERIOD_PULSE_HARDWARE_ACTIVE_HIGH =     0b00001,
  UC_TMR2_FREE_RUN_PERIOD_PULSE_HARDWARE_ACTIVE_LOW =      0b00010,
  UC_TMR2_FREE_RUN_PERIOD_PULSE_HARDWARE_RESET =           0b00011,
  UC_TMR2_FREE_RUN_PERIOD_PULSE_HARDWARE_RESET_RISING =    0b00100,
  UC_TMR2_FREE_RUN_PERIOD_PULSE_HARDWARE_RESET_FALLING =   0b00101,
  UC_TMR2_FREE_RUN_PERIOD_PULSE_HARDWARE_RESET_LOW =       0b00110,
  UC_TMR2_FREE_RUN_PERIOD_PULSE_HARDWARE_RESET_HIGH =      0b00111,
  UC_TMR2_ONE_SHOT_SOFTWARE_START =                        0b01000,
  UC_TMR2_ONE_SHOT_EDGE_TRIGGERED_START_RISING =           0b01001,
  UC_TMR2_ONE_SHOT_EDGE_TRIGGERED_START_FALLING =          0b01010,
  UC_TMR2_ONE_SHOT_EDGE_TRIGGERED_START_ANY =              0b01011,  
  UC_TMR2_ONE_SHOT_EDGE_TRIGGERED_HW_RESET_RISING =        0b01100,  
  UC_TMR2_ONE_SHOT_EDGE_TRIGGERED_HW_RESET_FALLING =       0b01101,
  UC_TMR2_ONE_SHOT_EDGE_TRIGGERED_HW_RESET_LOW =           0b01110,
  UC_TMR2_ONE_SHOT_EDGE_TRIGGERED_HW_RESET_HIGH =          0b01111,
  UC_TMR2_MONOSTABLE_RISING_START =                        0b10001,  
  UC_TMR2_MONOSTABLE_FALLING_START =                       0b10010,
  UC_TMR2_MONOSTABLE_ANY_START =                           0b10011,
  UC_TMR2_ONESHOT_LEVEL_TRIGGER_HW_RESET_HIGH_LOW  =       0b10110,
  UC_TMR2_ONESHOT_LEVEL_TRIGGER_HW_RESET_LOW_HIGH  =       0b10111,  
}uc_tmr2_mode_select_t;

/******************************************************************************
* Timer2 Clock Source Select Enum * This enum selects the clock source value for Timer2 on the PIC16F1532x devices.
*******************************************************************************/
typedef enum
{
  UC_TMR2_LC4_OUT = 0b1110,
  UC_TMR2_LC3_OUT = 0b1101,
  UC_TMR2_LC2_OUT = 0b1100,
  UC_TMR2_LC1_OUT = 0b1011,
  UC_TMR2_ZCD1_OUT = 0b1010,
  UC_TMR2_NCO1_OUT = 0b1001,
  UC_TMR2_CLKR_OUT = 0b1000,
  UC_TMR2_MFINTOSC_32KHZ = 0b0110,
  UC_TMR2_MFINTOSC_500KHZ = 0b0101,
  UC_TMR2_LFINTOSC = 0b0100,
  UC_TMR2_HFINTOSC = 0b0011,
  UC_TMR2_FOSC = 0b0010,
  UC_TMR2_FOSC_D4 = 0b0001,
  UC_TMR2_T1CKIPPS = 0b0000
}uc_tmr2_clock_source_t;

/******************************************************************************
* Timer2 Post-Scaler Select Enum * This enum selects the post-scaler value for Timer2 on the PIC16F1532x devices.
*******************************************************************************/
typedef enum 
{
  UC_TMR2_POST_SCALE_1_1 = 0b0000,
  UC_TMR2_POST_SCALE_1_2 = 0b0001,
  UC_TMR2_POST_SCALE_1_3 = 0b0010,
  UC_TMR2_POST_SCALE_1_4 = 0b0011,
  UC_TMR2_POST_SCALE_1_5 = 0b0100,
  UC_TMR2_POST_SCALE_1_6 = 0b0101,
  UC_TMR2_POST_SCALE_1_7 = 0b0110,
  UC_TMR2_POST_SCALE_1_8 = 0b0111,
  UC_TMR2_POST_SCALE_1_9 = 0b1000,
  UC_TMR2_POST_SCALE_1_10 = 0b1001,
  UC_TMR2_POST_SCALE_1_11 = 0b1010,
  UC_TMR2_POST_SCALE_1_12 = 0b1011,
  UC_TMR2_POST_SCALE_1_13 = 0b1100,
  UC_TMR2_POST_SCALE_1_14 = 0b1101,
  UC_TMR2_POST_SCALE_1_15 = 0b1110,
  UC_TMR2_POST_SCALE_1_16 = 0b1111  
}uc_tmr2_post_scaler_t;


#define TMR2_PIE_REGISTER PIE1bits
#define TMR2_PIR_REGISTER PIR1bits

#endif /* UC_DEVICE_LU_TMR2_H */
#endif /* #ifdef UC_SYSTEM_DEVICE_16F15313 */
/*** End of File **************************************************************/
