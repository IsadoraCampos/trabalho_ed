#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int id;
    char descricao[30];
    int tempo;
    char situacao[20];
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

int concluir(Node *root, int n){
    if (root == NULL){          // utilizando o método de busca pré-ordem
        return -1;
    }
    if (root->id == n){
      strcpy(root->situacao, "Concluída");     // se achou retorna 1
      return 1;
    } 
    
    int resul1 = concluir(root->left,n);    // se achou no lado esquerdo da árvore retorna 1
    if (resul1 == 1){                  
        return 1;
    }
    
    int resul2 = concluir(root->right,n);    // se achou no lado direito da árvore retorna 1
    if (resul2 == 1){
        return 1;
    }
    return -1;   // se não encontrou a tarefa
}

int atualizaRoot1(Node *root,Node *root1,int n){  // atualiza a segunda árvore para a visualização
    if (concluir(root,n) == 1){
      concluir(root1, n);
      return 1;
    }
    else{
        return -1;
    }
}




