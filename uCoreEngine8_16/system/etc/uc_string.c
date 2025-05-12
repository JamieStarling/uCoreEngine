/****************************************************************************
* Title                 :   Core MCU Framework Generic Utilities
* Filename              :   utils.c
* Author                :   Jamie Starling
* Origin Date           :   2024/08/15
* Version               :   1.0.2
* Compiler              :   XC8
* Target                :   Microchip PIC16F series
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
*   2024/08/15  1.0.0       Jamie Starling  Initial Version
*  
*
*****************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "uc_string.h"

/******************************************************************************
* Defines / Options
*******************************************************************************/
#if UC_STRING_FUNCTIONS     

/******************************************************************************
* Interface
*******************************************************************************/
const uc_strings_interface_t UC_STRINGS = {
    .float_to_string = &uc_float_to_string,
    .int_to_string = &uc_int_to_string,
};

/******************************************************************************
* Functions
*******************************************************************************/

/******************************************************************************
* Function : uc_float_to_string
* Description: Converts a floating-point number to a string representation with a specified 
* number of decimal places. The function handles both positive and negative 
* numbers and formats the output as a null-terminated string.
* 
* Parameters:
* - float number: The floating-point number to convert.
* - char* buffer: A pointer to the character array to store the resulting string.
* - uint8_t decimalPlaces: The number of decimal places to include in the output.
*******************************************************************************/

void uc_float_to_string(float number, char* buffer, uint8_t decimal_places)
{
    int32_t integerPart = (int32_t)number;
    int32_t decimalPart;
    uint8_t i = 0;
    bool isNegative = false;

    // Handle negative numbers
    if (number < 0) {
        isNegative = true;
        number = -number;
        integerPart = -integerPart;
    }

    // Extract integer part
    do {
        buffer[i++] = (integerPart % 10) + '0';
        integerPart /= 10;
    } while (integerPart > 0);

    // Add negative sign if necessary
    if (isNegative) {
        buffer[i++] = '-';
    }

    // Reverse the integer part
    for (uint8_t j = 0; j < i / 2; j++) {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }

    // Add decimal point
    buffer[i++] = '.';

    // Extract decimal part
    number -= (int32_t)number;
    for (uint8_t j = 0; j < decimal_places; j++) {
        number *= 10;
    }
    decimalPart = (int32_t)number;

    // Convert decimal part to string
    for (uint8_t j = 0; j < decimal_places; j++) {
        buffer[i + decimal_places - j - 1] = (decimalPart % 10) + '0';
        decimalPart /= 10;
    }

    // Null-terminate the string
    buffer[i + decimal_places] = '\0';
}

/****************************************************************************** 
* Function : uc_int_to_string 
* Description: Converts an integer number to a string representation. The function handles 
* both positive and negative numbers and formats the output as a null-terminated 
* string.
*
* Parameters:
* - int32_t number: The integer number to convert.
* - char* buffer: A pointer to the character array to store the resulting string.
*******************************************************************************/
void uc_int_to_string(int32_t number, char* buffer)
{
    uint8_t i = 0;
    bool isNegative = false;

    // Handle negative numbers
    if (number < 0) {
        isNegative = true;
        number = -number;
    }

    // Extract digits and store them in the buffer
    do {
        buffer[i++] = (number % 10) + '0';
        number /= 10;
    } while (number > 0);

    // Add negative sign if necessary
    if (isNegative) {
        buffer[i++] = '-';
    }

    // Reverse the buffer to get the correct order
    for (uint8_t j = 0; j < i / 2; j++) {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }

    // Null-terminate the string
    buffer[i] = '\0';
}

#endif /* #if UC_STRING_FUNCTIONS     */
/*** End of File **************************************************************/
