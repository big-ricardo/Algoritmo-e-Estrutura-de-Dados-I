#include <stdlib.h>
#include "pilha.h"
#define true 1
#define false 0
typedef int bool;

struct pilha_No {
    void* info;
    struct pilha_No* prox;
};

struct Pilha {
    p_pilha_no pilha;
};

p_pilha criaPilha() {
    p_pilha p = malloc(sizeof(Pilha));
    p->pilha = NULL;
    return p;
}

void empilha(p_pilha p, void* info) {
    p_pilha_no novo = malloc(sizeof(struct pilha_No));
    novo->info = info;
    novo->prox = p->pilha;
    p->pilha = novo;

    return;
}

bool pilhaVazia(p_pilha p) {
    return p->pilha == NULL;
}

void* desempilha(p_pilha p) {
    if (pilhaVazia(p)) {
        return NULL;
    }

    p_pilha_no aux = p->pilha;
    p->pilha = p->pilha->prox;
    void* info = aux->info;
    free(aux);

    return info;
}

void liberaPilha(p_pilha p) {
    while (!pilhaVazia(p)) {
        desempilha(p);
    }
    free(p);
}