#include <stdio.h>
#include <stdlib.h>
#ifndef ARRAY_PTR_H
#define ARRAY_PTR_H
struct Array {
    int *A;
    int size;
    int length;
};
void Display(struct Array arr) {
    for(int i=0; i<arr.length; i++) printf("%d ", arr.A[i]);
    printf("\n");
}
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
#endif

void Reverse(struct Array *arr) {
    int *B;
    int i, j;
    B = (int *)malloc(arr->length * sizeof(int));
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];
    for (i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
    free(B);
}

void Reverse2(struct Array *arr) {
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--) {
        swap(&arr->A[i], &arr->A[j]);
    }
}

void InsertSort(struct Array *arr, int x) {
    int i = arr->length - 1;
    if (arr->length == arr->size) 
        return;

    while (i >= 0 && arr->A[i] > x) {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

int isSorted(struct Array arr) {
    int i;
    for (i = 0; i < arr.length - 1; i++) {
        if (arr.A[i] > arr.A[i + 1])
            return 0; 
    }
    return 1; 
}

void Rearrange(struct Array *arr) {
    int i = 0;
    int j = arr->length - 1;

    while (i < j) {
        while (arr->A[i] < 0) i++;
        while (arr->A[j] >= 0) j--;
        if (i < j) swap(&arr->A[i], &arr->A[j]);
    }
}

int main() { return 0; }
