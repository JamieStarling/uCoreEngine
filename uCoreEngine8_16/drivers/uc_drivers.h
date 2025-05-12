/****************************************************************************
* Title                 :   uCore Engine Driver Include Header
* Filename              :   uc_drivers.h
* Author                :   Jamie Starling
* Origin Date           :   2024/12/26
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
*   Date        Version     Author          Description 
*   2024/12/26  1.0.0       Jamie Starling  Initial Version
*  
*****************************************************************************/


/******************************************************************************
* Includes
*******************************************************************************/
#include "../ucore8-16.h"

#ifndef UC_DRIVERS_H
#define UC_DRIVERS_H

/******************************************************************************
* Driver Enable/Disable
*******************************************************************************/

#define UC_DRIVER_LCD_I2C   UC_SYSTEM_DISABLE
#define UC_DRIVER_DS18B20   UC_SYSTEM_DISABLE
#define UC_DRIVER_LED_RGB   UC_SYSTEM_DISABLE



/******************************************************************************
* Driver Include / Based on Enable - Disable
*******************************************************************************/

#if UC_DRIVER_LCD_I2C
    #include "lcd_i2c/lcd_i2c.h"
#endif

#if UC_DRIVER_DS18B20
    #include "ds18b20/ds18b20.h"
#endif

#if UC_DRIVER_LED_RGB
    #include "led_rgb/led_rgb.h"
#endif


#endif /* UC_DRIVERS_H */

/*** End of File **************************************************************/
