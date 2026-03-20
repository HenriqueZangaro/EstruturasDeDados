#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct No {
    int dado;
    struct No* proximo;
} No;


No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    

    if (novo == NULL) {
        printf("ERRO: Memória insuficiente!\n");
        return NULL;
    }
    
    novo->dado = valor;
    novo->proximo = NULL;
    return novo;
}


void inserirInicio(No** cabeca, int valor) {
    No* novo = criarNo(valor);
    
    if (novo == NULL) {
        return;
    }
    
    novo->proximo = *cabeca;
    *cabeca = novo;
    printf("Elemento %d inserido no início!\n", valor);
}


void inserirFinal(No** cabeca, int valor) {
    No* novo = criarNo(valor);
    
    if (novo == NULL) {
        return;
    }
    

    if (*cabeca == NULL) {
        *cabeca = novo;
        printf("Elemento %d inserido no final!\n", valor);
        return;
    }
    

    No* atual = *cabeca;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    
    atual->proximo = novo;
    printf("Elemento %d inserido no final!\n", valor);
}


void inserirMeio(No** cabeca, int valor, int posicao) {

    if (posicao == 0) {
        inserirInicio(cabeca, valor);
        return;
    }
    
    No* novo = criarNo(valor);
    if (novo == NULL) {
        return;
    }
    
    No* atual = *cabeca;
    int i;
    

    for (i = 0; i < posicao - 1 && atual != NULL; i++) {
        atual = atual->proximo;
    }
    

    if (atual == NULL) {
        printf("ERRO: Posição inválida!\n");
        free(novo);
        return;
    }
    
    novo->proximo = atual->proximo;
    atual->proximo = novo;
    printf("Elemento %d inserido na posição %d!\n", valor, posicao);
}


void imprimir(No* cabeca) {
    if (cabeca == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    
    printf("Lista: ");
    No* atual = cabeca;
    
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}


void apagarElemento(No** cabeca, int valor) {
    No* atual = *cabeca;
    No* anterior = NULL;
    int contador = 0;
    

    while (atual != NULL && atual->dado == valor) {
        No* temp = atual;
        *cabeca = atual->proximo;
        atual = atual->proximo;
        free(temp);
        contador++;
    }
    

    anterior = *cabeca;
    if (anterior != NULL) {
        atual = anterior->proximo;
    }
    
    while (atual != NULL) {
        if (atual->dado == valor) {
            No* temp = atual;
            anterior->proximo = atual->proximo;
            atual = atual->proximo;
            free(temp);
            contador++;
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
    }
    
    if (contador > 0) {
        printf("%d elemento(s) com valor %d removido(s)!\n", contador, valor);
    } else {
        printf("Elemento %d não encontrado!\n", valor);
    }
}


void apagarLista(No** cabeca) {
    No* atual = *cabeca;
    No* proximo;
    
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    
    *cabeca = NULL;
    printf("Lista completamente apagada!\n");
}


void exibirMenu() {
    printf("\n========== MENU ==========\n");
    printf("0 - Sair\n");
    printf("1 - Inserir no início\n");
    printf("2 - Inserir no final\n");
    printf("3 - Inserir no meio\n");
    printf("4 - Imprimir lista\n");
    printf("5 - Apagar elemento\n");
    printf("6 - Apagar lista\n");
    printf("==========================\n");
    printf("Escolha uma opção: ");
}

int main() {
    SetConsoleOutputCP(65001);
    No* lista = NULL;
    int opcao, valor, posicao;
    
    printf("=== PROGRAMA DE LISTA LIGADA ===\n");
    
    do {
        exibirMenu();
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 0:
                printf("Encerrando o programa...\n");
                apagarLista(&lista);
                break;
                
            case 1:
                printf("Digite o valor a inserir no início: ");
                scanf("%d", &valor);
                inserirInicio(&lista, valor);
                break;
                
            case 2:
                printf("Digite o valor a inserir no final: ");
                scanf("%d", &valor);
                inserirFinal(&lista, valor);
                break;
                
            case 3:
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                printf("Digite a posição (0 = início): ");
                scanf("%d", &posicao);
                inserirMeio(&lista, valor, posicao);
                break;
                
            case 4:
                imprimir(lista);
                break;
                
            case 5:
                printf("Digite o valor a apagar: ");
                scanf("%d", &valor);
                apagarElemento(&lista, valor);
                break;
                
            case 6:
                apagarLista(&lista);
                break;
                
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
        
    } while(opcao != 0);
    
    printf("Programa finalizado!\n");
    return 0;
}