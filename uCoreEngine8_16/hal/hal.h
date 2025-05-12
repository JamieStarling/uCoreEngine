/****************************************************************************
* Title                 :   uCore HAL Include Functions
* Filename              :   hal.h
* Author                :   Jamie Starling
* Origin Date           :   2025/01/13
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
*****************************************************************************/


/******************************************************************************
* Includes
*******************************************************************************/
#include "../ucore8-16.h"

#ifndef _UC_HAL_INCLUDE_H
#define _UC_HAL_INCLUDE_H


/******************************************************************************
********* Start of Core MCU System HAL Includes - Default/Required
*******************************************************************************/
#include "gpio/gpio.h"          //Include GPIO Functions


/******************************************************************************
********* Includes - Based on Device Hal Configuration And Framework Features
*******************************************************************************/

/******************************************************************************
* ISR
*******************************************************************************/
#if UC_PROCESSOR_HAL_ISR
    #include "isr/isr.h"
#endif

/******************************************************************************
* PPS Functions
*******************************************************************************/
#if UC_PROCESSOR_HAL_PPS
    #include "pps/pps.h"           
#endif


/******************************************************************************
* Analog Digital Conversion
*******************************************************************************/
#if UC_PROCESSOR_HAL_ADC
    #include "adc/adc.h"
#endif


/******************************************************************************
* Timers
*******************************************************************************/


/**** Timer 0                               *****************************/
#if (UC_PROCESSOR_HAL_TMR0 || UC_SYSTEM_TIMER )
    #include "tmr0/tmr0.h"
#endif


/* Timer 1 ***/
#if UC_PROCESSOR_HAL_TMR1                                     
    #include "tmr1/tmr1.h"
#endif

/* Timer 2 ***/
#if (UC_PROCESSOR_HAL_TMR2 || UC_PROCESSOR_HAL_PWM_TIMER)         
    #include "tmr2/tmr2.h"
#endif


/******************************************************************************
* PWM
*******************************************************************************/
#if (UC_PROCESSOR_HAL_PWM3 || UC_PROCESSOR_HAL_PWM4 || UC_PROCESSOR_HAL_PWM5 || UC_PROCESSOR_HAL_PWM6)
    #include "pwm/pwm.h"
#endif 

/******************************************************************************
* UART
*******************************************************************************/
#if UC_PROCESSOR_HAL_UART_0                                 
    #include "uart0/uart0.h"
#endif

/******************************************************************************
* NCO
*******************************************************************************/
#if UC_PROCESSOR_HAL_NCO                                    
    #include "/nco/nco.h"
#endif

/******************************************************************************
* One Wire
*******************************************************************************/
#if UC_PROCESSOR_HAL_OW                                
    #include "sw_one_wire/one_wire.h"
#endif

 /******************************************************************************
* I2C
*******************************************************************************/
#if (UC_PROCESSOR_HAL_I2C_HOST ||  UC_PROCESSOR_HAL_I2C_CLIENT)
    #include "i2c/i2c.h"
#endif

/******************************************************************************
* Watchdog Timer
*******************************************************************************/
#if UC_PROCESSOR_HAL_WATCHDOG
    #include "wdt/wdt.h"
#endif

/******************************************************************************
* EEPROM
*******************************************************************************/
#if UC_PROCESSOR_HAL_EEPROM
    #include "eeprom/eeprom.h"
#endif


#endif /*_H_*/

/*** End of File **************************************************************/
