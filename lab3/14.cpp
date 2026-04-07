#include <stdio.h>
#include <stdlib.h> 

struct Array {
    int A[20]; 
    int size;   
    int length; 
};

void Display(struct Array arr) {
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void Append(struct Array *arr, int x) {
    if (arr->length < arr->size) {
        arr->A[arr->length++] = x;
    } else {
        printf("Error: Array is full, cannot append %d\n", x);
    }
}

int main() {
    
    struct Array arr = {{2,3,4,5,6}, 10, 5}; 

    printf("Initial array:\n");
    Display(arr); 

    Append(&arr, 10); 
    printf("Array after appending 10:\n");
    Display(arr);      

    Append(&arr, 20); 
    printf("Array after appending 20:\n");
    Display(arr);      

    Append(&arr, 30); 
    Append(&arr, 40);
    Append(&arr, 50);
    Append(&arr, 60);
    Append(&arr, 70); 
    Append(&arr, 80); 
    printf("Array after several appends:\n");
    Display(arr);

    return 0;
}
