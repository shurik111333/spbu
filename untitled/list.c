#include "list.h"

struct list_node {
    int8_t *data;
    struct list_node *next;
};

struct list {
    struct list_node *root;
};

struct list *create_list() {
    struct list *lst = (struct list *)malloc(sizeof(struct list));
    lst->root = NULL;
    return lst;
}

void free_list(struct list *lst) {
    while (!is_list_empty(lst)) {
        get_and_remove(lst);
    }
    free(lst);
}

void add_to_list(struct list *lst, int8_t *data) {
    struct list_node *node = (struct list_node *)malloc(sizeof(struct list_node));
    node->data = data;
    node->next = lst->root;
    lst->root = node;
}

int8_t *get_and_remove(struct list *lst) {
    struct list_node *next = lst->root->next;
    int8_t *data = lst->root->data;
    free(lst->root);
    lst->root = next;
    return data;
}

int is_list_empty(struct list *lst) {
    return lst->root == NULL;
}
