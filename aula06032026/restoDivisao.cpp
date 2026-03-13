#include <iostream>
#include <Windows.h>

// Faça uma função recursiva que calcula o resto de uma
// divisão usando subtrações sucessivas.Int mod(int a, int b);

int mod(int a, int b);

int main() {

    std::cout << mod(70, 15);
	return 0;
}

int mod(int a, int b) {
    if (b <= 0) {
        return 0;
    }

    if (a < b) {
        return a;
    }

    return mod(a - b, b);
}