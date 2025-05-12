/****************************************************************************
* Title                 :   16F Analog Functions
* Filename              :   16f_adc.c
* Author                :   Jamie Starling
* Origin Date           :   2025/01/05
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
*   2025/01/05  1.0.0       Jamie Starling  Initial Version
*  
*
*****************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "16f_adc.h"

#if (UC_UCORE_MCU_16F && UC_PROCESSOR_HAL_ADC)


/******************************************************************************
***** Analog Interface
*******************************************************************************/
const uc_hal_analog_interface_t ANALOG = {
  .initialize = &uc_hal_adc_init,
  .select_channel = &uc_hal_adc_select_channel,
  .set_pin_analog = &uc_hal_adc_set_pin_analog,
  .read_channel =  &uc_hal_adc_read_channel
};

/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : uc_hal_adc_init()
* Description: Initializes the ADC for a specified analog channel, sets the conversion 
* clock based on the system clock, and enables the ADC module.
*
* Parameters:
*   - Channel (uc_adc_channels_t): The analog channel to initialize 
*     (e.g., UC_ANA0, UC_ANA1).

*******************************************************************************/
void uc_hal_adc_init(uc_adc_channels_t channel)
{
    //ADC Conversion Clock Select bits  - 
    #if _XTAL_FREQ == 1000000    
    ADCON1bits.ADCS = 0b00000000;       //1 MHz 2.0us FOSC/2    
    #elif _XTAL_FREQ == 2000000    
    ADCON1bits.ADCS = 0b00000100;       //2 MHz 2.0us FOSC/4    
    #elif _XTAL_FREQ == 4000000    
    //ADCON1bits.ADCS = 0b00000100;     //4 MHz 1.0us FOSC/4    
    ADCON1bits.ADCS = 0b00000001;       //4 MHz 2.0us FOSC/8  
    #elif _XTAL_FREQ == 8000000
    //ADCON1bits.ADCS = 0b00000001;     //8 MHz 1.0us FOSC/8
    ADCON1bits.ADCS = 0b00000101;       //8 MHz 2.0us FOSC/16 
    #elif _XTAL_FREQ == 16000000
     //ADCON1bits.ADCS = 0b00000101;    //16 MHz 1.0us FOSC/16
    ADCON1bits.ADCS = 0b00000010;       //16 MHz 2.0us FOSC/32
    #elif _XTAL_FREQ == 20000000    
    //ADCON1bits.ADCS = 0b00000010;     //20 MHz 1.6us FOSC/32
    ADCON1bits.ADCS = 0b00000110;       //20 MHz 3.2us FOSC/64
    #elif _XTAL_FREQ == 32000000
    //ADCON1bits.ADCS = 0b00000010;     //32 MHz 1.0us FOSC/32
    ADCON1bits.ADCS = 0b00000110;       //32 MHz 2.0us FOSC/64  
    #else
    #error "Unsupported _XTAL_FREQ value for Analog Conversion. Please check the frequency settings."
    #endif
    
   //Set Channel - 
   ADCON0bits.CHS = channel;
   ADCON1bits.ADFM = 1; //ADRESH holds the High Value
           
   ADCON0bits.ADON = 1;
}

/******************************************************************************
* Function : uc_hal_adc_select_channel()
* Description:Selects an analog channel for ADC conversions by setting the channel select 
*   bits (CHS) in the ADCON0 register.
*
* Parameters:
*   - Channel (uc_adc_channels_t): The analog channel to select 
*     (e.g., UC_ANA0, UC_ANA1).

*******************************************************************************/
void uc_hal_adc_select_channel(uc_adc_channels_t channel)
{
    ADCON0bits.CHS = channel;    
}

/******************************************************************************
* Function : uc_hal_adc_set_pin_analog()
* Description:Configures a GPIO pin for analog input and initializes the ADC with the 
* specified analog channel.
*
* Parameters:
*   - port_pin (uc_gpio_portpins_t): The GPIO pin to configure (e.g., PORTA_0, PORTC_1).
*   - channel (uc_adc_channels_t): The analog channel to associate with 
*     the pin (e.g., UC_ANA0, UC_ANA1).
*******************************************************************************/
void uc_hal_adc_set_pin_analog(uc_gpio_portpins_t port_pin, uc_adc_channels_t channel)
{   
   GPIO.mode(port_pin,UC_ANALOG);
   uc_hal_adc_init(channel);
}

/******************************************************************************
* Function : uc_hal_adc_read_channel()
* Description:Starts an ADC conversion on the selected channel, waits for it to complete, 
* and returns the 10-bit conversion result.
*
* Parameters:
*   - None
*
* Returns:
*   - uint16_t: The 10-bit ADC conversion result.
*******************************************************************************/
uint16_t uc_hal_adc_read_channel(void)
{
   uint16_t adc_result; 
   ADCON0bits.GOnDONE = 1;  //Start the conversion
    
   while (ADCON0bits.GOnDONE == 1){}   
       
   adc_result = UC_UTILS.make_16(ADRESH,ADRESL);    
   return adc_result;    //Verify that this returns 10bit result    
}

#endif /* #if UC_DEVICE_HAL_ADC */

/*** End of File **************************************************************/
