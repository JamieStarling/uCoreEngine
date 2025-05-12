/****************************************************************************
* Title                 :   uCore LCD I2C Drivers
* Filename              :   lcd_i2c.c
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

/*************** CHANGE LOG ***************************************************
*
*    Date    Version   Author         Description 
*   2024/12/26  1.0.0   Jamie Starling  Initial Version
*******************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "lcd_i2c.h"

#if UC_DRIVER_LCD_I2C

/******************************************************************************
* I2C1 Interface
*******************************************************************************/
const uc_lcd_i2c_driver_interface_t I2C_LCD_DRIVER = {
  .initialize = &uc_lcd_i2c_init,
  .black_light = &uc_lcd_i2c_black_light,
  .location = &uc_lcd_i2c_location,
  .clear = &uc_lcd_i2c_clear_display,
  .write_character = &uc_lcd_i2c_write_character,
  .write = &uc_lcd_i2c_write_string          
};

/******************************************************************************
* Variables 
*******************************************************************************/
uc_driver_lcd_i2c_data_byte_access_t uc_lcd_i2c_data;


/******************************************************************************
* Function Prototypes
*******************************************************************************/
void uc_lcd_i2c_check_bus_status(void);
uc_driver_lcd_i2c_status_t uc_lcd_i2c_send(uint8_t address, bool RS, uint8_t data);
uc_driver_lcd_i2c_status_t uc_lcd_i2c_check_address(uint8_t address);
uc_driver_lcd_i2c_status_t uc_lcd_i2c_init_4bit_mode(uint8_t address);
/******************************************************************************
* Functions
*******************************************************************************/

/******************************************************************************
* Function : uc_lcd_i2c_init()
* Description: Initializes the I2C communication for an LCD module at a given address. 
* It sets up the LCD data structure, initializes the I2C module, checks the address, 
* and starts the LCD in 4-bit mode.
*
* @param address - The I2C address of the LCD.
* @return uc_driver_lcd_i2c_status_t - Status of the initialization.
*******************************************************************************/
uc_driver_lcd_i2c_status_t uc_lcd_i2c_init(uint8_t address)
{  
  //Clear the LCD Data Structure
  uc_lcd_i2c_data.byte = 0x00;
  
  //Initialize I2C 
  I2C_MASTER.initialize(); 
  
  // Check if the provided I2C address is valid
  if (I2C_MASTER.write_data(address,0,&uc_lcd_i2c_data.byte) != UC_I2C_OK){return LCD_I2C_INVALID_ADDRESS;}  
  
  // Start LCD initialization in 4-bit mode and check for errors
  if (uc_lcd_i2c_init_4bit_mode(address) != LCD_I2C_OK){return LCD_I2C_GENERIC_ERROR;}  
  
  // Initial delay to allow LCD setup
  __delay_ms(UC_LCD_INIT_DELAY_MS);  
  
  return LCD_I2C_OK;  
}


/******************************************************************************
* Function : uc_lcd_i2c_init_4bit_mode()
* Description: Initializes the LCD module in 4-bit mode using the I2C interface.
* Sends the initialization sequence commands to configure the LCD.
*
* @param address - The I2C address of the LCD.
* @return uc_driver_lcd_i2c_status_t - Status of the initialization.
*******************************************************************************/
uc_driver_lcd_i2c_status_t uc_lcd_i2c_init_4bit_mode(uint8_t address)
{
    uc_driver_lcd_i2c_status_t LCD_Status; 
    
    // Send the first part of the 4-bit initialization sequence
    LCD_Status = uc_lcd_i2c_send(address,UC_LCD_RS_CMD,UC_UTILS.get_high_nibble(UC_LCD_CMD_4BIT_MODE_1));  
    if (LCD_Status != LCD_I2C_OK) {return LCD_Status;}
    
    LCD_Status = uc_lcd_i2c_send(address,UC_LCD_RS_CMD,UC_UTILS.get_low_nibble(UC_LCD_CMD_4BIT_MODE_1));
    if (LCD_Status != LCD_I2C_OK) {return LCD_Status;}
    
    // Send the second part of the 4-bit initialization sequence
    LCD_Status = uc_lcd_i2c_send(address,UC_LCD_RS_CMD,UC_UTILS.get_high_nibble(UC_LCD_CMD_4BIT_MODE_2));
    if (LCD_Status != LCD_I2C_OK) {return LCD_Status;}
    
    LCD_Status = uc_lcd_i2c_send(address,UC_LCD_RS_CMD,UC_UTILS.get_low_nibble(UC_LCD_CMD_4BIT_MODE_2));
    if (LCD_Status != LCD_I2C_OK) {return LCD_Status;}
    
    // Delay to allow the LCD to process the command
    __delay_ms(UC_LCD_INIT_DELAY_MS);
    
    // Set function mode
    LCD_Status = uc_lcd_i2c_send(address,UC_LCD_RS_CMD,UC_UTILS.get_high_nibble(UC_LCD_CMD_SET_FUNCTION));
    if (LCD_Status != LCD_I2C_OK) {return LCD_Status;}
    
    LCD_Status = uc_lcd_i2c_send(address,UC_LCD_RS_CMD,UC_UTILS.get_low_nibble(UC_LCD_CMD_SET_FUNCTION)); 
    if (LCD_Status != LCD_I2C_OK) {return LCD_Status;}
    
    // Delay to allow the LCD to process the command
    __delay_ms(UC_LCD_INIT_DELAY_MS);
  
    // Set display mode
    LCD_Status = uc_lcd_i2c_send(address,UC_LCD_RS_CMD,UC_UTILS.get_high_nibble(UC_LCD_CMD_SET_DISPLAY));
    if (LCD_Status != LCD_I2C_OK) {return LCD_Status;}
    LCD_Status = uc_lcd_i2c_send(address,UC_LCD_RS_CMD,UC_UTILS.get_low_nibble(UC_LCD_CMD_SET_DISPLAY)); 
    if (LCD_Status != LCD_I2C_OK) {return LCD_Status;}
    
    // Delay to allow the LCD to process the command
    __delay_ms(UC_LCD_INIT_DELAY_MS); 
    
    // Clear the display
    LCD_Status = uc_lcd_i2c_clear_display(address);
    if (LCD_Status != LCD_I2C_OK) {return LCD_Status;}
    
    return LCD_I2C_OK;
}


