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
    struct no *elemento = malloc(sizeof(struct no));
    elemento->p_cidade = nova_cidade;
    elemento->prox = elemento->ant = NULL;
    //insereNome(listaNome, elemento);
    insereCodigo(listaCodigo, elemento);
}

void insereCodigo(struct lista *lista, struct no *elemento)
{
    if (listaVazia(lista) || lista->prim->p_cidade->codigo >= elemento->p_cidade->codigo)
    {
        elemento->prox = lista->prim;
        lista->prim = elemento;
    }
    else
    {
        struct no *aux = lista->prim;
        while (aux->prox != NULL && aux->prox->p_cidade->codigo < elemento->p_cidade->codigo)
        {
            aux = aux->prox;
        }
        elemento->prox = aux->prox;
        elemento->ant = aux;
        aux->prox = elemento;
    }
}

void exibir(struct lista *listaNome, struct lista *listaCodigo)
{
    int i = 1;
    struct no *aux = listaCodigo->prim;
    while (aux != NULL)
    {
        printf("%d %s %d\n", i, aux->p_cidade->nome, aux->p_cidade->codigo);
        aux = aux->prox;
        i++;
    }
}