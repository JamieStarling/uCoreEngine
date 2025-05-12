/****************************************************************************
* Title                 :   uCore System Delays
* Filename              :   delays.c
* Author                :   Jamie Starling
* Origin Date           :   2024/12/23
* Version               :   1.0.0
* Compiler              :   XC8 
* Target                :   Microchip series  
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
***** Includes
*******************************************************************************/
#include "delays.h"

#if UC_SYSTEM_DELAYS

/******************************************************************************
* Interface
*******************************************************************************/
const uc_system_delays_interface_t UC_DELAY = {
    .ms = &uc_delay_blocking_ms,
};


/******************************************************************************
****** Functions
*******************************************************************************/
/******************************************************************************
* Function : uc_delay_blocking_ms()
* Description:
*
* This function generates a blocking delay for a specified duration in milliseconds.
* It continuously checks the elapsed time using ISR_CORE16F_SYSTEM_TIMER_GetMillis()
* and blocks the program until the delay period has passed.
*  
* Parameters:
* - time_ms (uint32_t): The desired delay time in milliseconds.
*  If less than UC_MIN_SYSTEM_DELAY_VALUE, the function sets it to the minimum delay value.
*
* 
*******************************************************************************/
void uc_delay_blocking_ms(uint32_t time_ms)
{  
  if (time_ms < UC_MIN_SYSTEM_DELAY_VALUE){time_ms = UC_MIN_SYSTEM_DELAY_VALUE;}
  
  // Store the current time in milliseconds  
  uint32_t start_ms = SYSTEM_TIMER.get_time();
    
  // Block execution until the specified time has passed 
  while (SYSTEM_TIMER.get_time() - start_ms < time_ms){}
}

#endif /* #if UC_SYSTEM_DELAYS */
/*** End of File **************************************************************/
