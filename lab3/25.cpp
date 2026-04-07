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

struct Array* Merge(struct Array* a, struct Array* b) {
    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
    arr3->A = (int*)malloc(10*sizeof(int));
    arr3->length = 10;
    arr3->size = 10;
    return arr3;
}
void InsertSort(struct Array* a, int x) {}
int isSorted(struct Array a) { return 1; }
void Rearrange(struct Array* a) {}

int main() {
    
    struct Array arr_sort = {
        .A = (int[]){2, 3, 5, 10, 15, 0, 0, 0, 0, 0}, 
        .size = 10,
        .length = 5
    };
    printf("Original array for sort:\n");
    Display(arr_sort);

    InsertSort(&arr_sort, 20);
    printf("Array after InsertSort(20):\n");
    Display(arr_sort);
    printf("Is sorted: %d\n", isSorted(arr_sort));

    InsertSort(&arr_sort, 1);
    printf("Array after InsertSort(1):\n");
    Display(arr_sort);
    printf("Is sorted: %d\n", isSorted(arr_sort));

    struct Array arr_rearrange = {
        .A = (int[]){2, -3, 25, 10, -15, -7, 0, 0, 0, 0},
        .size = 10,
        .length = 6
    };
    printf("\nOriginal array for rearrange:\n");
    Display(arr_rearrange);
    Rearrange(&arr_rearrange);
    printf("Array after Rearrange:\n");
    Display(arr_rearrange);

    struct Array arr1 = {
        .A = (int *)malloc(10 * sizeof(int)),
        .size = 10,
        .length = 5
    };
    arr1.A[0]=2; arr1.A[1]=6; arr1.A[2]=10; arr1.A[3]=15; arr1.A[4]=25;

    struct Array arr2 = {
        .A = (int *)malloc(10 * sizeof(int)),
        .size = 10,
        .length = 5
    };
    arr2.A[0]=3; arr2.A[1]=4; arr2.A[2]=7; arr2.A[3]=18; arr2.A[4]=20;

    printf("\nArray 1 for merge:\n");
    Display(arr1);
    printf("Array 2 for merge:\n");
    Display(arr2);

    struct Array *arr3;
    arr3 = Merge(&arr1, &arr2); 
    printf("Merged array:\n");
    Display(*arr3); 

    free(arr1.A);
    free(arr2.A);
    free(arr3->A);
    free(arr3);
    free(arr_sort.A); 
    
    free(arr_rearrange.A);

    return 0;
}
