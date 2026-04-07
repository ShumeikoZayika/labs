#ifndef ARRAY_OPERATIONS_C_H
#define ARRAY_OPERATIONS_C_H

#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void swap(int *x, int *y);

void Display(struct Array arr);
void Append(struct Array *arr, int x);
void Insert(struct Array *arr, int index, int x);
int Delete(struct Array *arr, int index);
int LinearSearch(struct Array *arr, int key);
int BinarySearch(struct Array arr, int key);
int RBinSearch(int a[], int l, int h, int key); 
int Get(struct Array arr, int index);
void Set(struct Array *arr, int index, int x);
int Max(struct Array arr);
int Min(struct Array arr);
int Sum(struct Array arr);
float Avg(struct Array arr);
void Reverse(struct Array *arr);  
void Reverse2(struct Array *arr); 
void InsertSort(struct Array *arr, int x);
int isSorted(struct Array arr);
void Rearrange(struct Array *arr); 

struct Array* Merge(struct Array *arr1, struct Array *arr2);
struct Array* Union(struct Array *arr1, struct Array *arr2);
struct Array* Intersection(struct Array *arr1, struct Array *arr2);
struct Array* Difference(struct Array *arr1, struct Array *arr2);

#endif 

int main() { return 0; }
