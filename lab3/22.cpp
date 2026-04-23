#include <stdio.h>
int main() {
int N=10, K=10;
int A[10]={0};

int min_val = A[0];
int max_val = A[0];

for (int i = 1; i < N; i++) {
    if (A[i] < min_val) {
        min_val = A[i]; 
    } else if (A[i] > max_val) { 
        max_val = A[i]; 
    }
}

return 0;
}
