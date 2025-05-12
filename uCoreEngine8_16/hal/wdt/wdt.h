/****************************************************************************
* Title                 :   uCore MCU WatchDog Timer Functions
* Filename              :   wdt.h
* Author                :   Jamie Starling
* Origin Date           :   2024/12/26
* Version               :   1.0.0
* Compiler              :   XC8
* Target                :   MicroChip PIC 16F devices
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
*****************************************************************************/


/******************************************************************************
* Includes
*******************************************************************************/
#include "../hal.h"

#ifndef _UC_HAL_MCU_WDT_H
#define _UC_HAL_MCU_WDT_H

#if UC_DEVICE_HAL_WATCHDOG

/******************************************************************************
* WDT Interval
******************************************************************************/
typedef enum
{    
    WDT_S256 = 0b10010, // 1:8388608 (223) (Interval 256s nominal)
    WDT_S128 = 0b10001, // 1:4194304 (222) (Interval 128s nominal)
    WDT_S64 = 0b10000, // 1:2097152 (221) (Interval 64s nominal)
    WDT_S32 = 0b01111, // 1:1048576 (220) (Interval 32s nominal)
    WDT_S16 = 0b01110, // 1:524288 (219) (Interval 16s nominal)
    WDT_S8 = 0b01101, // 1:262144 (218) (Interval 8s nominal)
    WDT_S4 = 0b01100, // 1:131072 (217) (Interval 4s nominal)
    WDT_S2 = 0b01011, // 1:65536 (Interval 2s nominal) (Reset value)
    WDT_S1 = 0b01010, // 1:32768 (Interval 1s nominal)
    WDT_MS512 = 0b01001, // 1:16384 (Interval 512 ms nominal)
    WDT_MS256 = 0b01000, // 1:8192 (Interval 256 ms nominal)
    WDT_MS128 = 0b00111, // 1:4096 (Interval 128 ms nominal)
    WDT_MS64 = 0b00110, // 1:2048 (Interval 64 ms nominal)
    WDT_MS32 = 0b00101, // 1:1024 (Interval 32 ms nominal)
    WDT_MS16 = 0b00100, // 1:512 (Interval 16 ms nominal)
    WDT_MS8 = 0b00011, // 1:256 (Interval 8 ms nominal)
    WDT_MS4 = 0b00010, // 1:128 (Interval 4 ms nominal)
    WDT_MS2 = 0b00001, // 1:64 (Interval 2 ms nominal)
    WDT_MS1 = 0b00000, // 1:32 (Interval 1 ms nominal)
}uc_hal_wdt_interval_t;



/******************************************************************************
***** WDT Interface
*******************************************************************************/
typedef struct {
 void (*initialize)(uc_hal_wdt_interval_t interval);
 void (*enable)(uc_logic_t set_state);
 void (*clear)(void);
}uc_wdt_interface_t;

extern const uc_wdt_interface_t WDT;

/******************************************************************************
* Function Prototypes
*******************************************************************************/
void uc_hal_wdt_init(uc_hal_wdt_interval_t interval);
void uc_hal_wdt_enable(uc_logic_t set_state);
void uc_hal_wdt_clear(void);

#endif /*_CORE_MCU_WDT*/
#endif /* UC_DEVICE_HAL_WATCHDOG */
/*** End of File **************************************************************/
