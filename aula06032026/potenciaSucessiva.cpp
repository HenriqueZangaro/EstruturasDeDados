#include <iostream>
#include <Windows.h>

// Faça uma função recursiva que calcula a pontencia de
// um número usando multiplicações sucessivas.Int pot(int base, int exp);

int pot(int base, int exp);

int main() {

    std::cout << pot(3, 3);
    return 0;
}

int pot(int base, int exp) {
    if (exp == 1) {
        return 1;
    }

    return base * pot(base, exp - 1);
}