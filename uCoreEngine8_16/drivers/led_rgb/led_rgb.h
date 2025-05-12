/****************************************************************************
* Title                 :   RGB LED Driver (4 Pin LEDs)
* Filename              :   led_rgb.h
* Author                :   Jamie Starling
* Origin Date           :   2024/04/26
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


/******************************************************************************
* Includes
*******************************************************************************/
#include "../uc_drivers.h"

#if UC_DRIVER_LED_RGB

#ifndef UC_DRIVER_RGB_LED_H
#define UC_DRIVER_RGB_LED_H

/******************************************************************************
***** RGB_LED Interface
*******************************************************************************/
typedef struct {
  void (*initialize)(void);
  void (*write_color_value)(uint8_t red,uint8_t blue,uint8_t green);
  void (*write_color_name)(uc_rgb_driver_led_color_names_t color_name); 
}uc_rgb_led_driver_interface_t;

extern const uc_rgb_led_driver_interface_t RGB_LED_DRIVER;








/******************************************************************************
* Configuration
*******************************************************************************/

#define LED_RGB_RED_PWM_CHANNEL_PIN PORTA_0
#define LED_RGB_GREEN_PWM_CHANNEL_PIN PORTA_1
#define LED_RGB_BLUE_PWM_CHANNEL_PIN PORTA_2

#define LED_RGB_RED_PWM_CHANNEL_INIT PWM3_Init
#define LED_RGB_GREEN_PWM_CHANNEL_INIT PWM4_Init
#define LED_RGB_BLUE_PWM_CHANNEL_INIT PWM5_Init

#define LED_RGB_RED_PWM_DUTYSET PWM3_set_dutycycle
#define LED_RGB_GREEN_PWM_DUTYSET PWM4_set_dutycycle
#define LED_RGB_BLUE_PWM_DUTYSET PWM5_set_dutycycle


typedef struct
{
    uint8_t RedValue; 
    uint8_t GreenValue; 
    uint8_t BlueValue; 
}uc_rgb_driver_led_color_config_t;

typedef enum
{
    UC_RGB_COLOR_OFF,
    UC_RGB_COLOR_RED,
    UC_RGB_COLOR_GREEN,
    RGB_COLOR_BLUE,
}uc_rgb_driver_led_color_names_t;


const uc_rgb_driver_led_color_config_t RGB_LED_COLOR[]=
{        
    {0,0,0},
    {255,0,0},
    {0,255,0},
    {0,0,255},
};


/******************************************************************************
* Function Prototypes
*******************************************************************************/

void uc_rgb_led_init(void);
void uc_rgb_led_write_color_value(uint8_t red,uint8_t blue,uint8_t green);
void uc_rgb_led_write_color_name(uc_rgb_driver_led_color_names_t color_name);

#endif /*_DRIVER_RGB_LED_H*/
#endif
/*** End of File **************************************************************/
