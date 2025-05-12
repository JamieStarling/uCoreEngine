/******************************************************************************
* Includes
*******************************************************************************/
#include "..\ucore8-16.h"


void turn_on_led(const uc_event_t *event);

uint8_t test[] = {0xAA,0X55};
uint8_t address = 0x20;
uc_return_status_t status;
uc_i2c_buffer_result_t last_result;

void main (void)
{
    UC_SYSTEM.initialize();    
    UC_EVENTS.assign(UC_EVENT_I2C_0_COMPLETE,turn_on_led);
    GPIO.mode(UC_PORTA0,UC_OUTPUT);
    GPIO.pin_write(UC_PORTA0,UC_LOW);
    I2C_HOST.initialize();
    status = uc_hal_i2c_host_load_data(address,UC_I2C_WRITE_ONLY,test,0,UC_TRUE);    
  
  while(1){     
      UC_EVENTS.process();
      
    }   
}

void turn_on_led(const uc_event_t *event)
{
  GPIO.pin_write(UC_PORTA0,UC_HIGH);
}




/*** End of File **************************************************************/
