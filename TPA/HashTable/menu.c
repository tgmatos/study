#include "menu.h"

int menuFile()
{
    int op;

    do
    {
        printf("\n-----------------------------\n");
        printf("1 - Arquivo com mil alunos\n");
        printf("2 - Arquivo com cem mil alunos\n");
        
        printf("Opção: ");
        scanf("%d", &op);
    } while(op < 0 || op > 2);
    
    return op;
}

int opcao()
{
    int op;

    do
    {
        printf("\n-----------------------------\n");
        printf("0 - Sair\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Exibir\n");
        printf("4 - Pesquisar\n");
        printf("5 - Salvar\n");
        printf("\n-----------------------------\n");

        printf("Opção: ");
        scanf("%d", &op);
    } while(op < 0 || op > 5);

    return op;
}
