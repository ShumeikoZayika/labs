#include <iostream> 
#include <vector>   
#include <algorithm> 

class ArrayOperations {
private:
    std::vector<int> data;
    int length; 

public:
    
    ArrayOperations(int size) {
        if (size < 0) {
            std::cerr << "Warning: Initializing ArrayOperations with negative size. Setting to 0." << std::endl;
            length = 0;
        } else {
            length = size;
            data.resize(length); 
        }
    }

    int Get(int index) {
        
        if (index >= 0 && index < length) {
            return data[index];
        } else {
            std::cerr << "Error: Index " << index << " out of bounds in Get(). Array length: " << length << std::endl;
            
            return -1; 
        }
    }

    void Set(int index, int x) {
        
        if (index >= 0 && index < length) {
            data[index] = x;
        } else {
            std::cerr << "Error: Index " << index << " out of bounds in Set(). Array length: " << length << std::endl;
            
        }
    }

    int Max() {
        if (length <= 0) {
            std::cerr << "Error: Array is empty, cannot find maximum value." << std::endl;
            
            return -1; 
        }

        int max_val = data[0]; 

        for (int i = 1; i < length; i++) {
            if (data[i] > max_val) {
                max_val = data[i]; 
            }
        }
        return max_val;
    }

};

int main() { return 0; }
