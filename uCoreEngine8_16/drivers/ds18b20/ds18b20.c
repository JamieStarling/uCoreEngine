/****************************************************************************
* Title                 :   DS18B20 Driver
* Filename              :   ds18b20.c
* Author                :   Jamie Starling
* Origin Date           :   2025/01/06
* Version               :   1.0.0
* Compiler              :   XC8 
* Target                :   PIC MCUs 
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
*   2025/01/06  1.0.0       Jamie Starling  Initial Version
*  
*****************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "ds18b20.h"

#if UC_DRIVER_DS18B20

/******************************************************************************
* Interface
*******************************************************************************/
const uc_ds18b20_interface_t DS18B20 = {
  .initialize = &uc_ds18b20_init,
  .read_c = &uc_ds18b20_get_temperature_c,
  .read_f = &uc_ds18b20_get_temperature_f,
  .is_present = &uc_ds18b20_present_status,
  .read_raw = &uc_ds18b20_get_temperature_raw,
  .get_resolution = &uc_ds18b20_return_resolution,
  .start_conversion = &uc_ds18b20_read_temperature,
};



/******************************************************************************
* Variables
*******************************************************************************/
typedef struct {
    bool is_present;
    uint8_t crc_fail_count;
    uint8_t family_code;
    uint8_t serial_number[6];
    int16_t raw_previous_temperature_value;
    int16_t raw_current_temperature_value;
    uint8_t previous_crc_status;
    uint8_t configuration_value;
    uint8_t temperature_lsb;
    uint8_t temperature_msb;
    float temperature_in_c;    
}ds18b20_data_t;
ds18b20_data_t ds18b20_data = {.previous_crc_status = UC_DS18B20_STATUS_CRC_FAILED};

/******************************************************************************
* Function Prototypes
*******************************************************************************/
bool uc_ds18b20_is_present(void);
uint8_t uc_ds18b20_compute_crc(uint8_t *data, uint8_t len);
bool uc_ds18b20_start_conversion(void);
uint8_t uc_ds18b20_read_scratchpad(void);
void uc_ds18b20_handle_crc_fail(void);
void uc_ds18b20_update_status(uint8_t *ds_data);
void uc_ds18b20_read_rom(uint8_t *ds_data, uint8_t *ds_crc_value);
void uc_ds18b20_read_scratchpad_data(uint8_t *ds_data, uint8_t *ds_crc_value);
void uc_ds18b20_update_scratchpad_status(uint8_t *ds_data);
/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : uc_ds18b20_is_present()
* Description: Checks if the DS18B20 is present on the One-Wire bus.
* Returns true if the device is detected, otherwise false.
*
*******************************************************************************/
bool uc_ds18b20_is_present(void)
{   
  return (ONE_WIRE.send_reset() == UC_OW_DEVICE_PRESENT) ? true : false;     
}

/******************************************************************************
* Function : DS18B20_Init()
* Description: Initializes the DS18B20 sensor and verifies its presence on the One Wire bus.
* Reads the ROM data and checks its CRC for validation. Updates the device status
* if the CRC is valid; otherwise, handles CRC failure. 
*
* Returns:
* - DS18B20_STATUS_OK if the sensor is successfully initialized and verified.
* - DS18B20_STATUS_CRC_FAILED if the CRC check fails.
* - DS18B20_STATUS_NO_DEVICE if the sensor is not detected.
*******************************************************************************/
uc_ds18b20_status_t uc_ds18b20_init(void)
{
  uint8_t receivedCRC;
  uint8_t computed_crc_value;
  uint8_t ds_data[UC_DS18B20_ROM_SIZE];
  
  ONE_WIRE.initialize();
  __delay_us(20);
  
  if (uc_ds18b20_is_present()){
      ds18b20_data.is_present = true;
      uc_ds18b20_read_rom(ds_data, &receivedCRC);
      
      computed_crc_value = uc_ds18b20_compute_crc(ds_data, sizeof(ds_data));
      
      /*If CRC is ok, Store data and return OK*/
      if (computed_crc_value == receivedCRC){
            uc_ds18b20_update_status(ds_data);
            return UC_DS18B20_STATUS_OK;
        }
      
      /*If CRC check failed, Handle Failed Event*/
      else {
            uc_ds18b20_handle_crc_fail();
            return UC_DS18B20_STATUS_CRC_FAILED;
        }
    }/*End of If DS Present Logic*/
  
  /*If DS is not present we fail and send back no_device*/  
    ds18b20_data.is_present = false;
    return UC_DS18B20_STATUS_NO_DEVICE;   
}


