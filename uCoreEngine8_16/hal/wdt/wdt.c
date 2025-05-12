/****************************************************************************
* Title                 :   CORE MCU WatchDog Timer Functions
* Filename              :   wdt.c
* Author                :   Jamie Starling
* Origin Date           :   2024/12/26
* Version               :   1.0.0
* Compiler              :   XC8
* Target                :   MicroChip PIC 16F devices
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

/*************** CHANGE LOG ***************************************************
*
*    Date    Version   Author         Description 
*
*******************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "wdt.h"

#if UC_DEVICE_HAL_WATCHDOG

/******************************************************************************
***** Watchdog Interface
*******************************************************************************/
const uc_wdt_interface_t WDT = {
  .initialize = &uc_hal_wdt_init,
  .enable = &uc_hal_wdt_enable,
  .clear = &uc_hal_wdt_clear
};

/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : <NAME>
*//** 
* \b Description:
*
*******************************************************************************/
void uc_hal_wdt_init(uc_hal_wdt_interval_t interval)
{
  WDTCON0bits.WDTPS = interval;
  WDTCON1bits.WDTCS = 0b000;  // Set to LFINTOSC 31Khz
  uc_hal_wdt_enable(UC_ENABLED);
}

/******************************************************************************
* Function : <NAME>
*//** 
* \b Description:
*
*******************************************************************************/
void uc_hal_wdt_enable(uc_logic_t set_state)
{
  WDTCON0bits.SWDTEN = (set_state == UC_ENABLED) ? 0x01 : 0x00;  
}

/******************************************************************************
* Function : <NAME>
*//** 
* \b Description:
*
*******************************************************************************/
void uc_hal_wdt_clear(void)
{
  CLRWDT();
}

#endif /* #if UC_DEVICE_HAL_WATCHDOG */

/*** End of File **************************************************************/
