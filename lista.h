#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista
typedef struct sNo {
    int dado;
    struct sNo* prox;
} No;

// Funções básicas para manipulação da lista
void inicializar_lista(No** lista);
void inserir_inicio(No** lista, int valor);
void inserir_fim(No** lista, int valor);
int remover_inicio(No** lista);
int remover_fim(No** lista);
No* buscar(No** lista, int valor);
void imprimir_lista(No* lista);
void liberar_lista(No** lista);

#endif
