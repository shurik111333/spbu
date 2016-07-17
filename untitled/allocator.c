#include "allocator.h"

struct memory {
    SIZE_TYPE size;
    int8_t *data;   
};

void set_chunk_size(int8_t *ptr, SIZE_TYPE size) { //Sets chunk size. Allows positive and negative size
   *(SIZE_TYPE *)(ptr - sizeof(SIZE_TYPE)) = size; //Set left bound
   *(SIZE_TYPE *)(ptr + abs(size)) = size; //Set right bound
}

struct memory *create_memory(SIZE_TYPE size){
    struct memory *mem = malloc(sizeof(struct memory));
    mem->size = size;
    mem->data = calloc(size, 1);
    set_chunk_size(mem->data + sizeof(SIZE_TYPE), -(size - 2 * sizeof(SIZE_TYPE)));// Let's create empty chunk
    return mem;
}

void free_memory(struct memory *mem) {
    free(mem->data);
    free(mem);
}

void *allocate_chunk(struct memory *mem, SIZE_TYPE size) { // Returns pointer to the beginig of allocated memory if succed. NULL otherwise
    int8_t * ptr = mem->data;
    SIZE_TYPE current_index = 0;
    while (1) { // Let's find suitable empty chunk and use it!
        if (current_index >= mem->size - (size + 3 * sizeof(SIZE_TYPE))) { // If we'v got not enough memory
            return NULL;
        }
        SIZE_TYPE current_chunk_size = *(SIZE_TYPE *)ptr;
        if (current_chunk_size < 0 && abs(current_chunk_size) >= size) { //Good free chunk
            SIZE_TYPE rest_size = abs(current_chunk_size) - size; // But we can have some free space after our allocation
            if (rest_size > 0) {// If we got some free mem after our chunk
                if (rest_size <= 2 * sizeof(SIZE_TYPE)) { // If rest mem is too small for further allocations....
                    size = abs(current_chunk_size); // We have to give a little more memory because we cannot use the rest 
                } else { // Or if wer can use it after 
                    set_chunk_size(ptr + size + 3 * sizeof(SIZE_TYPE), -(rest_size - 2 * sizeof(SIZE_TYPE)));// Create a new empty chunk
                }
            }
            set_chunk_size(ptr + sizeof(SIZE_TYPE), size); //Let's create our new chunk
            return ptr + sizeof(SIZE_TYPE); // return pointer to beginig of our chunk
        }
        //If chunks is not suitable...
        ptr += abs(current_chunk_size) + 2 * sizeof(SIZE_TYPE);// Let's go to the next one
        current_index += abs(current_chunk_size) + 2 * sizeof(SIZE_TYPE);
    }
}

void free_chunk(struct memory *mem, int8_t *ptr) {
    SIZE_TYPE size = get_chunk_size(ptr);
    SIZE_TYPE new_size = size;
    int8_t *new_ptr = ptr;
    if (ptr - mem->data >= 2 * sizeof(SIZE_TYPE)) {// If our chunk is not first
        SIZE_TYPE prev_chunk_size = *(SIZE_TYPE *)(ptr - 2 * sizeof(SIZE_TYPE));
        if (prev_chunk_size < 0) {// If prev chunk is free
            new_size += abs(prev_chunk_size) + 2 * sizeof(SIZE_TYPE);//Merge it!
            new_ptr -= abs(prev_chunk_size) + 2 * sizeof(SIZE_TYPE); // Merge it!
        }
    }

    if (ptr - mem->data < mem->size - 2 * sizeof(SIZE_TYPE)) {// If our chunk is not last
        SIZE_TYPE next_chunk_size = *(SIZE_TYPE *)(ptr + size + sizeof(SIZE_TYPE));
        if (next_chunk_size < 0) {// If next chunk is free
            new_size += abs(next_chunk_size) + 2 * sizeof(SIZE_TYPE);//Merge it!
        }
    }
    set_chunk_size(new_ptr, -new_size);
}

SIZE_TYPE get_chunk_size(int8_t *ptr) {
    return *(SIZE_TYPE *)(ptr - sizeof(SIZE_TYPE));
}

