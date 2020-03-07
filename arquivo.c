#include "arquivo.h"

void preencherListas(struct lista *listaNome, struct lista *listaCodigo, char *nome_arq)
{
    char nome[50];
    int codigo, r;                   // r recebe o retorno de fscanf e para o loop em EOF
    FILE *fp = fopen(nome_arq, "r"); // abre o arquivo

    // Caso não consiga abrir o arquivo termina a execução do programa

    if (!fp)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(EXIT_FAILURE);
    }

    else
    {
        r = fscanf(fp, "%d; %s", &codigo, nome);
        while (r != EOF)
        {
            inserir(listaNome, listaCodigo, nome, codigo);
            r = fscanf(fp, "%d; %s", &codigo, nome);
        }
        fclose(fp); // Fecha o arquivo depois de ler todos os dados
    }
}

void gerarArquivos(struct lista *listaNome, struct lista *listaCodigo)
{
    FILE *fp;
    struct no *aux;
    fp = fopen("listaNome.txt", "w"); // primeiro abre o arquivo para a lista ordenada por nome
    printf("Gerando arquivos...\n");

    // Termina a execução com falha caso não seja possível gerar o arquivo

    if (!fp)
    {
        printf("Erro ao gerar o arquivo listaNome.txt\n");
        exit(EXIT_FAILURE);
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

    fp = fopen("listaCodigo.txt", "w"); // Abre o arquivo da lista ordenada por código

    // Termina a execução com falha caso não seja possível gerar o arquivo

    if (!fp)
    {
        printf("Erro ao gerar o arquivo listaCodigo.txt\n");
        exit(EXIT_FAILURE);
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