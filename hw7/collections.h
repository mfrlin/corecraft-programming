/*
* file:                 collections.h
* comment:              collections library
*/

#ifndef COLLECTIONS
#define COLLECTIONS

/*
* Linked list
*/

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

/*
* Binary tree
*/

struct bin_tree {
    struct tree_node* root;
    int max_depth;
    int num_elements;
};

struct bin_tree* tree_alloc();

int tree_insert(struct bin_tree* tree, char* key, char* phone_number);

char* tree_search(struct bin_tree* tree, char* key);

#endif
