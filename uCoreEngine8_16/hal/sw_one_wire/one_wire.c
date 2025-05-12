/****************************************************************************
* Title                 :   uCore Engine One Wire HAL
* Filename              :   one_wire.c
* Author                :   Jamie Starling
* Origin Date           :   2024/12/25
* Version               :   1.0.0
* Compiler              :   XC8 
* Target                :   Microchip PIC16F series 
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
*   2024/12/25  1.0.0       Jamie Starling  Initial Version
*  
*
*****************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "one_wire.h"

#if UC_DEVICE_HAL_OW


/******************************************************************************
***** ONE WIRE Interface
*******************************************************************************/
const uc_hal_ow_interface_t ONE_WIRE = {
  .initialize = &uc_hal_ow_init,
  .send_reset = &uc_hal_ow_reset,
  .write_byte =  &uc_hal_ow_write_byte,  
  .read_byte =  &uc_hal_ow_read_byte,
  .read_bit = &uc_hal_ow_read_bit
};

/******************************************************************************
* Function Prototypes
*******************************************************************************/
void uc_hal_ow_drive_low(void);
void uc_hal_ow_drive_high(void);
uint8_t uc_hal_ow_read(void);
void uc_hal_ow_write_bit(uint8_t write_bit);
//uint8_t ONE_WIRE_Read_Bit(void);

/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : ONE_WIRE_Init()
* Description: Initializes the one-wire bus by disabling the analog function and setting 
* the pin as an input to prepare for communication.
*
*******************************************************************************/
void uc_hal_ow_init(void)
{
  UC_OW_PINANALOG_REGISTER = 0;  //turn off analog  
  UC_OW_DIRECTION_REGISTER = 1;  //set pin as input
}

/******************************************************************************
* Function : ONE_WIRE_Reset()
* Description: Sends a reset pulse on the one-wire bus and waits for a presence pulse from 
* connected devices to signal their presence.
*
* Parameters:
*   - None
*
* Returns:
*   - LogicEnum_t: `DEVICE_PRESENT` if devices respond, `NO_DEVICE` if no response.
*******************************************************************************/
uc_hal_ow_status_t uc_hal_ow_reset(void)
{    
  uc_hal_ow_drive_low(); 
  __delay_us(UC_HAL_OW_RESET_DELAY_US); // wait for 480us+

  uc_hal_ow_drive_high();    
  __delay_us(UC_HAL_OW_RESET_DELAY_DRIVE_HIGH_US);

  uint8_t response = uc_hal_ow_read();
  __delay_us(UC_HAL_OW_RESET_DELAY_READ_US); 

  uc_hal_ow_drive_high(); 
  
  return (response == 0) ? UC_OW_DEVICE_PRESENT : UC_OW_NO_DEVICE;   
}

/******************************************************************************
* Function : ONE_WIRE_Drive_Low()
* Description: Drives the one-wire bus low by setting the pin as an output and pulling it 
* to a low logic level (0V).
*
*******************************************************************************/
void uc_hal_ow_drive_low(void)
{
  UC_OW_DIRECTION_REGISTER = 0;
  UC_OW_PINDRIVER_REGISTER = 0;  
}

/******************************************************************************
* Function : ONE_WIRE_Drive_High()
* Description: Releases the one-wire bus by setting the pin to a high logic level, allowing 
* the pull-up resistor to maintain the line at a high voltage.
*
*******************************************************************************/
void uc_hal_ow_drive_high(void)
{   
  UC_OW_DIRECTION_REGISTER = 1;  // Release the one-wire bus to go high
   
}

/******************************************************************************
* Function : ONE_WIRE_Read()
* Description: Reads the current logic level of the one-wire bus, returning `1` if high 
* (logic 1) or `0` if low (logic 0).
*
* Returns:
*   - uint8_t: `1` if the bus is high, `0` if the bus is low.
*******************************************************************************/
uint8_t uc_hal_ow_read(void)
{

  UC_OW_DIRECTION_REGISTER = 1;  // Set pin as input
  
  return (UC_OW_PINREAD_REGISTER) ? 1 : 0;
}

