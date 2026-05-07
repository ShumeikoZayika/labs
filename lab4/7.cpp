#include <stdio.h>

int main() {
    char A[] = "decimal";
    char B[] = "medical";
    int H[26] = {0};
    int i;

    for (i = 0; A[i] != '\0'; i++) {
        H[A[i] - 'a']++;
    }

    for (i = 0; B[i] != '\0'; i++) {
        H[B[i] - 'a']--;
    }

    for (i = 0; i < 26; i++) {
        if (H[i] != 0) {
            printf("Not Anagrams\n");
            return 0;
        }
    }

    printf("Anagrams\n");
    return 0;
}