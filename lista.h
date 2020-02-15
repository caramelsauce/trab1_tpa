#ifndef LISTA_H
#define LISTA_H

struct cidade
{
    char nome[50];
    int codigo;
};

struct no
{
    struct cidade *p_cidade;
    struct no *ant, *prox;
};

struct lista
{
    struct no *prim, *ult;
};

void inicLista(struct lista *lista);

void inserir(struct lista *listaNome, struct lista *listaCodigo, char *nome,
             int codigo);

void insereNome(struct lista *lista, struct no *elemento);

void insereCodigo(struct lista *lista, struct no *elemento);

void excluir(struct lista *listaNome, struct lista *listaCodigo, char *nome,
             int codigo);

void exibir(struct lista *listaNome, struct lista *listaCodigo);

int listaVazia(struct lista *lista);

void consultarNome(struct lista *lista, char *nome);

void consultarCodigo(struct lista *lista, int codigo);

#endif
