#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./collections.h"

/*
* Linked list
*/

struct ll_node {
    int data;
    struct ll_node* next;
    struct ll_node* prev;
};

struct ll_node* ll_node_alloc() {
    struct ll_node* node = malloc(sizeof(struct ll_node));
    if (node) {
        node->next = NULL;
        node->prev = NULL;
        return node;
    } else {
        printf("Error allocating new node!\n");
        return 0;
    }
}

struct linked_list* ll_alloc() {
    struct linked_list* ll = malloc(sizeof(struct linked_list));
    if (ll) {
        struct ll_node* node = ll_node_alloc();
        if (node) {
            ll->head = node;
            ll->tail = node;
        } else {
            free(ll);
            return 0;
        }
        ll->size = 0;
        return ll;
    } else {
        printf("Error allocating new linked list!\n");
        return 0;
    }
}
static void ll_node_free(struct ll_node* node) {
    free(node);
}

void ll_free(struct linked_list* ll) {
    struct ll_node* node = ll->head;
    for ( ; node != NULL; node = node->next) {
        free(node);
    }
    free(ll);
}


int ll_append(struct linked_list* ll, int item) {
    struct ll_node* new_tail = ll_node_alloc();
    if (new_tail) {
        ll->tail->data = item;
        ll->tail->next = new_tail;
        new_tail->prev = ll->tail;
        ll->tail = new_tail;
        ll->size++;
        return 1;
    } else {
        printf("Error appending!\n");
        return 0;
    }
}

static void ll_delete_node(struct linked_list* ll, struct ll_node* node) {
    node->next->prev = node->prev;
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        ll->head = node->next;
    }
    ll_node_free(node);
    ll->size--;
}

int ll_delete_index(struct linked_list* ll, int index) {
    struct ll_node* node = ll->head;
    if (index > ll->size - 1 || index < 0) {
        printf("%d index is out of range!\n", index);
        return 0;
    } else {
        for ( ; index > 0; node = node->next, index--) {
        }
        ll_delete_node(ll, node);
        return 1;
    }
}

int ll_delete_element(struct linked_list* ll, int element) {
    struct ll_node* node = ll->head;
    for ( ; node->next != NULL; node = node->next) {
        if (node->data == element) {
            ll_delete_node(ll, node);
            return 1;
        }
    }
    return 0;
}

void ll_print(struct linked_list* ll) {
    struct ll_node* node = ll->head;
    for ( ; node != NULL; node = node->next) {
        printf("%d\n", node->data);
        printf("%p\n", node);
        printf("%p\n", node->next);
        printf("%p\n", node->prev);
    }
}

/*
* Binary tree
*/

struct tree_node {
    char* key;
    char* phone_number;
    struct tree_node* left_child;
    struct tree_node* right_child;
};

struct tree_node* tree_node_alloc() {
    struct tree_node* node = malloc(sizeof(struct tree_node));
    if (node) {
        node->left_child = NULL;
        node->right_child = NULL;
        return node;
    } else {
        printf("Error creating node!\n");
        return 0;
    }
}

struct bin_tree* tree_alloc() {
    struct bin_tree* tree = malloc(sizeof(struct bin_tree));
    if (tree) {
        tree->max_depth = 0;
        tree->num_elements = 0;
        return tree;
    } else {
        printf("Error creating tree!\n");
        return 0;
    }
}

void tree_node_free(struct tree_node* node) {
    free(node->key);
    free(node->phone_number);
    free(node);
}

int tree_insert(struct bin_tree* tree, char* key, char* phone_number) {
    struct tree_node* new_node = tree_node_alloc();
    if (!new_node) {
        return 0;
    }
    int len = strlen(key);
    char* buffer = malloc(sizeof(char) * (len+1));
    strcpy(buffer, key);
    new_node->key = buffer;
    len = strlen(phone_number);
    buffer = malloc(sizeof(char) * (len+1));
    strcpy(buffer, phone_number);
    new_node->phone_number = buffer;

    if (tree->num_elements == 0) {
        tree->root = new_node;
        tree->num_elements = 1;
        return 1;
    }

    struct tree_node* node = tree->root;
    struct tree_node* insert_node = NULL;
    int cmp;
    while (node) {
        cmp = strcmp(node->key, key);
        if (cmp == 0) {
            tree_node_free(new_node);
            return 0;
        } else if (cmp > 0) {
            insert_node = node;
            node = node->right_child;
        } else {
            insert_node = node;
            node = node->left_child;
        }
    }
    if (cmp > 0) {
        insert_node->right_child = new_node;
    } else {
        insert_node->left_child = new_node;
    }
    tree->num_elements++;
    return 1;
}

char* tree_search(struct bin_tree* tree, char* key) {
    struct tree_node* node = tree->root;
    while (node) {
        printf("%s\n", node->key);
        int cmp = strcmp(node->key, key);
        if (cmp == 0) {
            return node->phone_number;
        } else if (cmp > 0) {
            node = node->right_child;
        } else {
            node = node->left_child;
        }
    }
    printf("No such key in a tree!\n");
    return 0;
}