/******************************************************************************
* Function : uc_lcd_i2c_send()
* Description: Sends data or a command to the LCD over I2C. The RS bit determines if the data
* is a command (RS = 0) or data (RS = 1).
*
* @param address - The I2C address of the LCD.
* @param RS - Boolean value; true for data, false for command.
* @param data - The data byte to send.
*
* @return uc_driver_lcd_i2c_status_t - Status of the transmission.
*******************************************************************************/
uc_driver_lcd_i2c_status_t uc_lcd_i2c_send(uint8_t address, bool RS, uint8_t data)
{  
  uc_lcd_i2c_data.bits.LCD_DATA = data;
  uc_lcd_i2c_data.bits.RS = RS;  //Set RS 
  
  // First pass with EN Low 
  __delay_us(UC_LCD_DATA_DELAY_US);
  uc_lcd_i2c_data.bits.EN = UC_CLEAR;
  if (I2C_MASTER.write_data(address,1,&uc_lcd_i2c_data.byte) != UC_I2C_OK){ return LCD_I2C_GENERIC_ERROR; }

  // Second pass with EN High
   __delay_us(UC_LCD_DATA_DELAY_US);
  uc_lcd_i2c_data.bits.EN = UC_SET;
  if (I2C_MASTER.write_data(address,1,&uc_lcd_i2c_data.byte) != UC_I2C_OK) { return LCD_I2C_GENERIC_ERROR; }

  // Third pass with EN Low again
   __delay_us(UC_LCD_DATA_DELAY_US);
  uc_lcd_i2c_data.bits.EN = UC_CLEAR;
  if (I2C_MASTER.write_data(address,1,&uc_lcd_i2c_data.byte) != UC_I2C_OK) { return LCD_I2C_GENERIC_ERROR; }  
  return LCD_I2C_OK;  
}

/******************************************************************************
* Function : uc_lcd_i2c_black_light()
* Description: Controls the LCD backlight state (on or off).
*
* @param address - The I2C address of the LCD.
* @param set_light - The desired state of the backlight (ON or OFF).
* 
* @return uc_driver_lcd_i2c_status_t - Status of the transmission.
*******************************************************************************/
uc_driver_lcd_i2c_status_t uc_lcd_i2c_black_light(uint8_t address, uc_logic_t set_light)
{  
  // Set backlight bit based on the input state
  uc_lcd_i2c_data.bits.BackLight = (set_light == UC_ON) ? 1 : 0;    
  uc_lcd_i2c_data.bits.LCD_DATA = 0x00;  // Clear data bits if not needed for backlight control
  
  // Write to the LCD and check for errors
  if (I2C_MASTER.write_data(address,1,&uc_lcd_i2c_data.byte) != UC_I2C_OK){return LCD_I2C_GENERIC_ERROR;}    
  return LCD_I2C_OK;  
}

