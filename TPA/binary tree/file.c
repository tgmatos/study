#include "file.h"

Node *readFile(FILE *file)
{
    long matricula;
    int cont = 0;
    Node *treeRoot = NULL;
    
    char buf[300], nomeAluno[101];
    

    //Pequena função para poder criar e inserir uma raíz na árvore.
    while(cont == 0)
    {
        fgets(buf, sizeof(buf), file);
        
        fscanf(file, "%lld", &matricula);
        fscanf(file, "%s", nomeAluno);

        treeRoot = createNode(matricula, nomeAluno);
        cont += 1;
    }

    //Leio o arquivo até o final dele
    while(!feof(file))
    {
        fscanf(file, "%lld\n", &matricula); //Guardo a matrícula em uma var
        fscanf(file, "%s", nomeAluno); //Guardo o nome em uma var


        //Crio um novo node com o nome e matricula
        Node *newNode = createNode(matricula, nomeAluno);

        //Insiro o node na árvore.
        insertNode(treeRoot, newNode);
    }

    return treeRoot;
}