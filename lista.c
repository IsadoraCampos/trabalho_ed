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

Node* criarNo(int id, char* descricao, int tempo, char* situacao){
    Node *newNode= (Node *)malloc(sizeof(Node));
    newNode->id = id;
    strcpy(newNode->descricao, descricao);
    newNode->tempo = tempo;
    strcpy(newNode->situacao, situacao);
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertTree(Node* node, Node* newNode){
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

void visualizar(Node *root){
    
}

