#include <stdio.h>
#include <stdlib.h>

#define MAX 5000

#define pai(i) ((i-1)/2)
#define filho_esq(i) (2*i+1)
#define filho_dir(i) (2*i+2)

typedef struct {
  int id;
  int vida;
} torre;

// Estrutura do heap
typedef struct Heap {
  int tamanho;
  int capacidade;
  torre* vetor;
} Heap;

// Ponteiro para a estrutura do heap
typedef Heap* p_fp;
// Ponteiro para estrutura da torre
typedef torre* p_torre;

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

int vida(p_fp fila, int i) {
  return fila->vetor[i].vida;
}

int id(p_fp fila, int i) {
  return fila->vetor[i].id;
}

void troca(p_fp fila, int i, int j) {
  torre aux = fila->vetor[i];
  fila->vetor[i] = fila->vetor[j];
  fila->vetor[j] = aux;
}

// Função que sobe o elemento no heap
void sobe_no_heap(p_fp fila, int i) {
  int p = pai(i);

  if (i == p) return;

  if (fila->vetor[i].vida < fila->vetor[p].vida) {
    torre aux = fila->vetor[i];
    fila->vetor[i] = fila->vetor[p];
    fila->vetor[p] = aux;
    sobe_no_heap(fila, p);
  }
  else if (fila->vetor[i].vida == fila->vetor[p].vida) {
    if (fila->vetor[i].id < fila->vetor[p].id) {
      troca(fila, i, p);
      sobe_no_heap(fila, p);
    }
  }

  return;
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
  if (menor > tamanho_fila(fila)) return;

  if (filho_dir(i) < tamanho_fila(fila) &&
    vida(fila, filho_dir(i)) < vida(fila, menor)) {
    menor = filho_dir(i);
  }

  if (vida(fila, i) > vida(fila, menor)) {
    troca(fila, i, menor);
    i = menor;
  }

  if (fila->vetor[i].vida == vida(fila, menor) && id(fila, i) > id(fila, menor)) {
    troca(fila, i, menor);
    i = menor;
  }
  else return;

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

int main(int argc, char* argv[]) {

  p_fp f = criar_fila_prio(MAX);
  int torre_id = 0;
  int turnos = 0;
  int dano_jogador = 0;

  //lendo a quantidade de turnos
  scanf("%d", &turnos);
  // insere(f, 3, 2);
  // insere(f, 4, 1);
  // insere(f, 1, 2);
  // insere(f, 2, 2);

  // for (int i = 0; i < 4; i++)
  // {
  //   printf("Nova torre %d: %d\n", f->vetor[i].id, f->vetor[i].vida);
  // }
  // torre torre_alvo = extrai_minimo(f);
  // printf("\n\n#################################################3\n\n");
  // printf("Nova torre %d: %d\n", torre_alvo.id, torre_alvo.vida);
  // torre_alvo = extrai_minimo(f);
  // printf("Nova torre %d: %d\n", torre_alvo.id, torre_alvo.vida);
  // torre_alvo = extrai_minimo(f);
  // printf("Nova torre %d: %d\n", torre_alvo.id, torre_alvo.vida);
  // torre_alvo = extrai_minimo(f);
  // printf("Nova torre %d: %d\n", torre_alvo.id, torre_alvo.vida);



  // return 1;
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

  destroi_heap(f);

  return 0;
}
