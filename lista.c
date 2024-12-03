#include "lista.h"

// Inicializa a lista como vazia (NULL)
void inicializar_lista(No** lista) {
    *lista = NULL;
}

// Insere um elemento no início da lista
void inserir_inicio(No** lista, int valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novo_no->dado = valor;
    novo_no->prox = *lista;
    *lista = novo_no;
}

// Insere um elemento no final da lista
void inserir_fim(No** lista, int valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novo_no->dado = valor;
    novo_no->prox = NULL;

    if (*lista == NULL) {
        *lista = novo_no;
    } else {
        No* temp = *lista;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo_no;
    }
}

// Remove o elemento do início da lista
int remover_inicio(No** lista) {
    if (*lista == NULL) {
        printf("Lista vazia.\n");
        return -1;
    }
    No* temp = *lista;
    int valor = temp->dado;
    *lista = temp->prox;
    free(temp);
    return valor;
}

// Remove o elemento do final da lista
int remover_fim(No** lista) {
    if (*lista == NULL) {
        printf("Lista vazia.\n");
        return -1;
    }

    No* temp = *lista;
    if (temp->prox == NULL) {
        int valor = temp->dado;
        free(temp);
        *lista = NULL;
        return valor;
    }

    while (temp->prox->prox != NULL) {
        temp = temp->prox;
    }

    int valor = temp->prox->dado;
    free(temp->prox);
    temp->prox = NULL;
    return valor;
}

// Busca um elemento na lista
No* buscar(No** lista, int valor) {
    No* temp = *lista;
    while (temp != NULL) {
        if (temp->dado == valor) {
            return temp;
        }
        temp = temp->prox;
    }
    return NULL;
}

// Imprime todos os elementos da lista
void imprimir_lista(No* lista) {
    No* temp = lista;
    while (temp != NULL) {
        printf("%d -> ", temp->dado);
        temp = temp->prox;
    }
    printf("NULL\n");
}

// Libera a memória de todos os nós da lista
void liberar_lista(No** lista) {
    No* temp;
    while (*lista != NULL) {
        temp = *lista;
        *lista = (*lista)->prox;
        free(temp);
    }
}

