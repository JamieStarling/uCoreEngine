/****************************************************************************
* Title                 :   CORE MUC Event System
* Filename              :   events.c
* Author                :   Jamie Starling
* Origin Date           :   2024/10/17
* Version               :   1.0.0
* Compiler              :   XC8 
* Target                :   PIC16 Family 
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
*   2024/10/17  1.0.0       Jamie Starling  Initial Version
*  
*
*****************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "timed_events.h"

#if UC_SYSTEM_TIMED_EVENTS

/******************************************************************************
* Interface
*******************************************************************************/
const uc_system_timed_events_interface_t UC_TIMED_EVENTS = {
    .initialize = &uc_sytem_timed_events_init,
    .schedule = &uc_system_timed_events_schedule,
    .check =  &uc_system_timed_events_check,
    .cancel = &uc_system_timed_events_cancel,
};

/******************************************************************************
* Variables
*******************************************************************************/
uc_system_timed_event_t EventList[UC_TIMED_EVENTS_MAX_EVENTS];      // Event list

/******************************************************************************
****** Functions
*******************************************************************************/
/******************************************************************************
* Function : uc_sytem_timed_events_init()
* Description: Initializes the Event System
*
*******************************************************************************/
void uc_sytem_timed_events_init(void)
{
    for (uint8_t i = 0; i < UC_TIMED_EVENTS_MAX_EVENTS; i++) {
        EventList[i].active = 0;        // Mark all events as inactive
    }
}

/******************************************************************************
* Function : uc_system_timed_events_schedule()
* Description: Adds an event to the List
*
* Parameters:
*
*******************************************************************************/
uint8_t uc_system_timed_events_schedule(uint32_t delay_ms, void (*callback)(void), uint32_t interval)
{
    for (uint8_t i = 0; i < UC_TIMED_EVENTS_MAX_EVENTS; i++) {
        if (EventList[i].active == 0) {     // Find an available slot
            EventList[i].trigger_time = SYSTEM_TIMER.get_time() + delay_ms;
            EventList[i].event_callback = callback;
            EventList[i].interval = interval;
            EventList[i].active = 1;
            return 1;  // Successfully scheduled
        }
    }
    return 0;  // No available slots
}

/******************************************************************************
* Function : uc_system_timed_events_check()
* Description: Checks the Event list - Add in to Main Loop
*
*******************************************************************************/
void uc_system_timed_events_check(void)
{
    uint32_t current_time = SYSTEM_TIMER.get_time();
    
    for (uint8_t i = 0; i < UC_TIMED_EVENTS_MAX_EVENTS; i++) {
        if (EventList[i].active && (current_time >= EventList[i].trigger_time)) {
            // Trigger the event
            EventList[i].event_callback();
            
            // Reschedule the event if it's recurring, otherwise deactivate it
            if (EventList[i].interval > 0) {
                EventList[i].trigger_time += EventList[i].interval;  // Set next trigger time
            } else {
                EventList[i].active = 0;  // Deactivate one-time events
            }
        }
    }
}

/******************************************************************************
* Function : uc_system_timed_events_cancel()
* Description: Removes an event from the list
*
* Parameters:
*
*******************************************************************************/
void uc_system_timed_events_cancel(void (*callback)(void))
{
    for (uint8_t i = 0; i < UC_TIMED_EVENTS_MAX_EVENTS; i++) {
        if (EventList[i].event_callback == callback) {
            EventList[i].active = 0;  // Mark as inactive
            break;
        }
    }
}

#endif /* #if UC_SYSTEM_TIMED_EVENTS */

/*** End of File **************************************************************/
