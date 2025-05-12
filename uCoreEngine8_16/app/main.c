/******************************************************************************
* Includes
*******************************************************************************/
#include "..\ucore8-16.h"


void turn_on_led(const uc_event_t *event);
void i2c_address_check(const uc_event_t *event);

uint8_t test[] = {0x00,0X55};
uint8_t address = 0x2F;
uint8_t address2 = 0x3F;
uc_return_status_t status;
uc_i2c_buffer_result_t last_result;

void main (void)
{
    UC_SYSTEM.initialize();    
    UC_EVENTS.assign(UC_EVENT_I2C_0_COMPLETE,i2c_address_check);
    
    GPIO.mode(UC_PORTA0,UC_OUTPUT);
    GPIO.pin_write(UC_PORTA0,UC_LOW);
    I2C_HOST.initialize();
    status = I2C_HOST.load_data(address,UC_I2C_WRITE_ONLY,test,1,UC_TRUE);
      
  
  while(1){     
      UC_EVENTS.process();
      UC_DELAY.ms(1000);
      status = I2C_HOST.load_data(address2,UC_I2C_WRITE_ONLY,test,1,UC_TRUE);      
    }   
}

void turn_on_led(const uc_event_t *event)
{
  GPIO.pin_write(UC_PORTA0,UC_HIGH);
}

void i2c_address_check(const uc_event_t *event)
{
  if (I2C_HOST.buffer_result() == UC_I2C_RESULT_INVALID_ADDRESS){GPIO.pin_write(UC_PORTA0,UC_HIGH);}
  if (I2C_HOST.buffer_result() == UC_I2C_RESULT_SUCCESS){GPIO.pin_write(UC_PORTA0,UC_LOW);}
  I2C_HOST.reset_buffer();
}



/*** End of File **************************************************************/
