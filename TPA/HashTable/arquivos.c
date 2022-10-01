//Libs do programa
#include "arquivos.h"


//Função básica para contar linhas do arquivo
long long countLines(FILE *file)
{
    char buf[200];

    long long lines = 0;

    while(fgets(buf, sizeof(buf), file) != NULL)
    {
        lines += 1;
    }
    
    rewind(file);

    return lines;
}

void lerArquivo(FILE *file, TElemento *array, long long tam)
{
    long long valor = 0, hash = 0, cont = 0;
    
    char buf[200];

    //Percorre todo o arquivo, até o final dele.
    while(fgets(buf, sizeof(buf), file) != NULL)
    {
        //Coloca os dados do arquivo em variáveis
        fscanf(file, "%lld", &valor);

        //Insere no array
        inserir(array, valor, tam);
        
        cont += 1;
    }
}


//Função para salvar o arquivo
void gravarArquivo(TElemento *array, const char *filename, long long tamanhoArray)
{
    //Abro o arquivo no modo "write", para propositalmente apagar todo o conteúdo
    //do arquivo e assim reescrevê-lo
    FILE *file = fopen(filename, "w+");

    for(long long i = 0; i < tamanhoArray; i++)
    {
        //Condição para caso a posição do array esteja "vazia", ele não gravará
        //no arquivo
        if(array[i].matricula != -1)
        {
            fprintf(file, "%lld\n", array[i].matricula);
        }
    }
    fclose(file);
}