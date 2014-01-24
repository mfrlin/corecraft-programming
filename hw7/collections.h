/*
* file:                 collections.h
* comment:              collections library
*/

#ifndef COLLECTIONS
#define COLLECTIONS

struct linked_list {
    struct ll_node* head;
    struct ll_node* tail;
    int size;
};

struct linked_list* ll_alloc();

void ll_free(struct linked_list* ll);

int ll_append(struct linked_list* ll, int item);

int ll_delete_index(struct linked_list* ll, int index);

int ll_delete_element(struct linked_list* ll, int element);

void ll_print(struct linked_list* ll);

#endif
