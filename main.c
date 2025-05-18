#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    unsigned int capacity;
    unsigned int size;

    int* first;
    int* last;
} Dray;

void append(Dray *arr, int num) { 
    assert(arr->size <= arr->capacity);

    if (arr->size == arr->capacity) {
        int new_size = arr->capacity * 2;
        int *new_start = realloc(arr->first, new_size * sizeof(int));

        if (new_start == NULL) {
            perror("Failed to reallocate memory");
            free(arr->first);
            exit(1);
        }

        arr->last = &(new_start[arr->size]);
        arr->first = new_start;
        arr->capacity = new_size;
    }

    *(arr->last) = num;
    arr->last++;
    arr->size++;
}

int pop(Dray *arr) { 
    assert(arr->capacity > 0);
    assert(arr->last != arr->first);
    
    arr->last--;
    arr->size--;
    if (arr->size < arr->capacity/2) {
        int new_size = arr->capacity / 2;
        int *new_start = realloc(arr->first, new_size * sizeof(int));

        if (new_start == NULL) {
            perror("Failed to reallocate memory");
            free(arr->first);
            exit(1);
        }

        arr->last = &(new_start[arr->size]);
        arr->first = new_start;
        arr->capacity = new_size;
    }
    return *arr->last;
}

Dray construct(unsigned int size) {
    Dray arr;
    arr.capacity = size;
    arr.size = 0;
    arr.first = malloc(size * sizeof(int));

    if (arr.first == NULL) {
        perror("Failed to allocate memory");
        free(arr.first);
        exit(1);
    }

    arr.last = arr.first;
    return arr;
}

int front(Dray *arr) {
    assert(arr->size >= 1);
    return arr->first[0];
}

int back(Dray *arr) {
    assert(arr->size >= 1);
    return arr->first[arr->size-1];
}


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

    for (int i = 0; i < arr.size; i++) {
        printf("%d\n", arr.first[i]);
    }

    printf("element number 2: %d\n", arr.first[2]);

    free(arr.first);
    ////////////////////////////////////////////////////////////////////

    return 0;
}
