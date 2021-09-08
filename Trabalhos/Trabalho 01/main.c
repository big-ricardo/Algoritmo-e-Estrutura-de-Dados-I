#include <stdio.h>

/*
  Luis Ricardo Albano Santos - 2021031844
  gcc -pedantic-errors -Wall main.c -o main.exe && ./main.exe 
*/

//VocÃª deverÃ¡ modificar apenas a funÃ§Ã£o abaixo, vocÃª 
//nÃ£o pode modificar a assinatura dela


/*
  Função resposavel por receber de fato a string e realizar a concatenação 
  juntamente com as analizes de somatoria, onde retorna a soma de espaços da 
  string 
*/
int analizaString(char* sin, char* sres, int* tam){
  //Iniciando a variavel local espacos com 0
  int espacos = 0;

  //loop que irá rodar do tamanho da string
  for(int i = 0; sin[i] != '\0'; i++){

    //teste logico para verificar se o caracter é um caracter valido

    //caso for quebra de linha apenas pula para o proximo ciclo do loop
    if(sin[i] == '\n') continue;
    
     //caso for espaço,somo 1 na variavel espacos
    if(sin[i] == ' ') espacos++;
     
    //atribuo o caracter na variavel da concatenação, na posição adequada
    sres[*tam] = sin[i];
    //somo 1 no tamanho total da string
    *tam = *tam + 1;
  }

  // retorno o tamanho de espaços da string adiconada
  return espacos;

}

/*
  Função responsavel por receber as variaveis e retornar a string cocatenada
  com seus com a contagem de seus respectivos espaços e caracteres 
*/
int concatena(char* s1, char* s2, char* sres, int* espacos){

  // variavel resposavel pela somatoria dos caracteres inciando em 0
  int tamTotal = 0; 

  /*
    Chamando a função para executar a concatenação da string e as somatorias
    e atribuindo seu retorno a variavel espaços
  */
  *espacos = analizaString(s1, sres, &tamTotal);

  /*
    Adicionando um espaço entre as string que serão concatenadas e somo 1 no 
    tamanho da string
  */
  sres[tamTotal++] = ' ';
  //somando mais um espaço
  *espacos = *espacos + 1;

  /*
    Chamando a função para executar a concatenação da string e as somatorias
    e atribuindo o valor da variavel espacos mais o seu retorno
  */
  *espacos += analizaString(s2, sres, &tamTotal);

  //Adicionando o caracter nulo no final da string
  sres[tamTotal] = '\0';
  
  //retornando o resultado da somatoria de caracteres validos da string
  return tamTotal;

}

//Funcao para imprimir uma string, NÃ‚O MODIFIQUE
void print_string(char* str){
  int k = 0;
  while(str[k] != '\0'){
    printf("%c", str[k]);
    k++;
  }
  printf("\n");
}

//NÃ‚O MODIFIQUE a main
int main(int argc, char * argv[]){
  char frase1[40];
  char frase2[40];
  char fraseResultado[80];
  int tamResultado;
  int espacos;
  
  //lendo a entrada
  fgets(frase1, 40, stdin);
  fgets(frase2, 40, stdin);
  
  tamResultado = concatena(frase1, frase2, fraseResultado, &espacos);
  
  print_string(fraseResultado);
  printf("String com %d caracteres e %d espacos.\n", tamResultado, espacos);
  
  return 0;
}
