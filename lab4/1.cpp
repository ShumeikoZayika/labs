#include <iostream>
#include <cstdio>

int main() {
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Your name is: %s\n", name);

    std::cout << "Enter your name (C++): ";
    std::cin >> name;
    std::cout << "Your name is (C++): " << name << std::endl;

    return 0;
}
