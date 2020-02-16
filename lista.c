#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

void inicLista(struct lista *lista)
{
    lista->prim = lista->ult = NULL;
}

int listaVazia(struct lista *lista)
{
    return (!lista->prim && !lista->ult);
}

void inserir(struct lista *listaNome, struct lista *listaCodigo, char *nome,
             int codigo)
{
    struct cidade *nova_cidade = malloc(sizeof(struct cidade));
    strcpy(nova_cidade->nome, nome);
    nova_cidade->codigo = codigo;
    struct no *elemento_nome = malloc(sizeof(struct no));
    struct no *elemento_codigo = malloc(sizeof(struct no));
    elemento_nome->p_cidade = nova_cidade;
    elemento_nome->prox = elemento_nome->ant = NULL;
    elemento_codigo->p_cidade = nova_cidade;
    elemento_codigo->prox = elemento_codigo->ant = NULL;
    insereNome(listaNome, elemento_nome);
    insereCodigo(listaCodigo, elemento_codigo);
}

void insereNome(struct lista *lista, struct no *elemento)
{
    if (listaVazia(lista))
        lista->prim = lista->ult = elemento;
    else
    {
        struct no *aux = lista->prim;
        while (aux != NULL && strcmp(elemento->p_cidade->nome, aux->p_cidade->nome) > 0)
        {
            aux = aux->prox;
        }
        if (aux == NULL)
        {
            lista->ult->prox = elemento;
            elemento->ant = lista->ult;
            lista->ult = elemento;
        }
        else if (aux->ant == NULL)
        {
            elemento->prox = aux;
            aux->ant = elemento;
            lista->prim = elemento;
        }
        else
        {
            aux->ant->prox = elemento;
            elemento->ant = aux->ant;
            aux->ant = elemento;
            elemento->prox = aux;
        }
    }
}

void insereCodigo(struct lista *lista, struct no *elemento)
{
    if (listaVazia(lista))
        lista->prim = lista->ult = elemento;
    else
    {
        struct no *aux = lista->prim;
        while (aux != NULL && elemento->p_cidade->codigo > aux->p_cidade->codigo)
        {
            aux = aux->prox;
        }
        if (aux == NULL)
        {
            lista->ult->prox = elemento;
            elemento->ant = lista->ult;
            lista->ult = elemento;
        }
        else if (aux->ant == NULL)
        {
            elemento->prox = aux;
            aux->ant = elemento;
            lista->prim = elemento;
        }
        else
        {
            aux->ant->prox = elemento;
            elemento->ant = aux->ant;
            aux->ant = elemento;
            elemento->prox = aux;
        }
    }
}

void exibir(struct lista *listaNome, struct lista *listaCodigo)
{
    int i = 1;
    struct no *aux = listaNome->prim;
    printf("\nLista ordenada por nome:\n");
    while (aux != NULL)
    {
        printf("%d %s %d\n", i, aux->p_cidade->nome, aux->p_cidade->codigo);
        aux = aux->prox;
        i++;
    }
    aux = listaCodigo->prim;
    i = 1;
    printf("\nLista ordenada por código:\n");
    while (aux != NULL)
    {
        printf("%d %s %d\n", i, aux->p_cidade->nome, aux->p_cidade->codigo);
        aux = aux->prox;
        i++;
    }
}