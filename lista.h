#ifndef LISTA_H
#define LISTA_H

struct lista {
    int id;
    char descricao[30];
    int tempo;
    char situacao[10];
    struct lista *next;
};

typedef struct lista Lista;

void initLista(Lista *l);
Lista* adicionar(Lista *l);
void vizualizar(Lista *l);
void concluir(Lista *l);


#endif
