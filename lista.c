#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

// Setar os ponteiros da lista pra NULL
void inicLista(struct lista *lista)
{
    lista->prim = lista->ult = NULL;
}

// Verificar se os ponteiros da lista apontam pra NULL
int listaVazia(struct lista *lista)
{
    return (!lista->prim && !lista->ult);
}

//Aloca a cidade e os elementos e insere nas duas listas de forma ordenada
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

void consultarNome(struct lista *lista, char *nome)
{
    struct no *aux = lista->prim;
    while (aux != NULL)
    {
        if (strcmp(nome, aux->p_cidade->nome) == 0)
        {
            printf("\nDados da cidade:\n\n\t%d %s\n", aux->p_cidade->codigo, aux->p_cidade->nome);
            return;
        }
        else
            aux = aux->prox;
    }
    printf("\nNome não encontrado\n\n");
}

void consultarCodigo(struct lista *lista, int codigo)
{
    struct no *aux = lista->prim;
    while (aux != NULL)
    {
        if (aux->p_cidade->codigo == codigo)
        {
            printf("\nDados da cidade:\n\n\t%d %s\n", aux->p_cidade->codigo, aux->p_cidade->nome);
            return;
        }
        else
            aux = aux->prox;
    }
    printf("\nCódigo não encontrado\n\n");
}

void exibir(struct lista *listaNome, struct lista *listaCodigo)
{
    int i = 1;
    struct no *aux = listaNome->prim;
    printf("\nLista ordenada por nome:\n\n");
    while (aux != NULL)
    {
        printf("\t%d %s\n", aux->p_cidade->codigo, aux->p_cidade->nome);
        aux = aux->prox;
        i++;
    }
    aux = listaCodigo->prim;
    i = 1;
    printf("\nLista ordenada por código:\n\n");
    while (aux != NULL)
    {
        printf("\t%d %s\n", aux->p_cidade->codigo, aux->p_cidade->nome);
        aux = aux->prox;
        i++;
    }
}