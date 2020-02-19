#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "arquivo.h"

void menu()
{
    printf("\n\n");
    printf("1 - Efetuar busca por nome\n");
    printf("2 - Efetuar busca por código\n");
    printf("3 - Sair\n");
    printf("Opção: ");
}

int main(int argc, char *argv[])
{
    int quit = 0, op;
    struct lista listaCodigo;
    struct lista listaNome;
    inicLista(&listaCodigo);
    inicLista(&listaNome);
    printf("Carregando dados do arquivo de texto...\n");
    preencherListas(&listaNome, &listaCodigo, "entrada.txt");
    while (!quit)
    {
        menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            quit = 1;
            break;
        }
    }
    gerarArquivos(&listaNome, &listaCodigo);
    return 0;
}
