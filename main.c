#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dray.h"


int main(void) {
    // Example
    ////////////////////////////////////////////////////////////////////
    Dray arr = construct(1);
    append(&arr, 5);
    printf("%d\n", back(&arr));
    printf("size: %d\ncapacity: %d\n", arr.size, arr.capacity);
    append(&arr, 7);
    printf("%d\n", back(&arr));
    printf("size: %d\ncapacity: %d\n", arr.size, arr.capacity);
    append(&arr, 4);
    printf("%d\n", back(&arr));
    printf("size: %d\ncapacity: %d\n", arr.size, arr.capacity);
    append(&arr, 7);
    printf("%d\n", back(&arr));
    printf("size: %d\ncapacity: %d\n", arr.size, arr.capacity);
    append(&arr, 4);
    printf("%d\n", back(&arr));
    printf("size: %d\ncapacity: %d\n", arr.size, arr.capacity);
    printf("%d\n", pop(&arr));
    printf("size: %d\ncapacity: %d\n", arr.size, arr.capacity);
    printf("%d\n", pop(&arr));
    printf("size: %d\ncapacity: %d\n", arr.size, arr.capacity);

    for (size_t i = 0; i < arr.size; i++) {
        printf("%d\n", arr.items[i]);
    }

    printf("element number 2: %d\n", arr.items[2]);

    free(arr.items);
    ////////////////////////////////////////////////////////////////////

    return 0;
}
