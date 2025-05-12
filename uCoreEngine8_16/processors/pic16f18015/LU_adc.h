/****************************************************************************
* Title                 :   uCore Engine Analog Lookup
* Filename              :   LU_adc.h
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
*   Date        Version     Author          Description 
*   2024/12/23  1.0.0       Jamie Starling  Initial Version
*  
*****************************************************************************/


/******************************************************************************
* Includes
*******************************************************************************/
#include "pic16f18015.h"

#ifdef UC_SYSTEM_PROCESSOR_16F18015

#ifndef _UC_PROCESSOR_ADC_LU_H
#define _UC_PROCESSOR_ADC_LU_H

/******************************************************************************
*Analog Channel Select Enum -  This enum defines the analog channels available for selection on the device.
*******************************************************************************/
typedef enum
{
    UC_ANA0 = 0b000000,			    
    UC_ANA1 = 0b000001, 
    UC_ANA2 = 0b000010,
    UC_ANA3 = 0b000011,
    UC_ANA4 = 0b000100,
    UC_ANA5 = 0b000101,
    UC_AVSS = 0b111011,
    UC_TEMPERATURE_SENSOR = 0b111100,
    UC_DAC1_OUTPUT = 0b111101,
    UC_FVR_BUFFER1 = 0b111110,
    UC_FVR_BUFFER2 = 0b111111,
}uc_adc_channels_t;



#endif /* UC_DEVICE_ADC_LU_H*/
#endif /* #ifdef UC_SYSTEM_DEVICE_16F15313 */
/*** End of File **************************************************************/
