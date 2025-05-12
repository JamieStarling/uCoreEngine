/****************************************************************************
* Title                 :   GPIO Lookup Table
* Filename              :   LU_gpio.c
* Author                :   Jamie Starling
* Origin Date           :   2025/02/06
* Version               :   1.0.0
* Compiler              :   XC16 
* Target                :   24F Devices 
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


/*************** CHANGE LOG ***************************************************
*
*    Date    Version   Author         Description 
*
*******************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "LU_gpio.h"

#ifdef UC_SYSTEM_PROCESSOR_16F18015

const uc_gpio_registers_t gpio_register_lu[] = {
    {&TRISA, &LATA, &PORTA, &WPUA, &ANSELA, &ODCONA, 0b00000001U},  // RA.0
    {&TRISA, &LATA, &PORTA, &WPUA, &ANSELA, &ODCONA, 0b00000010U},  // RA.1
    {&TRISA, &LATA, &PORTA, &WPUA, &ANSELA, &ODCONA, 0b00000100U},  // RA.2
    {&TRISA, &LATA, &PORTA, &WPUA, &ANSELA, &ODCONA, 0b00001000U},  // RA.3
    {&TRISA, &LATA, &PORTA, &WPUA, &ANSELA, &ODCONA, 0b00010000U},  // RA.4
    {&TRISA, &LATA, &PORTA, &WPUA, &ANSELA, &ODCONA, 0b00100000U},  // RA.5 
};

#endif 

/*** End of File **************************************************************/
