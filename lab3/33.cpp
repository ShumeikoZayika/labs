
#include <cstdio> 

void findDuplicatesUnsorted(int arr[], int n) {
    
    for (int i = 0; i < n - 1; i++) {
        
        if (arr[i] != -1) {
            int count = 1;
            
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    arr[j] = -1; 
                }
            }
            
            if (count > 1) {
                printf("%d appears %d times\n", arr[i], count);
            }
        }
    }
}

int main() { return 0; }
