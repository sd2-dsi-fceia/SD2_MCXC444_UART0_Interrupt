/* Copyright , DSI FCEIA UNR - Sistemas Digitales 2
 *    DSI: http://www.dsi.fceia.unr.edu.ar/
 * Copyright, Diego Alegrechi
 * Copyright, Gustavo Muro
 * Copyright, Prof. Ing. Daniel Márquez 2025
 * Copyright, Guido Cicconi 2025
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*==================[inclusions]=============================================*/

// Standard C Included Files
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

// Project Included Files
#include "SD2_board.h"
#include "clock_config.h"
#include "fsl_lpuart.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

static int32_t i;

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

int main(void)
{
	BOARD_BootClockRUN();

	// Se inicializan funciones de la placa
	board_init();

    while(1)
    {
       /* Tarea en segundo plano */
    	board_setLed(BOARD_LED_ID_ROJO, BOARD_LED_MSG_TOGGLE);
    	for(i = 0; i < 1000000; i++);
    }
}

void LPUART0_IRQHandler(void)
{
	uint8_t rxChar;

    /* si llega un dato nuevo */
    if ((kLPUART_RxDataRegFullFlag) & LPUART_GetStatusFlags(LPUART0))
    {
    	rxChar = LPUART_ReadByte(LPUART0);
    	LPUART_WriteByte(LPUART0, rxChar);
    	board_setLed(BOARD_LED_ID_VERDE, BOARD_LED_MSG_TOGGLE);
    }
}

/*==================[end of file]============================================*/
