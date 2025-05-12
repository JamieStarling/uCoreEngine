/****************************************************************************
* Title                 :   Host uCore Engine I2C HAL Functions for 18F Devices With Hardware I2C
* Filename              :   18f_i2c_hw.c
* Author                :   Jamie Starling
* Origin Date           :   2025/05/08
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
*
*******************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "18f_i2c_hw_host.h"

#if (UC_UCORE_MCU_18F && UC_I2C_TYPE_I2C_HW)

/******************************************************************************
* I2C1 Interface
*******************************************************************************/
const uc_hal_I2C_host_interface_t I2C_HOST = {
  .initialize = &uc_hal_i2c_host_init,  
  .reset = &uc_hal_i2c_host_reset,
  //.write_data = &uc_hal_i2c_master_write_data,
  //.read_data = &uc_hal_i2c_read_data,  
};

uc_i2c_state_t i2c_host_status = UC_I2C_STATE_IDLE;

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : uc_hal_i2c_host_init()
* Description: This function initializes the I2C1 module in master mode for communication on 
* the I2C bus. It sets the appropriate I2C pins, configures the I2C clock speed, 
* and enables the I2C1 module. The function uses the Peripheral Pin Select (PPS) 
* system to map the I2C data (SDA) and clock (SCL) lines to the specified GPIO pins.
*
*
*******************************************************************************/
void uc_hal_i2c_host_init(void)
{
    GPIO.mode(UC_I2C_CLOCK_PIN,UC_OPEN_DRAIN);
    GPIO.mode(UC_I2C_DATA_PIN,UC_OPEN_DRAIN);  
    GPIO.pin_write(UC_I2C_CLOCK_PIN,UC_HIGH);
    GPIO.pin_write(UC_I2C_DATA_PIN,UC_HIGH);    
 
    PPS.map_bidirectional(UC_I2C_CLOCK_PIN,UC_PPSOUT_I2C1_SCL,&I2C1SCLPPS);
    PPS.map_bidirectional(UC_I2C_DATA_PIN,UC_PPSOUT_I2C1_SDA,&I2C1SDAPPS); 
    
    I2C1CON0 = 0x4; //I2C Host mode, 7-bit address 
    I2C1CON1 = 0x80; //ACKCNT Not Acknowledge;     
    I2C1CON2bits.SDAHT = 0b10; //SDAHT 30 ns hold time;
    I2C1CON2bits.ABD = 0; //Address Buffer 
  
    I2C1CLK = 0x0; //CLK Fosc/4
    I2C1PIR = 0x0; //Clear Interrupt Flags  
    I2C1PIE = 0x0; //Disable all I2C1 Interrupts  
    I2C1ERR = 0x0; //Clear All Errors
    /* Clear Byte Count registers */
    I2C1CNTL = 0x0;
    I2C1CNTH = 0x0;  
    I2C1BAUD = 0x1F; // Set BAUD 31 - 100Khz   
    I2C1BTOC = 0x0; /* BTOC TMR2 post scaled output;  */     
  
    
    ISR_CONTROL.register_handler(IRQ_I2C1TX,uc_hal_i2c_host_isr_load_data);
    ISR_CONTROL.register_handler(IRQ_I2C1,uc_hal_i2c_host_isr);
    
    
    
    //I2C1EIE error irq
    //I2C1TXIE?I2C1 Transmit Interrupt Enable
    //I2C1RXIE?I2C1 Receive Interrupt Enable
    
    uc_hal_i2c_host_reset();
}

/******************************************************************************
* Function : uc_hal_i2c_host_reset()
* Description: This function resets the I2C1 module 
*
*******************************************************************************/
void uc_hal_i2c_host_reset(void)
{  
    I2C1CON0bits.EN = 0;  //Disable I2C  
    I2C1STAT1bits.CLRBF = 1; //Clears Buffers
    I2C1STAT1bits.TXWE = 0; //Clear Transmit Write Error
    I2C1STAT1bits.RXRE = 0; //Clear Receive Write Error  
    uc_hal_i2c_host_set_status(UC_I2C_STATE_IDLE);
    __delay_ms(25);
    I2C1CON0bits.EN = 1; //Enable I2C
}

/******************************************************************************
* Function : uc_hal_i2c_host_load_data
* \b Description: Loads a block of data for transmission - address, etc. 
*
* <DESCRIPTION>
*  
*******************************************************************************/
uc_return_status_t uc_hal_i2c_host_load_data(uint8_t address,
                                             uc_i2c_buffer_request_type_t mode,
                                             uint8_t *data_block,
                                             uint8_t block_byte_count,
                                             uc_logic_t send_on_complete)
{
  uc_return_status_t load_status;
  load_status = I2C_0_BUFFER.set_client_address(address,mode); 
  if (load_status != UC_STATUS_OK){return UC_STATUS_FAILED;}
  load_status =  I2C_0_BUFFER.load_tx_data_block(data_block,block_byte_count);
  if (load_status != UC_STATUS_OK){return UC_STATUS_FAILED;}
  
  if (send_on_complete == UC_TRUE){
      I2C_0_BUFFER.host_mode_mark_ready();
      if (uc_hal_i2c_host_start_transfer()!= UC_STATUS_OK){return UC_STATUS_FAILED;}
    }
    
  return UC_STATUS_OK;
}

