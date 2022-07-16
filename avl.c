#include <stdio.h>
#include <stdlib.h>

#include "avl.h"


/* OK */
/* Cria no retornando ponteiro */
no_t *cria_no(int chave){
    no_t *no;

    /* Alocacao dinamica */
    if (!(no = malloc(sizeof(no_t)))){
        fprintf(stderr, "Falha na criacao do nodo\n");
        return NULL;
    }

    /* configura nodo */
    no->chave = chave;
    no->balanco = 0;
    no->esq = NULL;
    no->dir = NULL;
    no->pai = NULL;

    return no;
}

/* Testa o balanceamento dos filhos */
int testa_bal (no_t *no){
    int bal_esq;
    int bal_dir;

    /* Guarda o balanco dos filhos */
    bal_esq = fb(no->esq);
    bal_dir = fb(no->dir);

    /*  Testa o balanceamento */
    return bal_esq - bal_dir;
}


/* Arrumar balanceamento */
/* Inclui nodo na folha arvore */
no_t *insere(no_t *no, int chave){
    int bal_test;
    int bal_filho;

    /* Caso base */
    if (!no)
        return cria_no(chave);

    /* Testa inclusao na esq ou dir */
    if (chave < no->chave){
        no->esq = insere(no->esq, chave);
        no->esq->pai = no;
        no->balanco = 1 + no->esq->balanco;
    } else if (chave >= no->chave){
        no->dir = insere(no->dir, chave);
        no->dir->pai = no;
        no->balanco = 1 + no->dir->balanco;
    }


    /*  Testa o balanceamento */
    bal_test = testa_bal(no);

    /* no esquerdo mais pesado */
    if (bal_test > 1){

        bal_filho = testa_bal(no->esq);
        if (bal_filho > 0)
            return rot_direita(no); //zig zig
        else{
            no->esq = rot_esquerda(no->esq); //zig zag
            return rot_direita(no);
        }
    }

    /* no direito mais pesado */
    if (bal_test < -1){

        bal_filho = testa_bal(no->dir);
        if (bal_filho < 0)
            return rot_esquerda(no); //zig zig
        else{
            no->esq = rot_direita(no->esq); //zig zag
            return rot_esquerda(no);
        }
    }

    return no;
}

/* Arrumar balanceamento */
/* Remove nodo da arvore */
no_t *retira(no_t *no, int chave){
    no_t *q;

    /* Base */
    if (!no)
        return no;

    /* Procura o nodo */
    if (chave == no->chave){

        /* testa caso dois filhos */
        if (no->esq && no->dir){

            /* Ajusta chave para o sucessor */
            q = min(no->dir);
            no->chave = q->chave;
            q->pai->esq = NULL;
            free(q);
        } else {

            /* testa caso folha */
            if (!(no->esq || no->dir)){
                free(no);
            }

                /* Testa se tem um filho */

    }
    }



}


/* Operacao de rotacao a esquerda */
no_t *rot_esquerda(no_t *no){
    no_t *q = no->dir;   /* Ponteiro do no que "sobe" */

    (*no).dir = q->esq;
    q->pai = no->pai;
    (*no).pai = q;

    if (q->esq != NULL)
        q->esq->pai = no;
    q->esq = no;

    /* Ajusta ponteiro do pai de no */
    if (q->pai != NULL){
        if (q->pai->esq == no)
            q->pai->esq = q;
        else
            if (q->pai->dir == no)
                q->pai->dir = q;
    }

    /* Ajusta balanco */
    (*no).balanco = q->balanco - 1;

    /* Retorna o nodo que subiu para a raiz */
    return q;
}
/* Operacao de rotacao a direita */
no_t *rot_direita(no_t *no){
    no_t *q = no->esq;    /* Ponteiro do no que sobe */

    (*no).esq = q->dir;
    q->pai = no->pai;
    (*no).pai = q;

    if (q->dir != NULL)
        q->dir->pai = no;
    q->dir = no;

    /* Ajusta ponteiro do pai de no */
    if (q->pai != NULL){
        if (q->pai->dir == no)
            q->pai->dir = q;
        else
            if (q->pai->dir == no)
            q->pai->dir = q;
    }

    /* Ajusta balanco */
    (*no).balanco = q->balanco - 1;

    /* Retorna o no que subiu para a raiz */
    return q;
}

/* Imprime toda a arvore em ordem */
void imprime_arvore(no_t *no, int h){

    /* Testa se chegou na folha */
    if (no == NULL)
        return;

    imprime_arvore(no->esq, h+1);
    printf("%d, %d\n", no->chave, h);
    imprime_arvore(no->dir, h+1);
}

/* OK */
/* Busca nodo dentro da arvore */
no_t *busca(no_t *no, int chave){

    /* Chave não encontrada */
    if (no == NULL)
        return NULL;

    /* Encontrou a chave */
    if (no->chave == chave)
        return no;

    /* Procura a chave recursivo */
    if (chave < no->chave)
        return busca(no->esq, chave);
    else
        return busca(no->dir, chave);
}

/* Retorna o no do menor valor da arvore */
no_t *min(no_t *no){

    /* Se nao ha mais nodos a esquerda,
     * retorna o nodo */
    if (no->esq == NULL)
        return no;
    else
        return min(no->esq);
}

/* Retorna o maior valor entre dois numeros */
int max(int x, int y){
    if (x > y)
        return x;
    return y;
}

/* retorna o fator de balanceamento */
int fb(no_t *no){

    if (!no)
        return -1;
    return no->balanco;
}


