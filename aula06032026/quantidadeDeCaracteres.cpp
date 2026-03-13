#include <iostream>
#include <Windows.h>
#include <string>

// Faça uma função recursiva que calcula a quantidade
// de caracteres em uma string.Int tamanho(char* str)

int tamanho(std::string str, int tam = 0);

int main() {

    tamanho("Televisao");

    return 0;
}

int tamanho(std::string str, int tam) {
    if (tam == str.size()) {
        return 0;
    }

    return 1 + tamanho(str, tam + 1);
}