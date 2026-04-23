#include <iostream>
class Array {
private:
    int *A;
    int size;
    int length;
public:
    Array();
    Array(int sz);
    ~Array();
    void Display();
    void swap(int *x, int *y);
};


void Array::swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

Array::Array()
{
    size = 10;
    length = 0;
    A = new int[size];
    if (A == NULL) {
        std::cerr << "Memory allocation failed in default constructor." << std::endl;
        
    }
}

Array::Array(int sz)
{
    size = sz; 
    length = 0;
    A = new int[size];
    if (A == NULL) {
        std::cerr << "Memory allocation failed in parameterized constructor." << std::endl;
        
    }
}

Array::~Array()
{
    delete []A;
    A = NULL; 
}

void Array::Display()
{
    printf("Elements are: ");
    for(int i = 0; i < length; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() { return 0; }

