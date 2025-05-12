/****************************************************************************
* Title                 :   uCore Engine Processor Header
* Filename              :   processors.h
* Author                :   Jamie Starling
* Origin Date           :   2025/04/25
* Version               :   1.0.0
* Compiler              :   XC8/XC16
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

/***************  CHANGE LIST *************************************************
*
*   Date        Version     Author          Description 
*   2024/12/19  1.0.0       Jamie Starling  Initial Version
*  
*****************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "../ucore8-16.h"

#ifndef _UC_ENGINE_PROCESSORS_H
#define _UC_ENGINE_PROCESSORS_H


/******************************************************************************
************ Sets uCore Engine Processor
*******************************************************************************/
/******************************************************************************
* Sets the uCore 8 processor device
*******************************************************************************/
#if defined(_PIC16F15313_H_) /****PIC16F15313****/
    #define UC_SYSTEM_PROCESSOR_16F15313    
    #define UC_UCORE_MCU_16F 1   
    #define UC_VERSION_MCU_TARGET 16F
    #define UC_VERSION_MCU_ARCH 8BIT
    #include "pic16f15313/pic16f15313.h"

/****PIC16F1532X Series (PIC16F15323, PIC16F15324, PIC16F15325)****/
#elif defined(_PIC16F15323_H_) || defined(_PIC16F15324_H_) || defined(_PIC16F15325_H_)
    #define UC_SYSTEM_PROCESSOR_16F1532X
    #define UC_UCORE_MCU_16F 1       
    #define UC_VERSION_MCU_TARGET 16F
    #define UC_VERSION_MCU_ARCH 8BIT
    #include "pic16f1532x/pic16f1532x.h"

/****PIC16F18015****/
#elif defined(_PIC16F18015_H_) 
    #define UC_SYSTEM_PROCESSOR_16F18015
    #define UC_UCORE_MCU_16F 1      
    #define UC_VERSION_MCU_TARGET 16F
    #define UC_VERSION_MCU_ARCH 8BIT
    #include "pic16f18015/pic16f18015.h"

/***************************** 18F Processors*/

#elif defined (_PIC18F26Q84_H_) || defined(_PIC18F27Q84_H_)
    #define UC_SYSTEM_PROCESSOR_18F2xQ84
    #define UC_UCORE_MCU_18F 1       
    #define UC_VERSION_MCU_TARGET 18F
    #define UC_VERSION_MCU_ARCH 8BIT
    #include "pic18f2xq84/pic18f2xq84.h"

#elif defined(_PIC18F16Q41_H_) || defined(_PIC18F15Q41_H_) || defined(_PIC18F14Q41_H_)
    #define UC_SYSTEM_PROCESSOR_18F1xQ41
    #define UC_VERSION_MCU_TARGET 18F
    #define UC_VERSION_MCU_ARCH 8BIT


#else /**** Unsupported Processor ****/
    #error "Unsupported processor: Please check your device or add support for this processor."
#endif


#endif /*UC_PROCESSOR_H*/

/*** End of File **************************************************************/
