#define	PILHA_H

typedef struct Pilha Pilha;
typedef struct No pilha_No;

typedef struct  pilha_No* p_pilha_no;
typedef struct  Pilha* p_pilha;

//CriaPilha (cria a estrutura pilha vazia)
p_pilha criaPilha();

//Push (inserir elemento na pilha)
void empilha(p_pilha p, void* elemento);

//Pop (remover elemento da pilha)
void* desempilha(p_pilha p);

//Esvazia (remove todos os elementos da pilha)
void liberaPilha(p_pilha p);

//pilhaVazia (verifica se a pilha está vazia)
int pilhaVazia(p_pilha p);

//tamanhoPilha (retorna o tamanho da pilha)
int tamanhoPilha(p_pilha p);
