#include <iostream>
#include <cctype>

int main() {
    char A[] = "WELCOME";
    int i;

    for (i = 0; A[i] != '\0'; i++) {
        if (A[i] >= 'A' && A[i] <= 'Z') {
            A[i] += 32;
        }
    }
    std::cout << "Lowercase: " << A << std::endl;

    char B[] = "welcome";
    for (i = 0; B[i] != '\0'; i++) {
        if (B[i] >= 'a' && B[i] <= 'z') {
            B[i] -= 32;
        }
    }
    std::cout << "Uppercase: " << B << std::endl;

    return 0;
}
