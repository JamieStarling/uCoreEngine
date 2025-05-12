/****************************************************************************
* Title                 :   uCore 8 Engine String Utilities
* Filename              :   uc_string.h
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
#ifndef _UC_SYSTEM_STRING_UTILS_H
#define _UC_SYSTEM_STRING_UTILS_H

#include "../uc_core_system.h"

/******************************************************************************
* Defines / Options
*******************************************************************************/
#if UC_STRING_FUNCTIONS     

/******************************************************************************
***** uCore Interface
*******************************************************************************/
typedef struct {
    void(*float_to_string)(float number, char* buffer, uint8_t decimal_places); 
    void(*int_to_string)(int32_t number, char* buffer);
}uc_strings_interface_t;

extern const uc_strings_interface_t UC_STRINGS;


/******************************************************************************
* Function Prototypes
*******************************************************************************/
void uc_float_to_string(float number, char* buffer, uint8_t decimal_places);
void uc_int_to_string(int32_t number, char* buffer);

#endif /*UC_STRING_UTILS_H*/
#endif /*#if UC_STRING_FUNCTIONS*/     
/*** End of File **************************************************************/
