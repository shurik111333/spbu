#include <stdlib.h>
#include <stdint.h>
#define SIZE_TYPE int32_t

struct memory;

struct memory *create_memory(SIZE_TYPE size);

void free_memory(struct memory *mem);

void *allocate_chunk(struct memory *mem, SIZE_TYPE size);

void free_chunk(struct memory *mem, int8_t *ptr);

SIZE_TYPE get_chunk_size(int8_t *ptr);
