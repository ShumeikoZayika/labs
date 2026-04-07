#include <stdio.h>
#include <stdlib.h> 

struct Array {
    int A[10]; 
    int size;   
    int length; 
};

void Display(struct Array arr) {
    int i;
    printf("Elements are\n");
    for (i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr, int key) {
    int i;
    for (i = 0; i < arr->length; i++) {
        if (key == arr->A[i]) {
            swap(&arr->A[i], &arr->A[0]); 
            return i;
        }
    }
    return -1;
}

int Get(struct Array arr, int index) {
    if (index >= 0 && index < arr.length) {
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int x) {
    if (index >= 0 && index < arr->length) {
        arr->A[index] = x;
    }
}

int Max(struct Array arr) {
    int max = arr.A[0];
    int i;
    for (i = 1; i < arr.length; i++) {
        if (arr.A[i] > max) {
            max = arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr) {
    int min = arr.A[0];
    int i;
    for (i = 1; i < arr.length; i++) {
        if (arr.A[i] < min) {
            min = arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr) {
    int s = 0;
    int i;
    for (i = 0; i < arr.length; i++) {
        s += arr.A[i];
    }
    return s;
}

float Avg(struct Array arr) {
    return (float)Sum(arr) / arr.length;
}

void Reverse(struct Array *arr) {
    int *B;
    int i, j;
    B = (int *)malloc(arr->length * sizeof(int));
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++) {
        B[j] = arr->A[i];
    }
    for (i = 0; i < arr->length; i++) {
        arr->A[i] = B[i];
    }
    free(B); 
}

void Reverse2(struct Array *arr) {
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--) {
        swap(&arr->A[i], &arr->A[j]);
    }
}

int main() {
    
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    printf("Initial array:\n");
    Display(arr);

    printf("Element at index 2: %d\n", Get(arr, 2));

    Set(&arr, 0, 15);
    printf("After Set(0, 15):\n");
    Display(arr);

    struct Array arr_max_test = {{2, 3, 14, 25, 6}, 10, 5};
    printf("Max element in {2,3,14,25,6}: %d\n", Max(arr_max_test));

    printf("Min element in {2,3,14,25,6}: %d\n", Min(arr_max_test));

    printf("Sum of elements in {2,3,14,25,6}: %d\n", Sum(arr_max_test));

    printf("Average of elements in {2,3,14,25,6}: %f\n", Avg(arr_max_test));

    printf("Before Reverse2:\n");
    Display(arr_max_test);
    Reverse2(&arr_max_test); 
    printf("After Reverse2:\n");
    Display(arr_max_test);

    return 0;
}