/******************************************************************************
* Function : uc_ds18b20_read_rom()
* Description: Reads the ROM data from the DS18B20 sensor on the One Wire bus.
* The ROM data is used for identification and includes a CRC byte for validation.
*
* Parameters:
* - ds_data: Pointer to store the read ROM data.
* - ds_crc_value: Pointer to store the read CRC value.
*******************************************************************************/
void uc_ds18b20_read_rom(uint8_t *ds_data, uint8_t *ds_crc_value)
{
    ONE_WIRE.write_byte(UC_DS18B20_READ_ROM_COMMAND);
    for (uint8_t i = 0; i < UC_DS18B20_ROM_SIZE; i++) {
        ds_data[i] = ONE_WIRE.read_byte();
    }
    *ds_crc_value = ONE_WIRE.read_byte();
}

/******************************************************************************
* Function : uc_ds18b20_update_status()
* Description: Updates the DS18B20 status structure with the family code and serial number 
* from the provided ROM data.
*
* Parameters:
* - ds_data: Pointer to the ROM data array read from the DS18B20 sensor.
*******************************************************************************/
void uc_ds18b20_update_status(uint8_t *ds_data)
{
    ds18b20_data.family_code = ds_data[0];
    for (uint8_t i = 0; i < 6; i++) {
        ds18b20_data.serial_number[i] = ds_data[i + 1];
    }
    ds18b20_data.previous_crc_status = UC_DS18B20_STATUS_OK;
}

/******************************************************************************
* Function : uc_ds18b20_handle_crc_fail()
* Description: Increments the CRC failure count and updates the status to indicate a CRC failure.
*
*******************************************************************************/
void uc_ds18b20_handle_crc_fail(void)
{
    ds18b20_data.crc_fail_count++;
    ds18b20_data.previous_crc_status = UC_DS18B20_STATUS_CRC_FAILED;
}

/******************************************************************************
* Function : uc_ds18b20_compute_crc()
* Description: Computes the CRC for a given data array using the polynomial 0x31.
* 
* @param data - Pointer to the data array.
* @param len - Length of the data array.
* 
* @return - The computed 8-bit CRC value.
*******************************************************************************/
uint8_t uc_ds18b20_compute_crc(uint8_t *data, uint8_t len)
{
  uint8_t computed_crc = 0;
  
   while (len--) {
        uint8_t byte = *data++;
        computed_crc ^= byte;
        
        for (uint8_t i = 0; i < 8; i++) {
            if (computed_crc & 0x01) {
                computed_crc = (computed_crc >> 1) ^ 0x8C;  // Polynomial is 0x31 (0x8C when shifted by 1 bit)
            } else {
                computed_crc >>= 1;
            }
        }
    }    
    return computed_crc;  
}

/******************************************************************************
* Function : DS18B20_Read_Temperature()
* Description: Initiates temperature conversion and reads the result from the DS18B20 sensor.
* 
* @return - Status of the operation: 
*           DS18B20_STATUS_OK if successful, 
*           DS18B20_STATUS_TEMPERATURE_CONVERSION_FAILED if conversion fails,
*           DS18B20_STATUS_CRC_FAILED if data read fails.
*******************************************************************************/
uc_ds18b20_status_t uc_ds18b20_read_temperature(void)
{             
    // Start the conversion process
    if (!uc_ds18b20_start_conversion()) {
        return UC_DS18B20_STATUS_TEMPERATURE_CONVERSION_FAILED;  // Failed to start conversion
    }
  
    // Try to read scratchpad data, retrying up to MAX_RETRY_COUNT times
    uint8_t retry_count = 0;
    while (uc_ds18b20_read_scratchpad() == UC_DS18B20_STATUS_CRC_FAILED && retry_count < UC_DS18B20_MAX_RETRY_COUNT) {        
        __delay_ms(UC_DS18B20_RETRY_DELAY_MS);  // Short delay before retry
        retry_count++;
    }
  
    // Check if scratchpad data was read successfully
    if (retry_count >= UC_DS18B20_MAX_RETRY_COUNT) {
        return UC_DS18B20_STATUS_CRC_FAILED;  // Failed to read scratchpad data
    }
  
    // Update temperature values
    ds18b20_data.raw_previous_temperature_value = ds18b20_data.raw_current_temperature_value;
    ds18b20_data.raw_current_temperature_value = (ds18b20_data.temperature_msb << 8) | ds18b20_data.temperature_lsb;
    
    // Calculate the temperature in Celsius
    ds18b20_data.temperature_in_c = (float)(ds18b20_data.raw_current_temperature_value * UC_DS18B20_TEMPERATURE_RESOLUTION_12bit_INCREMENT);

    return UC_DS18B20_STATUS_OK;  // Temperature read successfully    
}

