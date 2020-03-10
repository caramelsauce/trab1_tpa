#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Lê as cidades de um arquivo e carrega os dados para as listas
void preencherListas(struct lista *listaNome, struct lista *listaCodigo, char *nome_arq);

// Escreve em 2 arquivos de texto as lista ordenadas por nome e código
void gerarArquivos(struct lista *listaNome, struct lista *listaCodigo);

#endif
