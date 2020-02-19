#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdio.h>
#include "lista.h"

void preencherListas(struct lista *listaNome, struct lista *listaCodigo, char *nome_arq);

void gerarArquivos(struct lista *listaNome, struct lista *listaCodigo);

#endif