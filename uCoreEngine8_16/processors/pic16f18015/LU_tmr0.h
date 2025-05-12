/****************************************************************************
* Title                 :   uCore Device TMR0 Lookup
* Filename              :   LU_tmr0.h
* Author                :   Jamie Starling
* Origin Date           :   2024/12/20
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
*   2024/12/20  1.0.0       Jamie Starling  Initial Version
*  
*****************************************************************************/


/******************************************************************************
* Includes
*******************************************************************************/
#include "pic16f18015.h"

#ifdef UC_SYSTEM_PROCESSOR_16F18015

#ifndef _UC_PROCESSOR_LU_TMR0_H
#define _UC_PROCESSOR_LU_TMR0_H

/******************************************************************************
*Timer0 Post-Scaler Select Enum * This enum selects the post-scaler value for Timer0 on the PIC16F1532x devices.
*******************************************************************************/
typedef enum
{
  UC_TMR0_POST_SCALE_1_1 = 0b0000,
  UC_TMR0_POST_SCALE_1_2 = 0b0001,
  UC_TMR0_POST_SCALE_1_3 = 0b0010,
  UC_TMR0_POST_SCALE_1_4 = 0b0011,
  UC_TMR0_POST_SCALE_1_5 = 0b0100,
  UC_TMR0_POST_SCALE_1_6 = 0b0101,
  UC_TMR0_POST_SCALE_1_7 = 0b0110,
  UC_TMR0_POST_SCALE_1_8 = 0b0111,
  UC_TMR0_POST_SCALE_1_9 = 0b1000,
  UC_TMR0_POST_SCALE_1_10 = 0b1001,
  UC_TMR0_POST_SCALE_1_11 = 0b1010,
  UC_TMR0_POST_SCALE_1_12 = 0b1011,
  UC_TMR0_POST_SCALE_1_13 = 0b1100,
  UC_TMR0_POST_SCALE_1_14 = 0b1101,
  UC_TMR0_POST_SCALE_1_15 = 0b1110,
  UC_TMR0_POST_SCALE_1_16 = 0b1111  
}uc_tmr0_post_scale_t;


/******************************************************************************
* Timer0 Clock Source Select Enum * This enum selects the clock source value for Timer0 on the PIC16F1532x devices.
*******************************************************************************/
typedef enum
{
  UC_TMR0_LC1_OUT = 0b111,  
  UC_TMR0_MFINTOSC = 0b101,
  UC_TMR0_LFINTOSC = 0b100,
  UC_TMR0_HFINTOSC = 0b011,
  UC_TMR0_FOSC_D4 = 0b010,
  UC_TMR0_T0CKIPPS_INV = 0b001,
  UC_TMR0_T0CKIPPS_NINV = 0b000
}uc_tmr0_clock_source_t;

/******************************************************************************
* Timer0 Pre-Scaler Select Enum * This enum selects the Pre-Scaler value for Timer0 on the PIC16F1532x devices.
*******************************************************************************/
typedef enum
{
  UC_TMR0_PRESCALER_1_32768 = 0b1111,
  UC_TMR0_PRESCALER_1_16384 = 0b1110,
  UC_TMR0_PRESCALER_1_8192 = 0b1101,
  UC_TMR0_PRESCALER_1_4096 = 0b1100,
  UC_TMR0_PRESCALER_1_2048 = 0b1011,
  UC_TMR0_PRESCALER_1_1024 = 0b1010,
  UC_TMR0_PRESCALER_1_512 = 0b1001,
  UC_TMR0_PRESCALER_1_256 = 0b1000,
  UC_TMR0_PRESCALER_1_128 = 0b0111,
  UC_TMR0_PRESCALER_1_64 = 0b0110,
  UC_TMR0_PRESCALER_1_32 = 0b0101,
  UC_TMR0_PRESCALER_1_16 = 0b0100,
  UC_TMR0_PRESCALER_1_8 = 0b0011,
  UC_TMR0_PRESCALER_1_4 = 0b0010,
  UC_TMR0_PRESCALER_1_2 = 0b0001,
  UC_TMR0_PRESCALER_1_1 = 0b0000
}uc_tmr0_prescaler_t;


#endif /*UC_DEVICE_LU_TMR0_H*/
#endif 
/*** End of File **************************************************************/
