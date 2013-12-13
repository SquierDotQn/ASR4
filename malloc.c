#include <stdio.h>
#include "malloc.h"


/* Q4 bis &(s[i])
void display_raw();
Q4 ter
void display_chucks();*/


unsigned int get_int(void *ptr){
        unsigned int i = *(unsigned int*)ptr;
        return i;
}
void set_int(void *ptr, unsigned int val){
        unsigned int* iptr = (unsigned int*) ptr;
        *iptr = val;
}


void set_chunk(chunk *c, unsigned char *ptr){
	set_int(ptr,c->free);
	set_int(ptr + sizeof(unsigned int),c->size);
	set_int( (ptr + c->size - sizeof(unsigned int)) ,c->size);
}

void get_chunk(chunk *c, unsigned char *ptr){
	c->free = get_int(ptr);
	c->size = get_int(ptr + sizeof(unsigned int));
	c->addr = ptr;
	if(ptr == heap)
		c->previous_chunk = NULL;
	else
		c->previous_chunk = ptr - get_int(ptr-sizeof(unsigned int));
	if(ptr + get_int(ptr+sizeof(unsigned int))==&heap[get_int(ptr+sizeof(unsigned int))])
		c->next_chunk = ptr + get_int(ptr+sizeof(unsigned int));
	else
		c->next_chunk = NULL;
}

void init_alloc(){
	chunk init;
	init.free = FREE;
	init.size = HEAP_SIZE;
	set_chunk(&init, heap);
}

