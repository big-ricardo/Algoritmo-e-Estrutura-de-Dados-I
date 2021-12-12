#define HEAP

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

// Cria um heap(int capacidade)
p_fp criar_fila_prio(int capacidade);

// Insere um elemento no heap(p_fp heap, p_torre elemento)
void insere(p_fp fila, int id, int hp);
// Remove um elemento do heap(p_fp heap)
torre extrai_minimo(p_fp fila);

// Destroi o heap(p_fp heap)
void destroi_heap(p_fp fila);

// Retorna o tamanho do heap(p_fp heap)
int tamanho_fila(p_fp fila);