#include <iostream>
#include <cctype>

bool isValid(const char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalnum(name[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    char name1[] = "Ani123";
    char name2[] = "Ani!321";

    if (isValid(name1)) {
        std::cout << name1 << " is valid." << std::endl;
    } else {
        std::cout << name1 << " is not valid." << std::endl;
    }

    if (isValid(name2)) {
        std::cout << name2 << " is valid." << std::endl;
    } else {
        std::cout << name2 << " is not valid." << std::endl;
    }

    return 0;
}