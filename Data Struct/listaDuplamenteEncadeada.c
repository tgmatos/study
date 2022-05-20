#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "listaDuplamenteEncadeada.h"

TLista lista;

int main(){
	int op;
	
	inicializa(&lista);
	
	do {
		op = menu();
		
		switch(op){
		   case 1: insere(&lista); break;
		   case 2: mostraLista(&lista); break;
		   case 3: reordenarPorSexoENome(&lista); break;
		   case 4: remover(&lista); break;	
		}//switch
		
	} while(op != 0);
	
}

void clear()
{
    while( getchar() != '\n' );
}

void inicializa(TLista *L){
	L->inicio = NULL;
	L->fim = NULL;
	L->total = 0;
}

int menu(){
	int opcao;
	system("clear"); //Limpa a Tela e posiciona o 
	               //CURSOR no canto esquerdo superior da mesma
    printf("\n\n\n\t     =====| MENU |=====\n\n");
    printf("0 - SAIR (Encerrar Programa).\n\n");
    printf("1 - Inserir.\n");
    printf("2 - Exibir Lista Completa.\n");
    printf("3 - Ordenar por nome.\n");
    printf("4 - Excluir.\n\n");
    printf("\tInforme OPCAO desejada: ");
    
    scanf("%d",&opcao);
	
	if ((opcao > 4) || (opcao < 0)){
		printf("\n\n\n");
		printf("\t+-------------------------------------------------+");
		printf("\t|   ERRO:                                         |");
		printf("\t|                                                 |");
		printf("\t|   OPCAO INVALIDA!!!                             |");
		printf("\t|                                                 |");
		printf("\t|   Tente outra vez.                              |");
		printf("\t+-------------------------------------------------+\n\n");
		//system("PAUSE");
		clear();
		getchar();
	}
	return opcao;
}

void insere(TLista *L){
   	TNo *novo = (TNo *)malloc(sizeof(TNo));
   	int inserido = 0;
   
   	printf("\n\n\n");
   	printf("\t=====| INSERE NOVO NO |=====\n\n");
   	printf("\tInforme o nome: ");
   	scanf("%s", &novo->nome);
	*novo->nome = toupper(*novo->nome);

	printf("\n\n\n");
   	printf("\t=====| INSERE NOVO NO |=====\n\n");
	printf("\tInforme o sexo (M ou F): ");
   	scanf("%s", &novo->sexo);
	*novo->sexo = toupper(*novo->sexo);
//	toupper(novo->sexo);

	printf("\n\n\n");
   	printf("\t=====| INSERE NOVO NO |=====\n\n");
   	printf("\tInforme o número: ");
   	scanf("%d", &novo->valor);

   
   	novo->ante = NULL;
	novo->prox = NULL;
   
   	if(L->inicio == NULL){
   	  //Lista VAZIA: inserir o primeiro N?.
   	  	L->inicio = novo;
   	  	L->fim = novo;
   	} else {
   	  //Lista possui pelo menos um N?: Inserir dados em
   	  //ordem crescente.
		TNo *atual = L->inicio;
   	  	TNo *previo = NULL;
   	  
   	  while (atual != NULL){
   	  	if(atual->valor >= novo->valor){
			inserido = 1;
			novo->prox = atual;
			novo->ante = atual->ante;
			
			if(novo->ante == NULL){
				//Inserir novo no in?cio da Lista
				L->inicio = novo;
				atual->ante = novo;
			} else {
				//Inserir novo em algum ponto no meio da Lista
				previo = atual->ante;
				previo->prox = novo;
				
				atual->ante = novo;
			}//if else
			break;
		}//if
		
		atual = atual->prox; //movimenta ponteiro ATUAL para 
		                     //o N? SEGUINTE.
	  }//while
	  
	  if (!inserido){
	     //Inserir novo no final da Lista
		 L->fim->prox = novo;
		 novo->ante = L->fim;
		 L->fim = novo;	
	  }//if
	  
   }//if ... else
   
   L->total++;
}

void exibe(TNo *atual){
	printf("\n+----------------------------------||+----------------------------------+");
	if(atual->ante == NULL)
	{
		printf("\nAnterior: NULL, Valor: %d, Nome: %s, Sexo: %s, Próximo: %s", atual->valor, atual->nome, atual->sexo, atual->prox->nome);
	
	}

	else if(atual->prox == NULL)
	{
		printf("\nAnterior: %s, Valor: %d, Nome: %s, Sexo: %s, Próximo: NULL", atual->ante->nome, atual->valor, atual->nome, atual->sexo);
	}
	else
	{
		printf("\nAnterior: %s, Valor: %d, Nome: %s, Sexo: %s, Próximo: %s", atual->ante->nome, atual->valor, atual->nome, atual->sexo, atual->prox->nome);
	}
}

void mostraLista(TLista *L){
   TNo *atual = L->inicio;
   
   printf("\n\n\n");
   printf("\t=====| EXIBE LISTA COMPLETA |=====\n\n");
   
   while(atual != NULL){
   	   exibe(atual);
   	   atual = atual->prox;
   }//while
   printf("\n\nTotal de Nos: %d\n\n",L->total);
   //system("PAUSE");
   clear();
   getchar();
}

