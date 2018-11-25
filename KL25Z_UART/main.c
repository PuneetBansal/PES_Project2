/*
 * Copyright (c) 2013 - 2014, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

///////////////////////////////////////////////////////////////////////////////
//  Includes
///////////////////////////////////////////////////////////////////////////////
// SDK Included Files
#include <stdint.h>
#include <stdlib.h>
#include "board.h"
#include "fsl_lptmr_driver.h"
#include "fsl_debug_console.h"

#include "MKL25Z4.h"
#include "UART.h"
#include "circular_buffer.h"
#include "character_count.h"
#include "report.h"

cb *rx,*tx;

uint8_t *(element_deleted_tx);
uint8_t *(element_deleted_rx);

uint8_t* info;

int tx_flag=1;
int count=0;
//int wait_flag=0;

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////
// Timer period: 500000uS
#define TMR_PERIOD         500000U
#if defined(TWR_KV46F150M)
#define LPTMR0_IDX LPTMR_IDX
#endif

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////
/*!
 * @brief LPTMR interrupt call back function.
 * The function is used to toggle LED1.
 *
 */


void lptmr_call_back(void)
{
    // Toggle LED1
    LED1_TOGGLE;
}

/*!
 * @brief Main function
 */
cb rx_buf;
char recv;

int main (void)
{
	//int i;
	//char uart0_char;

	rx= malloc(sizeof(cb));//&rx_buf; //
	rx->buffer=malloc(1000);
	cb_init(rx,100);

	tx= malloc(sizeof(cb));//&tx_buf; //
	tx->buffer=malloc(1000);
	cb_init(tx,100);

	element_deleted_tx= malloc(2);//&recv; //malloc(2);
	element_deleted_rx= malloc(2);

	UART0_init();
    //uart0_putstr_nb("BASS");
	//uart0_putstr("\n\rHello\n\r");
	//uart0_putstr("\n\rHello\n\r");


	/*
	check=malloc(sizeof(cb));
	check->buffer=malloc(10);


	for(i=0;i<10;i++)
	{
		cb_add(ptr,i);
	}
	check=ptr;
	for(i=0;i<10;i++)
		{
		putnumber(*(check->buffer));
		uart0_putstr("\n\r");
		check->buffer++;
		}

		//UART0_init();
		uart0_putchar('p');
		uart0_putchar('u');
		uart0_putchar('n');
		uart0_putchar('e');
		uart0_putchar('e');
		uart0_putchar('t');

		uart0_putstr("\n\rHello\n\r");
		putnumber(15);*/
    //UART0_C2|= (UART0_C2_TIE_MASK);
    //buffer_status  status;
    //uart0_putstr("\n\rHello\n\r");
		while(1)
		{
			if(cb_isempty(rx)!= cb_empty)
			{
				cb_delete(rx, element_deleted_rx);
				info = character_count(element_deleted_rx);
				//UART0_C2 |= (UART0_C2_TIE_MASK);
				generate_report(info);
				//UART0_C2 |= (UART0_C2_TIE_MASK);

			}
		    	/*UART0_D=*(element_deleted);*/
		    	//UART0_C2 |= (UART0_C2_TIE_MASK);
				//tx_flag=0;

			if(tx_flag==1 && cb_isempty(tx)!=cb_empty )

			{

				tx_flag=0;
				cb_delete(tx,element_deleted_tx);
				uart0_putchar(*element_deleted_tx);

			}




			else
			{
		    	//UART0_C2 &= ~(UART0_C2_TIE_MASK);
		    }
		   // if (status == cb_empty) {
		    //	UART0_C1 |= (UART0_C2_TIE_MASK);
		    	//UART0_C1 &= ~(UART0_C2_TIE_MASK);
		   // }

		}
			//uart0_char = uart0_getchar();
			//uart0_putchar(uart0_char);

}
