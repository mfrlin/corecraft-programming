#include <stdio.h>
#include <string.h>
#include "./collections.h"

int main(void) {
    struct bin_tree* tree = tree_alloc();
    tree_insert(tree, "a", "031-555-66a");
    tree_insert(tree, "c", "031-555-66c");
    tree_insert(tree, "e", "031-555-66e");
    tree_insert(tree, "h", "031-555-66h");
    tree_insert(tree, "g", "031-555-66g");
    tree_insert(tree, "f", "031-555-66f");
    tree_insert(tree, "d", "031-555-66d");
    tree_insert(tree, "b", "031-555-66b");
    char* phone = tree_search(tree, "y");
    phone = tree_search(tree, "f");
    printf("%s\n", phone);

    return 0;
}
