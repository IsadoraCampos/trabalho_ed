#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int id;
    char descricao[30];
    int tempo;
    char situacao[10];
    struct node *left, *right;
};

typedef struct node Node;

Node* criarNo(int id, char* descricao, int tempo, char* situacao){  // função que cria o nó
    Node *newNode= (Node *)malloc(sizeof(Node));
    newNode->id = id;
    strcpy(newNode->descricao, descricao);
    newNode->tempo = tempo;
    strcpy(newNode->situacao, situacao);
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertTree(Node* node, Node* newNode){     // função para inserir na árvore
    if(node == NULL){
        return newNode;
    }
    if(newNode -> id < node -> id){
        node -> left = insertTree(node->left, newNode);
    }else{
        node -> right = insertTree(node->right, newNode);
    }
    return node;
}

Node* ordTempo(Node *node, Node* newNode){   // função que ordena pelo tempo para a visualização das tarefas
    if (node == NULL){
        return newNode;
    }
    if(newNode->tempo < node->tempo){
        node->left = ordTempo(node->left, newNode);
    } else{
        node->right = ordTempo(node->right, newNode);
    }
    return node;
}

void visualizar(Node *root, int n){
    if (root != NULL){                  // método de busca In-ordem
        visualizar(root->left,n);
        if (n == 1){
            if (strcmp(root->situacao, "Ativo") == 0){
                printf("Tempo: %dh | ID: %d | Descrição: %s | Situação: %s\n", root->tempo, root->id, root->descricao, root->situacao);
            }
        }
        if (n == 2){
            if (strcmp(root->situacao, "Concluída") == 0){
                printf("Tempo: %dh | ID: %d | Descrição: %s | Situação: %s\n", root->tempo, root->id, root->descricao, root->situacao);
            }
        }
        if (n == 3){
            printf("Tempo: %dh | ID: %d | Descrição: %s | Situação: %s\n", root->tempo, root->id, root->descricao, root->situacao);
        }

        visualizar(root->right,n);
    }
}

Node* concluir(Node *root, int n){
    
}
