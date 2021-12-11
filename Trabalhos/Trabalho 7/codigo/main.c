#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

#define MAX 5000

int main(int argc, char* argv[]) {

  p_fp f = criar_fila_prio(MAX);
  int torre_id = 0;
  int turnos = 0;
  int dano_jogador = 0;

  //lendo a quantidade de turnos
  scanf("%d", &turnos);

  //semente para o gerador de numeros aleatorios
  srand(turnos);

  //enquanto houverem turnos
  while (turnos > 0) {
    //Nasce uma nova torre com vida sorteada aleatoriamente 
    //entre 1 e 20
    if (tamanho_fila(f) < MAX) {
      int vida = (rand() % 20) + 1;
      printf("Nova torre %d: %d\n", torre_id, vida);
      insere(f, torre_id, vida);
      torre_id++;
    }

    //Encontrando o proximo alvo e atacando (remove 10 de vida)
    torre torre_alvo = extrai_minimo(f);
    printf("Atk %d: %d -> %d\n", torre_alvo.id, torre_alvo.vida, torre_alvo.vida - 10);
    torre_alvo.vida = torre_alvo.vida - 10;
    if (torre_alvo.vida > 0) {
      //Torre nao caiu, volta para fila
      insere(f, torre_alvo.id, torre_alvo.vida);
    }
    else {
      printf("t%d caiu\n", torre_alvo.id);
    }

    //cada torre vida causa 1 de dado no jogador
    int num_torres_vivas = tamanho_fila(f);
    printf("%d dano\n\n", num_torres_vivas);
    dano_jogador = dano_jogador + num_torres_vivas;
    turnos--;
  }

  printf("\nFINAL:\n");
  printf("Jogador tomou %d dano\n", dano_jogador);

  return 0;
}
