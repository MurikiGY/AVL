#ifndef _AVL_
#define _AVL_

/* Estrutura do no da arvore */
struct no {
    int         chave;      /* Chave do nodo                    */
    int         balanco;    /* diferenca entre nodo esq e dir   */
    struct no   *pai;       /* Ponteiro para o Pai              */
    struct no   *esq;       /* Ponteiro para o filho esquerdo   */
    struct no   *dir;       /* Ponteiro para o filho da direita */
};
typedef struct no no_t;

/* Cria nodo retornando ponteiro */
no_t *cria_no(int chave);

/* Insere nodo na folha arvore */
no_t *insere(no_t *no, int chave);

/* Retira nodo da arvore */
no_t *retira(no_t *no, int chave);

/* Operacao de rotacao a esquerda */
no_t *rot_esquerda(no_t *no);

/* Operacao de rotacao a direita */
no_t *rot_direita(no_t *no);

/* Imprime toda a arvore */
void imprime_arvore(no_t *no, int h);

/* Busca nodo dentro da arvore */
no_t *busca(no_t *no, int chave);

/* Retorna o menor valor da arvore */
no_t *min(no_t *no);

/* Retorna o maior valor entre dois numeros */
int max(int x, int y);

/* retorna o fator de balanceamento */
int fb(no_t *no);

#endif

