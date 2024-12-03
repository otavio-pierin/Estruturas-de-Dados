#include <stdio.h>
#include <stdlib.h>
#include "lista_auto_organizada.h"

// Cria uma lista vazia
No* criar_lista() {
    return NULL;
}

// Libera todos os nós da lista de forma recursiva
No* liberar_lista(No* lista) {
    if (lista == NULL) return NULL;
    liberar_lista(lista->prox);
    free(lista);
    return NULL;
}

// Insere um elemento no início da lista
No* inserir_inicio(No* lista, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return lista; // Em caso de falha de memória
    novo->dado = valor;
    novo->acessos = 0;
    novo->prox = lista;
    return novo;
}

// Insere um elemento no fim da lista
No* inserir_fim(No* lista, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return lista; // Em caso de falha de memória
    novo->dado = valor;
    novo->acessos = 0;
    novo->prox = NULL;

    if (lista == NULL) {
        return novo;
    } else {
        No* temp = lista;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
        return lista;
    }
}

// Imprime a lista
void imprimir_lista(No* lista) {
    No* temp = lista;
    while (temp != NULL) {
        printf("%d (Acessos: %d) -> ", temp->dado, temp->acessos);
        temp = temp->prox;
    }
    printf("NULL\n");
}

// Busca e move o nó para frente se encontrado
No* buscar_mover_frente(No* lista, int valor) {
    if (lista == NULL) {
        return lista;
    }

    No* atual = lista;
    No* anterior = NULL;

    // Se o valor já está no primeiro nó
    if (atual->dado == valor) {
        return lista;
    }

    // Percorre a lista
    while (atual != NULL && atual->dado != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    // Se não encontrado
    if (atual == NULL) {
        return lista;
    }

    // Move o nó para frente
    if (anterior != NULL) {
        anterior->prox = atual->prox;  // Desconecta o nó encontrado
        atual->prox = lista;           // Conecta na frente
        lista = atual;                 // Atualiza a cabeça da lista
    }

    return lista;
}

// Busca e troca o nó com o anterior se encontrado (transposição)
No* buscar_transposicao(No* lista, int valor) {
    if (lista == NULL || lista->prox == NULL) {
        return lista;
    }

    No* anterior = NULL;
    No* atual = lista;

    // Se o valor já está no primeiro nó
    if (atual->dado == valor) {
        return lista;
    }

    // Percorre a lista
    while (atual->prox != NULL && atual->prox->dado != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    // Se encontrado
    if (atual->prox != NULL && atual->prox->dado == valor) {
        No* encontrado = atual->prox;
        atual->prox = encontrado->prox;  // Desconecta o nó encontrado
        encontrado->prox = atual;        // Conecta antes do atual

        // Ajusta o anterior
        if (anterior == NULL) {
            lista = encontrado;
        } else {
            anterior->prox = encontrado;
        }

        return lista;
    }

    return lista;
}

// Busca e reorganiza a lista com base na contagem de acessos
No* buscar_contagem(No* lista, int valor) {
    if (lista == NULL) {
        return NULL;
    }

    No* atual = lista;
    No* anterior = NULL;

    // Percorre a lista até encontrar o valor
    while (atual != NULL && atual->dado != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    // Se não encontrado
    if (atual == NULL) {
        return lista;
    }

    // Incrementa o contador de acessos
    atual->acessos++;

    // Se o valor já está no primeiro nó ou sua posição já está correta
    if (anterior == NULL || atual->acessos <= anterior->acessos) {
        return lista;
    }

    // Desconecta o nó
    anterior->prox = atual->prox;

    // Reposiciona o nó com base na contagem
    No* temp = lista;
    No* prev = NULL;
    while (temp != NULL && temp->acessos >= atual->acessos) {
        prev = temp;
        temp = temp->prox;
    }

    // Conecta o nó na nova posição
    if (prev == NULL) {
        atual->prox = lista;
        lista = atual;
    } else {
        atual->prox = prev->prox;
        prev->prox = atual;
    }

    return lista;
}
