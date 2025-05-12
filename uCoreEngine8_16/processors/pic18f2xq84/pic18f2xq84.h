/****************************************************************************
* Title                 :   uCore Engine Header for PIC18F2xQ84 Devices
* Filename              :   pic18f2xq84.h
* Author                :   Jamie Starling
* Origin Date           :   24/12/26
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
#include "../processors.h"

#ifdef UC_SYSTEM_PROCESSOR_18F2xQ84

#ifndef _UC_PROCESSOR_PIC18F2xQ84_H
#define _UC_PROCESSOR_PIC18F2xQ84_H

/*Sets the Pointer Register Size - Set accordingly depending on target CPU*/
#define UC_POINTER_REGISTER_SIZE uint8_t

/******************************************************************************
*******************************************************************************
* Processor HAL Configuration 
*******************************************************************************
*******************************************************************************/

/***** ISR Options **************************************************/
#define UC_PROCESSOR_HAL_ISR           UC_SYSTEM_ENABLE
#define UC_ISR_BASE_ADDRESS 0x000008
#define UC_ENABLE_LOW_PRIORITY_INTERRUPTS UC_TRUE
#define UC_ENABLE_INTERRUPT_PRIORITY UC_FALSE 
#define UC_PROCESSOR_VECTOR_ISR UC_TRUE
#define UC_ISR_MAX_VECTORS 118  

/***** WatchDog Timer Enable **************************************************/
#define UC_PROCESSOR_HAL_WATCHDOG      UC_SYSTEM_DISABLE   

/***** PPS Enable **************************************************/
#define UC_PROCESSOR_HAL_PPS           UC_SYSTEM_ENABLE

/***** GPIO **************************************************/
#define UC_PROCESSOR_HAL_GPIO_CONFIG   UC_SYSTEM_DISABLE    /* GPIO to Be Set Through Lookup Table */
#define UC_PROCESSOR_HAL_ADC           UC_SYSTEM_DISABLE    /* Analog Features */

/***** Device Timers **************************************************/
#define UC_PROCESSOR_HAL_TMR0          UC_SYSTEM_DISABLE    /* Timer 0 */
#define UC_PROCESSOR_HAL_TMR1          UC_SYSTEM_DISABLE    /* Timer 1 */
#define UC_PROCESSOR_HAL_TMR2          UC_SYSTEM_DISABLE    /* Timer 2 */

/***** UART **************************************************/
#define UC_PROCESSOR_HAL_UART_0        UC_SYSTEM_DISABLE    

/***** PWM **************************************************/
#define UC_PROCESSOR_HAL_PWM_TIMER     UC_SYSTEM_DISABLE
#define UC_PROCESSOR_HAL_PWM3          UC_SYSTEM_DISABLE
#define UC_PROCESSOR_HAL_PWM4          UC_SYSTEM_DISABLE
#define UC_PROCESSOR_HAL_PWM5          UC_SYSTEM_DISABLE
#define UC_PROCESSOR_HAL_PWM6          UC_SYSTEM_DISABLE

/***** I2C **************************************************/
#define UC_PROCESSOR_HAL_I2C_HOST      UC_SYSTEM_ENABLE
#define UC_PROCESSOR_HAL_I2C_CLIENT    UC_SYSTEM_DISABLE

/***** One Wire **************************************************/
#define UC_PROCESSOR_HAL_OW            UC_SYSTEM_DISABLE


/***** XTAL_FREQ **************************************************/
/*Used to calculate the delay time - Change depending on processor Speed*/
#define _XTAL_FREQ 64000000UL 

/**** EEPROM CONFIG **************************************************/
#define UC_SYSTEM_DEVICE_EEPROM_SIZE 1024
#define UC_SYSTEM_DEVICE_EEPROM_ADDRESS_START 0x380000

/******************************************************************************
* Interrupt State Status
*******************************************************************************/
typedef enum
{
  UC_MAIN_RUNNING = 0b00,
  UC_LOW_ISR_RUNNING = 0b01,
  UC_HIGH_ISR_RUNNING = 0b10,
  UC_BOTH_ISR_RUNNING = 0b11  
}uc_isr_interrupt_state_t;

/******************************************************************************
*******************************************************************************
* Include Files for Processor Configuration
*******************************************************************************
*******************************************************************************/

#include "LU_gpio.h"        // Lookup table for GPIO


#if UC_PROCESSOR_HAL_PPS
    #include "LU_pps.h"         // Lookup table for PPS 
#endif

#if UC_PROCESSOR_HAL_GPIO_CONFIG
    #include "config_gpio.h" // Include GPIO Config if required
#endif
    
#if UC_PROCESSOR_HAL_ADC
    #include "LU_adc.h"  // Include Analog Config if required
#endif

#if (UC_PROCESSOR_HAL_TMR0 || UC_SYSTEM_TIMER)
    #include "LU_tmr0.h"       // Lookup table for TMR0 
#endif    

#if UC_PROCESSOR_HAL_TMR1
    #include "LU_tmr1.h"  // Lookup table for TMR1 
#endif

#if (UC_PROCESSOR_HAL_TMR2 || UC_PROCESSOR_HAL_PWM_TIMER)
    #include "LU_tmr2.h"  // Lookup table for TMR1 
#endif

#if UC_PROCESSOR_HAL_PWM_TIMER
    #include "config_pwm.h"
#endif

#if UC_PROCESSOR_HAL_UART_0
    #include "config_uart.h"
#endif

#if UC_PROCESSOR_HAL_OW
    #include "config_1wire.h"
#endif

#if (UC_PROCESSOR_HAL_I2C_HOST || UC_PROCESSOR_HAL_I2C_CLIENT)
    #include "config_i2c.h"
#endif



#endif /*UC_DEVICE_PIC18F2xQ84_H*/
#endif /* #ifdef UC_SYSTEM_DEVICE_18F2xQ84 */
/*** End of File **************************************************************/
