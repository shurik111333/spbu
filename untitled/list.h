#include <stdlib.h>
#include <stdint.h>
struct list;

struct list *create_list();

void free_list(struct list *lst);

void add_to_list(struct list *lst, int8_t *data);

int8_t *get_and_remove(struct list *lst);

int is_list_empty(struct list *lst);
