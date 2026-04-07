#include <iostream>
using namespace std;
template<class T>
class Array {
public:
    Array(int sz) {}
    void Insert(int index, T x) {}
    T Delete(int index) { return T(); }
    void Display() {}
};
 

int main()
{
    
    cout << "--- Testing Array<int> ---" << endl;
    Array<int> arr_int(10); 

    arr_int.Insert(0, 5);
    arr_int.Insert(1, 6);
    arr_int.Insert(2, 9);
    arr_int.Display(); 

    cout << "Deleted Element is: " << arr_int.Delete(0) << endl; 
    arr_int.Display(); 

    cout << "\n--- Testing Array<float> ---" << endl;
    Array<float> arr_float(10); 

    arr_float.Insert(0, 5.2f);
    arr_float.Insert(1, 6.4f);
    arr_float.Insert(2, 9.1f);
    arr_float.Display(); 

    cout << "Deleted Element is: " << arr_float.Delete(0) << endl; 
    arr_float.Display(); 

    cout << "\n--- Testing Array<char> ---" << endl;
    Array<char> arr_char(10); 

    arr_char.Insert(0, 'a');
    arr_char.Insert(1, 'c');
    arr_char.Insert(2, 'd');
    arr_char.Display(); 

    cout << "Deleted Element is: " << arr_char.Delete(0) << endl; 
    arr_char.Display(); 

    return 0;
}
