/****************************************************************************
* Title                 :   DS18B20 Driver
* Filename              :   ds18b20.h
* Author                :   Jamie Starling
* Origin Date           :   2025/01/06
* Version               :   1.0.0
* Compiler              :   XC8
* Target                :   PIC MCUs
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
*   2025/01/06  1.0.0       Jamie Starling  Initial Version
*  
*****************************************************************************/



/******************************************************************************
* Includes
*******************************************************************************/
#include "../uc_drivers.h"

#if UC_DRIVER_DS18B20

#ifndef UC_DRIVER_DS18B20_H
#define UC_DRIVER_DS18B20_H


/******************************************************************************
* Constants
*******************************************************************************/

#define UC_DS18B20_INVALID_TEMPERATURE 0xFF

#define UC_DS18B20_ROM_SIZE 7
#define UC_DS18B20_SCRATCHPAD_DATA_SIZE 8
#define UC_DS18B20_MAX_RETRY_COUNT 10

#define UC_DS18B20_CONVERSION_DELAY_MS 1000
#define UC_DS18B20_RETRY_DELAY_MS 20

// DS18B20 Resolution Temperature Increment
#define UC_DS18B20_TEMPERATURE_RESOLUTION_12bit_INCREMENT .0625
#define UC_DS18B20_TEMPERATURE_RESOLUTION_11bit_INCREMENT .0125
#define UC_DS18B20_TEMPERATURE_RESOLUTION_10bit_INCREMENT .25
#define UC_DS18B20_TEMPERATURE_RESOLUTION_9bit_INCREMENT .5


/******************************************************************************
* Typedefs
*******************************************************************************/
// Enum for DS18B20 Commands
typedef enum {
    UC_DS18B20_READ_ROM_COMMAND = 0x33,
    UC_DS18B20_SKIP_ROM_COMMAND = 0xCC,
    UC_DS18B20_CONVERT_COMMAND  = 0x44,
    UC_DS18B20_READ_SCRATCHPAD  = 0xBE,
}uc_ds18b20_commands_t;

// Enum for DS18B20 Resolution
typedef enum {
    UC_DS18B20_9BIT_RESOLUTION  = 0x00,
    UC_DS18B20_10BIT_RESOLUTION = 0x20,
    UC_DS18B20_11BIT_RESOLUTION = 0x40,
    UC_DS18B20_12BIT_RESOLUTION = 0x60,
}uc_ds18b20_resolution_t;


typedef enum {
    UC_DS18B20_STATUS_OK,
    UC_DS18B20_STATUS_NO_DEVICE,
    UC_DS18B20_STATUS_CRC_FAILED,
    UC_DS18B20_STATUS_TEMPERATURE_CONVERSION_FAILED,
    UC_DS18B20_ERROR_GENERIC,
    UC_DS18B20_RESOLUTION_9BIT,
    UC_DS18B20_RESOLUTION_10BIT,
    UC_DS18B20_RESOLUTION_11BIT,
    UC_DS18B20_RESOLUTION_12BIT
}uc_ds18b20_status_t;



/******************************************************************************
***** DS18B20 Interface
*******************************************************************************/
typedef struct {
  uc_ds18b20_status_t (*initialize)(void);   
  float (*read_c)(void);
  float (*read_f)(void);
  int16_t (*read_raw)(void);
  bool (*is_present)(void);
  uc_ds18b20_status_t(*get_resolution)(void);
  uc_ds18b20_status_t(*start_conversion)(void);
}uc_ds18b20_interface_t;

extern const uc_ds18b20_interface_t DS18B20;




/******************************************************************************
* Function Prototypes
*******************************************************************************/
uc_ds18b20_status_t uc_ds18b20_init(void);
uc_ds18b20_status_t uc_ds18b20_read_temperature(void);
bool uc_ds18b20_present_status(void);
float uc_ds18b20_get_temperature_c(void);
float uc_ds18b20_get_temperature_f(void);
int16_t uc_ds18b20_get_temperature_raw(void);
uc_ds18b20_status_t uc_ds18b20_return_resolution(void);

#endif /*_COREMCU_DS18B20_H*/
#endif 

/*** End of File **************************************************************/
