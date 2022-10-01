// ALUNO: TIAGO MATOS CARVALHO REIS


#include "tree.h"
#include "file.h"
#include "menu.h"

int main()
{

    int op;
    long matricula;

    char nome[200];

    char *filename = "Lista_Aluno_Matricula_Atual.txt";
    FILE *file = fopen(filename, "rt");

    if(!file)
    {
        perror("Erro ao abrir o arquivo!");
        return -1;
    }

    Node *treeRoot = readFile(file);
    fclose(file);

    do
    {
        op = menu();

        switch (op)
        {
        case 1:
            printf("\nNome aluno: ");
            scanf("%s", nome);
            
            printf("\nMatrícula: ");
            scanf("%lld", &matricula);

            insertNode(treeRoot, createNode(matricula, nome));
            break;
        
        case 2:
            printf("\nMatricula: ");
            scanf("%lld", &matricula);

            deleteNode(treeRoot, matricula);
            break;
        
        case 3:
            printf("\nMatricula a ser buscada: ");
            scanf("%lld", matricula);
            searchNode(treeRoot, matricula);
            break;

        case 4:
            printf("\n\n\n");
            printPreOrdem(treeRoot);
            break;
        
        case 5:
            printf("\n\n\n");
            printEmOrdem(treeRoot);
            break;

        case 6:
            printf("\n\n\n");
            printPosOrdem(treeRoot);
            break;
        }
    } while (op != 0);
    
    

}