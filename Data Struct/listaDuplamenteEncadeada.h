typedef struct tipoNo
{
	int valor;
	char nome[20];
	char sexo[1];
	struct tipoNo *ante, *prox;
}TNo;

typedef struct tipoLista
{
	int total;
	struct tipoNo *inicio;
	struct tipoNo *fim;
}TLista;

TLista lista;

void inicializa(TLista *L);
int menu();
void insere(TLista *L);
void exibe(TNo *atual);
void mostraLista(TLista *L);
void mostraListaInversa(TLista *L);
void remover(TLista *L);
void clear();
void reordenarPorNome(TLista *L);
void reordenarPorSexoENome(TLista *L);