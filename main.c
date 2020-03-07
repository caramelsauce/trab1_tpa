#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#include "lista.h"
#include "arquivo.h"

// Printa as opções do menu

void menu()
{
    printf("\n\n");
    printf("1 - Efetuar busca por nome\n");
    printf("2 - Efetuar busca por código\n");
    printf("3 - Sair\n");
    printf("Opção: ");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // Declaração de variáveis

    int quit = 0, op;
    struct lista listaCodigo;
    struct lista listaNome;

    // Inicialização das Listas

    inicLista(&listaCodigo);
    inicLista(&listaNome);

    // Carregar os dados do arquivos de texto para a Memória

    printf("Carregando dados do arquivo de texto...\n");
    preencherListas(&listaNome, &listaCodigo, "entrada.txt");

    // Loop do menu

    while (!quit)
    {
        menu();
        scanf("%d", &op);
        switch (op)
        {
            // 1 - Consulta por Nome

        case 1:
        {
            char nome[50];
            clock_t clock_inicial, clock_final;
            getchar();
            printf("\nDigite o nome: ");
            gets(nome);
            clock_inicial = clock();
            consultarNome(&listaNome, nome);
            clock_final = clock();
            printf("\nTempo gasto para busca: %f segundos", ((double)clock_final - (double)clock_inicial) / CLOCKS_PER_SEC);
            break;
        }

            // 2 - Consulta por código

        case 2:
        {
            int codigo;
            clock_t clock_inicial, clock_final;
            printf("\nDigite o código: ");
            scanf("%d", &codigo);
            clock_inicial = clock();
            consultarCodigo(&listaCodigo, codigo);
            clock_final = clock();
            printf("\nTempo gasto para busca: %f segundos", ((double)clock_final - (double)clock_inicial) / CLOCKS_PER_SEC);
            break;
        }

            // 3 - Sair

        case 3:
            quit = 1;
            break;
        default:
            printf("\nOpção Inválida\n");
            break;
        }
    }

    // Escrever escrever as listas ordenadas em arquivos de texto

    gerarArquivos(&listaNome, &listaCodigo);

    return EXIT_SUCCESS;
}
