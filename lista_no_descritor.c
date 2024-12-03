#include <stdio.h>
#include <stdlib.h>

typedef struct sNo
{
    int dado;
    struct sNo *prox;
}No;

typedef struct sLista
{
    No *inicio;
    No *fim;
    int qtd;
}Lista;

Lista* alocar(){
    Lista *l = (Lista *)malloc(sizeof(Lista));
    if (l==NULL)
    {
        exit(1);
    }
    return l;
}

Lista* inicializar(){
    Lista* l = alocar();
    l->qtd=0;
    l->inicio=NULL;
    l->fim=NULL;
    return l;
}

int vazia(Lista* l){
    if (l!=NULL)
    {
        if (l->qtd!=0)
        {
            return 0;
        }
        return 1;
    }
}

int qtd(Lista *l){
    return l->qtd;
}

void inserir_inicio(Lista** l, int info){
    No* novo = (No*)malloc(sizeof(No));
    if (novo!=NULL)
    {
        novo->dado=info;
        if (vazia(*l))
        {
            novo->prox=NULL;
            (*l)->inicio=novo;
            (*l)->fim=novo;
        }else{
            novo->prox= (*l)->inicio;
            (*l)->inicio=novo;
        }
        (*l)->qtd++;
    }
}

void inserir_fim(Lista **l, int info){
    No* novo = (No*)malloc(sizeof(No));
    if (novo!=NULL)
    {
        novo->dado=info;
        if (vazia(*l))
        {
            novo->prox=NULL;
            (*l)->inicio=novo;
            (*l)->fim=novo;
        }else{
            novo->prox=NULL;
            (*l)->fim->prox=novo;
            (*l)->fim=novo;
            
        }
        (*l)->qtd++;
    }
}

void remover_inicio(Lista **l){
    if (vazia(*l))
    {
        return;
    }
    No* aux = (*l)->inicio;
    if (aux->prox==NULL)
    {
        (*l)->inicio=NULL;
        (*l)->fim=NULL;
    }else{
        (*l)->inicio=(*l)->inicio->prox;
    }
    free(aux);
    (*l)->qtd--;
}

void liberar_lista(Lista** lista) {
    if (vazia(*lista)) {
        return;
    }
    No* atual = (*lista)->inicio;
    No* aux;
    while (atual != (*lista)->fim) {
        aux = atual;
        atual = atual->prox;
        free(aux);
    }
    free((*lista)->fim);
    *lista = NULL;
}

void imprimir(Lista* lista){
    if (vazia(lista)) {
        printf("Lista vazia!");
        return;
    }
    No* aux = lista->inicio;
    while (aux != lista->fim)
    {
        printf("%d -> ", aux->dado);
        aux = aux->prox;
    }    
    printf("%d\n", lista->fim->dado);
}

int main(){
    Lista *l = inicializar();

    inserir_inicio(&l, 243);
    inserir_fim(&l, 98);
    inserir_inicio(&l, 45);
    inserir_fim(&l, 125);
    inserir_inicio(&l, 87);
    inserir_fim(&l, 32);
    inserir_fim(&l, 69);

    imprimir(l);
    remover_inicio(&l);
    remover_inicio(&l);
    imprimir(l);

    liberar_lista(&l);
    return 0;
}