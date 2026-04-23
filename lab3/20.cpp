
#include <cstdio> 

void findPairWithSum(int arr[], int n, int k, int hash_table_size, int hash_table[]) {
    
    for (int i = 0; i < n; i++) {
        
        int complement = k - arr[i];

        if (complement >= 0 && complement < hash_table_size) {
            
            if (hash_table[complement] != 0) {
                printf("Pair found: %d + %d = %d\n", arr[i], complement, k);
            }
        }

        if (arr[i] >= 0 && arr[i] < hash_table_size) {
            hash_table[arr[i]]++;
        }
    }
}

int main() { return 0; }
