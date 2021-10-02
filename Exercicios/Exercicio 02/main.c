#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;

/*
  Luis Ricardo Albano Santos - 2021031844
  gcc -pedantic-errors -Wall main.c -o main.exe && ./main.exe
*/

typedef struct No {
    int dado;
    struct No* prox;
}No;

typedef No* p_no;

p_no criaLista() {
    return NULL;
}

p_no adicionaLista(p_no lista, int dado) {
    p_no no = malloc(sizeof(No));
    no->dado = dado;
    no->prox = lista;

    return no;
}

void apagaLista(p_no lista) {
    if (lista == NULL) return;

    apagaLista(lista->prox);
    free(lista);
}

void printaElemento(p_no elemento) {
    if (elemento == NULL) return;
    printf("%d ", elemento->dado);
}

void printaLista(p_no lista) {
    if (lista == NULL) return;
    printaLista(lista->prox);
    printaElemento(lista);

}

p_no deletaElemento(p_no lista, int dado) {
    if (lista == NULL || lista->prox == NULL) return NULL;
    p_no proximo = lista->prox;
    if (proximo->dado == dado) {
        lista->prox = proximo->prox;

        free(proximo);
        return lista;
    } else if (lista->dado == dado) {
        free(lista);

        return proximo;
    }

    deletaElemento(lista->prox, dado);

    return lista;

}

p_no buscaElemento(p_no lista, int dado) {
    if (lista == NULL) return NULL;
    if (lista->dado == dado) return lista;

    p_no no = buscaElemento(lista->prox, dado);

    return no;
}

int main(void) {

    p_no lista = criaLista();

    for (int i = 0; i < 10; i++) {
        lista = adicionaLista(lista, i);
    }

    printaLista(lista);
    printf("\n");

    p_no elemento = buscaElemento(lista, 0);

    printaElemento(elemento);
    printf("\n");

    elemento = buscaElemento(lista, 4);
    printaElemento(elemento); 
    printf("\n");

    lista = deletaElemento(lista, 2);

    printaLista(lista);
    printf("\n");
    apagaLista(lista);

    printf("\n");

    return 0;

}
