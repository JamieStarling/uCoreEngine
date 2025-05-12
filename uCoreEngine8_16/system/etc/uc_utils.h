/****************************************************************************
* Title                 :   uCore 8 Engine Generic Utilities
* Filename              :   uc_utils.h
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
*****************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "../uc_core_system.h"

/******************************************************************************
* Defines / Options
*******************************************************************************/
#if UC_UTIL_FUNCTIONS 

#ifndef UC_UTILS_H
#define UC_UTILS_H
/******************************************************************************
***** UC_UTILS Interface
*******************************************************************************/
typedef struct {
    uint16_t(*make_16)(uint8_t high_byte, uint8_t low_byte);  
    uint8_t(*get_low_nibble)(uint8_t byte);
    uint8_t(*get_high_nibble)(uint8_t byte);
    uint8_t(*set_bit)(uint8_t byte, uint8_t bit_position);
    uint8_t(*clear_bit)(uint8_t byte, uint8_t bit_position);
}uc_utils_interface_t;

extern const uc_utils_interface_t UC_UTILS;





/******************************************************************************
* Function Prototypes
*******************************************************************************/
uint16_t uc_make_16(uint8_t high_byte, uint8_t low_byte);
uint8_t uc_return_nibble_low(uint8_t byte);
uint8_t uc_return_nibble_high(uint8_t byte);
uint8_t uc_set_bit(uint8_t byte, uint8_t bit_position);
uint8_t uc_clear_bit(uint8_t byte, uint8_t bit_position);

#endif /* UC_UTILS_H*/
#endif /* UC_UTIL_FUNCTIONS */
/*** End of File **************************************************************/
