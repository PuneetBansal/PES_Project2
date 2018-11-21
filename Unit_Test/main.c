#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "circular_buffer.h"
#include <time.h>


void main()
{
int i=0;
uint8_t deleted_element,rand_buff_size;
buffer_status stat;
srand(time(0));
cb *tx_buffer,*check;
tx_buffer=malloc(sizeof(cb));
rand_buff_size=(rand()%256);
tx_buffer->buffer=malloc(sizeof(uint8_t)*rand_buff_size);
check=malloc(sizeof(cb));
check->buffer=malloc(sizeof(uint8_t)*rand_buff_size);

cb_init(tx_buffer,rand_buff_size);
//printf("\nStatus for init is %d",stat);
//stat=cb_isempty(tx_buffer);
//printf("\nStatus for cb is empty is %d",stat);
for(i=0;i<rand_buff_size;i++)
	{
	stat=cb_add(tx_buffer,rand()%256);
	printf("\nstat is %d,",stat);
	printf("count is %d",tx_buffer->count);
	}
//cb_resize(tx_buffer,11);
//printf("\n\rthe address of ptr->buffer is %p",tx_buffer->buffer);
//printf("\n\rthe address of ptr->new buffer is %p",tx_buffer->newbuffer);
/*for(i=0;i<6;i++)
	{
	stat=cb_add(tx_buffer,i);
	printf("\nstat is %d,",stat);
	printf("count is %d",tx_buffer->count);
	}*/

//stat=cb_add(tx_buffer,11);
//printf("\n%d, ",stat);
//printf("count is %d",tx_buffer->count);

/*
stat=cb_add(tx_buffer,11);
printf("\n%d, ",stat);
printf("count is %d",tx_buffer->count);
cb_resize(tx_buffer,15);

for(i=10;i<15;i++)
	{
	stat=cb_add(tx_buffer,i);
	printf("\nstat is %d,",stat);
	printf("count is %d",tx_buffer->count);
	}
//stat=cb_add(tx_buffer,11);
//printf("\n%d, ",stat);
//printf("count is %d",tx_buffer->count);

*/

check=tx_buffer;
printf("\nNow printing contents");
for(i=0;i<15;i++)
	{
        printf("\n%d element is : %d",i,*(check->buffer));
	check->buffer++;
	}

/*
printf("\nNow checking delete");
cb_delete(tx_buffer,deleted_element);
printf("\nNow printing contents");
check=tx_buffer;
for(i=0;i<11;i++)
	{
        printf("\n%d element is : %d",i,*(check->buffer));
	check->buffer++;
	}
*/


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
