/****************************************************************************
* Title                 :   uCore Engine System Timers Chooser
* Filename              :   uc_system_timer.h
* Author                :   Jamie Starling
* Origin Date           :   2025/01/04
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
*    Date    Version   Author         Description 
*  
*  
*
*****************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#ifndef _UC_SYSTEM_TIMER_H
#define _UC_SYSTEM_TIMER_H

#include "../uc_core_system.h"

 /*** System Timer ISR Functions 16F Devices    *****************************/
#if (UC_SYSTEM_TIMER && UC_UCORE_MCU_16F)                             
    #include "16f/16f_isr_system_timer.h"
#endif

 /*** System Timer ISR Functions 18F Devices    *****************************/
#if (UC_SYSTEM_TIMER && UC_UCORE_MCU_18F)                             
    #include "18f/18f_isr_system_timer.h"
#endif


#endif /*UC_SYSTEM_TIMER_H*/

/*** End of File **************************************************************/
