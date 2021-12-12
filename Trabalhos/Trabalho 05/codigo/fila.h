#define	FILA_H

typedef struct Fila Fila;

typedef struct  Fila* p_fila;


//CriaFila (cria a estrutura fila vazia)
p_fila criaFila();

//Enfileira (insere um elemento na fila)
void enfileira(p_fila, void*);

//desenfileira (remove um elemento da fila)
void* desenfileira(p_fila);

//LiberaFila (libera a memória alocada para a fila)
void liberaFila(p_fila);

//FilaVazia (verifica se a fila está vazia)
int filaVazia(p_fila);
