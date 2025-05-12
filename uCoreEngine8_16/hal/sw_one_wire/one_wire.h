/****************************************************************************
* Title                 :   uCore Engine One Wire HAL
* Filename              :   one_wire.h
* Author                :   Jamie Starling
* Origin Date           :   2024/12/25
* Version               :   1.0.0
* Compiler              :   XC8
* Target                :   Microchip PIC16F series
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
*   2024/12/25  1.0.0       Jamie Starling  Initial Version
*  
*
*****************************************************************************/


/******************************************************************************
* Includes
*******************************************************************************/
#include "../hal.h"


#if UC_DEVICE_HAL_OW

#ifndef UC_DEVICE_HAL_ONE_WIRE_H
#define UC_DEVICE_HAL_ONE_WIRE_H

typedef enum
{    
    UC_OW_NO_DEVICE,
    UC_OW_DEVICE_PRESENT,
}uc_hal_ow_status_t;

/******************************************************************************
***** ONE WIRE Interface
*******************************************************************************/
typedef struct {
  void (*initialize)(void);
  uc_hal_ow_status_t (*send_reset)(void);
  void (*write_byte)(uint8_t data);
  uint8_t (*read_byte)(void);
  uint8_t (*read_bit)(void);
}uc_hal_ow_interface_t;

extern const uc_hal_ow_interface_t ONE_WIRE;

/******************************************************************************
* Configuration
*******************************************************************************/

/*ONE WIRE RESET TIMINGS*/
#define UC_HAL_OW_RESET_DELAY_US 485
#define UC_HAL_OW_RESET_DELAY_DRIVE_HIGH_US 70
#define UC_HAL_OW_RESET_DELAY_READ_US 410

/*ONE WIRE WRITE TIMINGS*/
#define UC_HAL_OW_WRITE_BIT_1_DELAY_DRIVE_LOW_US 6
#define UC_HAL_OW_WRITE_BIT_1_DELAY_DRIVE_HIGH_US 64
#define UC_HAL_OW_WRITE_BIT_0_DELAY_DRIVE_LOW_US 60
#define UC_HAL_OW_WRITE_BIT_0_DELAY_DRIVE_HIGH_US 10

/*ONE WIRE READ TIMINGS*/
#define UC_HAL_OW_READ_BIT_DELAY_DRIVE_LOW_US 5
#define UC_HAL_OW_READ_BIT_DELAY_DRIVE_HIGH_US 2
#define UC_HAL_OW_READ_BIT_DELAY_END_US 45


/******************************************************************************
* Function Prototypes
*******************************************************************************/
void uc_hal_ow_init(void);
uc_hal_ow_status_t uc_hal_ow_reset(void);
void uc_hal_ow_write_byte(uint8_t data);
uint8_t uc_hal_ow_read_byte(void);
uint8_t uc_hal_ow_read_bit(void);

#endif /* UC_DEVICE_HAL_ONE_WIRE_H*/
#endif /* #if UC_DEVICE_HAL_OW */

/*** End of File **************************************************************/
