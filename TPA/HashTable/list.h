//#ifndef list_h
//#define list_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct tipoElemento
{
    int flag;
    long long matricula;
}TElemento;

//Inicializa o array com NULL
void inicializarArray(TElemento *array, long long tamanhoArray);

//Funções de controle de array
void inserir(TElemento *array, long long valor, long long tam);
void remover(TElemento *array, long long hashnum, long long valor, long long tam);
long long buscar(TElemento *array, long long hashnum, long long valor, long long tam);
void exibir(TElemento *array, long long tamanhoArray);

//Funções de lista
//void inserirNaLista(TElemento *atual, long long valor, char *nome);
//void exibirLista(TElemento *atual, int i);

