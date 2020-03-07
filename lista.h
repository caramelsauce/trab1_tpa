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

// Setar os ponteiros da lista pra NULL
void inicLista(struct lista *lista);

// Verificar se os ponteiros da lista apontam pra NULL
int listaVazia(struct lista *lista);

//Aloca a cidade e os elementos e insere nas duas listas de forma ordenada
void inserir(struct lista *listaNome, struct lista *listaCodigo, char *nome,
             int codigo);

// Insere na lista ordenando a lista por nome
void insereNome(struct lista *lista, struct no *elemento);

// Insere na lista ordenando a lista por código
void insereCodigo(struct lista *lista, struct no *elemento);

// Printa os elementos de 2 listas
void exibir(struct lista *listaNome, struct lista *listaCodigo);

//Procura um elemento na lista pelo nome printando os dados do elemento se achar ou uma mensagem de erro caso não encontrar
void consultarNome(struct lista *lista, char *nome);

//Procura um elemento na lista pelo código printando os dados do elemento se achar ou uma mensagem de erro caso não encontrar
void consultarCodigo(struct lista *lista, int codigo);

#endif
