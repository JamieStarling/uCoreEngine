/****************************************************************************
* Title                 :   PPS Peripheral Pin Select functions
* Filename              :   pps.h
* Author                :   Jamie Starling
* Origin Date           :   2024/12/20
* Version               :   1.0.0
* Compiler              :   XC8
* Target                :   
* Copyright             :   © 2024 Jamie Starling
* All Rights Reserved
*
* 
* Purpose : Functions to for mapping The Peripheral Pin Select (PPS) module
*  (PPS) module connects peripheral inputs and outputs to the device I/O pins
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
*   2024/12/20  1.0.0       Jamie Starling  Initial Version
*  
*****************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "../pps.h"

#ifndef _UC_HAL_18F_PPS_H
#define _UC_HAL_18F_PPS_H

#if (UC_PROCESSOR_HAL_PPS && UC_UCORE_MCU_18F)


/******************************************************************************
* Function Prototypes
*******************************************************************************/

void uc_hal_pps_map_output(uc_gpio_portpins_t port_pin, uc_pps_output_peripheral_t pps_device);

#if UC_HAL_PPS_FUNCTION_MAP_BIDIRECTIONAL
    void uc_hal_pps_map_bidirectional(uc_gpio_portpins_t port_pin, uc_pps_output_peripheral_t pps_device, volatile uint8_t *regPPC_Input_ptr);
#endif

#if UC_HAL_PPS_FUNCTION_MAP_INPUT    
    void uc_hal_pps_map_input(uc_gpio_portpins_t port_pin, volatile uint8_t *regPPC_Input_ptr);
#endif

#endif /*UC_HAL_PPS_H*/
#endif 
/*** End of File **************************************************************/
