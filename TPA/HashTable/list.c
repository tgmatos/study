#include "list.h"
#include "hashFunction.h"


//Inicializo o array com todos os valores de "matriculas" settados para -1
//e os valores de "flag" como 0.
void inicializarArray(TElemento *array, long long tamanhoArray)
{
    for(long long i = 0; i < tamanhoArray; i++)
    {
        array[i].matricula = -1;
        array[i].flag = 0;
    }
}


void inserir(TElemento *array, long long valor, long long tam)
{
    long long hash, hash2, hash3;

    //Calculo o valor da hash
    hash = hashFunction(valor, tam);
    
    //Insire a matrícula no endereço da hash
    if(array[hash].matricula != -1)
    {
        array[hash].flag = 1;
        array[hash].matricula = valor;
    }
    
    //Caso o valor de array[hash].matricula for diferente de -1, o programa entrará
    //neste else
    else
    {
        //Calcula o valor usando a segunda função hash
        hash2 = secondHashFunction(valor, tam);
        
        //Insire a matrícula no array[hash2].matricula
        if(array[hash2].matricula != -1)
        {
            array[hash2].flag = 1;
            array[hash2].matricula = valor;
        }

        //Caso o valor de array[hash2].matricula for diferente de -1, o programa entrará
        //neste else
        else
        {
            //Como já teve 3 iterações de hash, a variável 'i' será inicializada
            //com o valor 3.
            long i = 3;
            do
            {
                //Calculo a terceira função hash
                hash3 = thirdHashFunction(tam, i, hash2);

                // Se o array[hash3].matricula for diferente de 1, ele adicionará
                // +1 à variável 'i', e recalculará o valor da terceira hash
                // até encontrar uma posição disponível
                if(array[hash3].matricula != -1)
                {
                    i++;
                }
            }while(array[hash3].matricula != -1);

            //Insiro na posição
            array[hash3].matricula = valor;
            array[hash3].flag = 1;
        }
    }
}


void remover(TElemento *array, long long hashnum, long long valor, long long tam)
{
    long long hash = buscar(array, hashnum, valor, tam);

    array[hash].matricula = -1;
    array[hash].flag = 0;
}


//Uso basicamente a mesma estrutura da função inserir.
long long buscar(TElemento *array, long long hashnum, long long valor, long long tam)
{
    long long i = 3;
    long long hash = 0, hash3 = 0;

    if(array[hashnum].matricula == valor)
    {
        return hashnum;
    }

    else
    {
        hash = secondHashFunction(valor, tam);

        if(array[hash].matricula == valor)
        {
            return hash;
        }

        else
        {
            hash3 = hash;

            while(array[hash3].matricula != valor)
            {
                //hash = hash3;
                hash3 = thirdHashFunction(tam, i, hash);
                i += 1;

                if(i == tam)
                {
                    return -1;
                }
            }

            return hash3;
        }
    }

    return 0;
}

//Função para exibir o array
//Caso a posição seja "vazia", ele não irá exibir
void exibir(TElemento *array, long long tamanhoArray)
{    
    for(long long i = 0; i < tamanhoArray; i++)
    {
        if(array[i].matricula != -1)
        {
            printf("Matrícula[%lld]: %lld\n", i, array[i].matricula);
        }
    }
}