/******************************************************************************
* Function : ONE_WIRE_Write_Bit()
* Description: Writes a single bit to the one-wire bus. Drives the bus low for a specific 
* duration based on the bit value (1 or 0), then releases it to complete the 
* write operation.
*
* Parameters:
*   - write_bit (uint8_t): The bit to write (1 or 0).
*******************************************************************************/
void uc_hal_ow_write_bit(uint8_t write_bit)
{
  if (write_bit)  // Write 1 to buss
    {
      uc_hal_ow_drive_low();
      __delay_us(UC_HAL_OW_WRITE_BIT_1_DELAY_DRIVE_LOW_US);
      uc_hal_ow_drive_high();
      __delay_us(UC_HAL_OW_WRITE_BIT_1_DELAY_DRIVE_HIGH_US);      
    }
  else  // Write 0 to buss
    {
       uc_hal_ow_drive_low();
       __delay_us(UC_HAL_OW_WRITE_BIT_0_DELAY_DRIVE_LOW_US);
       uc_hal_ow_drive_high();
       __delay_us(UC_HAL_OW_WRITE_BIT_0_DELAY_DRIVE_HIGH_US);      
    }
}

/******************************************************************************
* Function : uc_hal_ow_read_bit()
* Description: Reads a single bit from the one-wire bus. The function drives the bus low 
* briefly, releases it to allow the bus to be pulled high, and then reads the 
* state of the bus to determine the bit value.
*
* Returns:
*   - uint8_t: The bit read from the bus (1 for high, 0 for low).  
*******************************************************************************/
uint8_t uc_hal_ow_read_bit(void)
{
  uint8_t one_wire_data = 0;
  
  // Initiate reading a bit
  uc_hal_ow_drive_low();
  __delay_us(UC_HAL_OW_READ_BIT_DELAY_DRIVE_LOW_US);
  
  // Release the bus and wait for the read time
  UC_OW_DIRECTION_REGISTER = 1;
  __delay_us(UC_HAL_OW_READ_BIT_DELAY_DRIVE_HIGH_US);
  
  // Read the bit from the bus
  one_wire_data = uc_hal_ow_read();
  
   __delay_us(UC_HAL_OW_READ_BIT_DELAY_END_US);
   return one_wire_data;
}

/******************************************************************************
* Function : uc_hal_ow_write_byte()
* Description:  Writes a byte of data to the one-wire bus by transmitting each bit 
* sequentially, starting with the least significant bit (LSB).
*
* Parameters:
*   - data (uint8_t): The byte of data to be sent.
*
*******************************************************************************/
void uc_hal_ow_write_byte(uint8_t data)
{  
  for (uint8_t loop_counter = 0; loop_counter < 8; loop_counter++)
    {
      uc_hal_ow_write_bit(data & 0x01); //Sending LS-bit first
      data >>= 1; // shift the data byte for the next bit to send
    }  
}

/******************************************************************************
* Function : ONE_WIRE_Read_Byte()
* Description: Reads a byte of data from the one-wire bus by receiving each bit sequentially,
* starting with the least significant bit (LSB).
*
* Parameters:
*   - None
*
* Returns:
*   - uint8_t: The byte of data received from the one-wire bus.
*
*******************************************************************************/
uint8_t uc_hal_ow_read_byte(void)
{
  uint8_t result = 0;
  
  for (uint8_t loop_counter = 0; loop_counter < 8; loop_counter++)
	{		
            result >>= 1; // Shift result to prepare for the next bit
            if (uc_hal_ow_read_bit()){result |= 0x80;} // Set MSB if the read bit is 1					
	}
	return result;  
}

#endif /* #if UC_DEVICE_HAL_OW */ 
/*** End of File **************************************************************/
