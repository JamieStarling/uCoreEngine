/****************************************************************************
* Title                 :   uCore Engine - 16F Series Main ISR Function
* Filename              :   main_isr.c
* Author                :   Jamie Starling
* Origin Date           :   2024/12/23
* Version               :   1.0.0
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
*   2024/12/23  1.0.0       Jamie Starling  Initial Version
*  
*****************************************************************************/

/******************************************************************************
***** Includes
*******************************************************************************/
#include "16f_isr_control.h"

/******************************************************************************
****** Functions
*******************************************************************************/
/******************************************************************************
* Function : uc_isr_routine_16F()
* Description: Main interrupt service routine (ISR) for the Core MCU framework, handling 
* system interrupts. Processes system timer interrupts and can be expanded 
* to include additional interrupt handlers as needed.
*
*******************************************************************************/

#if (UC_UCORE_MCU_16F && UC_PROCESSOR_HAL_ISR)

void __interrupt () uc_isr_routine_16F(void) {  
    
  //Processes the Interrupt Handlers. 
  for (uint8_t i = 0; i < UC_ISR_MAX_HANDLERS; i++) {
        if (uc_isr_handlers[i] != 0) {
            uc_isr_handlers[i]();
        }
    }  
}
#endif /* UC_UCORE_MCU_16F */


/*** End of File **************************************************************/

