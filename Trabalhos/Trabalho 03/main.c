#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;

/*
  Luis Ricardo Albano Santos - 2021031844
  gcc -pedantic-errors -Wall main.c -o main.exe && ./main.exe
*/

//SUGESTAO DE ESTRUTURA PARA GUARDAR UM BLOCO
//PODE MUDAR SE QUISER
typedef struct Bloco {
  int id;
  int altura;
  struct Bloco* prox;
} Bloco;

typedef struct Bloco* p_Bloco;


//SUGESTAO DE ESTRUTURA PARA GUARDAR UM MACACO
//PODE MUDAR SE QUISER
typedef struct Macaco {
  int altura;
  p_Bloco lista_blocos;
} Macaco;

typedef struct Macaco* p_Macaco;



//SUGESTAO DE FUNCOES PARA IMPRESSAO
//PODE MUDAR SE QUISER
void imprime_blocos(p_Bloco lista) {
  if (lista == NULL) return;
  imprime_blocos(lista->prox);
  printf(" %d %d", lista->id, lista->altura);
}

void imprime_macacos(p_Macaco M, int num_macacos) {
  for (int i = 0; i < num_macacos; i++) {
    printf("M[%d] altura = %d:", i, M[i].altura);
    imprime_blocos(M[i].lista_blocos);
    printf("\n");
  }
}

p_Macaco inicializa_macacos(int n_macacos) {
  p_Macaco macacos = malloc(n_macacos * sizeof(Macaco));

  for (int i = 0; i < n_macacos; i++) {
    macacos[i].altura = 0;
    macacos[i].lista_blocos = NULL;
  }

  return macacos;
}

p_Bloco add_bloco(p_Bloco lista_blocos, int id, int altura) {
  p_Bloco bloco = malloc(sizeof(Bloco));

  bloco->id = id;
  bloco->altura = altura;
  bloco->prox = lista_blocos;

  return bloco;
}

void bota_no_menor(p_Macaco macacos, int n_macacos, int id, int altura) {
  int menor = 0;

  if (n_macacos > 2) {
    for (int i = 1; i < n_macacos; i++) {
      if (macacos[menor].altura > macacos[i].altura) {
        menor = i;
      }
    }
  }

  p_Macaco macaco = &macacos[menor];

  p_Bloco bloco = add_bloco(macaco->lista_blocos, id, altura);
  macaco->altura = macaco->altura + altura;
  macaco->lista_blocos = bloco;

}

void libera_blocos(p_Bloco blocos) {
  if (blocos == NULL) return;
  libera_blocos(blocos->prox);
  free(blocos);
}

void libera_macacos(p_Macaco macacos, int n_macacos) {
  for (int i = 1; i < n_macacos; i++) {
    libera_blocos(macacos[i].lista_blocos);
  }

  free(macacos);
}


//******************************
//VOCE NAO PODE MODIFICAR A MAIN
//******************************
int main(int argc, char* argv[]) {

  p_Macaco M;
  int num_macacos;
  int id_bloco;
  int altura_bloco;

  //le o numero de macacos
  scanf("%d", &num_macacos);

  M = inicializa_macacos(num_macacos);

  //le o primeiro bloco
  scanf("%d %d", &id_bloco, &altura_bloco);
  while (id_bloco != -1) {
    bota_no_menor(M, num_macacos, id_bloco, altura_bloco);
    //le o proximo bloco
    scanf("%d %d", &id_bloco, &altura_bloco);
  }

  imprime_macacos(M, num_macacos);

  //Lembre que cada macaca tem uma lista que precisa ser liberada
  libera_macacos(M, num_macacos);
  return 0;
}
