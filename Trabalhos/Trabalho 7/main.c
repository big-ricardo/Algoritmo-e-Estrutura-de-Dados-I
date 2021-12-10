#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#define true 1
#define false 0
typedef int bool;

/*
  Luis Ricardo Albano Santos - 2021031844
  gcc -pedantic-errors -Wall main.c -o main.exe && ./main.exe
*/

void imprime_torre(Torre torre) {
  printf("id:%d ", torre.id);
  printf("hp:%d ", torre.hp);
  printf("\n");
}

void imprime_vetor(p_torre vetor, int tam) {
  printf("############################################\n");
  for (int i = 0; i < tam; i++) {
    imprime_torre(vetor[i]);
  }
  printf("\n");
}

int main(void) {

  p_heap heap = cria_fila_prio(10);
  insere(heap, 1, 60);
  insere(heap, 2, 30);
  insere(heap, 3, 50);
  insere(heap, 4, 40);
  insere(heap, 5, 10);

  imprime_vetor(heap->vetor, heap->tamanho);

  insere(heap, 6, 6);
  insere(heap, 7, 20);
  imprime_vetor(heap->vetor, heap->tamanho);

  imprime_torre(retorna_min(heap));
  imprime_torre(retorna_min(heap));
  imprime_torre(retorna_min(heap));
  imprime_vetor(heap->vetor, heap->tamanho);

  destroi_heap(heap);
  return 0;

}
