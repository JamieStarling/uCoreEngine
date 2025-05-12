/****************************************************************************
* Title                 :   uCore Engine GPIO Configuration
* Filename              :   config_gpio.c
* Author                :   Jamie Starling
* Origin Date           :   2025/02/06
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

/*************** CHANGE LOG ***************************************************
*
*    Date    Version   Author         Description 
*
*******************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "config_gpio.h"

/******************************************************************************
* Constants
*******************************************************************************/

#ifdef UC_SYSTEM_PROCESSOR_16F1532X
#if UC_PROCESSOR_HAL_GPIO_CONFIG

/*GPIO Configuration Table */
/* port_pin, mode, Initial pin_value */

const uc_hal_gpio_config_t uc_gpio_config[]=
{        
    {UC_PORTA0, UC_OUTPUT, UC_LOW},
    {UC_PORTA1, UC_OUTPUT, UC_LOW},
    {UC_PORTA2, UC_OUTPUT, UC_LOW},
    {UC_PORTA3, UC_INPUT, UC_NA},    
    {UC_PORTA4, UC_OUTPUT, UC_LOW},
    {UC_PORTA5, UC_OUTPUT, UC_LOW},
};

#endif //UC_DEVICE_HAL_GPIO_CONFIG
#endif //#ifdef UC_SYSTEM_DEVICE_16F15313
/*** End of File **************************************************************/
