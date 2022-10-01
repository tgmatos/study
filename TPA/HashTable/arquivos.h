#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hashFunction.h"
#include "list.h"

long long countLines(FILE *file);
void lerArquivo(FILE *file, TElemento *array, long long tamanho);
void gravarArquivo(TElemento *array, const char *filename, long long tamanhoArray);