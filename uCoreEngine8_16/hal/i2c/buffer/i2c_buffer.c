/****************************************************************************
* Title                 :   I2C Buffer
* Filename              :   i2c_buffer.c
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


/*************** CHANGE LOG ***************************************************
*
*    Date    Version   Author         Description 
*
*******************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "i2c_buffer.h"


uc_i2c_buffer_t i2c_0_buffer = {0};


/******************************************************************************
***** I2C Buffer Interface
*******************************************************************************/
const uc_i2c_0_buffer_interface_t I2C_0_BUFFER= { 
  .set_client_address = &uc_hal_i2c_buffer_set_client_address,
  .set_my_address = &uc_hal_i2c_buffer_set_my_address,
  .load_tx_data_byte = &uc_hal_i2c_buffer_load_tx_data_byte,
  .load_tx_data_block = &uc_hal_i2c_buffer_load_tx_data_block,
  .get_status = &uc_hal_i2c_buffer_get_status,
  .get_tx_byte_count = &uc_hal_i2c_buffer_get_tx_byte_count,
  .get_client_address = &uc_hal_i2c_buffer_get_client_address,
  .get_request_type = &uc_hal_i2c_buffer_get_request_type,
  .get_tx_byte = &uc_hal_i2c_buffer_get_data_tx_byte,
  .host_mode_mark_ready = &uc_hal_i2c_buffer_host_mode_mark_ready,
  .set_result = &uc_hal_i2c_buffer_set_result,
  .get_result = &uc_hal_i2c_buffer_get_result,
  .reset = &uc_hal_i2c_buffer_reset,
};



/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : uc_hal_i2c_buffer_set_client_address
* \b Description: Used in I2C Host Mode Only - Sets Client Address and R/W
*
* <DESCRIPTION>
*  
*******************************************************************************/
uc_return_status_t uc_hal_i2c_buffer_set_client_address (uint8_t i2c_address, uc_i2c_buffer_request_type_t request_type)
{
  if (i2c_0_buffer.status != UC_I2C_STATUS_PENDING){return UC_STATUS_FAILED;}
  i2c_0_buffer.tx_address = i2c_address;
  i2c_0_buffer.type = request_type;
  return UC_STATUS_OK;
}

/******************************************************************************
* Function : uc_hal_i2c_buffer_set_my_address
* \b Description: Used in I2C Client Mode Only - Sets local I2C Address
*
* <DESCRIPTION>
*  
*******************************************************************************/
uc_return_status_t uc_hal_i2c_buffer_set_my_address(uint8_t my_i2c_address)
{
  if (i2c_0_buffer.status != UC_I2C_STATUS_PENDING){return UC_STATUS_FAILED;}
  i2c_0_buffer.my_address = my_i2c_address;
  return UC_STATUS_OK;
}

/******************************************************************************
* Function : uc_hal_i2c_buffer_load_tx_data_byte
* \b Description: Loads a byte of data into the Client Data Buffer
* If Host mode - data is loaded here to be sent to Client
* If Client mode - data is loaded here to be sent to Host
* 
*
* <DESCRIPTION>
*  
*******************************************************************************/
uc_return_status_t uc_hal_i2c_buffer_load_tx_data_byte (uint8_t tx_data)
{
  if (i2c_0_buffer.status != UC_I2C_STATUS_PENDING){return UC_STATUS_FAILED;}
  i2c_0_buffer.data_tx[i2c_0_buffer.tx_index] = tx_data;
  i2c_0_buffer.tx_index++;
  return UC_STATUS_OK;
}

/******************************************************************************
* Function : uc_hal_i2c_buffer_host_mode_mark_ready
* \b Description: Sets the i2c buffer as ready for Host Mode
* If Host mode - Sets data is ready
*
* <DESCRIPTION>
*  
*******************************************************************************/
uc_return_status_t uc_hal_i2c_buffer_host_mode_mark_ready(void)
{
  if (i2c_0_buffer.status != UC_I2C_STATUS_PENDING){return UC_STATUS_FAILED;}
  i2c_0_buffer.status = UC_I2C_STATUS_READY;  // Mark Buffer Ready
  i2c_0_buffer.tx_data_len = (i2c_0_buffer.tx_index);
  i2c_0_buffer.tx_index = 0;
  return UC_STATUS_OK;
}

