#include <iostream>
#include <cstdio>

int main() {
    char A[] = "How are you";
    int i, word_count = 1;

    for (i = 0; A[i] != '\0'; i++) {
        if (A[i] == ' ') {
            word_count++;
        }
    }
    printf("Number of words: %d\n", word_count);

    return 0;
}