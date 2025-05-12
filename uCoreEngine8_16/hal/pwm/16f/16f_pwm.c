/****************************************************************************
* Title                 :   uCore Engine PWM3 Functions
* Filename              :   pwm3.c
* Author                :   Jamie Starling
* Origin Date           :   2024/12/23
* Version               :   1.0.0
* Compiler              :   XC8
* Target                :   Microchip PIC16F series 
* Copyright             :   © 2024 Jamie Starling
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
*   2024/12/23  1.0.0       Jamie Starling  Initial Version
*  
*
*****************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "16f_pwm.h"

#if UC_UCORE_MCU_16F

/******************************************************************************
***** PWM3 Interface
*******************************************************************************/
#if UC_PROCESSOR_HAL_PWM3
const uc_hal_pwm3_interface_t PWM3 = {
  .initialize = &uc_hal_pwm3_init,
  .output = &uc_hal_pwm3_output_enable,
  .set_duty_cycle = &uc_hal_pwm3_set_duty_cycle  
};
#endif

/******************************************************************************
***** PWM4 Interface
*******************************************************************************/
#if UC_PROCESSOR_HAL_PWM4
const uc_hal_pwm4_interface_t PWM4 = {
  .initialize = &uc_hal_pwm4_init,
  .output = &uc_hal_pwm4_output_enable,
  .set_duty_cycle = &uc_hal_pwm4_set_duty_cycle  
};
#endif

/******************************************************************************
***** PWM5 Interface
*******************************************************************************/
#if UC_PROCESSOR_HAL_PWM5
const uc_hal_pwm5_interface_t PWM5 = {
  .initialize = &uc_hal_pwm5_init,
  .output = &uc_hal_pwm5_output_enable,
  .set_duty_cycle = &uc_hal_pwm5_set_duty_cycle  
};
#endif

/******************************************************************************
***** PWM6 Interface
*******************************************************************************/
#if UC_PROCESSOR_HAL_PWM6
const uc_hal_pwm5_interface_t PWM6 = {
  .initialize = &uc_hal_pwm6_init,
  .output = &uc_hal_pwm6_output_enable,
  .set_duty_cycle = &uc_hal_pwm6_set_duty_cycle  
};
#endif

/******************************************************************************
* Functions PWM3
*******************************************************************************/
#if UC_PROCESSOR_HAL_PWM3
/******************************************************************************
* Function : uc_hal_pwm3_init()
* Description: Initializes the PWM3 module on the specified GPIO pin for Pulse Width Modulation (PWM) output.
*
*******************************************************************************/
void uc_hal_pwm3_init(uc_gpio_portpins_t port_pin,uc_hal_pwm_configuration_t pwm_config_select)
{     
  PPS.map_output(port_pin,UC_PPSOUT_PWM3OUT);
  
  PR2 = uc_hal_pwm_settings[pwm_config_select].PR2_Value;
  TIMER2.set_clock_source(UC_TMR2_FOSC_D4); // Set Timer2 clock source to FOSC/4
  TIMER2.set_prescaler_rate(uc_hal_pwm_settings[pwm_config_select].T2_Prescale_Value);  // Set Timer2 prescaler
  TIMER2.enable(UC_ENABLED);  // Enable Timer2
   
  PWM3CONbits.PWM3OUT = 0x01;  // Enable PWM output
  PWM3CONbits.PWM3EN = 0x01;  // Enable PWM       
}

/******************************************************************************
* Function : uc_hal_pwm3_output_enable()
* Description:Enables or disables the PWM3 output on the selected GPIO pin by modifying 
*   the PWM3 output enable bit.
*
* Parameters:
*   - set_state (uc_logic_t): UC_ENABLED to enable the output, UC_DISABLED to disable it.
*
* 
*******************************************************************************/
void uc_hal_pwm3_output_enable(uc_logic_t set_state)
{
  PWM3CONbits.PWM3OUT = (set_state == UC_ENABLED) ? 0x01 : 0x00;  
}


/******************************************************************************
* Function : uc_hal_pwm3_set_duty_cycle()
* Description: Description:
*   Sets the duty cycle for the PWM3 output by writing a 10-bit value to the 
*   duty cycle registers (PWM3DCL and PWM3DCH).
*
* Parameters:
*   - duty_value (uint16_t): The 10-bit duty cycle value, where 0 represents 0% 
*     duty cycle and the maximum value represents 100% duty cycle.
*
*******************************************************************************/
void uc_hal_pwm3_set_duty_cycle(uint16_t duty_value)
{
    //2 LSB's of dutyValue
    PWM3DCL = (uint8_t)(duty_value << 6);
    //8 MSB's of dutyValue
    PWM3DCH = (uint8_t)(duty_value >> 2);
    
}
#endif /*#if UC_PROCESSOR_HAL_PWM3 */



#endif /* #if UC_UCORE_MCU_16F */
/*** End of File **************************************************************/