/******************************************************************************
* Function : uc_hal_i2c_buffer_reset
* \b Description: Resets the I2C Buffer
*
* <DESCRIPTION>
*  
*******************************************************************************/
void uc_hal_i2c_buffer_reset(void)
{
  i2c_0_buffer.status = UC_I2C_STATUS_PENDING;
  i2c_0_buffer.tx_index = 0;
  i2c_0_buffer.rx_index = 0;
  i2c_0_buffer.result = UC_I2C_RESULT_NONE;
}

/******************************************************************************
* Function : uc_hal_i2c_buffer_load_tx_data_block
* \b Description: Loads a block of data into the tx buffer
*
* <DESCRIPTION>
*  
*******************************************************************************/
uc_return_status_t uc_hal_i2c_buffer_load_tx_data_block(uint8_t *data_block, uint8_t block_byte_count)
{
  uc_return_status_t load_data_block_status;
  for (uint8_t block_byte_counter = 0; block_byte_counter < block_byte_count; block_byte_counter++){  
      load_data_block_status =  uc_hal_i2c_buffer_load_tx_data_byte(data_block[block_byte_counter]);
      if (load_data_block_status != UC_STATUS_OK){return UC_STATUS_FAILED;}              
    }
  return UC_STATUS_OK;  
}
 

/******************************************************************************
* Function : uc_hal_i2c_buffer_get_status
* \b Description: retuns the status of the buff
*
* <DESCRIPTION>
*  
*******************************************************************************/
uc_i2c_buffer_status_t uc_hal_i2c_buffer_get_status(void)
{
  return i2c_0_buffer.status;
}

/******************************************************************************
* Function : uc_hal_i2c_buffer_get_tx_byte_count
* \b Description: returns the value of the tx_data_len
*
* <DESCRIPTION>
*  
*******************************************************************************/
uint8_t uc_hal_i2c_buffer_get_tx_byte_count(void)
{
  return i2c_0_buffer.tx_data_len;
}

/******************************************************************************
* Function : uc_hal_i2c_buffer_get_client_address
* \b Description: returns the value of the tx_address aka the client address
*
* <DESCRIPTION>
*  
*******************************************************************************/
uint8_t uc_hal_i2c_buffer_get_client_address(void)
{
  return i2c_0_buffer.tx_address;
}

/******************************************************************************
* Function : uc_hal_i2c_buffer_get_request_type
* \b Description: returns the value of the request type
*
* <DESCRIPTION>
*  
*******************************************************************************/
uc_i2c_buffer_request_type_t uc_hal_i2c_buffer_get_request_type(void)
{
  return i2c_0_buffer.type;
  
}
/******************************************************************************
* Function : uc_hal_i2c_buffer_get_data_tx
* \b Description: returns a byte of data to be transmitted - increments the tx_index
*
* <DESCRIPTION>
*  
*******************************************************************************/
uint8_t uc_hal_i2c_buffer_get_data_tx_byte(void)
{
  uint8_t tx_data = i2c_0_buffer.data_rx[i2c_0_buffer.tx_index];
  i2c_0_buffer.tx_index++;
  return tx_data;
}

/******************************************************************************
* Function : uc_hal_i2c_buffer_set_result
* \b Description: Sets the Result of the last tried transmission
*
* <DESCRIPTION>
*  
*******************************************************************************/
void uc_hal_i2c_buffer_set_result(uc_i2c_buffer_result_t result_status)
{
    i2c_0_buffer.result = result_status;
}

/******************************************************************************
* Function : uc_hal_i2c_buffer_get_result
* \b Description: Sets the Result of the last tried transmission
*
* <DESCRIPTION>
*  
*******************************************************************************/
uc_i2c_buffer_result_t uc_hal_i2c_buffer_get_result(void)
{
    return i2c_0_buffer.result;
}
/*** End of File **************************************************************/
