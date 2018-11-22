#include "character_count.h"

uint8_t cc[256];

uint8_t* character_count(uint8_t *report_char)
{
	cc[*report_char] ++;
	return cc;

}


