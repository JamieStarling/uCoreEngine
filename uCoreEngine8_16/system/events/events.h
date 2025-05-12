/****************************************************************************
* Title                 :   uCore Event System
* Filename              :   events.h
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
#ifndef _UC_CORE_EVENTS_H
#define _UC_CORE_EVENTS_H

#include "../uc_core_system.h"

#if UC_SYSTEM_EVENTS

//Event Type and Queue
#define UC_EVENT_QUEUE_SIZE 8
#define UC_EVENT_MAX_HANDLERS 8

typedef enum {
    UC_EVENT_NONE,
    UC_EVENT_I2C_0_COMPLETE,
    UC_EVENT_UART_0_COMPLETE,    
} uc_system_event_type_t;

typedef struct {
    uc_system_event_type_t type;
    void *context;   // A pointer to the driver state or callback data
} uc_event_t;

typedef struct {
    uc_event_t queue[UC_EVENT_QUEUE_SIZE];
    uint8_t head;
    uint8_t tail;
    uint8_t count;
} uc_event_queue_t;

// Callback Type
typedef void (*uc_event_callback_t)(const uc_event_t *event);


//Register Handler
typedef struct {
    uc_system_event_type_t type;
    uc_event_callback_t callback;
} uc_system_event_handler_t;


/******************************************************************************
***** uCore System Events Interface
*******************************************************************************/
typedef struct {
    void (*initialize)(void);
    bool (*post)(uc_system_event_type_t type, void *context);  
    bool (*assign)(uc_system_event_type_t type, uc_event_callback_t callback);
    void (*process)(void);
}uc_system_events_interface_t;

extern const uc_system_events_interface_t UC_EVENTS;


/******************************************************************************
* Function Prototypes
*******************************************************************************/
void uc_event_init(void);
bool uc_event_post(uc_system_event_type_t type, void *context);
bool uc_event_register_handler(uc_system_event_type_t type, uc_event_callback_t callback);
void uc_event_process_all(void);

#endif /*_H_*/
#endif

/*** End of File **************************************************************/
