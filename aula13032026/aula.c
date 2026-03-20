#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int dado;
	struct No* prox;
} No;

struct No* criar_lista() {
	return NULL;
}

void destruir_lista(struct No* lista) {
	if (lista != NULL) {
		free(lista);
	}
}

int main() {
	struct No* lista;
	lista = criar_lista();

	printf("Lista criada com sucesso!");

	return 0;
}