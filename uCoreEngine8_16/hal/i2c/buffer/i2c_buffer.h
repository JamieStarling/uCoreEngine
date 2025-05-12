/****************************************************************************
* Title                 :   I2C Buffer
* Filename              :   i2c_buffer.h
* Author                :   Jamie Starling
* Origin Date           :   2025/05/09
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
#include "../i2c.h"

#ifndef _UC_I2C_HAL_BUFFER_H
#define _UC_I2C_HAL_BUFFER_H


/******************************************************************************
***** I2C Buffer 
*******************************************************************************/
#define UC_I2C_TX_BUFFER_MAX_DATA_SIZE 8
#define UC_I2C_RX_BUFFER_MAX_DATA_SIZE 8

typedef enum {
    UC_I2C_WRITE_ONLY,
    UC_I2C_READ_ONLY,
    UC_I2C_WRITE_THEN_READ
} uc_i2c_buffer_request_type_t;

typedef enum {  
  UC_I2C_STATUS_PENDING,
  UC_I2C_STATUS_READY,
  UC_I2C_STATUS_IN_PROGRESS,
  UC_I2C_STATUS_DONE,
  UC_I2C_STATUS_ERROR
} uc_i2c_buffer_status_t;

typedef enum {
    UC_I2C_RESULT_NONE,
    UC_I2C_RESULT_SUCCESS,
    UC_I2C_RESULT_INVALID_ADDRESS,
    UC_I2C_RESULT_NACK,
    UC_I2C_RESULT_ARBITRATION_LOST,
    UC_I2C_RESULT_TIMEOUT,    
    UC_I2C_RESULT_BUS_ERROR,
    UC_I2C_RESULT_UNKNOWN_ERROR
} uc_i2c_buffer_result_t;

typedef struct {
    uc_i2c_buffer_request_type_t type;
    uint8_t tx_address;                                 //Address we Transmit to 
    uint8_t data_tx[UC_I2C_TX_BUFFER_MAX_DATA_SIZE];    //Data to be Sent
    uint8_t data_rx[UC_I2C_RX_BUFFER_MAX_DATA_SIZE];    //Received Data
    uint8_t tx_data_len;
    uint8_t rx_data_len;
    uint8_t tx_index;       
    uint8_t rx_index;
    uc_i2c_buffer_status_t status;
    uint8_t my_address;                                //Used in Client Mode - Local I2C Address
    uc_i2c_buffer_result_t result;
} uc_i2c_buffer_t;



/******************************************************************************
* Function Prototypes
*******************************************************************************/
uc_return_status_t uc_hal_i2c_buffer_set_client_address (uint8_t i2c_address, uc_i2c_buffer_request_type_t request_type);
uc_return_status_t uc_hal_i2c_buffer_set_my_address(uint8_t my_i2c_address);
uc_return_status_t uc_hal_i2c_buffer_load_tx_data_byte (uint8_t tx_data);
uc_return_status_t uc_hal_i2c_buffer_host_mode_mark_ready(void);
void uc_hal_i2c_buffer_reset(void);
uc_return_status_t uc_hal_i2c_buffer_load_tx_data_block(uint8_t *data_block, uint8_t block_byte_count);
uc_i2c_buffer_status_t uc_hal_i2c_buffer_get_status(void);
uint8_t uc_hal_i2c_buffer_get_tx_byte_count(void);
uint8_t uc_hal_i2c_buffer_get_client_address(void);
uc_i2c_buffer_request_type_t uc_hal_i2c_buffer_get_request_type(void);
uint8_t uc_hal_i2c_buffer_get_data_tx_byte(void);
void uc_hal_i2c_buffer_set_result(uc_i2c_buffer_result_t result_status);
uc_i2c_buffer_result_t uc_hal_i2c_buffer_get_result(void);
uc_return_status_t uc_hal_i2c_buffer_host_mode_mark_in_progress(void);
uc_return_status_t uc_hal_i2c_buffer_host_mode_mark_done(void);
uc_return_status_t uc_hal_i2c_buffer_load_rx_data_byte (uint8_t rx_data);
#endif /*_H_*/

/*** End of File **************************************************************/
