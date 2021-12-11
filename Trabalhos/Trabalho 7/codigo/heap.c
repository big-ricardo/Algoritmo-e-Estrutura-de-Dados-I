#include <stdlib.h>
#include "heap.h"
#define pai(i) ((i-1)/2)
#define filho_esq(i) (2*i+1)
#define filho_dir(i) (2*i+2)

// Função que cria um heap vazio
p_fp criar_fila_prio(int capacidade) {
    p_fp fila = (p_fp)malloc(sizeof(Heap));
    fila->tamanho = 0;
    fila->capacidade = capacidade;
    fila->vetor = malloc(capacidade * sizeof(torre));
    return fila;
}

// Função que retorna o tamanho do heap
int tamanho_fila(p_fp fila) {
    return fila->tamanho;
}

// Função que sobe o elemento no heap
void sobe_no_heap(p_fp fila, int i) {
    int pai = pai(i);
    torre aux = fila->vetor[i];
    while (i > 0 && fila->vetor[pai].vida > aux.vida) {
        fila->vetor[i] = fila->vetor[pai];
        i = pai;
        pai = pai(i);
    }
    fila->vetor[i] = aux;
}

// Função que insere um elemento no heap
void insere(p_fp fila, int id, int vida) {
    torre nova;
    nova.id = id;
    nova.vida = vida;
    if (tamanho_fila(fila) == fila->capacidade) {
        return;
    }
    fila->vetor[tamanho_fila(fila)] = nova;
    fila->tamanho++;
    sobe_no_heap(fila, tamanho_fila(fila) - 1);
    return;
}

// Função que desce o elemento no heap
void desce_no_heap(p_fp fila, int i) {
    int menor = filho_esq(i);
    if (menor >= tamanho_fila(fila)) return;

    if (filho_dir(i) < tamanho_fila(fila) &&
        fila->vetor[filho_dir(i)].vida < fila->vetor[menor].vida) {
        menor = filho_dir(i);
    }
    if (fila->vetor[i].vida > fila->vetor[menor].vida) {
        torre aux = fila->vetor[i];
        fila->vetor[i] = fila->vetor[menor];
        fila->vetor[menor] = aux;
        i = menor;
    }
    else {
        return;
    }

    desce_no_heap(fila, i);
}

// Função que remove o elemento com Menor vida no heap
torre extrai_minimo(p_fp fila) {
    if (fila->tamanho == 0) {
        torre torre;
        torre.id = -1;
        torre.vida = -1;
        return torre;
    }
    torre min = fila->vetor[0];
    fila->vetor[0] = fila->vetor[tamanho_fila(fila) - 1];
    fila->tamanho--;
    desce_no_heap(fila, 0);
    return min;
}

// Função que destroi o heap
void destroi_heap(p_fp fila) {
    free(fila->vetor);
    free(fila);
}
