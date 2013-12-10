#include <stdio.h>
#include "malloc.h"


/* Q4 bis &(s[i])
void display_raw();
Q4 ter
void display_chucks();*/


unsigned int get_int(void *ptr){
	unsigned int i = (int)*ptr;
	return i;
}
void set_int(void *ptr, unsigned int val){
	(*int)ptr = &val;
}
