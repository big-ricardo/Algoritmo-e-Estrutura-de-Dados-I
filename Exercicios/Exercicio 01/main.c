#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;

/*
  Luis Ricardo Albano Santos - 2021031844
  gcc -pedantic-errors -Wall main.c -o main.exe && ./main.exe
*/

void debug(int n,char origem,char auxiliar, char destino){

  if(n == 0){
     printf("\n---------------------------\n");
    printf("return\n\n");
    return;
  }
  printf("\n---------------------------\n");
  printf("Pino: %d\n", n);
  printf("Origem: %c\n", origem);
  printf("Auxiliar: %c\n", auxiliar);
  printf("Destino: %c\n", destino);

}

void hanoi(int n,char origem,char auxiliar, char destino){
  debug(n, origem, auxiliar, destino);
  if(n==0) return;

	hanoi(n-1,origem, destino, auxiliar);
	
	printf("Mova o disco %d da base %c para a base %c\n",n,origem,destino);
	
	hanoi(n-1,auxiliar,destino,origem);
}

int main(){

	hanoi(2,'A','B','C');

	return 0;
}
