#include <report.h>
#include "circular_buffer.h"

void delay();
//static int wait=1;
extern int tx_flag;
extern int wait_flag;
extern cb *tx;

#define puneet

#ifndef puneet
void generate_report(uint8_t *report_character)
{
	//wait_flag = 1;
	for(uint8_t i=0; i<127; i++)
	{
		if(*(report_character+i) != 0)
		{
			wait_flag = 1;
			//UART0_C2 |= (UART0_C2_TIE_MASK);
			while(wait_flag == 2 || wait_flag == 1){
			if(wait_flag == 1){
			switch(wait)
			{
			case 1:
			{
				//delay();
				//UART0_C2 |= (UART0_C2_TIE_MASK);
				uart0_putchar((char)i);

				//UART0_C2 |= (UART0_C2_TIE_MASK);
				wait++;
				wait_flag = 2;
				UART0_C2 |= (UART0_C2_TIE_MASK);
				break;
			}
			case 2:
			{
				//UART0_C2 |= (UART0_C2_TIE_MASK);
				uart0_putchar(' ');
				wait++;
				wait_flag = 2;
				UART0_C2 |= (UART0_C2_TIE_MASK);
				break;
			}
			case 3 :
			{
				//UART0_C2 |= (UART0_C2_TIE_MASK);
				uart0_putchar('-');
				wait++;
				wait_flag = 2;
				UART0_C2 |= (UART0_C2_TIE_MASK);
				break;
			}
			case 4 :
			{
				//UART0_C2 |= (UART0_C2_TIE_MASK);
				uart0_putchar(' ');
				wait++;
				wait_flag = 2;
				UART0_C2 |= (UART0_C2_TIE_MASK);
				break;
			}
			case 5:
			{
				//UART0_C2 |= (UART0_C2_TIE_MASK);
				putnumber(*(report_character+i));
				wait++;
				wait_flag = 2;
				UART0_C2 |= (UART0_C2_TIE_MASK);
				break;
			}
			case 6:
			{
				//UART0_C2 |= (UART0_C2_TIE_MASK);
				uart0_putchar('\n');
				wait++;
				wait_flag = 2;
				UART0_C2 |= (UART0_C2_TIE_MASK);
				break;
			}
			case 7:
			{
				//UART0_C2 |= (UART0_C2_TIE_MASK);
				uart0_putchar('\r');

				wait = 1;
				wait_flag = 0;

				UART0_C2 |= (UART0_C2_TIE_MASK);
				break;
			}
			}
			}
			}
		}

	}
	//tx_flag=0;
	/*uart0_putchar('\n');
	UART0_C2 |= (UART0_C2_TIE_MASK);
	delay();*/
}

#else

void generate_report(uint8_t *report_character)
{
	//wait_flag=1;
	uint8_t num,rem;
	for(uint8_t i=0; i<127; i++)
		{
		num=*(report_character+i);
		if(*(report_character+i) != 0)
				{

				cb_add(tx,(char)i);
				cb_add(tx,' ');
				cb_add(tx,'-');
				while(num!=0)
					{
					rem=num%10;
					num=num/10;
					if(num!=0)
					cb_add(tx,num+48);
					else
					cb_add(tx,rem+48);
					}

				cb_add(tx,'\n');
				cb_add(tx,'\r');

				}

		}
	//wait_flag=0;

}
#endif

void delay()
{
	for(uint16_t z=0;z<1000;z++);
}
