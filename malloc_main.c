#include <stdio.h>
#include "malloc.h"

int main(void){
	unsigned int i=8;
	chunk ch, ch2;
	ch.free = BUSY;
	ch.size = 2;
	printf("%d\n", get_int(&i));
	set_int(&i,12);
	printf("%d\n", get_int(&i));
	printf("set_int marche\n");
	set_chunk(&ch, heap);
	printf("set_chunk marche, entré,    etat (0 busy, 1 free) = %d | ch.size  = %d\n",ch.free, ch.size);
	get_chunk(&ch2, heap);
	printf("get_chunk marche, recupéré, etat (0 busy, 1 free) = %d | ch2.size = %d\n",ch2.free, ch2.size);
	init_alloc();
	get_chunk(&ch2, heap);
	printf("init_alloc marche\n");
	get_chunk(&ch2, heap);
	printf("get_chunk marche, recupéré, etat (0 busy, 1 free) = %d | ch2.size = %d\n",ch2.free, ch2.size);
	return 0;
}
