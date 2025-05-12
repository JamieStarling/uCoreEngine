/****************************************************************************
* Title                 :   I2C Platform Chooser
* Filename              :   i2c.h
* Author                :   Jamie Starling
* Origin Date           :   2025/01/04
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
*****************************************************************************/

#ifndef _UC_HAL_I2C_H
#define _UC_HAL_I2C_H
/******************************************************************************
* Includes
*******************************************************************************/

#include "../hal.h"

#if UC_PROCESSOR_HAL_I2C_ENABLE

#include "buffer/i2c_buffer.h"

typedef enum {
    UC_I2C_STATE_IDLE,
    UC_I2C_STATE_START,
    UC_I2C_STATE_SEND_ADDR,
    UC_I2C_STATE_SEND_DATA,
    UC_I2C_STATE_RECEIVE_DATA,
    UC_I2C_STATE_STOP,    
    UC_I2C_STATE_ERROR
} uc_i2c_state_t;


/******************************************************************************
***** I2C Host Interface
*******************************************************************************/
typedef struct {
  void (*initialize)(void);  
  void (*reset)(void);   
  uc_return_status_t (*load_data)(uint8_t address, uc_i2c_buffer_request_type_t mode, uint8_t *data_block, uint8_t block_byte_count, uc_logic_t send_on_complete);
  uc_i2c_state_t (*status)(void);
  uc_i2c_buffer_status_t (*buffer_status)(void);
  uc_i2c_buffer_result_t (*buffer_result)(void);
  void (*reset_buffer)(void);
  
}uc_hal_I2C_host_interface_t;

extern const uc_hal_I2C_host_interface_t I2C_HOST;

/******************************************************************************
***** I2C Client Interface
*******************************************************************************/
typedef struct {
  void (*initialize)(void);    
}uc_hal_I2C_client_interface_t;

extern const uc_hal_I2C_client_interface_t I2C_CLIENT;



#if UC_UCORE_MCU_16F /*16F Devices*/        
#endif

#if (UC_UCORE_MCU_18F && UC_I2C_TYPE_I2C_HW)/*18F Devices*/        
    #include "18f/i2c_hw/18f_i2c_hw_host.h"
#endif


#endif /*UC_I2C_H*/
#endif

/*** End of File **************************************************************/
