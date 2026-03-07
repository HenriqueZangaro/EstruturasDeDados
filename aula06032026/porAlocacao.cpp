#include <iostream>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(65001);


    int* valor = new int;
    int* dobro = new int;
    int* triplo = new int;

    std::cout << "Digite um número inteiro: ";
    std::cin >> *valor;

    *dobro = (*valor) * 2;
    *triplo = (*valor) * 3;

    std::cout << "\nResultados:" << std::endl;
    std::cout << "Número original: " << *valor << std::endl;
    std::cout << "Dobro: " << *dobro << std::endl;
    std::cout << "Triplo: " << *triplo << std::endl;

    delete valor;
    delete dobro;
    delete triplo;

    valor = nullptr;
    dobro = nullptr;
    triplo = nullptr;

    return 0;
}