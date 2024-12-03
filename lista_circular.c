#include <stdio.h>
#include <stdlib.h>

typedef struct sNo
{
    int dado;
    struct sNo *prox;
}No;


void inicializar(No** lista){
    *lista=NULL;
}

int vazia(No* lista){
    if (lista==NULL)
    {
        return 1;
    }else{
        return 0;
    }    
}

No* alocar(){
    No* novo = (No*)malloc(sizeof(No));
    if (novo==NULL)
    {
        printf("Erro na alocacao de no!");
        exit(1);
    }
    return novo;
}

void insere_inicio(No** lista, int val){
    No* novo = alocar();
    novo->dado = val;
    if (vazia(*lista))
    {
        novo->prox=novo;
        *lista=novo;
    }else{
        novo->prox=(*lista)->prox;
        (*lista)->prox=novo;
    }
}

void insere_fim(No** lista, int info){
    No* novo = alocar();
    novo->dado=info;
    if (vazia(*lista))
    {
        novo->prox=novo;
        *lista=novo;
    }else{
        novo->prox=(*lista)->prox;
        (*lista)->prox=novo;
        *lista=novo;
    }
}

void remove_inicio(No** lista){
    if (vazia(*lista))
    {
        return;
    }else if (*lista==(*lista)->prox)
    {
        free(*lista);
        inicializar(lista);
    }else{
        No* aux = (*lista)->prox;
        (*lista)->prox=aux->prox;
        free(aux);
    }   
}

void remove_fim(No** lista){
if (vazia(*lista))
    {
        return;
    }else if (*lista==(*lista)->prox)
    {
        free(*lista);
        inicializar(lista);
        return;
    }else{
        No* ant = (*lista)->prox;
        while (ant->prox!=*lista)
        {
            ant = ant->prox;
        }
        ant->prox=(*lista)->prox;
        free(*lista);
        (*lista)=ant;      
    }       
}

int quantidade(No* lista){
    int cont =1;
    No* aux = lista;
    if (vazia(lista))
    {
        return 0;
    }
    while (aux->prox!=lista)
    {
        cont++;
        aux=aux->prox;
    }
    return cont;
}

No* buscar(No* lista, int val){
    if (vazia(lista))
    {
        return NULL;
    }
    No* aux = lista->prox;
    while (aux->dado!=val && aux!=lista)
    {
        aux=aux->prox;
    }
    if (aux->dado=val)
    {
        return aux;
    }else{
        return NULL;
    }    
}

void imprimir(No* lista){
    if (vazia(lista))
    {
        printf("Lista vazia!\n");
        return;
    }else{
        No* aux = lista->prox;
        do
        {
            printf("%d -> ", aux->dado);
            aux = aux->prox;
        } while (aux != lista->prox);
        printf("(volta ao início)\n");
    }   
}

void liberar_lista(No** lista) {
    if (vazia(*lista)) {
        return;
    }
    No* atual = (*lista)->prox;
    No* aux;
    while (atual != *lista) {
        aux = atual;
        atual = atual->prox;
        free(aux);
    }
    free(*lista);
    *lista = NULL;
}

int main(){
    No* lista;
    inicializar(&lista);

    insere_inicio(&lista, 78);
    insere_inicio(&lista, 18);
    insere_inicio(&lista, 7); 
    insere_inicio(&lista, 43);
    insere_fim(&lista, 89);
    insere_fim(&lista, 82);
    insere_fim(&lista, 9);
    insere_fim(&lista, 59);

    imprimir(lista);

    remove_inicio(&lista);
    remove_fim(&lista);
    imprimir(lista);

    No* novo = (buscar(lista, 9));
    printf("%d -> %d", novo->dado, novo->prox->dado);

    liberar_lista(&lista);
    return 0;
}