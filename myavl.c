#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "avl.h"
#include "aux.h"

int main(){
    no_t    *root = NULL;       /* Ponteiro da raiz da arvore       */
    int     valor;              /* Valor a ser inserido ou removido */
    char    oper[5];               /* tipo de operação a ser feita     */
    char    linha[10];

    fgets(linha, 10, stdin);

    while(linha[0] != '\n'){

        strncpy(oper, strtok(linha, " "), 2);
        valor = atoi(strtok(NULL, " "));

        if (!strcmp(oper, "i")){
            root = insere(root, valor);

        } else if (!strcmp(oper, "r")){
           root = (retira(root, valor));

        } else
            fprintf(stderr, "Operação invalida\n");

        linha[0] = '\n';
        fgets(linha, 10, stdin);
    }

    imprime_arvore(root, 0);

    return 0;
}