/******************************************************************************
* Function : DS18B20_Get_TemperatureC()
* Description: Returns the temperature in Celsius from the DS18B20 sensor from previous conversion. 
* 
* @return - Temperature in Celsius if read is successful.
*           Returns `_DS18B20_INVALID_TEMPERATURE` if the read fails.
*******************************************************************************/
float uc_ds18b20_get_temperature_c(void){
  if (uc_ds18b20_read_temperature() == UC_DS18B20_STATUS_OK){
      return ds18b20_data.temperature_in_c;
    }
  else{
      return UC_DS18B20_INVALID_TEMPERATURE;
    }
}

/******************************************************************************
* Function : DS18B20_Get_TemperatureF()
* Description: Returns the temperature in Fahrenheit from the DS18B20 sensor from previous conversion. 
* 
* @return - Temperature in Fahrenheit if read is successful.
*           Returns `_DS18B20_INVALID_TEMPERATURE` if the read fails.
*******************************************************************************/
float uc_ds18b20_get_temperature_f(void){
  if (uc_ds18b20_read_temperature() == UC_DS18B20_STATUS_OK){
      return (ds18b20_data.temperature_in_c * 1.8f) + 32.0f;
    }
  else{
      return UC_DS18B20_INVALID_TEMPERATURE;
    }
}




/******************************************************************************
* Function : DS18B20_Get_TemperatureRAW()
* Description: Returns the raw temperature value from the DS18B20 sensor from previous conversion.
* 
* @return - Raw temperature value as `int16_t` if the read is successful.
*           Returns `_DS18B20_INVALID_TEMPERATURE` if the read fails.
*******************************************************************************/
int16_t uc_ds18b20_get_temperature_raw(void){
 if (uc_ds18b20_read_temperature() == UC_DS18B20_STATUS_OK){
      return ds18b20_data.raw_current_temperature_value;
    }
  else{
      return UC_DS18B20_INVALID_TEMPERATURE;
    }
}


/******************************************************************************
* Function : uc_ds18b20_start_conversion()
* Description: Initiates a temperature conversion on the DS18B20 sensor.
* 
* @return - `true` if the sensor is present and the conversion is initiated.
*           `false` if the sensor is not detected.
*******************************************************************************/
bool uc_ds18b20_start_conversion(void)
{
  if (uc_ds18b20_is_present())  
    {
       ONE_WIRE.write_byte(UC_DS18B20_SKIP_ROM_COMMAND);
       ONE_WIRE.write_byte(UC_DS18B20_CONVERT_COMMAND);
       //Wait until conversion is complete
       __delay_ms(UC_DS18B20_CONVERSION_DELAY_MS);
       return true;
    }
  return false;
}

