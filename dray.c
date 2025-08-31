#include "dray.h"
#include <stdlib.h>
#include <assert.h>


void append(Dray *arr, int num) { 
    assert(arr->size <= arr->capacity);

    if (arr->size == arr->capacity) {
        int new_size = arr->capacity * 2;
		if (arr->capacity == 0) {
			new_size = 256;
		}
        int *new_start = realloc(arr->items, new_size * sizeof(int));

        if (new_start == NULL) {
            perror("Failed to reallocate memory");
            free(arr->items);
            exit(1);
        }

        arr->items = new_start;
        arr->capacity = new_size;
    }

	arr->items[arr->size] = num;
    arr->size++;
}

int pop(Dray *arr) { 
    assert(arr->capacity > 0);
    
    int val = arr->items[arr->size-1];
    arr->size--;
    if (arr->size < arr->capacity/2) {
        int new_size = arr->capacity / 2;
        int *new_start = realloc(arr->items, new_size * sizeof(int));

        if (new_start == NULL) {
            perror("Failed to reallocate memory");
            free(arr->items);
            exit(1);
        }

        arr->items = new_start;
        arr->capacity = new_size;
    }
    return val;
}

Dray construct(size_t size) {
    Dray arr;
    arr.capacity = size;
    arr.size = 0;
    arr.items = malloc(size * sizeof(int));

    if (arr.items == NULL) {
        perror("Failed to allocate memory");
        free(arr.items);
        exit(1);
    }

    return arr;
}

int front(Dray *arr) {
    assert(arr->size >= 1);
    return arr->items[0];
}

int back(Dray *arr) {
    assert(arr->size >= 1);
    return arr->items[arr->size-1];
}

