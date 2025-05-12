/****************************************************************************
* Title                 :   uCore System Delays
* Filename              :   delays.h
* Author                :   Jamie Starling
* Origin Date           :   2024/12/23
* Version               :   1.0.0
* Compiler              :   XC8
* Target                :   
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
***** Includes
*******************************************************************************/
#include "../uc_core_system.h"

#if UC_SYSTEM_DELAYS

#ifndef UC_SYSTEM_DELAYS_H
#define UC_SYSTEM_DELAYS_H

/******************************************************************************
***** uCore Systel Delays Interface
*******************************************************************************/
typedef struct {
  void (*ms)(uint32_t time_ms);
}uc_system_delays_interface_t;

extern const uc_system_delays_interface_t UC_DELAY;




/******************************************************************************
***** Defines
*******************************************************************************/
#define UC_MIN_SYSTEM_DELAY_VALUE 5

/******************************************************************************
***** Function Prototypes
*******************************************************************************/
void uc_delay_blocking_ms(uint32_t time_ms);

#endif /*UC_SYSTEM_DELAYS_H*/
#endif /*#if UC_SYSTEM_DELAYS */
/*** End of File **************************************************************/
