#include "arquivo.h"

void preencherListas(struct lista *listaNome, struct lista *listaCodigo, char *nome_arq)
{
    char nome[50];
    int codigo, r;
    FILE *fp = fopen(nome_arq, "r");
    if (!fp)
        printf("Erro ao abrir o arquivo\n");
    else
    {
        r = fscanf(fp, "%d; %s", &codigo, nome);
        while (r != EOF)
        {
            //printf(" %d;%s\n", codigo, nome);
            inserir(listaNome, listaCodigo, nome, codigo);
            r = fscanf(fp, "%d; %s", &codigo, nome);
        }
        fclose(fp);
    }
}

void gerarArquivos(struct lista *listaNome, struct lista *listaCodigo)
{
    FILE *fp;
    struct no *aux;
    fp = fopen("listaNome.txt", "w");
    printf("Gerando arquivos...\n");
    if (!fp)
    {
        printf("Erro ao gerar o arquivo listaNome.txt\n");
        return;
    }
    else
    {
        aux = listaNome->prim;
        fprintf(fp, "Lista Ordenada por Nome:\n\n");
        while (aux != NULL)
        {
            fprintf(fp, "\t%d; %s\n", aux->p_cidade->codigo, aux->p_cidade->nome);
            aux = aux->prox;
        }
        fclose(fp);
    }
    fp = fopen("listaCodigo.txt", "w");
    if (!fp)
    {
        printf("Erro ao gerar o arquivo listaCodigo.txt\n");
        return;
    }
    else
    {
        aux = listaCodigo->prim;
        fprintf(fp, "Lista Ordenada por Código:\n\n");
        while (aux != NULL)
        {
            fprintf(fp, "\t%d; %s\n", aux->p_cidade->codigo, aux->p_cidade->nome);
            aux = aux->prox;
        }
        fclose(fp);
    }
    printf("Arquivos gerados com sucesso.\n");
}