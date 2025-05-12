/****************************************************************************
* Title                 :   Configuration Bits for 16F18015
* Filename              :   config_bits.c
* Author                :   Jamie Starling
* Origin Date           :   2024/12/26
* Version               :   1.0.0
* Compiler              :   XC8
* Target                :   PIC16F15313
* Copyright             :   Jamie Starling
* All Rights Reserved
*
* 
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
#include "pic16f18015.h"

#ifdef UC_SYSTEM_PROCESSOR_16F18015

#ifndef _UC_DEVICE_16F18015_CONFIG_BITS_H
#define _UC_DEVICE_16F18015_CONFIG_BITS_H


//CONFIG1
#pragma config FEXTOSC = OFF    // External Oscillator Selection bits->Oscillator not enabled
#pragma config RSTOSC = HFINTOSC_32MHz    // Reset Oscillator Selection bits->HFINTOSC (32 MHz)
#pragma config CLKOUTEN = OFF    // Clock Out Enable bit->CLKOUT function is disabled; i/o or oscillator function on OSC2
#pragma config VDDAR = HI    // VDD Range Analog Calibration Selection bit->Internal analog systems are calibrated for operation between VDD = 2.3 - 5.5V

//CONFIG2
#pragma config MCLRE = INTMCLR    // Master Clear Enable bit->If LVP = 0, MCLR is port-defined function; If LVP = 1, RA3 pin function is MCLR
#pragma config PWRTS = PWRT_64    // Power-up Timer Selection bits->PWRT set at 64 ms

#if UC_DEVICE_HAL_WATCHDOG
    #pragma config WDTE = SWDTEN// WDT operating mode->WDT Controlled by Software
#else
    #pragma config WDTE = OFF    // WDT operating mode->WDT Disabled, SWDTEN is ignored
#endif //END UC_DEVICE_HAL_WATCHDOG

#pragma config BOREN = ON    // Brown-out Reset Enable bits->Brown-out Reset enabled, SBOREN bit is ignored
#pragma config DACAUTOEN = OFF    // DAC Buffer Automatic Range Select Enable bit->DAC Buffer reference range is determined by the REFRNG bit
#pragma config BORV = LO    // Brown-out Reset Voltage Selection bit->Brown-out Reset Voltage (VBOR) set to 1.9V
#pragma config ZCD = OFF    // ZCD Disable bit->ZCD module is disabled; ZCD can be enabled by setting the ZCDSEN bit of ZCDCON
#pragma config PPS1WAY = OFF    // PPSLOCKED One-Way Set Enable bit->The PPSLOCKED bit can be set and cleared as needed (unlocking sequence is required)
#pragma config STVREN = ON    // Stack Overflow/Underflow Reset Enable bit->Stack Overflow or Underflow will cause a reset

//CONFIG4
#pragma config BBSIZE = BB512    // Boot Block Size Selection bits->512 words boot block size
#pragma config BBEN = OFF    // Boot Block Enable bit->Boot Block disabled
#pragma config SAFEN = OFF    // Storage Area Flash (SAF) Enable bit->SAF disabled
#pragma config WRTAPP = OFF    // Application Block Write Protection bit->Application Block is NOT write protected
#pragma config WRTB = OFF    // Boot Block Write Protection bit->Boot Block is NOT write protected
#pragma config WRTC = OFF    // Configuration Register Write Protection bit->Configuration Register is NOT write protected
#pragma config WRTD = OFF    // Data EEPROM Write Protection bit->Data EEPROM is NOT write-protected
#pragma config WRTSAF = OFF    // Storage Area Flash (SAF) Write Protection bit->SAF is NOT write protected
#pragma config LVP = ON    // Low Voltage Programming Enable bit->Low Voltage programming enabled. MCLR/Vpp pin function is MCLR. MCLRE Configuration bit is ignored

//CONFIG5
#pragma config CP = OFF    // Program Flash Memory Code Protection bit->Program Flash Memory code protection is disabled
#pragma config CPD = OFF    // Data EEPROM Code Protection bit->EEPROM code protection is disabled


#endif /*UC_DEVICE_16F18015_CONFIG_BITS_H*/
#endif /*#ifdef UC_SYSTEM_DEVICE_16F18015 */
/*** End of File **************************************************************/
