/****************************************************************************
* Title                 :   uCore Device TMR1 Lookup
* Filename              :   LU_tmr1.h
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

#ifndef UC_PROCESSOR_LU_TMR1_H
#define UC_PROCESSOR_LU_TMR1_H
/******************************************************************************
****** Lookup : Timer1
*******************************************************************************/
/******************************************************************************
* Timer1 Pre-Scaler Select Enum * This enum selects the Pre-Scaler value for Timer1 on the PIC16F1532x devices.
*******************************************************************************/
typedef enum
{
  UC_TMR1_PRESCALER_1_8 = 0b11,
  UC_TMR1_PRESCALER_1_4 = 0b10,
  UC_TMR1_PRESCALER_1_2 = 0b01,
  UC_TMR1_PRESCALER_1_1 = 0b00
}uc_tmr1_prescaler_t;

/******************************************************************************
* Timer1 Clock Source Select Enum * This enum selects the clock source value for Timer1 on the PIC16F1532x devices.
*******************************************************************************/
typedef enum
{
  UC_TMR1_LC4_OUT = 0b1101,
  UC_TMR1_LC3_OUT = 0b1100,
  UC_TMR1_LC2_OUT = 0b1011,
  UC_TMR1_LC1_OUT = 0b1010,
  UC_TMR1_TMR0_OVERFLOW_OUT = 0b1001,
  UC_TMR1_CLKR_OUT = 0b1000,
  UC_TMR1_MFINTOSC_32KHZ = 0b0110,
  UC_TMR1_MFINTOSC_500KHZ = 0b0101,
  UC_TMR1_LFINTOSC = 0b0100,
  UC_TMR1_HFINTOSC = 0b0011,
  UC_TMR1_FOSC = 0b0010,
  UC_TMR1_FOSC_D4 = 0b0001,
  UC_TMR1_T1CKIPPS = 0b0000
}uc_tmr1_clock_source_t;


#endif /* UC_DEVICE_LU_TMR1_H */
#endif /* #ifdef UC_SYSTEM_DEVICE_16F15313 */
/*** End of File **************************************************************/
