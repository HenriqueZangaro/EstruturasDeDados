#include <iostream>
#include <Windows.h>

// Faça uma função recursiva que calcula a divisão
// usando subtrações sucessivas.Int div(int a, int b);

int divisao(int a, int b);

int main() {

	std::cout << divisao(30, 5);

	return 0;
}

int divisao(int a, int b) {
	if (a < b) {
		return 0;
	}
	return 1 + divisao(a - b, b);
}