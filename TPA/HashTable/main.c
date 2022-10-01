//Aluno: TIAGO MATOS CARVALHO REIS

/*
Tempo com mil linhas: 0.001114
Tempo com cem mil linhas: 0.022868
*/

#include "menu.h"
#include "arquivos.h"

#include <string.h>
#include <time.h>

int main()
{
    clock_t begin = clock();

    int op;

    long long matricula = 0, lines = 0, hash = 0, tamanhoArray = 0, search = 0;

    //char *filename = "randInt1K.txt";
    char *filename = "randInt100K.txt";

    //Abro o arquivo
    FILE *file = fopen(filename, "a+");

    //Verifico se o arquivo foi aberto corretamente.
    if(!file)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    //Função para contar a quantidade de linhas no arquivo.
    lines = countLines(file);
    printf("Lines: %lld\n", lines);

    //Calculo o tamanho do array e aloca memória para ele
    tamanhoArray = lines * 1.5;
    printf("TamanhoArray: %lld", tamanhoArray);
    TElemento *array = malloc(sizeof(TElemento) * tamanhoArray);
    
    //Inicializo o array, colocando o conteúdo dele como -1
    inicializarArray(array, tamanhoArray);

    //Lê o arquivo, pega os dados e os insere no array de TElemento.
    lerArquivo(file, array, tamanhoArray);

    //Fecha o arquivo.
    fclose(file);


    ///Começo do user-input
    do
    {
        op = opcao();

        switch(op)
        {
        case 1:
            printf("Matrícula a ser inserida: ");
            scanf("%lld", &matricula);

            inserir(array, matricula, tamanhoArray);
            break;

        case 2:
            printf("Matrícula a ser removida: ");
            scanf("%lld", &matricula);

            hash = hashFunction(matricula, tamanhoArray);
            remover(array, hash, matricula, tamanhoArray);
            break;

        case 3:
            exibir(array, lines);
            break;

        case 4:
            printf("Matrícula a ser procurada: ");
            scanf("%lld", &matricula);

            hash = hashFunction(matricula, tamanhoArray);
            search = buscar(array, hash, matricula, tamanhoArray);
            printf("array[%lld].matricula = %lld\n", search, array[search].matricula);
            break;

        case 5:
            gravarArquivo(array, filename, tamanhoArray);
            break;
        }
    } while(op != 0);

    free(array);

    begin = clock() - begin;
    double time_spent = ((double)begin) / CLOCKS_PER_SEC;

    printf("\n\nTime: %lf\n\n", time_spent);
    return 0;
}
