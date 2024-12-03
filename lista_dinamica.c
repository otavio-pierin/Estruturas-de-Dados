#include <stdio.h>
#include <stdlib.h>
#include "lista_dinamica.h"

// Fun��o para criar uma lista (inicializa com NULL)
No* criar_lista() {
    return NULL; // Retorna uma lista vazia
}

// Fun��o para liberar a mem�ria da lista
void liberar_lista(No* lista) {
    No* temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->prox;
        free(temp);
    }
}

// Fun��o para inserir um elemento no in�cio da lista
No* inserir_inicio(No* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de aloca��o de mem�ria.\n");
        return lista;
    }
    novo->dado = valor;
    novo->prox = lista; // Aponta para o primeiro n� atual
    return novo;        // Retorna o novo n� como o primeiro da lista
}

// Fun��o para inserir um elemento no fim da lista
No* inserir_fim(No* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de aloca��o de mem�ria.\n");
        return lista;
    }
    novo->dado = valor;
    novo->prox = NULL;

    if (lista == NULL) {
        return novo; // Se a lista estiver vazia, o novo n� � o primeiro
    } else {
        No* temp = lista;
        while (temp->prox != NULL) { // Percorre at� o �ltimo n�
            temp = temp->prox;
        }
        temp->prox = novo; // Insere no fim
        return lista;
    }
}

// Fun��o para remover o primeiro elemento da lista
No* remover_inicio(No* lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return NULL;
    }

    No* temp = lista;
    lista = lista->prox; // Atualiza o ponteiro para o pr�ximo n�
    free(temp);          // Libera o n� removido
    return lista;        // Retorna a lista atualizada
}

// Fun��o para remover o �ltimo elemento da lista
No* remover_fim(No* lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return NULL;
    }

    No* temp = lista;
    if (temp->prox == NULL) {
        free(temp);      // Se houver apenas um elemento, remove-o
        return NULL;     // Retorna NULL, indicando lista vazia
    }

    // Percorre at� o pen�ltimo n�
    No* anterior = NULL;
    while (temp->prox != NULL) {
        anterior = temp;
        temp = temp->prox;
    }

    free(temp);
    anterior->prox = NULL; // O pen�ltimo n� se torna o �ltimo
    return lista;
}

// Fun��o para buscar um elemento na lista
No* buscar(No* lista, int valor) {
    while (lista != NULL) {
        if (lista->dado == valor) {
            return lista; // Retorna o ponteiro para o n� se encontrar
        }
        lista = lista->prox;
    }
    return NULL; // Retorna NULL se n�o encontrar
}

// Fun��o para imprimir os elementos da lista
void imprimir_lista(No* lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No* temp = lista;
    while (temp != NULL) {
        printf("%d -> ", temp->dado);
        temp = temp->prox;
    }
    printf("NULL\n");
}
