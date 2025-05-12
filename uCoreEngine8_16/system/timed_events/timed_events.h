/****************************************************************************
* Title                 :   uCore Engine Timed Events
* Filename              :   events.h
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
*
*****************************************************************************/

#ifndef UC_SYSTEM_TIMED_EVENTS_H
#define UC_SYSTEM_TIMED_EVENTS_H
/******************************************************************************
* Includes
*******************************************************************************/
#include "../uc_core_system.h"

#if UC_SYSTEM_TIMED_EVENTS

/******************************************************************************
***** uCore Timed Events Interface
*******************************************************************************/
typedef struct {
  void (*initialize)(void);
  uint8_t (*schedule)(uint32_t delay_ms, void (*callback)(void), uint32_t interval);
  void (*check)(void); 
  void (*cancel)(void (*callback)(void));
}uc_system_timed_events_interface_t;

extern const uc_system_timed_events_interface_t UC_TIMED_EVENTS;



/******************************************************************************
* Configuration
*******************************************************************************/
#define UC_TIMED_EVENTS_MAX_EVENTS 5                  // Maximum number of scheduled events

/******************************************************************************
* Typedefs
*******************************************************************************/
typedef struct {
    uint32_t trigger_time;              // Time in milliseconds when the event should trigger
    void (*event_callback)(void);       // Function pointer to the event handler
    uint32_t interval;                  // Interval for recurring events (0 for one-time events)
    uint8_t active;                     // Flag to indicate if the event is active
} uc_system_timed_event_t;

/******************************************************************************
* Function Prototypes
*******************************************************************************/
void uc_sytem_timed_events_init(void);
uint8_t uc_system_timed_events_schedule(uint32_t delay_ms, void (*callback)(void), uint32_t interval);
void uc_system_timed_events_check(void);
void uc_system_timed_events_cancel(void (*callback)(void));

#endif /* UC_SYSTEM_EVENTS_H */
#endif /* #if UC_SYSTEM_TIMED_EVENTS */
/*** End of File **************************************************************/
