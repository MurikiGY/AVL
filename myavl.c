#include <stdio.h>

#include "avl.h"

#define TAM 8

int main(){
    no_t    *root = NULL;       /* Ponteiro da raiz da arvore       */
    int     tam = 0;            /* Tamanho da arvore                */
    int     valor;              /* Valor a ser inserido ou removido */
    char    oper;               /* tipo de operação a ser feita     */


    printf("Entre com valores para inserir na AVL\n");

    while(tam != TAM){
        fscanf(stdin, "%c", &oper);
        fscanf(stdin, "%d", &valor);

        if (oper == 'i'){
            root = insere(root, valor);
            tam++;
            imprime_arvore(root, 0);
            printf("\n");
        }
//        else {
//           if (oper == 'r'){
//                root = (retira(root, valor));
//                tam--;
//           } else
//                fprintf(stdout, "Operação invalida\n");
//        }
    }

    imprime_arvore(root, 0);

    return 0;
}
