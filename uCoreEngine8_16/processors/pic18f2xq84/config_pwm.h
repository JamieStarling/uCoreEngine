/****************************************************************************
* Title                 :   uCore Engine PWM Configuration 
* Filename              :   config_pwm.h
* Author                :   Jamie Starling
* Origin Date           :   2024/12/23
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
*   2024/12/23  1.0.0       Jamie Starling  Initial Version
*  
*
*****************************************************************************/


/******************************************************************************
* Includes
*******************************************************************************/
#include "pic18f2xq84.h"

#ifdef UC_SYSTEM_PROCESSOR_18F2xQ84

#ifndef UC_CONFIG_PROCERSSOR_PWM_H
#define UC_CONFIG_PROCERSSOR_PWM_H

/******************************************************************************
***** Configuration for PWM
*******************************************************************************/

/******************************************************************************
* PWM LU  
******************************************************************************/
typedef enum
{
    UC_8bit_PWM,
    UC_10bit_PWM 
}uc_hal_pwm_configuration_t;

/******************************************************************************
*PWM Configuration Structure
* This structure defines the settings for PWM, including the period register value and prescale setting.
******************************************************************************/
typedef struct
{
    uint8_t PR2_Value; 
    uint8_t T2_Prescale_Value; 
}uc_hal_pwm_settings_t;

/******************************************************************************
* PWM Configuration Table
* This table defines the settings for PWM, including the period register value and prescale setting.
 ******************************************************************************/
/*Config for 32Mhz*/
#if _XTAL_FREQ == 32000000
const uc_hal_pwm_settings_t uc_hal_pwm_settings[]=
{        
    {65,0b00},  //32Mhz 8bit PWM
    {255,0b00}   //32Mhz 10bit PWM
};
#endif


#endif /* UC_CONFIG_DEVICE_PWM_H */
#endif /* #ifdef UC_SYSTEM_DEVICE_16F1532X */
/*** End of File **************************************************************/
