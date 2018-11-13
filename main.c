#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "circular_buffer.h"


void main()
{
int i=0;
uint8_t deleted_element;
buffer_status stat;
cb *tx_buffer,*check;
tx_buffer=malloc(sizeof(cb));
tx_buffer->buffer=malloc(sizeof(uint8_t)*10);
check=malloc(sizeof(cb));
check->buffer=malloc(sizeof(uint8_t)*10);

cb_init(tx_buffer,10);
//printf("\nStatus for init is %d",stat);
//stat=cb_isempty(tx_buffer);
//printf("\nStatus for cb is empty is %d",stat);
for(i=0;i<5;i++)
	{
	stat=cb_add(tx_buffer,i);
	printf("\nstat is %d,",stat);
	printf("count is %d",tx_buffer->count);
	}
cb_resize(tx_buffer,11);
for(i=0;i<6;i++)
	{
	stat=cb_add(tx_buffer,i);
	printf("\nstat is %d,",stat);
	printf("count is %d",tx_buffer->count);
	}

//stat=cb_add(tx_buffer,11);
//printf("\n%d, ",stat);
//printf("count is %d",tx_buffer->count);

stat=cb_add(tx_buffer,11);
printf("\n%d, ",stat);
printf("count is %d",tx_buffer->count);


check=tx_buffer;
for(i=0;i<13;i++)
	{
        printf("\n%d element is : %d",i,*(check->buffer));
	check->buffer++;
	}


printf("\nNow checking delete");
cb_delete(tx_buffer,deleted_element);
printf("\nNow printing contents");
check=tx_buffer;
for(i=0;i<11;i++)
	{
        printf("\n%d element is : %d",i,*(check->buffer));
	check->buffer++;
	}



//buffer_resize()

/*printf("\n\rNow Deleting");
for(i=0;i<10;i++)
	{
	stat=cb_delete(tx_buffer,deleted_element);
	printf("\n%d",stat);
	}
stat=cb_delete(tx_buffer,deleted_element);
printf("\n%d, ",stat);
printf("count is %d",tx_buffer->count);*/
}
