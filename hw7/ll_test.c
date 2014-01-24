#include <stdio.h>
#include "./collections.h"

int main(void) {
    struct linked_list* ll = ll_alloc();
    ll_print(ll);
    printf("Len: %d\n", ll->size);
    printf("-----------\n");
    ll_append(ll, 1);
    ll_append(ll, 2);
    ll_append(ll, 3);
    ll_print(ll);
    printf("Len: %d\n", ll->size);
    printf("-----------\n");
    ll_delete_index(ll, 1);
    ll_print(ll);
    printf("Len: %d\n", ll->size);
    printf("-----------\n");
    ll_append(ll, 42);
    ll_print(ll);
    printf("Len: %d\n", ll->size);
    printf("-----------\n");
    ll_delete_index(ll, 0);
    ll_print(ll);
    printf("Len: %d\n", ll->size);
    printf("-----------\n");
    ll_append(ll, 100);
    ll_append(ll, 200);
    ll_append(ll, 100);
    ll_print(ll);
    printf("Len: %d\n", ll->size);
    printf("-----------\n");
    ll_delete_element(ll, 100);
    ll_print(ll);
    printf("Len: %d\n", ll->size);
    printf("-----------\n");
    ll_free(ll);

    return 0;
}
