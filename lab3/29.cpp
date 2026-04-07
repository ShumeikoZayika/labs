#ifndef ARRAY_CLASS_DECLARATION_H
#define ARRAY_CLASS_DECLARATION_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class Array
{
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y); 

public:
    
    Array();          
    Array(int sz);    
    ~Array();         

    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int LinearSearch(int key);
    int BinarySearch(int key);
    
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(int x);
    int isSorted();
    void Rearrange(); 

    Array* Merge(Array *arr2);
    Array* Union(Array *arr2);
    Array* Intersection(Array *arr2);
    Array* Difference(Array *arr2);
};

#endif 

int main() { return 0; }
