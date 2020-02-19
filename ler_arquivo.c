#include "ler_arquivo.h"

void preencher_listas(struct lista *listaNome, struct lista *listaCodigo, char *nome_arq)
{
    char nome[50];
    int codigo, r;
    FILE *fp = fopen(nome_arq, "r");
    r = fscanf(fp, "%d; %s", &codigo, nome);
    while (r != EOF)
    {
        //printf(" %d;%s\n", codigo, nome);
        inserir(listaNome, listaCodigo, nome, codigo);
        r = fscanf(fp, "%d; %s", &codigo, nome);
    }
}