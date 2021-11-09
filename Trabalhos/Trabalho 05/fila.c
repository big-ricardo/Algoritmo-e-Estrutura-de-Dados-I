#include <stdlib.h>
#include "fila.h"
#define true 1
#define false 0
typedef int bool;

struct fila_No {
    void* info;
    struct fila_No* prox;
};

struct Fila {
    p_fila_no inicio;
    p_fila_no fim;
};

p_fila criaFila() {
    p_fila fila = (p_fila)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

void enfileira(p_fila f, void* info) {

    p_fila_no novo = malloc(sizeof(fila_No));

    novo->info = info;
    novo->prox = NULL;

    if (f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo;

    }
    else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    return;
}

bool filaVazia(p_fila f) {
    return f->fim == NULL;
}

void* desenfileira(p_fila f) {
    void* aux;
    p_fila_no noAux;

    if (f->inicio != NULL) {
        noAux = f->inicio;
        aux = noAux->info;
        f->inicio = f->inicio->prox;

        if (f->inicio == NULL) {
            f->fim = NULL;
        }
        free(noAux);
    }

    return aux;
}

void liberaFila(p_fila f) {
    p_fila_no no = f->inicio;
    while (no != NULL) {
        p_fila_no prox = no->prox;
        free(no);
        no = prox;
    }
    free(f);
}