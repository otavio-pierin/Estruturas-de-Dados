#include <stdio.h>
#include <stdlib.h>
#include "lista_dinamica.h"

// Função para criar uma lista (inicializa com NULL)
No* criar_lista() {
    return NULL; // Retorna uma lista vazia
}

// Função para liberar a memória da lista
void liberar_lista(No* lista) {
    No* temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->prox;
        free(temp);
    }
}

// Função para inserir um elemento no início da lista
No* inserir_inicio(No* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação de memória.\n");
        return lista;
    }
    novo->dado = valor;
    novo->prox = lista; // Aponta para o primeiro nó atual
    return novo;        // Retorna o novo nó como o primeiro da lista
}

// Função para inserir um elemento no fim da lista
No* inserir_fim(No* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação de memória.\n");
        return lista;
    }
    novo->dado = valor;
    novo->prox = NULL;

    if (lista == NULL) {
        return novo; // Se a lista estiver vazia, o novo nó é o primeiro
    } else {
        No* temp = lista;
        while (temp->prox != NULL) { // Percorre até o último nó
            temp = temp->prox;
        }
        temp->prox = novo; // Insere no fim
        return lista;
    }
}

// Função para remover o primeiro elemento da lista
No* remover_inicio(No* lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return NULL;
    }

    No* temp = lista;
    lista = lista->prox; // Atualiza o ponteiro para o próximo nó
    free(temp);          // Libera o nó removido
    return lista;        // Retorna a lista atualizada
}

// Função para remover o último elemento da lista
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

    // Percorre até o penúltimo nó
    No* anterior = NULL;
    while (temp->prox != NULL) {
        anterior = temp;
        temp = temp->prox;
    }

    free(temp);
    anterior->prox = NULL; // O penúltimo nó se torna o último
    return lista;
}

// Função para buscar um elemento na lista
No* buscar(No* lista, int valor) {
    while (lista != NULL) {
        if (lista->dado == valor) {
            return lista; // Retorna o ponteiro para o nó se encontrar
        }
        lista = lista->prox;
    }
    return NULL; // Retorna NULL se não encontrar
}

// Função para imprimir os elementos da lista
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
