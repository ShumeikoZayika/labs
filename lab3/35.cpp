#include <stdio.h>
int main() {
int N=10, K=10;
int A[10]={0};

int i = 0;
int j = N - 1; 

while (i < j) {
    if (A[i] + A[j] == K) {
        printf("%d + %d = %d\n", A[i], A[j], K);
        
        i++;
        j--;
        
    } else if (A[i] + A[j] < K) {
        i++; 
    } else { 
        j--; 
    }
}

return 0;
}