/******************************************************************************
* Function : uc_hal_i2c_host_start_transfer
* \b Description: Starts the I2C Transfer
*
* <DESCRIPTION>
*  
*******************************************************************************/
uc_return_status_t uc_hal_i2c_host_start_transfer(void)
{
  if (I2C_0_BUFFER.get_status() != UC_I2C_STATUS_READY){return UC_STATUS_FAILED;}
  
  //Load the Address
  if (I2C_0_BUFFER.get_request_type()== UC_I2C_READ_ONLY){
      I2C1ADB1 = (uint8_t)(I2C_0_BUFFER.get_client_address() << 1) | 1;   //Load the Address Register for Read
    }  
  else{
      I2C1ADB1 = (uint8_t)(I2C_0_BUFFER.get_client_address() << 1) | 0;   //Load the Address Register for Write
    }
  
  //Load the data byte count 
  I2C1CNTL = I2C_0_BUFFER.get_tx_byte_count();        
  
  I2C1PIRbits.PCIF = 0;             // Clear pending stop
  
  //ISR Enable
  PIE7bits.I2C1IE = 1;    // I2C interrupt enable
  PIE7bits.I2C1TXIE = 1;  // I2C interrupt enable TX buffer empty
  I2C1PIEbits.CNTIE = 1;  //Enable IRQ on Byte Count = 0
  I2C1PIEbits.PCIE = 1;   //Enable IRQ on Start Condition
  I2C1PIEbits.SCIE = 1;   ///Enable IRQ on Stop Condition
  
  
  uc_hal_i2c_host_set_status(UC_I2C_STATE_START);
  I2C1CON0bits.S = UC_SET; //Set the Start Bit 
  
  
  return UC_STATUS_OK;
}

/******************************************************************************
* Function : uc_hal_i2c_host_get_status
* \b Description: 
*
* <DESCRIPTION>
*  
*******************************************************************************/
uc_i2c_state_t uc_hal_i2c_host_get_status(void)
{
  return i2c_host_status;
}

/******************************************************************************
* Function : uc_hal_i2c_host_set_status
* \b Description: 
*
* <DESCRIPTION>
*  
*******************************************************************************/
void uc_hal_i2c_host_set_status(uc_i2c_state_t i2c_host_set_status)
{
    i2c_host_status = i2c_host_set_status;
}

/******************************************************************************
* Function : uc_hal_i2c_host_check_nack_address
* \b Description: Checks for NACK and updates buffer results.
*
* <DESCRIPTION>
*  
*******************************************************************************/
void uc_hal_i2c_host_check_nack_address(void)
{
    //Check to see if this was an address check
    if (uc_hal_i2c_host_get_status()==UC_I2C_STATE_SEND_ADDR)
    {
        if (I2C1CON1bits.ACKSTAT) {I2C_0_BUFFER.set_result(UC_I2C_RESULT_INVALID_ADDRESS);}
    }        
}



/******************************************************************************
* Function : uc_hal_i2c_host_isr_load_data
* \b Description: ISR Function to load data into transmit buffer when I2C1TXIF is set. 
*
* <DESCRIPTION>
*  
*******************************************************************************/
void uc_hal_i2c_host_isr_load_data(void)
{ 
  uc_hal_i2c_host_check_nack_address();
  uc_hal_i2c_host_set_status(UC_I2C_STATE_SEND_DATA); 
  I2C1TXB = I2C_0_BUFFER.get_tx_byte();  
}

/******************************************************************************
* Function : uc_hal_i2c_host_isr
* \b Description: ISR Function take care of Stop Bits, etc. 
*
* <DESCRIPTION>
*  
*******************************************************************************/
void uc_hal_i2c_host_isr(void)
{
    //Start Condition IRQ
    if (I2C1PIRbits.SCIF){
        uc_hal_i2c_host_set_status(UC_I2C_STATE_SEND_ADDR);               
        I2C1PIRbits.SCIF = 0;
      }
    //STOP Condition IRQ
    if (I2C1PIRbits.PCIF){
        uc_hal_i2c_host_set_status(UC_I2C_STATE_DONE); 
        UC_EVENTS.post(UC_EVENT_I2C_0_COMPLETE,NULL);
        I2C1PIRbits.PCIF = 0;        
      }
    //Byte Count is 0
    if (I2C1PIRbits.CNTIF){
        uc_hal_i2c_host_check_nack_address();        
        uc_hal_i2c_host_set_status(UC_I2C_STATE_STOP);         
        I2C1PIRbits.CNTIF = 0;        
      }   
}


#endif
/*** End of File **************************************************************/