/******************************************************************************
* Function : uc_ds18b20_read_scratchpad()
* Description: Reads the scratchpad data from the DS18B20 sensor and verifies its integrity using CRC.
*
* @return - `DS18B20_STATUS_OK` if the scratchpad data is read successfully and CRC matches.
*         - `DS18B20_STATUS_CRC_FAILED` if the sensor is not present or CRC check fails.
*******************************************************************************/
uint8_t uc_ds18b20_read_scratchpad(void)
{
    uint8_t receivedCRC;
    uint8_t computed_crc_value;
    uint8_t scratchpadData[UC_DS18B20_SCRATCHPAD_DATA_SIZE];

    if (uc_ds18b20_is_present()){  
        
        uc_ds18b20_read_scratchpad_data(scratchpadData, &receivedCRC);
        computed_crc_value =  uc_ds18b20_compute_crc(scratchpadData, sizeof(scratchpadData));
            
        if (computed_crc_value == receivedCRC) {
            uc_ds18b20_update_scratchpad_status(scratchpadData);
            return UC_DS18B20_STATUS_OK;
        }
        else {
            uc_ds18b20_handle_crc_fail();
            return UC_DS18B20_STATUS_CRC_FAILED;
        }
    }
    return UC_DS18B20_STATUS_CRC_FAILED;
}


/******************************************************************************
* Function : DS18B20_PresentStatus()
* Description: Checks if the DS18B20 sensor is present based on the stored status.
*
* @return - `true` if the sensor is present, `false` otherwise.
*******************************************************************************/
bool uc_ds18b20_present_status(void)
{
  return (ds18b20_data.is_present == UC_TRUE) ? true : false;  
}

/******************************************************************************
* Function : uc_ds18b20_read_scratchpad_data()
* Description: Reads the scratchpad data from the DS18B20 sensor, including temperature and configuration bytes.
*
* @param[out] ds_data - Pointer to the buffer where the scratchpad data will be stored.
* @param[out] ds_crc_value - Pointer to store the CRC byte read from the sensor.
*******************************************************************************/
void uc_ds18b20_read_scratchpad_data(uint8_t *ds_data, uint8_t *ds_crc_value)
{
  // Send commands to initiate scratchpad read  
  ONE_WIRE.write_byte(UC_DS18B20_SKIP_ROM_COMMAND);
  ONE_WIRE.write_byte(UC_DS18B20_READ_SCRATCHPAD);
  
  // Read scratchpad data bytes  
  for (uint8_t i = 0; i < UC_DS18B20_SCRATCHPAD_DATA_SIZE; i++) {
    ds_data[i] = ONE_WIRE.read_byte();  
    }
  
  // Read and store the CRC byte
  *ds_crc_value = ONE_WIRE.read_byte();
}

/******************************************************************************
* Function : uc_ds18b20_update_scratchpad_status()
* Description: Updates the global status structure with data read from the DS18B20 scratchpad.
*
* @param[in] ds_data - Pointer to the array containing the scratchpad data.
* 
*******************************************************************************/
void uc_ds18b20_update_scratchpad_status(uint8_t *ds_data)
{
  // Update the global status structure with scratchpad data  
  ds18b20_data.previous_crc_status = UC_DS18B20_STATUS_OK;
  ds18b20_data.configuration_value = ds_data[4];
  ds18b20_data.temperature_lsb = ds_data[0];
  ds18b20_data.temperature_msb = ds_data[1];
}

/******************************************************************************
* Function : DS18B20_Return_Resolution()
* Description: Returns the resolution setting of the DS18B20 sensor based on the current 
* configuration value stored in the status structure.
*
* @return ds18b20_dataEnum_t - The resolution or an error code if unrecognized.
* 
*******************************************************************************/
uc_ds18b20_status_t uc_ds18b20_return_resolution(void)
{
  switch (ds18b20_data.configuration_value) {
    case UC_DS18B20_9BIT_RESOLUTION:      // Resolution: 9-bit
      return UC_DS18B20_RESOLUTION_9BIT;
    case UC_DS18B20_10BIT_RESOLUTION:     // Resolution: 10-bit
      return UC_DS18B20_RESOLUTION_10BIT;
    case UC_DS18B20_11BIT_RESOLUTION:     // Resolution: 11-bit
      return UC_DS18B20_RESOLUTION_11BIT;
    case UC_DS18B20_12BIT_RESOLUTION:     // Resolution: 12-bit
      return UC_DS18B20_RESOLUTION_12BIT;
    default:                            // Unrecognized configuration
      return UC_DS18B20_ERROR_GENERIC;      
    }     
}

#endif

/*** End of File **************************************************************/
