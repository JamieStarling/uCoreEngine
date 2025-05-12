/****************************************************************************
* Title                 :   Core18F System Timer Functions
* Filename              :   isr_core18F_system_timer.h
* Author                :   Jamie Starling
* Origin Date           :   2025/01/03
* Version               :   1.0.0
* Compiler              :   XC8
* Target                :   Microchip PIC18F series 
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
*    Date    Version   Author         Description 
*  
*  *
*****************************************************************************/


/******************************************************************************
* Includes
*******************************************************************************/

#ifndef _UC_SYSTEM_TIMER_18F_H
#define _UC_SYSTEM_TIMER_18F_H

#include "../uc_system_timer.h"

#if (UC_SYSTEM_TIMER && UC_UCORE_MCU_18F) 

/******************************************************************************
***** uCore System Timer Interface
*******************************************************************************/
typedef struct {
  void (*initialize)(void);
  void (*isr)(void);
  uint32_t (*get_time)(void);  
}uc_system_timer_interface_t;

extern const uc_system_timer_interface_t SYSTEM_TIMER;

/******************************************************************************
* Function Prototypes
*******************************************************************************/

void uc_isr_18f_system_timer_init(void);
void uc_isr_18f_systerm_timer_isr(void);
uint32_t uc_isr_18f_system_timer_get_millis(void);

#endif /*_CORE18_SYSTEM_TIMER_H*/
#endif /* #if (UC_SYSTEM_TIMER && UC_UCORE8_18F)   */

/*** End of File **************************************************************/
