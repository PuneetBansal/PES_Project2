#include "UART.h"
#include "MKL25Z4.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "circular_buffer.h"

char ch1;
uint8_t deleted_element;
extern cb *rx;
extern uint8_t *element_deleted;
extern uint8_t info[256];
extern int tx_flag;
int wait_flag;
buffer_status st;

void UART0_init()
{
	SIM_SCGC4 |= UART0_CLK_EN;					// enable clock to UART0
	SIM_SOPT2 |= MCGFKKCLK;						// select MCGFKKCLK as a clock @ 48MHz
	SIM_SCGC5 |= PORTA_CLK;						// enable clock to Port A

	// UART0 configuration for communication
	UART0_C2  = DISABLE_UART0;					// No interrupts, Transmitter and Receiver disabled

	//Use NVIC ,enable_irq(12)

	#ifndef Blocking_Uart
	NVIC_EnableIRQ(UART0_IRQn);
    #endif

	UART0_BDH = BDH_VALUE;						// No interrupts, 1 stop bit
	UART0_BDL = BDL_VALUE;						// Prescaler for 115200 baud rate
	UART0_C1  = UART0_MODE_SEL;					// No loop, UART enabled in wait, 8-bit mode, no parity
	UART0_C4  = OSR;							// Over sampling rate

	// Port configuration to select Alternate 2 pin function
	PORTA_PCR2 |= UART0_PIN;
	PORTA_PCR1 |= UART0_PIN;

  #ifndef Blocking_Uart
  UART0_C2 = UART0_C2_RIE_MASK; //|| UART0_C2_TIE_MASK;
  #endif
	// Enable transmitter and receiver
	UART0_C2  |= ENABLE_UART0;

  #ifndef Blocking_Uart
	__enable_irq();
  #endif
}

#ifdef Blocking_Uart
char uart0_getchar(void)
{
    rx_wait();
	return UART0_D;
}

void uart0_putchar(char ch)
{
  tx_wait();
  UART0_D = ch;
}
#else
char uart0_getchar(void)
{
  return UART0_D;
}

void uart0_putchar(char ch)
{
	UART0_D = ch;
}
#endif


void uart0_putstr(char *str)
{
	while(*str != '\0')
	{
		uart0_putchar(*str);
		for(uint16_t k=0; k<2550; k++);
		str++;
	}
}

void putnumber(uint16_t count)
{
char str[10];
sprintf(str,"%d",count);
uart0_putstr(str);
}


void tx_wait()
{
while(!(UART0_S1 & (1 << 7))); //&& !(UART0_S1 & (1 << 6)));
}

void rx_wait()
{
while(!(UART0_S1 & (1 << 5)));
}

char getch()
{
	return UART0_D;
}

void putch(char ch)
{
 cb_add(rx,ch);
 //tx_flag=1;
}

void UART0_IRQHandler(void)
{
//__disable_irq();
if(UART0_S1 & UART0_S1_RDRF_MASK)
  {
	ch1=UART0_D;
	putch(ch1);
	//UART0_C1 &= ~(UART0_C2_RIE_MASK);
	//UART0_C1 |= UART0_C2_TCIE_MASK;
  }

if(UART0_S1 & UART0_S1_TDRE_MASK)
  {
  tx_flag = 1;
  wait_flag = 1;
  UART0_C2 &= ~(UART0_C2_TIE_MASK);
  //cb_delete(rx,element_deleted);
  //UART0_D=*(element_deleted);
  //UART0_C1 &= ~(UART0_C2_TCIE_MASK);
  //UART0_C1 |= UART0_C2_RIE_MASK;
  }
//__enable_irq();
}

/*
void UART0_IRQHandler(void)
{
if (UART0_S1 & UART_S1_RDRF_MASK)
{
	ch1 = UART0_D;
if (!(UART0_S1&UART_S1_TDRE_MASK) && !(UART0_S1&UART_S1_TC_MASK))
   {    UART0_D  = ch1;
   }
}
}
*/
void uart0_putstr_nb(char *str)
{

	while(*str != '\0')
		{
			putch(*str);
			str++;
		}
}

void getinfo(uint8_t *element_deleted)
{
info[*(element_deleted)]++;
}

