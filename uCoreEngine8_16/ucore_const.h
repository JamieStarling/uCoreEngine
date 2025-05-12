/****************************************************************************
* Title                 :   uCore Engine Constants
* Filename              :   ucore_const.h
* Author                :   Jamie Starling
* Origin Date           :   2025/04/25
* Version               :   1.0.0
* Compiler              :   
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
*   2025/04/25  1.0.0       Jamie Starling  Initial Version
*  
******************************************************************************/

#ifndef _UC_SYSTEM_CONST_H
#define _UC_SYSTEM_CONST_H

/******************************************************************************
********* Constants
*******************************************************************************/

/***Constants: Logic Values***/
/*uc_logic_t defines common logic values for use in the Core8 framework. 
* This enum provides standard definitions for enabled/disabled states, boolean values,
* pin states, and common control settings.*/
typedef enum 
{   UC_DISABLED        = 0,	
    UC_ENABLED         = 1,	
    UC_FALSE           = 0,		
    UC_TRUE            = 1,
    UC_OFF             = 0,
    UC_ON              = 1,
    UC_LOW             = 0,			    
    UC_HIGH            = 1, 
    UC_NA              = 0,  //Does not apply / Not Used
    UC_CLEAR           = 0,
    UC_SET             = 1,    
}uc_logic_t;


typedef enum 
{
  UC_STATUS_OK       = 1,
  UC_STATUS_FAILED   = 0
  
}uc_return_status_t;


#define UC_SYSTEM_ENABLE    1
#define UC_SYSTEM_DISABLE   0
#define UC_SYSTEM_ENABLED   1
#define UC_SYSTEM_DISABLED  0


/******************************************************************************
*********Typedefs
*******************************************************************************/
typedef bool boolean;       //Alias for the standard `bool` type, for use in logical conditions.
typedef uint8_t byte;       //Alias for the standard `uint8_t`, representing an 8-bit unsigned value.
typedef unsigned int word;  //Alias for `unsigned int`, representing a 16-bit unsigned value.

#endif /*_UC_SYSTEM_CONST_H*/

/*** End of File **************************************************************/
