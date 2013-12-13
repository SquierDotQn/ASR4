#define HEAP_SIZE 50
#define FREE 1
#define BUSY 0

typedef struct{
	unsigned int free ;
	unsigned int size ;
	/* ces champs ne sont pas écrit dans la heap
	mais sont affectés par get_chunk */
	unsigned char * addr ;
	unsigned char * next_chunk ;
	unsigned char * previous_chunk ;
}chunk;

unsigned char heap[HEAP_SIZE];

unsigned int get_int(void *ptr);
void set_int(void *ptr, unsigned int val);
void set_chunk(chunk *c, unsigned char *ptr);
void get_chunk(chunk *c, unsigned char *ptr);
void init_alloc();
