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
    // Aloca uma cidade para guardar o nome e o código

    struct cidade *nova_cidade = malloc(sizeof(struct cidade));

    // Copia os dados para a cidade

    strcpy(nova_cidade->nome, nome);
    nova_cidade->codigo = codigo;

    // Aloca 2 elementos sendo 1 para lista ordenada por nome e o outro para a lista ordenada por código

    struct no *elemento_nome = malloc(sizeof(struct no));
    struct no *elemento_codigo = malloc(sizeof(struct no));

    // Faz os elementos referenciarem a cidade alocada acima e seta os ponteiro prox e ant pra NULL

    elemento_nome->p_cidade = nova_cidade;
    elemento_nome->prox = elemento_nome->ant = NULL;

    elemento_codigo->p_cidade = nova_cidade;
    elemento_codigo->prox = elemento_codigo->ant = NULL;

    insereNome(listaNome, elemento_nome);       // Insere um elemento na lista ordenada por nome
    insereCodigo(listaCodigo, elemento_codigo); // Insere um elemento na lista ordenada por código
}

void insereNome(struct lista *lista, struct no *elemento)
{
    // Se a lista estiver vazia insere o elemento e faz os ponteiros prim e ult apontar para este elemento

    if (listaVazia(lista))
        lista->prim = lista->ult = elemento;

    else
    {
        struct no *aux = lista->prim;

        // Move o ponteiro aux até a posição que deve ser inserido o elemento

        while (aux != NULL && strcmp(elemento->p_cidade->nome, aux->p_cidade->nome) > 0)
        {
            aux = aux->prox;
        }

        // Testa se chegou no final para ser inserido como último elemento da lista

        if (aux == NULL)
        {
            lista->ult->prox = elemento;
            elemento->ant = lista->ult;
            lista->ult = elemento;
        }

        // Testa se será o primeiro da lista

        else if (aux->ant == NULL)
        {
            elemento->prox = aux;
            aux->ant = elemento;
            lista->prim = elemento;
        }

        // Inserção no meio da lista

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
    // Se a lista estiver vazia insere o elemento e faz os ponteiros prim e ult apontar para este elemento

    if (listaVazia(lista))
        lista->prim = lista->ult = elemento;

    else
    {
        struct no *aux = lista->prim;

        // Move o ponteiro aux até a posição que deve ser inserido o elemento

        while (aux != NULL && elemento->p_cidade->codigo > aux->p_cidade->codigo)
        {
            aux = aux->prox;
        }

        // Testa se chegou no final para ser inserido como último elemento da lista

        if (aux == NULL)
        {
            lista->ult->prox = elemento;
            elemento->ant = lista->ult;
            lista->ult = elemento;
        }

        // Testa se será o primeiro da lista

        else if (aux->ant == NULL)
        {
            elemento->prox = aux;
            aux->ant = elemento;
            lista->prim = elemento;
        }

        // Inserção no meio da lista

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
    struct no *aux = listaNome->prim;
    printf("\nLista ordenada por nome:\n\n");
    while (aux != NULL)
    {
        printf("\t%d %s\n", aux->p_cidade->codigo, aux->p_cidade->nome);
        aux = aux->prox;
    }
    aux = listaCodigo->prim;
    printf("\nLista ordenada por código:\n\n");
    while (aux != NULL)
    {
        printf("\t%d %s\n", aux->p_cidade->codigo, aux->p_cidade->nome);
        aux = aux->prox;
    }
}