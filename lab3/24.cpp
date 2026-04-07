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

struct Array* Merge(struct Array *arr1, struct Array *arr2) {
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    if (arr3 == NULL) {
        perror("Failed to allocate memory for arr3 struct");
        exit(EXIT_FAILURE);
    }

    arr3->A = (int *)malloc((arr1->length + arr2->length) * sizeof(int));
    if (arr3->A == NULL) {
        perror("Failed to allocate memory for arr3->A");
        free(arr3); 
        exit(EXIT_FAILURE);
    }

    arr3->size = arr1->length + arr2->length; 
    arr3->length = 0; 

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        } else {
            arr3->A[k++] = arr2->A[j++];
        }
    }

    for (; i < arr1->length; i++) {
        arr3->A[k++] = arr1->A[i];
    }

    for (; j < arr2->length; j++) {
        arr3->A[k++] = arr2->A[j];
    }

    arr3->length = k; 
    return arr3;
}

int main() { return 0; }
