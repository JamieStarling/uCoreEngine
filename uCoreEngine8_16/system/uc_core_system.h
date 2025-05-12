/****************************************************************************
* Title                 :   uCore Engine System Functions
* Filename              :   uc_core_system.h
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
*   2024/12/19  1.0.0       Jamie Starling  Initial Version
*  
*****************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#ifndef _UC_CORE_SYSTEM_FUNCTIONS_H
#define _UC_CORE_SYSTEM_FUNCTIONS_H

#include "../ucore8-16.h"

/******************************************************************************
********* Includes - Based on Framework Features
*******************************************************************************/

/*** System Timer ISR Functions     *****************************/
#if UC_SYSTEM_TIMER
    #include "systimer/uc_system_timer.h"
#endif

/*** System Delays                          *****************************/
#if UC_SYSTEM_DELAYS
    #include "delays/delays.h"
#endif

/*** Timed Event System                     *****************************/
#if UC_SYSTEM_TIMED_EVENTS
    #include "timed_events/timed_events.h"
#endif

#if UC_SYSTEM_EVENTS
    #include "events/events.h"
#endif



/*** Include UC Util Functions              *****************************/
#if UC_UTIL_FUNCTIONS                           
    #include "etc/uc_utils.h"
#endif

 /*** Include UC String Functions           *****************************/
#if UC_STRING_FUNCTIONS                        
    #include "etc/uc_string.h"
#endif





/******************************************************************************
***** uCore Engine System Functions Interface
*******************************************************************************/
typedef struct {
    void (*initialize)(void);  
}uc_system_interface_t;

extern const uc_system_interface_t UC_SYSTEM;

/******************************************************************************
* Function Prototypes
*******************************************************************************/

void uc_system_init(void);


#endif /*_UC_CORE_SYSTEM_FUNCTIONS_H*/

/*** End of File **************************************************************/
