#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista{
    int id;
    char descricao[30];
    int tempo;
    char situacao[10];
    struct lista *next;
};

typedef struct lista Lista;

void initLista(Lista *l){
    l = NULL;
}

Lista* adicionar(Lista *l){
    Lista *aux, *f;
    f = (Lista *)malloc(sizeof(Lista));
    printf("Insira o ID da tarefa: \n");
    scanf("%d", &f->id);
    getchar();
    printf("Insira a descrição da tarefa: \n");
    fgets(f->descricao, sizeof(f->descricao), stdin);
    f->descricao[strcspn(f->descricao, "\n")] = '\0';
    printf("Insira o tempo(em horas) para a realização da tarefa\n");
    scanf("%d", &f->tempo);
    strcpy(f->situacao, "Ativa");
    printf("Situação: Ativa\n");
    f->next = NULL;
    if (l == NULL){
        l = f; return l;
    } 
    for (aux=l;aux->next!=NULL;aux=aux->next);
    aux->next = f;
    return l;
}

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


