#include <stdio.h>

void Insert(int A[], int n)
{
    int i = n, temp;
    temp = A[i];
    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

int Delete(int A[], int n)
{
    int i, j, temp;
    int val = A[1];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = 2 * i;
    while (j < n)
    {
        if (j + 1 < n && A[j + 1] > A[j])
            j = j + 1;
        if (A[i] < A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * i;
        }
        else
            break;
    }
    return val;
}

void Heapify(int A[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        int k = i;
        int j = 2 * k;
        while (j <= n)
        {
            if (j + 1 <= n && A[j + 1] > A[j])
                j = j + 1;
            if (A[k] < A[j])
            {
                int temp = A[k];
                A[k] = A[j];
                A[j] = temp;
                k = j;
                j = 2 * k;
            }
            else
                break;
        }
    }
}

int main()
{
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};
    int n = 7;
    
    for (int i = 2; i <= n; i++)
        Insert(H, i);
        
    printf("Max Heap: ");
    for (int i = 1; i <= n; i++)
        printf("%d ", H[i]);
    printf("\n");
    
    for (int i = n; i >= 2; i--)
        Delete(H, i);
        
    printf("Sorted using Heap Sort: ");
    for (int i = 1; i <= n; i++)
        printf("%d ", H[i]);
    printf("\n");
    
    int A[] = {0, 5, 20, 15, 30, 25, 40, 10};
    int m = 7;
    Heapify(A, m);
    
    printf("Heapified Array: ");
    for (int i = 1; i <= m; i++)
        printf("%d ", A[i]);
    printf("\n");
    
    return 0;
}
