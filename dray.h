#ifndef DRAY_H
#define DRAY_H

#include <stddef.h>

typedef struct {
    size_t capacity;
    size_t size;

    int* items;
} Dray;

Dray construct(size_t size);
void append(Dray *arr, int num);
int pop(Dray *arr);
int front(Dray *arr);
int back(Dray *arr);

#endif // DRAY_H