/******************************************************************************
* Function : uc_lcd_i2c_location()
* Description: Sets the cursor position on the LCD display.
*
* @param address - The I2C address of the LCD.
* @param row - The row number (0-based index).
* @param column - The column number (0-based index).
*
*  @return uc_driver_lcd_i2c_status_t - Status of the transmission.
*******************************************************************************/
uc_driver_lcd_i2c_status_t uc_lcd_i2c_location(uint8_t address, uint8_t row, uint8_t column)
{
  uint8_t location_data;  
  
  // Determine the starting address based on the row
  switch (row) {
        case 0: location_data = UC_LCD_LINE_1 + column; break;  // Line 1
        case 1: location_data = UC_LCD_LINE_2 + column; break;  // Line 2
        case 2: location_data = UC_LCD_LINE_3 + column; break;  // Line 3 (for 4-line displays)
        case 3: location_data = UC_LCD_LINE_4 + column; break;  // Line 4 (for 4-line displays)
        default: return LCD_I2C_GENERIC_ERROR;  // Invalid row
    }
  
  // Combine with the command for setting the DDRAM address
  location_data = (0x80 | location_data);
  
  if(uc_lcd_i2c_send(address,UC_LCD_RS_CMD,UC_UTILS.get_high_nibble(location_data)) != LCD_I2C_OK){return LCD_I2C_GENERIC_ERROR;}
  if(uc_lcd_i2c_send(address,UC_LCD_RS_CMD,UC_UTILS.get_low_nibble(location_data)) != LCD_I2C_OK){return LCD_I2C_GENERIC_ERROR;}
  
  //LCD_Status = uc_lcd_i2c_send(address,UC_LCD_RS_CMD,CORE.High4(location_data));
  //LCD_Status = uc_lcd_i2c_send(address,UC_LCD_RS_CMD,CORE.Low4(location_data));
  
  return LCD_I2C_OK;  
}

/******************************************************************************
* Function : uc_lcd_i2c_clear_display()
* Description: Clears the LCD display and resets the cursor to the home position.
*
* @param address - The I2C address of the LCD.
* @return uc_driver_lcd_i2c_status_t - Status of the operation.
*******************************************************************************/
uc_driver_lcd_i2c_status_t uc_lcd_i2c_clear_display(uint8_t address)
{
  if(uc_lcd_i2c_send(address,UC_LCD_RS_CMD,UC_UTILS.get_high_nibble(UC_LCD_CMD_CLEAR_DISPLAY)) != LCD_I2C_OK){return LCD_I2C_GENERIC_ERROR;}
  if(uc_lcd_i2c_send(address,UC_LCD_RS_CMD,UC_UTILS.get_low_nibble(UC_LCD_CMD_CLEAR_DISPLAY)) != LCD_I2C_OK){return LCD_I2C_GENERIC_ERROR;}
  
  //LCD_Status = uc_lcd_i2c_send(address,UC_LCD_RS_CMD,CORE.High4(UC_LCD_CMD_CLEAR_DISPLAY));
  //LCD_Status = uc_lcd_i2c_send(address,UC_LCD_RS_CMD,CORE.Low4(UC_LCD_CMD_CLEAR_DISPLAY));  
  
  // Delay for the LCD to process the clear command
  __delay_ms(UC_LCD_CLEAR_DELAY_MS); 
  
  // Return success if both commands succeeded
  return LCD_I2C_OK;
}

/******************************************************************************
* Function : uc_lcd_i2c_write_character()
* Description: Writes a character to the LCD display.
*
* @param address - The I2C address of the LCD.
* @param character - The ASCII character to write to the display.
* 
* @return uc_driver_lcd_i2c_status_t - Status of the operation.
*******************************************************************************/
uc_driver_lcd_i2c_status_t uc_lcd_i2c_write_character(uint8_t address, uint8_t character)
{
  if(uc_lcd_i2c_send(address,UC_LCD_RS_DATA,UC_UTILS.get_high_nibble(character)) != LCD_I2C_OK){return LCD_I2C_GENERIC_ERROR;}
  if(uc_lcd_i2c_send(address,UC_LCD_RS_DATA,UC_UTILS.get_low_nibble(character)) != LCD_I2C_OK){return LCD_I2C_GENERIC_ERROR;}
  
  //LCD_Status = uc_lcd_i2c_send(address,UC_LCD_RS_DATA,CORE.High4(character));
  //LCD_Status = uc_lcd_i2c_send(address,UC_LCD_RS_DATA,CORE.Low4(character));
  
  return LCD_I2C_OK;
}

/******************************************************************************
* Function : uc_lcd_i2c_write_string()
* Description: Writes a string to the LCD display.
*
* @param address - The I2C address of the LCD.
* @param StringData - The null-terminated string to display.
* 
* @return uc_driver_lcd_i2c_status_t - Status of the last character written.
*******************************************************************************/
uc_driver_lcd_i2c_status_t uc_lcd_i2c_write_string(uint8_t address, char *StringData)
{
  uc_driver_lcd_i2c_status_t LCD_Status = LCD_I2C_OK;
    
  // Loop through the string until the null terminator is reached
  for (uint8_t i = 0; StringData[i] != '\0'; i++) {
    LCD_Status = uc_lcd_i2c_write_character(address, StringData[i]);
        
    // If any write operation fails, return immediately
    if (LCD_Status != LCD_I2C_OK) {
        return LCD_Status;
        }
    }
return LCD_Status;  // Return the last status (OK if all characters succeed)
}

#endif /*#if UC_DRIVER_LCD_I2C*/


/*** End of File **************************************************************/
