#ifndef ARRAY_DEFS_H
#define ARRAY_DEFS_H

#include <stdio.h> 

struct Array {
    int A[20];  
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

#endif 

int main() { return 0; }
