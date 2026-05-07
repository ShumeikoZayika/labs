#include <iostream>
#include <cstring>

int main() {
    char A[] = "python";
    char B[10];
    int i, j;

    for (i = 0; A[i] != '\0'; i++) {
        B[i] = A[i];
    }
    B[i] = '\0';
    std::cout << "Original: " << A << ", Copied: " << B << std::endl;

    char C[] = "hello";
    char reversed_C[10];
    int length = strlen(C);

    for (i = 0, j = length - 1; i < length; i++, j--) {
        reversed_C[i] = C[j];
    }
    reversed_C[length] = '\0';
    std::cout << "Original: " << C << ", Reversed: " << reversed_C << std::endl;

    return 0;
}