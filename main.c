#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "arquivo.h"

int main(int argc, char *argv[])
{
    struct lista listaCodigo;
    struct lista listaNome;
    inicLista(&listaCodigo);
    inicLista(&listaNome);
    /*inserir(&listaNome, &listaCodigo, "Vitória", 4321);
    inserir(&listaNome, &listaCodigo, "Colatina", 2222);
    inserir(&listaNome, &listaCodigo, "Belo Horizonte", 1234);
    inserir(&listaNome, &listaCodigo, "Sao Paulo", 9999);
    exibir(&listaNome, &listaCodigo);
    consultarCodigo(&listaNome, 1234);
    */
    preencherListas(&listaNome, &listaCodigo, "entrada.txt");
    exibir(&listaNome, &listaCodigo);
    gerarArquivos(&listaNome, &listaCodigo);
    return 0;
}
