#define	FILA_H

typedef struct Fila Fila;
typedef struct fila_No fila_No;

typedef struct  fila_No* p_fila_no;
typedef struct  Fila* p_fila;

p_fila criaFila();

//CriaFila (cria a estrutura fila vazia)
void infileira(p_fila, void*);

//Enfileira (insere um elemento na fila)
void enfileira(p_fila, void*);

//desenfileira (remove um elemento da fila)
void* desenfileira(p_fila);

//LiberaFila (libera a memória alocada para a fila)
void liberaFila(p_fila);

int filaVazia(p_fila);
