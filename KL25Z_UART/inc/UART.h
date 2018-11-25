#include <stdint.h>


#define bit_mask_2    		0x00000004
#define bit_mask_3    		0x00000008
#define ENABLE_UART0  		0x0C
#define UART0_PIN     		0x00000200
#define UART0_CLK_EN  		0x00000400
#define MCGFKKCLK			0x04000000
#define PORTA_CLK			0x00000200
#define DISABLE_UART0   	0x00
#define BDH_VALUE           0x00
#define BDL_VALUE           0x0C
#define UART0_MODE_SEL      0x00
#define OSR					0x0F

//extern void uarto_isr(void);
//#undef VECTOR_028
//#define VECTOR_028 uarto_isr
void UART0_IRQHandler(void);
//#define Blocking_Uart



void UART0_init(void);
char uart0_getchar(void);
void uart0_putchar(char);
void uart0_putstr(char *);
void putnumber(uint16_t);
void tx_wait();
void rx_wait();
char getch();
void putch(char);
void uart0_putstr_nb(char *);
void getinfo(uint8_t *);


