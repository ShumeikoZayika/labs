#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 

using namespace std;

template <class T>
class Array
{
private:
    T *A;
    int size;
    int length;
    void swap(T *x, T *y); 

public:
    
    Array()
    {
        size = 10;
        length = 0;
        A = new T[size];
    }

    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new T[size];
    }

    ~Array()
    {
        delete[] A;
    }

    void Display();
    void Append(T x);
    void Insert(int index, T x);
    T Delete(int index);
    int LinearSearch(T key); 
    int BinarySearch(T key); 
    T Get(int index); 
    void Set(int index, T x); 
    T Max(); 
    T Min(); 
    T Sum();
    float Avg();
    void Reverse(); 
    void Reverse2();
    void InsertSort(T x);
    int isSorted();
    void Rearrange();
    Array<T>* Merge(const Array<T> &arr2);
    Array<T>* Union(const Array<T> &arr2);
    Array<T>* Intersection(const Array<T> &arr2);
    Array<T>* Difference(const Array<T> &arr2);
};

template <class T>
void Array<T>::swap(T *x, T *y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}

template <class T>
void Array<T>::Display()
{
    cout << "Elements are\n";
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

template <class T>
void Array<T>::Append(T x)
{
    if (length < size)
    {
        A[length++] = x;
    }
}

template <class T>
void Array<T>::Insert(int index, T x)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length; i > index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = x;
        length++;
    }
}

template <class T>
T Array<T>::Delete(int index)
{
    T x = 0; 
    if (index >= 0 && index < length)
    {
        x = A[index];
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
    }
    return x;
}

template <class T>
T Array<T>::Sum()
{
    T s = 0; 
    for (int i = 0; i < length; i++)
    {
        s += A[i];
    }
    return s;
}

template <class T>
float Array<T>::Avg()
{
    
    return (float)Sum() / length;
}

template <class T>
void Array<T>::Reverse2()
{
    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        swap(&A[i], &A[j]);
    }
}

template <class T>
void Array<T>::InsertSort(T x)
{
    int i = length - 1;
    if (length == size)
    {
        return;
    }
    while (i >= 0 && A[i] > x) 
    {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}

template <class T>
int Array<T>::isSorted()
{
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1]) 
        {
            return 0;
        }
    }
    return 1;
}

template <class T>
void Array<T>::Rearrange()
{
    int i = 0;
    int j = length - 1;

    while (i < j)
    {
        while (A[i] < 0) 
        {
            i++;
        }
        while (A[j] >= 0) 
        {
            j--;
        }
        if (i < j)
        {
            swap(&A[i], &A[j]);
        }
    }
}

template <class T>
Array<T>* Array<T>::Merge(const Array<T> &arr2)
{
    int i, j, k;
    i = j = k = 0;

    Array<T> *arr3 = new Array<T>(length + arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j]) 
        {
            arr3->A[k++] = A[i++];
        }
        else
        {
            arr3->A[k++] = arr2.A[j++];
        }
    }
    for (; i < length; i++)
    {
        arr3->A[k++] = A[i];
    }
    for (; j < arr2.length; j++)
    {
        arr3->A[k++] = arr2.A[j];
    }
    arr3->length = length + arr2.length;
    
    return arr3;
}

template <class T>
Array<T>* Array<T>::Union(const Array<T> &arr2)
{
    int i, j, k;
    i = j = k = 0;

    Array<T> *arr3 = new Array<T>(length + arr2.length); 

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j]) 
        {
            arr3->A[k++] = A[i++];
        }
        else if (arr2.A[j] < A[i])
        {
            arr3->A[k++] = arr2.A[j++];
        }
        else 
        {
            arr3->A[k++] = A[i++];
            j++; 
        }
    }
    for (; i < length; i++)
    {
        arr3->A[k++] = A[i];
    }
    for (; j < arr2.length; j++)
    {
        arr3->A[k++] = arr2.A[j];
    }

    arr3->length = k; 
    
    return arr3;
}

template <class T>
Array<T>* Array<T>::Intersection(const Array<T> &arr2)
{
    int i, j, k;
    i = j = k = 0;

    Array<T> *arr3 = new Array<T>(length + arr2.length); 

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j]) 
        {
            i++;
        }
        else if (arr2.A[j] < A[i])
        {
            j++;
        }
        else if (A[i] == arr2.A[j]) 
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    arr3->length = k; 
    return arr3;
}

template <class T>
Array<T>* Array<T>::Difference(const Array<T> &arr2)
{
    int i, j, k;
    i = j = k = 0;

    Array<T> *arr3 = new Array<T>(length + arr2.length); 

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j]) 
        {
            arr3->A[k++] = A[i++];
        }
        else if (arr2.A[j] < A[i]) 
        {
            j++;
        }
        else 
        {
            i++;
            j++;
        }
    }
    for (; i < length; i++) 
    {
        arr3->A[k++] = A[i];
    }

    arr3->length = k; 
    return arr3;
}

template <class T>
int Array<T>::LinearSearch(T key) {  return -1; }
template <class T>
int Array<T>::BinarySearch(T key) {  return -1; }
template <class T>
T Array<T>::Get(int index) {  return T(); }
template <class T>
void Array<T>::Set(int index, T x) {  }
template <class T>
T Array<T>::Max() {  return T(); }
template <class T>
T Array<T>::Min() {  return T(); }
template <class T>
void Array<T>::Reverse() {  } 

int main() { return 0; }
