#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;

/*
  Luis Ricardo Albano Santos - 2021031844
  gcc -pedantic-errors -Wall main.c -o main.exe && ./main.exe
*/

int* iniciaVetor(int n_pos) {
  int* V = malloc(n_pos * sizeof(int));

  return V;
}

void liberaConjunto(int* V) {
  free(V);
}

bool verificaUnico(int* V, int nV, int v) {

  for (int i = 0; i < nV; i++) {
    if (v == V[i]) return false;
  }

  return true;
}

void ordena(int *V, int nV){
  for (int i = 0; i < nV; i++)
  {
    for (int j = 0; j < nV; j++)
    {
      if (V[i] < V[j])
      {
        
        int aux = V[i];
        V[i] = V[j];
        V[j] = aux;
      }
    }
  }
}

void insereValorConjuno(int* V, int* A, int nA, int* B, int nB, int* nC) {
  for (int i = 0; i < nA; i++) {
    V[(*nC)++] = A[i];
  }

  for (int i = 0; i < nB; i++) {
    if (verificaUnico(V, *nC, B[i])) {
      V[(*nC)++] = B[i];
    }
  }
}

int* uniao(int* A, int nA, int* B, int nB, int* nC) {
  int* U = iniciaVetor(nA + nB);
  *nC = 0;

  if (nA > nB) {
    insereValorConjuno(U, A, nA, B, nB, nC);
  }
  else {
    insereValorConjuno(U, B, nB, A, nA, nC);
  }

  int* C = iniciaVetor(*nC);

  for (int i = 0; i < *nC; i++) {
    C[i] = U[i];
  }

  liberaConjunto(U);

  ordena(C, *nC);

  return C;

}

int* interseccao(int* A, int nA, int* B, int nB, int* nD) {
  int* U = iniciaVetor(nA + nB);
  *nD = 0;

  for (int i = 0; i < nA; i++) {
    for (int j = 0; j < nB; j++) {
      if (A[i] == B[j] && verificaUnico(U, *nD, A[i])) {
        U[(*nD)++] = A[i];
      }
    }
  }

  int* D = iniciaVetor(*nD);

  for (int i = 0; i < *nD; i++) {
    D[i] = U[i];
  }

  liberaConjunto(U);

   ordena(D, *  nD);

  return D;
}

void imprimeConjunto(int* vet, int n_pos) {
  for (int i = 0; i < n_pos; i++) {
    printf("%d ", vet[i]);
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
