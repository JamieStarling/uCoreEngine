/****************************************************************************
* Title                 :   uCore Engine System Functions
* Filename              :   uc_core_system.c
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
#include "uc_core_system.h"

/******************************************************************************
* Interface
*******************************************************************************/
const uc_system_interface_t UC_SYSTEM = {
    .initialize = &uc_system_init,
};
/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : uc_system_init()
* Description: Initializes the uCore system, setting up timers and 
* events if they are enabled in the configuration.
* 
*******************************************************************************/
void uc_system_init(void)
{
    #if UC_SYSTEM_TIMER
        SYSTEM_TIMER.initialize();    // Initializes Timer ISR for system timing
    
    #if UC_SYSTEM_TIMED_EVENTS
        UC_TIMED_EVENTS.initialize();        // Initializes Core 16F Event System
    #endif /* UC_SYSTEM_TIMED_EVENTS */
    #endif /* UC_SYSTEM_TIMER */

    #if UC_SYSTEM_EVENTS
        uc_event_init();
    #endif
    
}



/*** End of File **************************************************************/
