/****************************************************************************
* Title                 :   uCore Engine Config for I2C
* Filename              :   config_i2c.h
* Author                :   Jamie Starling
* Origin Date           :   2024/12/24
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
*   Date        Version     Author         Description 
*   2024/12/24  1.0.0       Jamie Starling  Initial Version
*  
*****************************************************************************/


/******************************************************************************
* Includes
*******************************************************************************/
#include "pic18f2xq84.h"

#ifdef UC_SYSTEM_PROCESSOR_18F2xQ84

#ifndef UC_PROCESSOR_CONFIG_I2C_H
#define UC_PROCESSOR_CONFIG_I2C_H

/******************************************************************************
***** Configuration for I2C
*******************************************************************************/
#define UC_I2C_TYPE_I2C_HW UC_SYSTEM_ENABLE
#define UC_I2C_TYPE_MSSP   UC_SYSTEM_DISABLE

#define UC_I2C_CLOCK_PIN    UC_PORTC0
#define UC_I2C_DATA_PIN     UC_PORTC1

#endif /* UC_DEVICE_CONFIG_I2C_H */
#endif /* #ifdef UC_SYSTEM_DEVICE_18F2xQ84 */
/*** End of File **************************************************************/
