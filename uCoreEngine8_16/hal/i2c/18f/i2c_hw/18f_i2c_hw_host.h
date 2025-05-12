/****************************************************************************
* Title                 :   Host 18F MCU I2C HAL For MCUs that have a Hardware I2C Device
* Filename              :   18f_i2c_hw_host.h
* Author                :   %<%USER%>%
* Origin Date           :   %<%DATE%>%, %<%TIME%>%
* Version               :   1.0.0
* Compiler              :   
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
#include "../../i2c.h"
#include "../../buffer/i2c_buffer.h"

#ifndef _UC_HAL_18F_I2C_HW_H
#define _UC_HAL_18F_I2C_HW_H

#if (UC_UCORE_MCU_18F && UC_I2C_TYPE_I2C_HW)

/******************************************************************************
* Function Prototypes
*******************************************************************************/
void uc_hal_i2c_host_init(void);
void uc_hal_i2c_host_reset(void);
uc_return_status_t uc_hal_i2c_host_load_data(uint8_t address, uc_i2c_buffer_request_type_t mode, uint8_t *data_block, uint8_t block_byte_count, uc_logic_t send_on_complete);
uc_return_status_t uc_hal_i2c_host_start_transfer(void);
uc_i2c_state_t uc_hal_i2c_host_get_status(void);
void uc_hal_i2c_host_set_status(uc_i2c_state_t i2c_host_set_status);
void uc_hal_i2c_host_isr_load_data(void);
void uc_hal_i2c_host_isr(void);
void uc_hal_i2c_host_check_nack_address(void);

#endif /*_H_*/
#endif

/*** End of File **************************************************************/
