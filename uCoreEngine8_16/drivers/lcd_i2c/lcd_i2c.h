/****************************************************************************
* Title                 :   uCore LCD I2C Drivers
* Filename              :   lcd_i2c.h
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
*    Date    Version   Author         Description 
*    2024/12/26  1.0.0       Jamie Starling  Initial Version
*  
*****************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "../uc_drivers.h"

#if UC_DRIVER_LCD_I2C

#ifndef UC_DRIVERS_LCD_I2C_H
#define UC_DRIVERS_LCD_I2C_H

/******************************************************************************
* Constants
*******************************************************************************/
#define UC_LCD_RS_CMD 0 
#define UC_LCD_RS_DATA 1 
#define UC_LCD_CMD_4BIT_MODE_1 0b00110011
#define UC_LCD_CMD_4BIT_MODE_2 0b00110010
#define UC_LCD_CMD_SET_FUNCTION 0b00101000
#define UC_LCD_CMD_SET_DISPLAY 0b00001110
#define UC_LCD_CMD_CLEAR_DISPLAY 0b00000001

#define UC_LCD_LINE_1 0x00
#define UC_LCD_LINE_2 0x40
#define UC_LCD_LINE_3 0x14
#define UC_LCD_LINE_4 0x54

#define UC_LCD_INIT_DELAY_MS 10
#define UC_LCD_CLEAR_DELAY_MS 5
#define UC_LCD_DATA_DELAY_US 500

/******************************************************************************
* Typedefs
*******************************************************************************/
typedef enum
{
 LCD_I2C_OK,
 LCD_I2C_GENERIC_ERROR,
 LCD_I2C_INVALID_ADDRESS 
}uc_driver_lcd_i2c_status_t;


typedef struct
{
    uint8_t RS : 1;
    uint8_t RW : 1;
    uint8_t EN : 1;
    uint8_t BackLight : 1;
    uint8_t LCD_DATA : 4;  
}uc_driver_lcd_i2c_data_t;

typedef union {
    uc_driver_lcd_i2c_data_t bits;      // Access individual bits
    uint8_t byte;         // Access the entire byte
} uc_driver_lcd_i2c_data_byte_access_t;

extern uc_driver_lcd_i2c_data_byte_access_t uc_lcd_i2c_data;

/******************************************************************************
***** LCD_I2C Interface
*******************************************************************************/
typedef struct {
  uc_driver_lcd_i2c_status_t (*initialize)(uint8_t address);
  uc_driver_lcd_i2c_status_t (*black_light)(uint8_t address, uc_logic_t set_light);
  uc_driver_lcd_i2c_status_t (*location)(uint8_t address, uint8_t row, uint8_t column);
  uc_driver_lcd_i2c_status_t (*clear)(uint8_t address);
  uc_driver_lcd_i2c_status_t (*write_character)(uint8_t address, uint8_t character);
  uc_driver_lcd_i2c_status_t (*write)(uint8_t address, char *StringData);
}uc_lcd_i2c_driver_interface_t;

extern const uc_lcd_i2c_driver_interface_t I2C_LCD_DRIVER;

/******************************************************************************
* Function Prototypes
*******************************************************************************/
uc_driver_lcd_i2c_status_t uc_lcd_i2c_init(uint8_t address);
uc_driver_lcd_i2c_status_t uc_lcd_i2c_black_light(uint8_t address, uc_logic_t set_light);
uc_driver_lcd_i2c_status_t uc_lcd_i2c_location(uint8_t address, uint8_t row, uint8_t column);
uc_driver_lcd_i2c_status_t uc_lcd_i2c_clear_display(uint8_t address);
uc_driver_lcd_i2c_status_t uc_lcd_i2c_write_character(uint8_t address, uint8_t character);
uc_driver_lcd_i2c_status_t uc_lcd_i2c_write_string(uint8_t address, char *StringData);
#endif /*_CORE_LCD_I2C_H*/
#endif /*#if UC_DRIVER_LCD_I2C */

/*** End of File **************************************************************/
