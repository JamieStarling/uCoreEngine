/****************************************************************************
* Title                 :   ADC Hal Platform Chooser
* Filename              :   adc.h
* Author                :   Jamie Starling
* Origin Date           :   2025/01/05
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
#ifndef _UC_HAL_ADC_H
#define _UC_HAL_ADC_H

/******************************************************************************
* Includes
*******************************************************************************/
#include "../hal.h"

#if UC_PROCESSOR_HAL_ADC

/******************************************************************************
***** Analog Interface
*******************************************************************************/
typedef struct {
  void (*initialize)(uc_adc_channels_t channel);   
  void (*select_channel)(uc_adc_channels_t channel);
  void (*set_pin_analog)(uc_gpio_portpins_t port_pin, uc_adc_channels_t channel);
  uint16_t (*read_channel)(void);
}uc_hal_analog_interface_t;

extern const uc_hal_analog_interface_t ANALOG;


#if UC_UCORE_MCU_16F /*16F Devices*/        
    #include "16f/16f_adc.h"       
#endif

#if UC_UCORE_MCU_18F /*18F Devices*/       
    #include "18f/18f_adc.h"
#endif

#endif /*UC_HAL_ADC_H*/
#endif

/*** End of File **************************************************************/