void mostraListaInversa(TLista *L){
   TNo *atual = L->fim;
   
   printf("\n\n\n");
   printf("\t=====| EXIBE LISTA INVERTIDA |=====\n\n");
   
   while(atual != NULL){
   	   exibe(atual);
   	   atual = atual->ante;
   }//while
   printf("\n\nTotal de Nos: %d\n\n",L->total);
   //system("PAUSE");
   clear();
   getchar();
}

void remover(TLista *L){
	TNo *atual = L->inicio, *previo = NULL, *proximo = NULL;
	int parametro;
	int removido = 0;
	
	printf("\n\n\t=====| REMOVER No |=====\n\n");
	printf("\tInforme VALOR a ser REMOVIDO: ");
	scanf("%d", &parametro);
	
	while(atual != NULL){
	   if(atual->valor == parametro)	{
	   	  proximo = atual->prox;
	   	  previo = atual->ante;
	   	  
	   	  if(previo == NULL) {
	   	  	  L->inicio = proximo;
	   	  	  if(proximo != NULL) proximo->ante = NULL; 
			  if(atual == L->fim)L->fim = NULL;  
		  } else {
		      previo->prox = proximo;
			  if(proximo != NULL) {
				 proximo->ante = previo;	
			  } else {
			  	 L->fim = previo;
			  }
		  }
		  
		  free(atual);
		  L->total--;
		  removido = 1;
		  break;
	   }//if
	   
	   atual = atual->prox;
	   
	}//while
	
	if(removido){
		printf("\n\n\n");
		printf("+--------------------------------------+\n");
		printf("|  AVISO:                              |\n");
		printf("|                                      |\n");
		printf("|  No REMOVIDO com SUCESSO !!!         |\n");
		printf("|                                      |\n");
		printf("+--------------------------------------+\n\n\n");
		//system("PAUSE");
		clear();
		getchar();
	} else {
		printf("\n\n\n");
		printf("+--------------------------------------+\n");
		printf("|  ALERTA:                             |\n");
		printf("|                                      |\n");
		printf("|  No NAO ENCONTRADO e nem REMOVIDO!!! |\n");
		printf("|                                      |\n");
		printf("+--------------------------------------+\n\n\n");
		//system("PAUSE");
		clear();
		getchar();
	}
}


void troca(TNo *atual, TNo *previo){

	TNo *aux = malloc(sizeof(TNo));

	strcpy(aux->nome, atual->nome);
	aux->valor = atual->valor;
	strcpy(aux->sexo, atual->sexo);
	
	strcpy(atual->nome, previo->nome);
	atual->valor = previo->valor;
	strcpy(atual->sexo, previo->sexo);
	
	strcpy(previo->nome, aux->nome);
	previo->valor = aux->valor;
	strcpy(previo->sexo, aux->sexo);

	free(aux);
}

void CompareAndSwitch(TLista *L)
{
	int i, holder;
	TNo *atual = L->inicio;

	for(i = 1; i < L->total; i++, atual = atual->prox)
	{
		holder = strcmp(atual->nome, atual->prox->nome);
		
		if(holder <= 1)
		{
			troca(atual->prox, atual);
		}
	}
}

void reordenarPorNome(TLista *L)
{
	int i;

	if(L->inicio == NULL || L->inicio->prox == NULL)
	{
		printf("Lista ordenada por nome!\n");
		return;
	}
	else
	{
		for(i = 0; i < L->total; i++)
		{
			CompareAndSwitch(L);
		}
	}
TLista lista;
	printf("Lista ordenada por nome!");

}

void CompareNameSexAndSwitch(TLista *L)
{
	int i, holder;
	TNo *atual = L->inicio;

	for(i = 1; i < L->total; i++, atual = atual->prox)
	{
		if(((strcmp(atual->sexo, "F") == 0) && (strcmp(atual->prox->sexo, "M") == 0)))
		{
			troca(atual->prox, atual);
		}
	}


	atual = L->inicio;
	for(i = 1; i < L->total; i++, atual = atual->prox)
	{
		holder = strcmp(atual->nome, atual->prox->nome);
		if((strcmp(atual->sexo, "F") == 0) && (strcmp(atual->prox->sexo, "F") == 0) && holder <= 1)
		{
			troca(atual->prox, atual);
		}
	}

	atual = L->inicio;
	for(i = 1; i < L->total; i++, atual = atual->prox)
	{
		holder = strcmp(atual->nome, atual->prox->nome);
		if((strcmp(atual->sexo, "M") == 0) && (strcmp(atual->prox->sexo, "M") == 0) && holder <= 1)
		{
			troca(atual->prox, atual);
		}
	}
}

void reordenarPorSexoENome(TLista *L)
{

	int i;
	int contFemale = 0;
	int contMale = 0;
	TNo *atual = L->inicio;

	if(L->inicio == NULL || L->inicio->prox == NULL)
	{
		printf("Lista ordenada por nome e sexo!");
		return;
	}
	else
	{
		for(i = 0; i < L->total; i++)
		{
			CompareNameSexAndSwitch(L);
		}
	}
}
