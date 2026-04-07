#include <stdio.h>
#include <stdlib.h> 

struct Array {
    int *A;
    int size;   
    int length; 
};

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Display(struct Array arr) {
    printf("Elements are:\n");
    for(int i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

int main() { return 0; }
