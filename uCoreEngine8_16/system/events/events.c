/****************************************************************************
* Title                 :   uCore Event System
* Filename              :   events.c
* Author                :   Jamie Starling
* Origin Date           :   2025/05/12
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

/*************** CHANGE LOG ***************************************************
*
*    Date    Version   Author         Description 
*
*******************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "events.h"

#if UC_SYSTEM_EVENTS

static uc_event_queue_t event_queue = {0};
static uc_system_event_handler_t handlers[UC_EVENT_MAX_HANDLERS] = {0};


/******************************************************************************
* Interface
*******************************************************************************/
const uc_system_events_interface_t UC_EVENTS = {
    .initialize = &uc_event_init,
    .assign = &uc_event_register_handler,
    .post = &uc_event_post,
    .process = &uc_event_process_all,
};



/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : uc_event_init
*//** 
* \b Description:
*
*******************************************************************************/

void uc_event_init(void) {
    event_queue.head = 0;
    event_queue.tail = 0;
    event_queue.count = 0;
    for (int i = 0; i < UC_EVENT_MAX_HANDLERS; i++) {
        handlers[i].type = UC_EVENT_NONE;
        handlers[i].callback = 0;
      }
}

/******************************************************************************
* Function : uc_event_post
*//** 
* \b Description:
*
*******************************************************************************/
bool uc_event_post(uc_system_event_type_t type, void *context) {
    if (event_queue.count >= UC_EVENT_QUEUE_SIZE) {
        return false; // Queue full
    }
    event_queue.queue[event_queue.head].type = type;
    event_queue.queue[event_queue.head].context = context;
    event_queue.head = (event_queue.head + 1) % UC_EVENT_QUEUE_SIZE;
    event_queue.count++;
    return true;
}

/******************************************************************************
* Function : uc_event_register_handler
*//** 
* \b Description:
*
*******************************************************************************/
bool uc_event_register_handler(uc_system_event_type_t type, uc_event_callback_t callback) {
    for (int i = 0; i < UC_EVENT_MAX_HANDLERS; i++) {
        if (handlers[i].callback == 0 || handlers[i].type == type) {
            handlers[i].type = type;
            handlers[i].callback = callback;
            return true;
        }
    }
    return false;
}

/******************************************************************************
* Function : uc_event_process_all
*//** 
* \b Description:
*
*******************************************************************************/
void uc_event_process_all(void) {
    while (event_queue.count > 0) {
        uc_event_t evt = event_queue.queue[event_queue.tail];
        event_queue.tail = (event_queue.tail + 1) % UC_EVENT_QUEUE_SIZE;
        event_queue.count--;

        for (int i = 0; i < UC_EVENT_MAX_HANDLERS; i++) {
            if (handlers[i].type == evt.type && handlers[i].callback) {
                handlers[i].callback(&evt);
                break;
            }
        }
    }
}

#endif
/*** End of File **************************************************************/
