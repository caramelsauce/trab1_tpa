#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char *argv[])
{
    struct lista listaCodigo;
    inicLista(&listaCodigo);
    inserir(NULL, &listaCodigo, "Vitória", 4321);
    inserir(NULL, &listaCodigo, "Colatina", 2222);
    inserir(NULL, &listaCodigo, "Belo Horizonte", 1234);
    exibir(NULL, &listaCodigo);
    printf("%s", listaCodigo.prim->prox->p_cidade->nome);
    return 0;
}
