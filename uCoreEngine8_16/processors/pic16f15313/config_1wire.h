/****************************************************************************
* Title                 :   uCore Engine Config for One Wire
* Filename              :   config_1wire.h
* Author                :   Jamie Starling
* Origin Date           :   2024/12/24
* Version               :   1.0.0
* Compiler              :   XC8
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
*   Date        Version     Author         Description 
*   2024/12/24  1.0.0       Jamie Starling  Initial Version
*  
*****************************************************************************/


/******************************************************************************
* Includes
*******************************************************************************/
#include "pic16f15313.h"

#ifdef UC_SYSTEM_PROCESSOR_16F15313

#ifndef UC_CONFIG_PROCESSOR_CONFIG_1WIRE_H
#define UC_CONFIG_PROCESSOR_CONFIG_1WIRE_H

/******************************************************************************
***** Configuration for One Wire
*******************************************************************************/
/*PORTA.0*/
#define UC_OW_DIRECTION_REGISTER TRISAbits.TRISA0
#define UC_OW_PINDRIVER_REGISTER LATAbits.LATA0
#define UC_OW_PINREAD_REGISTER PORTAbits.RA0
#define UC_OW_PINANALOG_REGISTER ANSELAbits.ANSA0


#endif /* UC_DEVICE_CONFIG_1WIRE_H */
#endif /* #ifdef UC_SYSTEM_DEVICE_16F15313 */
/*** End of File **************************************************************/
