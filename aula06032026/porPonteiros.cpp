#include <iostream>
#include <Windows.h>


void calcularDobro(int* numero, int* resultado) {
    *resultado = (*numero) * 2;
}


void calcularTriplo(int* numero, int* resultado) {
    *resultado = (*numero) * 3;
}

int main() {
    SetConsoleOutputCP(65001);

    int valor;
    int dobro, triplo;


    std::cout << "Digite um número inteiro: ";
    std::cin >> valor;


    calcularDobro(&valor, &dobro);
    calcularTriplo(&valor, &triplo);


    std::cout << "\nResultados:" << std::endl;
    std::cout << "Número original: " << valor << std::endl;
    std:: cout << "Dobro: " << dobro << std::endl;
    std::cout << "Triplo: " << triplo << std::endl;

    return 0;
}