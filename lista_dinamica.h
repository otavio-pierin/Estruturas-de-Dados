#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H

// Definição do nó da lista
typedef struct sNo {
    int dado;
    struct sNo* prox;
} No;

// Funções básicas da lista
No* criar_lista();                        // Cria uma lista (inicializa como NULL)
void liberar_lista(No* lista);            // Libera a memória da lista
No* inserir_inicio(No* lista, int valor); // Insere um elemento no início
No* inserir_fim(No* lista, int valor);    // Insere um elemento no fim
No* remover_inicio(No* lista);            // Remove o primeiro elemento
No* remover_fim(No* lista);               // Remove o último elemento
No* buscar(No* lista, int valor);         // Busca um elemento na lista
void imprimir_lista(No* lista);           // Imprime todos os elementos da lista

#endif
