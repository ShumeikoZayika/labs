#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("Elements are: ");
    for(i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

struct Array* Merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    if (arr3 == NULL) { printf("Memory allocation failed (Merge).\n"); return NULL; }
    arr3->A = (int *)malloc((arr1->length + arr2->length) * sizeof(int));
    if (arr3->A == NULL) { printf("Memory allocation failed (Merge A).\n"); free(arr3); return NULL; }

    while(i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) arr3->A[k++] = arr1->A[i++];
        else arr3->A[k++] = arr2->A[j++];
    }
    for(; i < arr1->length; i++) arr3->A[k++] = arr1->A[i];
    for(; j < arr2->length; j++) arr3->A[k++] = arr2->A[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = arr3->length;
    return arr3;
}

struct Array* Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    if (arr3 == NULL) { printf("Memory allocation failed (Union).\n"); return NULL; }
    arr3->A = (int *)malloc((arr1->length + arr2->length) * sizeof(int));
    if (arr3->A == NULL) { printf("Memory allocation failed (Union A).\n"); free(arr3); return NULL; }

    while(i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i]) arr3->A[k++] = arr2->A[j++];
        else { arr3->A[k++] = arr1->A[i++]; j++; }
    }
    for(; i < arr1->length; i++) arr3->A[k++] = arr1->A[i];
    for(; j < arr2->length; j++) arr3->A[k++] = arr2->A[j];
    arr3->length = k;
    arr3->size = arr3->length;
    return arr3;
}

struct Array* Intersection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    if (arr3 == NULL) { printf("Memory allocation failed (Intersection).\n"); return NULL; }
    arr3->A = (int *)malloc((arr1->length + arr2->length) * sizeof(int));
    if (arr3->A == NULL) { printf("Memory allocation failed (Intersection A).\n"); free(arr3); return NULL; }

    while(i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) i++;
        else if (arr2->A[j] < arr1->A[i]) j++;
        else { arr3->A[k++] = arr1->A[i++]; j++; }
    }
    arr3->length = k;
    arr3->size = arr3->length;
    return arr3;
}

struct Array* Difference(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    if (arr3 == NULL) { printf("Memory allocation failed (Difference).\n"); return NULL; }
    arr3->A = (int *)malloc((arr1->length + arr2->length) * sizeof(int));
    if (arr3->A == NULL) { printf("Memory allocation failed (Difference A).\n"); free(arr3); return NULL; }

    while(i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i]) j++;
        else { i++; j++; }
    }
    for(; i < arr1->length; i++) arr3->A[k++] = arr1->A[i];
    arr3->length = k;
    arr3->size = arr3->length;
    return arr3;
}

int main()
{
    struct Array arr1, arr2;
    struct Array *arr3 = NULL; 

    arr1.size = 10;
    arr1.length = 5;
    arr1.A = (int *)malloc(arr1.size * sizeof(int));
    if (arr1.A == NULL) { printf("Memory allocation failed for arr1.\n"); return 1; }
    int temp1[] = {2, 6, 10, 15, 25};
    for(int i = 0; i < arr1.length; i++) {
        arr1.A[i] = temp1[i];
    }

    arr2.size = 10;
    arr2.length = 5;
    arr2.A = (int *)malloc(arr2.size * sizeof(int));
    if (arr2.A == NULL) {
        printf("Memory allocation failed for arr2.\n");
        free(arr1.A);
        return 1;
    }
    int temp2[] = {3, 6, 7, 15, 20};
    for(int i = 0; i < arr2.length; i++) {
        arr2.A[i] = temp2[i];
    }

    printf("Array 1: ");
    Display(arr1);
    printf("Array 2: ");
    Display(arr2);

    printf("\n--- Set Operations ---\n");

    arr3 = Intersection(&arr1, &arr2);
    printf("Intersection Array: ");
    
    if (arr3 != NULL) {
        Display(*arr3);
        free(arr3->A);
        free(arr3);
    } else {
        printf("Operation failed or returned NULL.\n");
    }

    free(arr1.A);
    free(arr2.A);

    return 0;
}
