/****************************************************************************
* Title                 :   uCore8-16 Engine
* Filename              :   ucore8-16.h
* Author                :   Jamie Starling
* Origin Date           :   2025/04/25
* Version               :   1.0.0
* Compiler              :   XC8/XC16
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
*   2025/04/25  1.0.0       Jamie Starling  Initial Version
*  
*****************************************************************************/

#ifndef _UC_UCORE816_ENGINE_H
#define _UC_UCORE816_ENGINE_H
/******************************************************************************
********* Standard Includes
*******************************************************************************/
#include <xc.h>
#include <stdint.h>     //For standard type definitions
#include <stdbool.h>    //For Bool
#include <stdlib.h> 
#include <stdio.h>

/******************************************************************************
********* Start of uCore Engine System Includes - Required
*******************************************************************************/
#include "ucore_version.h"
#include "ucore_const.h"

/******************************************************************************
************* uCore EngineConfiguration - Enable Disables Framework Features
*******************************************************************************/
#define UC_SYSTEM_TIMER         UC_SYSTEM_ENABLE     /* System Timer */
#define UC_SYSTEM_DELAYS        UC_SYSTEM_ENABLE      /* System Delay Functions - based on System Timer */
#define UC_SYSTEM_TIMED_EVENTS  UC_SYSTEM_DISABLE      /* Timed Event System */
#define UC_SYSTEM_EVENTS        UC_SYSTEM_ENABLE      /*Event System*/
#define UC_UTIL_FUNCTIONS       UC_SYSTEM_DISABLE      /* Useful Functions */
#define UC_STRING_FUNCTIONS     UC_SYSTEM_DISABLE      /* String Functions */


/******************************************************************************
********* uCore Engine System MCU Target Includes - Default/Required
*******************************************************************************/
#include "processors/processors.h"  // Processor Configuration and Settings.

/******************************************************************************
********* uCore Engine System HAL Includes - Default/Required
*******************************************************************************/
#include "hal/hal.h"

/******************************************************************************
********* uCore Engine Core System Functions Includes - Default/Required
*******************************************************************************/
#include "system/uc_core_system.h"

/******************************************************************************
********* Driver Includes
*******************************************************************************/
#include "drivers/uc_drivers.h"

#endif /*_UC_UCORE816_ENGINE_H*/

/*** End of File **************************************************************/
