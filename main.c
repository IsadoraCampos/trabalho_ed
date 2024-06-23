#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    
    int opcao, id, tempo;
    Node* root = NULL;
    
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
           printf("Insira o tempo(em horas) para a realização da tarefa\n");
           scanf("%d", &tempo);
           printf("Insira a descrição\n");
           scanf("%d", &descricao);
           insertTree(root, criarNo(id, descricao, tempo, Ativo));
        }
        if (opcao == 2){
            vizualizar(l);
        }
        if (opcao == 5){
            break;
        }
    }
    
   return 0;    
}
