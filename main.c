#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main(){
    
    int opcao, id, tempo, op1, op2;
    char descricao[30];
    Node  *root = NULL;
    Node *root1 = NULL;
    
    while (1){
        printf("\n----- Menu de Opções -----\n");
        printf(" 1 - Adicionar tarefa\n");
        printf(" 2 - Visualizar tarefas\n");
        printf(" 3 - Concluir tarefa\n");
        printf(" 4 - Excluir tarefa\n");
        printf(" 5 - Sair\n");
        printf("Digite a sua opção: \n");
        scanf("%d", &opcao);
        if (opcao == 1){
           printf("Insira o ID da tarefa: \n");
           scanf("%d", &id);
           getchar();
           printf("Insira a descrição: \n");
           fgets(descricao, sizeof(descricao), stdin);
           descricao[strcspn(descricao, "\n")] = '\0';
           printf("Insira o tempo(em horas) para a realização da tarefa: \n");
           scanf("%d", &tempo);
           root = insertTree(root, criarNo(id, descricao, tempo, "Ativo"));
           root1 = ordTempo(root1, criarNo(id, descricao, tempo, "Ativo"));
        }
        if (opcao == 2){
            printf("=== Menu de Visualização ===\n");
            printf("1 - Ativas\n"); printf("2 - Concluídas\n"); printf("3 - Todas\n");
            scanf("%d", &op1);
            if (op1 != 1 && op1 != 2 && op1 != 3){
                printf("Erro ao digitar. Tente novamente.\n");
            }
            visualizar(root1, op1);
        }
        if (opcao == 3){
            printf("Digite o ID da tarefa que deseja concluir: \n");
            scanf("%d", &op2);
            root = concluir(root,op2);
            
        }
        if (opcao == 5){
            break;
        }
    }
    
   return 0;    
}
