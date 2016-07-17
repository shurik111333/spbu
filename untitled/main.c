#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <getopt.h>
#include "allocator.h"
#include "list.h"

int memory_size = 2100;
int min_lifetime = 10;
int max_lifetime= 60;
int min_chunk_size = 1;
int max_chunk_size = 20;
int need_trace = 0;
int max_ticks = 10000000;


//returns rand value in range [from, to)
int rand_range(int from, int to) {
    return rand() % (to - from) + from;
}

void print_help() {
    printf("This is memory allocation simulator\n");
    printf("Before running run: 'ulimit -s unlimited'\n");
    printf("Required arguments to run:\n");
    printf("   'memory' - amount of memory in bytes that will be used for allocating chunks\n"
	       "fdskhkjsfh");
    printf("   'min_lifetime' - minimum count of ticks that allocated chunk will live\n");
    printf("   'max_lifetime' - maximum count of ticks that allocated chunk will live\n");
    printf("   'min_size' - minimum size of allocated chunk\n");
    printf("   'max_size' - maximum size of allocated chunk\n");
    printf("   'max_ticks' - maximum count of ticks\n");
    printf("Optional arguments:\n");
    printf("   'trace' - if specified - all allocation/free steps will be shown\n"); 
    printf("'help' - shows this message\n"); 
    printf("Exmaple: ./allocation --memory=8192 --min_lifetime=10 --max_lifetime=100 --min_size=16 --max_size=640 --max_ticks=5000\n");
}

void parse_opts(int argc, char* argv[]) {
    const struct option long_options[] = {
		{"memory",       required_argument, NULL, 'm'},
		{"min_lifetime", required_argument, NULL, 'l'},
		{"max_lifetime", required_argument, NULL, 'L'},
		{"min_size",     required_argument, NULL, 's'},
		{"max_size",     required_argument, NULL, 'S'},
		{"max_ticks",    required_argument, NULL, 'N'},
		{"trace",        no_argument,       NULL, 't'},
		{"help",         no_argument,       NULL, 'h'},
		{NULL,           0,                 NULL,  0}
	};
    
    int rez;
    int option_index;
    
	while ((rez = getopt_long(argc, argv, "", long_options, &option_index)) !=- 1){
        if (optarg != NULL && atoi(optarg) <= 0) {
            printf("Bad argument '%s'. It shoud be positive\n", long_options[option_index].name);
            exit(0);
        }            
        switch (rez) {
			case 'm':
                memory_size = atoi(optarg);
			break;
			case 'l': 
                min_lifetime = atoi(optarg);                  
			break;
			case 'L': 
                max_lifetime = atoi(optarg);                  
			break;
			case 's': 
                min_chunk_size = atoi(optarg);                  
			break;
			case 'S': 
                max_chunk_size = atoi(optarg);                  
			break;
			case 'N': 
                max_ticks = atoi(optarg);                  
			break;
			case 't': 
                need_trace = 1;
			break;
			case 'h': 
                print_help();
                exit(0);
			break;
			case '?': default: 
				printf("Unknown argument!\n");
                exit(0);
			break;
        }		
	}

    if (memory_size == 0) {
        printf("Please, specify memory size\n");
        exit(0);
    }
    if (min_lifetime == 0) {
        printf("Please, specify minimum lifetime\n");
        exit(0);
    }
    if (max_lifetime== 0) {
        printf("Please, specify maximum chunk lifetime\n");
        exit(0);
    }
    if (min_chunk_size == 0) {
        printf("Please, specify minimum chunk size\n");
        exit(0);
    }
    if (max_chunk_size== 0) {
        printf("Please, specify maximum chunk size\n");
        exit(0);
    }
    if (max_ticks == 0) {
        printf("Please, specify maximum ticks count\n");
        exit(0);
    }
}

//Before running run: "ulimit -s unlimited"
int main(int argc, char* argv[]) {
    parse_opts(argc, argv);

    srand(time(NULL)); 
    int tick = 0;
    struct list **chunks_lifetime = (struct list **)malloc(sizeof(struct list*) * max_ticks);// The stack memory has somee restrictions
    for (int i = 0; i < max_ticks; i++) {
        chunks_lifetime[i] = create_list();
    }

    struct memory *mem = create_memory(memory_size);
    printf("Starting\n"); 
    while (1) {
        if (need_trace) {
            printf("Tick %d:\n", tick);
        }
        while (!is_list_empty(chunks_lifetime[tick])) {
            int8_t *ptr = get_and_remove(chunks_lifetime[tick]);
            if (need_trace) {
                printf("   Removing chunk with size %d bytes\n", get_chunk_size(ptr));
            }
            free_chunk(mem, ptr);
        }
        SIZE_TYPE chunk_size = rand_range(min_chunk_size, max_chunk_size) / 4 * 4;
        int8_t *ptr = allocate_chunk(mem, chunk_size);

        if (ptr == NULL) {
            printf("Oops. We have no free memory to allocate %d bytes on tick %d. Exiting\n", chunk_size, tick);
            break;
        }
        int chunk_lifetime = rand_range(min_lifetime, max_lifetime);
        if (tick + chunk_lifetime >= max_ticks) {
            printf("The maximum number of ticks(%d) reached. Exiting\n", max_ticks);
            break;
        }
        
        add_to_list(chunks_lifetime[tick + chunk_lifetime], ptr);
        if (need_trace){
            printf("   Allocating chunk with size %d bytes. Its lifetime is %d ticks\n", chunk_size, chunk_lifetime);
        }
        tick++;
    }

    for (int i = 0; i < max_ticks; i++) {
        free_list(chunks_lifetime[i]);
    }
    free_memory(mem);
    free(chunks_lifetime);
    return 0;
}
