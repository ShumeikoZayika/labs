#include <stdio.h>
#include <stdlib.h>
struct Array {
    int A[20];
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


int RBinSearch(int a[], int l, int h, int key) {
    int mid;

    if (l <= h) { 
        mid = (l + h) / 2; 

        if (key == a[mid]) {
            return mid; 
        } else if (key < a[mid]) {
            
            return RBinSearch(a, l, mid - 1, key);
        } else {
            
            return RBinSearch(a, mid + 1, h, key);
        }
    }
    return -1; 
}

int main() {
    
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    printf("%d\n", RBinSearch(arr.A, 0, arr.length - 1, 5));

    Display(arr);

    return 0;
}
