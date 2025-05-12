/****************************************************************************
* Title                 :   uCore 8 Engine Generic Utilities
* Filename              :   uc_utils.c
* Author                :   Jamie Starling
* Origin Date           :   2024/12/21
* Version               :   1.0.0
* Compiler              :   XC8
* Target                :   
* Copyright             :   © 2024 Jamie Starling
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
*   2024/12/21  1.0.0       Jamie Starling  Initial Version
*  
*
*****************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "uc_utils.h"

/******************************************************************************
* Defines / Options
*******************************************************************************/
#if UC_UTIL_FUNCTIONS 


/******************************************************************************
* Interface
*******************************************************************************/
const uc_utils_interface_t UC_UTILS = {
    .make_16 = &uc_make_16,
    .get_low_nibble = &uc_return_nibble_low,
    .get_high_nibble =  &uc_return_nibble_high,
    .set_bit = &uc_set_bit,
    .clear_bit =&uc_clear_bit,
};



/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : uc_make_16
* Description: Combines two 8-bit values into a single 16-bit value, placing the high 
* byte in the upper 8 bits and the low byte in the lower 8 bits.
*
* Parameters:
*   - high_byte (uint8_t): The 8-bit value for the upper half of the result.
*   - low_byte (uint8_t): The 8-bit value for the lower half of the result.
*
* Returns:
*   - (uint16_t): The combined 16-bit value.
*  
*******************************************************************************/

uint16_t uc_make_16(uint8_t high_byte, uint8_t low_byte)
{
  // Combine the high byte and low byte into a 16-bit value
  uint16_t combined_value = ((uint16_t)high_byte << 8) | low_byte;
  
  // Return the combined result
  return combined_value;
}

/******************************************************************************
* Function : uc_return_nibble_low
* Description: Extracts and returns the lower 4 bits (low nibble) of an 8-bit value.
*
* Parameters:
*   - byte (uint8_t): The 8-bit input value.
*
* Returns:
*   - (uint8_t): The lower 4 bits of the input.
*******************************************************************************/
uint8_t uc_return_nibble_low(uint8_t byte)
{
  // Extract the lower 4 bits (mask with 0x0F)
    return (byte & 0x0F);
}

/******************************************************************************
* Function : uc_return_nibble_high
* Description: Extracts and returns the upper 4 bits (high nibble) of an 8-bit value.
*
* Parameters:
*   - byte (uint8_t): The 8-bit input value.
*
* Returns:
*   - (uint8_t): The upper 4 bits of the input, right-aligned.
*  
*******************************************************************************/
uint8_t uc_return_nibble_high(uint8_t byte)
{
  // Extract the lower 4 bits (mask with 0x0F)
    return ((byte >> 4) & 0x0F);
}

/******************************************************************************
* Function : uc_set_bit
* Description: Sets a specific bit in an 8-bit value.
*
* Parameters:
*   - byte: The original 8-bit value.
*   - bit_position: The position of the bit to set (0-7).
*
* Returns:
*   - The modified 8-bit value with the specified bit set.
*******************************************************************************/
uint8_t uc_set_bit(uint8_t byte, uint8_t bit_position)
{
    return byte | (uint8_t)(1 << bit_position);
}

/******************************************************************************
* Function : uc_clear_bit
* Description: Clears a specific bit in an 8-bit value.
* Parameters:
*   - byte: The original 8-bit value.
*   - bit_position: The position of the bit to clear (0-7).
* Returns:
*   - The modified 8-bit value with the specified bit cleared.
*******************************************************************************/
uint8_t uc_clear_bit(uint8_t byte, uint8_t bit_position)
{
    return byte & ~(uint8_t)(1 << bit_position);
}

#endif /* UC_UTIL_FUNCTIONS */

/*** End of File **************************************************************/
