#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;

/*
  Luis Ricardo Albano Santos - 2021031844
  gcc -pedantic-errors -Wall main.c -o main.exe && ./main.exe
*/

/*
  Função recebe um numero inteiro e retorna um vetor com este tamanho;
*/
int* iniciaVetor(int n_pos) {
  //faço a alocação de um vetor de n posições
  int* V = malloc(n_pos * sizeof(int));
  //retorno esse vetor
  return V;
}

/*
  Recebe um vetor para assim libera-lo na memória
*/
void liberaConjunto(int* V) {
  free(V);
}

/*
  Verifica se um valor é único em um determinado array e retorna true ou false
*/
bool verificaUnico(int* V, int nV, int v) {
  //Verifico se um elemento é unico no array
  for (int i = 0; i < nV; i++) {
    //Se cajo exixtir já retorno false
    if (v == V[i]) return false;
  }
  //Caso n existir retorno true
  return true;
}

/*
   Função resposavel por receber um vetor e o ordena em ordem crescente
*/
void ordena(int* V, int nV) {
  int aux;
  //Percorro o vetor 
  for (int i = 0; i < nV - 1; i++) {
    //Ordeno o vetor fazendo ele rodar cada vez menos, otimizando assim
    for (int j = 0; j < nV - i - 1; j++) {
      if (V[j] > V[j + 1]) {
        //realizo a troca
        aux = V[j];
        V[j] = V[j + 1];
        V[j + 1] = aux;
      }
    }
  }
}

/*
  Função reponsavel por fazer a união entre dois vetores e retorna-lo
*/
int* uniao(int* A, int nA, int* B, int nB, int* nC) {
  //Conjunto auxiliar para armanezar a interseccao
  int* U = iniciaVetor(nA + nB);
  *nC = 0;
  //insiro o conjunto inicial A
  for (int i = 0; i < nA; i++) {
    U[(*nC)++] = A[i];
  }
  //insiro o conjunto verificando se ele será unico no vetor
  for (int i = 0; i < nB; i++) {
    if (verificaUnico(U, *nC, B[i])) {
      U[(*nC)++] = B[i];
    }
  }
  //Conjunto  para conter a interseccao do tamanho exato necessario
  int* C = iniciaVetor(*nC);

  for (int i = 0; i < *nC; i++) {
    C[i] = U[i];
  }
  //Libero o conjunto U
  liberaConjunto(U);
  //ordeno meu conjunto D
  ordena(C, *nC);

  return C;

}

/*
  Função responsavel por encontrar a interseccao entre dois vetores e retornar esse vetor
*/
int* interseccao(int* A, int nA, int* B, int nB, int* nD) {
  //Conjunto auxiliar para armanezar a interseccao
  int* U = iniciaVetor(nA + nB);
  *nD = 0;
  //Encontro elementos que estão nos dois vetores
  for (int i = 0; i < nA; i++) {
    for (int j = 0; j < nB; j++) {
      if (A[i] == B[j] && verificaUnico(U, *nD, A[i])) {
        U[(*nD)++] = A[i];
      }
    }
  }
  //Conjunto  para conter a interseccao do tamanho exato necessario
  int* D = iniciaVetor(*nD);

  for (int i = 0; i < *nD; i++) {
    D[i] = U[i];
  }
  //Libero o conjunto U
  liberaConjunto(U);
  //ordeno meu conjunto D
  ordena(D, *nD);

  return D;
}

/*
  Função reponsavel por imprimir um array
*/
void imprimeConjunto(int* V, int nV) {
  for (int i = 0; i < nV; i++) {
    printf("%d ", V[i]);
  }

  printf("\n");
}

int main(int argc, char* argv[]) {
  int* A;
  int* B;
  int* C;
  int* D;
  int nA, nB, nC, nD, aux;

  //inicializando e lendo o conjunto A
  scanf("%d", &nA);
  A = iniciaVetor(nA);
  for (int i = 0; i < nA; i++) {
    scanf("%d", &aux);
    A[i] = aux;
  }

  //inicializando e lendo o conjunto B
  scanf("%d", &nB);
  B = iniciaVetor(nB);
  for (int i = 0; i < nB; i++) {
    scanf("%d", &aux);
    B[i] = aux;
  }

  //calcula e imprime a uniao e a interseccao
  C = uniao(A, nA, B, nB, &nC);
  imprimeConjunto(C, nC);

  D = interseccao(A, nA, B, nB, &nD);
  imprimeConjunto(D, nD);

  //libera a memoria dos 4 vetores
  liberaConjunto(A);
  liberaConjunto(B);
  liberaConjunto(C);
  liberaConjunto(D);

  return 0;
}
