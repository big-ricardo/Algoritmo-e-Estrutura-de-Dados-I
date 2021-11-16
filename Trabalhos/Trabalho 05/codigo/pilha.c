#include <stdlib.h>
#include "pilha.h"
#define true 1
#define false 0
typedef int bool;

// Definição da struct nó
struct No {
    void* info;
    struct No* prox;
};
// Definição do ponteiro para struct nó
typedef struct  No* p_no;

// Definição da struct pilha
struct Pilha {
    p_no pilha;
    int tamanho;
};
// Definição do ponteiro para struct pilha
typedef struct No No;

// Função que cria uma pilha
p_pilha criaPilha() {
    // Aloca memória para a pilha
    p_pilha p = malloc(sizeof(Pilha));
    // Inicializa a pilha com NULL
    p->pilha = NULL;
    // Inicializa o tamanho da pilha com 0
    p->tamanho = 0;
    // Retorna a pilha
    return p;
}

// Insira um elemento na pilha
void empilha(p_pilha p, void* info) {
    // Aloca memória para o nó
    p_no novo = malloc(sizeof(No));
    // Inicializa o nó com a informação
    novo->info = info;
    // Inicializa o nó com o próximo nó com o nó atual
    novo->prox = p->pilha;
    // Inicializa a pilha com o nó atual
    p->pilha = novo;
    // Incrementa o tamanho da pilha
    p->tamanho++;

    return;
}

// Verifique se a pilha está vazia
bool pilhaVazia(p_pilha p) {
    return p->pilha == NULL;
}

// Retire um elemento da pilha
void* desempilha(p_pilha p) {
    // Verifica se a pilha está vazia
    if (pilhaVazia(p)) {
        // Retorna NULL
        return NULL;
    }
    // Define o nó auxiliar atual como o primeiro nó da pilha
    p_no aux = p->pilha;
    // Define o primeiro nó da pilha com o próximo nó
    p->pilha = p->pilha->prox;
    // Decrementa o tamanho da pilha
    p->tamanho--;
    // Guarda a informação do nó auxiliar
    void* info = aux->info;
    // Libera a memória do nó auxiliar
    free(aux);
    // Retorna a informação do nó auxiliar
    return info;
}

// Libera a memória alocada para a pilha
void liberaPilha(p_pilha p) {
    // Enquanto a pilha não estiver vazia
    while (!pilhaVazia(p)) {
        // Desempilha o primeiro nó
        void* info = desempilha(p);
        // Libera a memória alocada para a informação
        free(info);
    }
    // Libera a memória alocada para a pilha
    free(p);
}

// Retorna o tamanho da pilha
int tamanhoPilha(p_pilha p) {
    return p->tamanho;
}