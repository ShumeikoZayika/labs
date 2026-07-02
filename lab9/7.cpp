#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int findMax(int A[], int n)
{
    int max = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void CountSort(int A[], int n)
{
    int i, j, max;
    int *C;
    max = findMax(A, n);
    C = (int *)malloc(sizeof(int) * (max + 1));
    for (i = 0; i <= max; i++)
        C[i] = 0;
    for (i = 0; i < n; i++)
        C[A[i]]++;
    i = 0;
    j = 0;
    while (i < max + 1)
    {
        if (C[i] > 0)
        {
            A[j++] = i;
            C[i]--;
        }
        else
            i++;
    }
    free(C);
}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = 10;
    
    CountSort(A, n);
    
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    
    return 0;
}
