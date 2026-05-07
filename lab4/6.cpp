#include <stdio.h>

int main() {
    char A[] = "finding";
    long int H = 0, x = 0;

    for (int i = 0; A[i] != '\0'; i++) {
        x = 1;
        x = x << (A[i] - 'a');

        if ((H & x) > 0) {
            printf("%c is Duplicate\n", A[i]);
        } else {
            H = H | x;
        }
    }
    return 0;
}