#ifndef TREE_H_
#define TREE_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node
{
    long elemento;
    char nome[300];
    struct Node *left;
    struct Node *right;
    struct Node *bef;
}Node;



Node *createNode(long valor, char *nome);
void insertNode(Node *treeRoot, Node *newNode);
Node *runNodes(Node *treeRoot, Node *newNode);
Node *searchNode(Node *treeRoot, long Matricula);
void printPreOrdem(Node *treeRoot);
void printEmOrdem(Node *treeRoot);
void printPosOrdem(Node *treeRoot);
Node *deleteNode(Node *treeRoot, long valor);

#endif