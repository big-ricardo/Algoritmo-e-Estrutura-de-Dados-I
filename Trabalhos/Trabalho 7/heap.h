#define HEAP

// Struct para torre
typedef struct {
    int id;
    int hp;
} Torre;

//Struc for the heap
typedef struct Heap {
    int tamanho;
    int capacidade;
    Torre* vetor;
} Heap;

typedef Heap* p_heap;
typedef Torre* p_torre;

p_heap cria_fila_prio(int capacidade);
void insere(p_heap fila, int id, int hp);
Torre retorna_min(p_heap fila);
void destroi_heap(p_heap fila);
