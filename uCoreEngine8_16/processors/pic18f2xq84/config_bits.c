/****************************************************************************
* Title                 :   <TITLE>
* Filename              :   %<%NAME%>%.%<%EXTENSION%>%
* Author                :   Jamie Starling
* Origin Date           :   %<%DATE%>%, %<%TIME%>%
* Version               :   1.0.0
* Compiler              :    
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

/*************** TODO *********************************************************
 * 
 * 
 * 
*****************************************************************************/


/*************** CHANGE LOG ***************************************************
*
*    Date    Version   Author         Description 
*
*******************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "pic18f2xq84.h"

#ifdef UC_SYSTEM_PROCESSOR_18F2xQ84

//CONFIG1
#pragma config FEXTOSC = OFF     // External Oscillator Selection->Oscillator not enabled
#pragma config RSTOSC = HFINTOSC_64MHZ     // Reset Oscillator Selection->HFINTOSC with HFFRQ = 64 MHz and CDIV = 1:1

//CONFIG2
#pragma config CLKOUTEN = OFF     // Clock out Enable bit->CLKOUT function is disabled
#pragma config PR1WAY = OFF     // PRLOCKED One-Way Set Enable bit->PRLOCKED bit can be set and cleared repeatedly
#pragma config CSWEN = ON     // Clock Switch Enable bit->Writing to NOSC and NDIV is allowed
#pragma config JTAGEN = OFF     // JTAG Enable bit->Disable JTAG Boundary Scan mode, JTAG pins revert to user functions
#pragma config FCMEN = ON     // Fail-Safe Clock Monitor Enable bit->Fail-Safe Clock Monitor enabled
#pragma config FCMENP = ON     // Fail-Safe Clock Monitor -Primary XTAL Enable bit->FSCM timer will set FSCMP bit and OSFIF interrupt on Primary XTAL failure
#pragma config FCMENS = ON     // Fail-Safe Clock Monitor -Secondary XTAL Enable bit->FSCM timer will set FSCMS bit and OSFIF interrupt on Secondary XTAL failure

//CONFIG3
#pragma config MCLRE = INTMCLR     // MCLR Enable bit->If LVP = 0, MCLR pin function is port defined function; If LVP =1, RE3 pin fuction is MCLR
#pragma config PWRTS = PWRT_64     // Power-up timer selection bits->PWRT set at 64ms
#pragma config MVECEN = ON     // Multi-vector enable bit
#pragma config IVT1WAY = OFF     // IVTLOCK bit One-way set enable bit
#pragma config LPBOREN = ON     // Low Power BOR Enable bit->Low-Power BOR enabled
#pragma config BOREN = SBORDIS     // Brown-out Reset Enable bits->Brown-out Reset enabled , SBOREN bit is ignored

//CONFIG4
#pragma config BORV = VBOR_1P9     // Brown-out Reset Voltage Selection bits->Brown-out Reset Voltage (VBOR) set to 1.9V
#pragma config ZCD = OFF     // ZCD Disable bit->ZCD module is disabled. ZCD can be enabled by setting the ZCDSEN bit of ZCDCON
#pragma config PPS1WAY = OFF     // PPSLOCK bit One-Way Set Enable bit->PPSLOCKED bit can be set and cleared repeatedly (subject to the unlock sequence)
#pragma config STVREN = ON     // Stack Full/Underflow Reset Enable bit->Stack full/underflow will cause Reset
#pragma config LVP = ON     // Low Voltage Programming Enable bit->Low voltage programming enabled. MCLR/VPP pin function is MCLR. MCLRE configuration bit is ignored
#pragma config XINST = OFF     // Extended Instruction Set Enable bit->Extended Instruction Set and Indexed Addressing Mode disabled

//CONFIG5
#pragma config WDTCPS = WDTCPS_31     // WDT Period selection bits->Divider ratio 1:65536; software control of WDTPS
#pragma config WDTE = OFF     // WDT operating mode->WDT Disabled; SWDTEN is ignored

//CONFIG6
#pragma config WDTCWS = WDTCWS_7     // WDT Window Select bits->window always open (100%); software control; keyed access not required
#pragma config WDTCCS = SC     // WDT input clock selector->Software Control

//CONFIG7
#pragma config BBSIZE = BBSIZE_512     // Boot Block Size selection bits->Boot Block size is 512 words
#pragma config BBEN = OFF     // Boot Block enable bit->Boot block disabled
#pragma config SAFEN = OFF     // Storage Area Flash enable bit->SAF disabled

//CONFIG8
#pragma config WRTB = OFF     // Boot Block Write Protection bit->Boot Block not Write protected
#pragma config WRTC = OFF     // Configuration Register Write Protection bit->Configuration registers not Write protected
#pragma config WRTD = OFF     // Data EEPROM Write Protection bit->Data EEPROM not Write protected
#pragma config WRTSAF = OFF     // SAF Write protection bit->SAF not Write Protected
#pragma config WRTAPP = OFF     // Application Block write protection bit->Application Block not write protected

//CONFIG9
#pragma config BOOTPINSEL = RC5     // CRC on boot output pin selection->CRC on boot output pin is RC5
#pragma config BPEN = OFF     // CRC on boot output pin enable bit->CRC on boot output pin disabled
#pragma config ODCON = OFF     // CRC on boot output pin open drain bit->Pin drives both high-going and low-going signals

//CONFIG10
#pragma config CP = OFF     // PFM and Data EEPROM Code Protection bit->PFM and Data EEPROM code protection disabled

//CONFIG11
#pragma config BOOTSCEN = OFF     // CRC on boot scan enable for boot area->CRC on boot will not include the boot area of program memory in its calculation
#pragma config BOOTCOE = HALT     // CRC on boot Continue on Error for boot areas bit->CRC on boot will stop device if error is detected in boot areas
#pragma config APPSCEN = OFF     // CRC on boot application code scan enable->CRC on boot will not include the application area of program memory in its calculation
#pragma config SAFSCEN = OFF     // CRC on boot SAF area scan enable->CRC on boot will not include the SAF area of program memory in its calculation
#pragma config DATASCEN = OFF     // CRC on boot Data EEPROM scan enable->CRC on boot will not include data EEPROM in its calculation
#pragma config CFGSCEN = OFF     // CRC on boot Config fuses scan enable->CRC on boot will not include the configuration fuses in its calculation
#pragma config COE = HALT     // CRC on boot Continue on Error for non-boot areas bit->CRC on boot will stop device if error is detected in non-boot areas
#pragma config BOOTPOR = OFF     // Boot on CRC Enable bit->CRC on boot will not run

//CONFIG12
#pragma config BCRCPOLT = hFF     // Boot Sector Polynomial for CRC on boot bits 31-24->Bits 31:24 of BCRCPOL are 0xFF

//CONFIG13
#pragma config BCRCPOLU = hFF     // Boot Sector Polynomial for CRC on boot bits 23-16->Bits 23:16 of BCRCPOL are 0xFF

//CONFIG14
#pragma config BCRCPOLH = hFF     // Boot Sector Polynomial for CRC on boot bits 15-8->Bits 15:8 of BCRCPOL are 0xFF

//CONFIG15
#pragma config BCRCPOLL = hFF     // Boot Sector Polynomial for CRC on boot bits 7-0->Bits 7:0 of BCRCPOL are 0xFF

//CONFIG16
#pragma config BCRCSEEDT = hFF     // Boot Sector Seed for CRC on boot bits 31-24->Bits 31:24 of BCRCSEED are 0xFF

//CONFIG17
#pragma config BCRCSEEDU = hFF     // Boot Sector Seed for CRC on boot bits 23-16->Bits 23:16 of BCRCSEED are 0xFF

//CONFIG18
#pragma config BCRCSEEDH = hFF     // Boot Sector Seed for CRC on boot bits 15-8->Bits 15:8 of BCRCSEED are 0xFF

//CONFIG19
#pragma config BCRCSEEDL = hFF     // Boot Sector Seed for CRC on boot bits 7-0->Bits 7:0 of BCRCSEED are 0xFF

//CONFIG20
#pragma config BCRCEREST = hFF     // Boot Sector Expected Result for CRC on boot bits 31-24->Bits 31:24 of BCRCERES are 0xFF

//CONFIG21
#pragma config BCRCERESU = hFF     // Boot Sector Expected Result for CRC on boot bits 23-16->Bits 23:16 of BCRCERES are 0xFF

//CONFIG22
#pragma config BCRCERESH = hFF     // Boot Sector Expected Result for CRC on boot bits 15-8->Bits 15:8 of BCRCERES are 0xFF

//CONFIG23
#pragma config BCRCERESL = hFF     // Boot Sector Expected Result for CRC on boot bits 7-0->Bits 7:0 of BCRCERES are 0xFF

//CONFIG24
#pragma config CRCPOLT = hFF     // Non-Boot Sector Polynomial for CRC on boot bits 31-24->Bits 31:24 of CRCPOL are 0xFF

//CONFIG25
#pragma config CRCPOLU = hFF     // Non-Boot Sector Polynomial for CRC on boot bits 23-16->Bits 23:16 of CRCPOL are 0xFF

//CONFIG26
#pragma config CRCPOLH = hFF     // Non-Boot Sector Polynomial for CRC on boot bits 15-8->Bits 15:8 of CRCPOL are 0xFF

//CONFIG27
#pragma config CRCPOLL = hFF     // Non-Boot Sector Polynomial for CRC on boot bits 7-0->Bits 7:0 of CRCPOL are 0xFF

//CONFIG28
#pragma config CRCSEEDT = hFF     // Non-Boot Sector Seed for CRC on boot bits 31-24->Bits 31:24 of CRCSEED are 0xFF

//CONFIG29
#pragma config CRCSEEDU = hFF     // Non-Boot Sector Seed for CRC on boot bits 23-16->Bits 23:16 of CRCSEED are 0xFF

//CONFIG30
#pragma config CRCSEEDH = hFF     // Non-Boot Sector Seed for CRC on boot bits 15-8->Bits 15:8 of CRCSEED are 0xFF

//CONFIG31
#pragma config CRCSEEDL = hFF     // Non-Boot Sector Seed for CRC on boot bits 7-0->Bits 7:0 of CRCSEED are 0xFF

//CONFIG32
#pragma config CRCEREST = hFF     // Non-Boot Sector Expected Result for CRC on boot bits 31-24->Bits 31:24 of CRCERES are 0xFF

//CONFIG33
#pragma config CRCERESU = hFF     // Non-Boot Sector Expected Result for CRC on boot bits 23-16->Bits 23:16 of CRCERES are 0xFF

//CONFIG34
#pragma config CRCERESH = hFF     // Non-Boot Sector Expected Result for CRC on boot bits 15-8->Bits 15:8 of CRCERES are 0xFF

//CONFIG35
#pragma config CRCERESL = hFF     // Non-Boot Sector Expected Result for CRC on boot bits 7-0->Bits 7:0 of CRCERES are 0xFF





#endif
/*** End of File **************************************************************/
