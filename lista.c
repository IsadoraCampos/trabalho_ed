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
    Node newNode= (Node *)malloc(sizeof(Node));
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


void excluir(Lista **l)

void vizualizar(Lista *l){
    int op;
    Lista *aux;
    printf("===== Menu de Vizualização =====\n");
    printf("1- Ativas\n");
    printf("2- Concluídas\n");
    printf("3- Todas\n");
    scanf("%d", &op);
    if (op == 1){
        printf("Tarefas Ativas\n");
        for (aux=l;aux!=NULL;aux= aux->next){
            if (strcmp(aux->situacao, "Ativa") == 0){
                printf("ID: %d Descrição: %s Tempo: %dh Situação: %s \n", aux->id,aux->descricao,aux->tempo,aux->situacao);
            }
        }
    }
    if (op == 2){
        printf("Tarefas Concluídas\n");
        for (aux=l;aux!=NULL;aux=aux->next){
            if (strcmp(aux->situacao, "Concluída") == 0){
                printf("ID: %d Descrição: %s Tempo: %dh Situação: %s \n", aux->id,aux->descricao,aux->tempo,aux->situacao);
            }
        }
    }
    if (op == 3){
        printf("Tarefas\n");
        for (aux=l;aux!=NULL;aux= aux->next){
            printf("ID: %d Descrição: %s Tempo: %dh Situação: %s \n", aux->id,aux->descricao,aux->tempo,aux->situacao);
        }
    }
    if (op != 1 && op != 2 && op != 3){
        printf("Opção inválida. Tente novamente");
    }
}


