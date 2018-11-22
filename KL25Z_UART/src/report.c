#include <report.h>

void delay();
static int wait=1;
extern int wait_flag;
void generate_report(uint8_t *report_character)
{
	for(uint8_t i=0; i<127; i++)
	{
		if(*(report_character+i) != 0)
		{
			wait_flag = 1;
			while(wait_flag == 2 || wait_flag == 1){
			if(wait_flag == 1){
			switch(wait)
			{
			case 1:
			{
				//delay();
				UART0_C2 |= (UART0_C2_TIE_MASK);
				uart0_putchar((char)i);
				wait++;
				wait_flag = 2;
				//UART0_C2 |= (UART0_C2_TIE_MASK);
				break;
			}
			case 2:
			{
				UART0_C2 |= (UART0_C2_TIE_MASK);
				uart0_putchar(' ');
				wait++;
				wait_flag = 2;
				//UART0_C2 |= (UART0_C2_TIE_MASK);
				break;
			}
			case 3 :
			{
				UART0_C2 |= (UART0_C2_TIE_MASK);
				uart0_putchar('-');
				wait++;
				wait_flag = 2;
				//UART0_C2 |= (UART0_C2_TIE_MASK);
				break;
			}
			case 4 :
			{
				UART0_C2 |= (UART0_C2_TIE_MASK);
				uart0_putchar(' ');
				wait++;
				wait_flag = 2;
				//UART0_C2 |= (UART0_C2_TIE_MASK);
				break;
			}
			case 5:
			{
				UART0_C2 |= (UART0_C2_TIE_MASK);
				putnumber(*(report_character+i));
				wait++;
				wait_flag = 2;
				//UART0_C2 |= (UART0_C2_TIE_MASK);
				break;
			}
			case 6:
			{
				UART0_C2 |= (UART0_C2_TIE_MASK);
				uart0_putchar('\n');
				wait++;
				wait_flag = 2;
				//UART0_C2 |= (UART0_C2_TIE_MASK);
				break;
			}
			case 7:
			{
				UART0_C2 |= (UART0_C2_TIE_MASK);
				uart0_putchar('\r');
				wait = 1;
				wait_flag = 0;
				//UART0_C2 |= (UART0_C2_TIE_MASK);
				break;
			}
			}
			}
			}
		}
	}
	/*uart0_putchar('\n');
	UART0_C2 |= (UART0_C2_TIE_MASK);
	delay();*/
}

void delay()
{
	for(uint16_t z=0;z<1000;z++);
}
