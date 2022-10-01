#include "tree.h"

// Função simples onde aloco memória para o novo node
// setto o nome e matricula com os valores
// e aponto os ponteiros como NULL.
Node *createNode(long valor, char *nome)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->elemento = valor;
    strcpy(newNode->nome, nome);
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->bef = NULL;

    return newNode;
}

void insertNode(Node *treeRoot, Node *newNode)
{

    // Percorro toda a árvore para achar qual será o node pai
    Node *nodeHolder = runNodes(treeRoot, newNode);

    // Verifico se é para inserir no lado esquerdo ou direito
    if(newNode->elemento >= nodeHolder->elemento)
    {
        nodeHolder->right = newNode;
        newNode->bef = nodeHolder;
    }

    else
    {
        nodeHolder->left = newNode;
        newNode->bef = nodeHolder;
    }
}

Node *runNodes(Node *treeRoot, Node *newNode)
{
    // Se o node direito for diferente de NULL e ele for maior, farei uma chamada
    // recursiva
    if((treeRoot->right != NULL) && (newNode->elemento >= treeRoot->elemento))
    {
        treeRoot = runNodes(treeRoot->right, newNode);
    }

    // Se o node esquerdo for diferente de NULL e ele for maior, farei uma chamada
    // recursiva
    else if((treeRoot->left != NULL) && (newNode->elemento < treeRoot->elemento))
    {
        treeRoot = runNodes(treeRoot->left, newNode);
    }

    // Quando chegar aqui, terei encontrado o local onde deverei inserir
    return treeRoot;

}

Node *searchNode(Node *treeRoot, long matricula)
{
    // Se a matrícula for igual à Node->elemento, retornarei o Node
    if(treeRoot->elemento == matricula)
    {
        return treeRoot;
    }

    // Se for maior, seguirei pelo branch direito
    else if(matricula > treeRoot->elemento)
    {
        searchNode(treeRoot->right, matricula);
    }

    // Se for menor, seguirei pelo branch esquerdo
    else if(matricula < treeRoot->elemento)
    {
        searchNode(treeRoot->left, matricula);
    }
}

void printPreOrdem(Node *treeRoot)
{
    // Primeiro printarei o node atual
    printf("\n%s: %lli", treeRoot->nome, treeRoot->elemento);

    // Se o node esquerdo for diferente de NULL, entrarei nele.
    if(treeRoot->left != NULL)
    {
        printPreOrdem(treeRoot->left);
    }

    // Se o node direito for diferente de NULL, entrarei nele
    if(treeRoot->right != NULL)
    {
        printPreOrdem(treeRoot->right);
    }
}

void printEmOrdem(Node *treeRoot)
{

    // Se o node for NULL, retornarei
    if(treeRoot == NULL)
    {
        return;
    }

    // Recursividade, andando pelo branch esquerdo
    printEmOrdem(treeRoot->left);

    // Dou print no elemento
    printf("\n%s: %lli", treeRoot->nome, treeRoot->elemento);

    // Recursividade, ando pelo branch direito
    printEmOrdem(treeRoot->right);
}

void printPosOrdem(Node *treeRoot)
{

    // Se for NULL, retornarei
    if(treeRoot == NULL)
    {
        return;
    }

    // Recursivdade, seguirei pelo lado esquerdo
    printPosOrdem(treeRoot->left);

    // Recursividade, seguirei pelo lado direito
    printPosOrdem(treeRoot->right);

    // Printo o node atual
    printf("\n%s: %lli", treeRoot->nome, treeRoot->elemento);
}

Node *deleteNode(Node *treeRoot, long valor) {
        
        // Primeiro será realizada uma busca, para encontrar o ponteiro para o node a ser removido
        if (treeRoot== NULL) {
                return NULL;
                // fim das chamada recursiva
        } else if (treeRoot->elemento > valor) {
                // Desce pela arvore à esquerda
                treeRoot->left = deleteNode(treeRoot->left, valor);
        } else if (treeRoot->elemento < valor) {
                // Desce pela arvore à direita
                treeRoot->right = deleteNode(treeRoot->right, valor);
                
        } else {
                
                // Apóss a busca -> Encontrou node a ser removido

                // Node a ser removido nao tem filhos 
                if (treeRoot->right == NULL && treeRoot->left== NULL) {
                        free(treeRoot);
                        
                // Node a ser removido tem filhos apenas pela direita
                } else if (treeRoot->left == NULL) {
                        Node *temp = treeRoot;
                        treeRoot = treeRoot->right;
                        free(temp);
                
                // Node a ser removido tem filhos apenas pela esquerda
                } else if (treeRoot->right == NULL) {
                        Node *temp = treeRoot;
                        treeRoot = treeRoot->left;
                        free(temp);
                
                // Node a ser removido tem dois filhos.
                } else {
                        Node *provisorio = treeRoot->left;   // Declaro um ponteiro provisorio que aponta para o filho a Esquerda do Node.
                        
                        while (provisorio->right != NULL) {       // Enquanto o proximo valor existir, provisório irá apontar para o valor do Node mais profundo à direita
                                provisorio = provisorio->right;
                        }
                        
                        // Trocando os dados entre os nodes, entre o provisorio (valor mais profundo é direita do Node esquerdo) e o node a ser excluido
                        treeRoot->elemento = provisorio->elemento;
                        strcpy(treeRoot->nome, provisorio->nome);
                
                        treeRoot->left = deleteNode(treeRoot->left, valor);
                }
        }
        
        return treeRoot;

}