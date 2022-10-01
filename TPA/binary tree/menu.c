#include "menu.h"

int menu()
{
    int op;

    do
    {
        printf("\n\n\n\n-----------------------------\n");
        printf("\n1 - INSERIR NOVO ALUNO");
        printf("\n2 - REMOVER ALUNO");
        printf("\n3 - BUSCAR ALUNO");
        printf("\n4 - IMPRIMIR PRÉ-ORDEM");
        printf("\n5 - IMPRIMIR EM ORDEM");
        printf("\n6 - IMPRIMIR PÓS ORDEM");
        printf("\n\n");
        printf("\n-----------------------------\n");

        printf("Opção: ");
        scanf("%d", &op);
    } while(op < 0 || op > 6);

    return op;
}

