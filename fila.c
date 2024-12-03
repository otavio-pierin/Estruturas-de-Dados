#include <stdio.h>
#include <stdlib.h>

typedef struct sNo{
    int dado;
    struct sNo *prox;
}No;

typedef struct sFila{
    No *inicio;
    No *fim;
}Fila;

Fila* inicializar(){
    Fila* l = (Fila*)malloc(sizeof(Fila));
    if (l==NULL)
    {
        exit(1);
    }
    l->fim=NULL;
    l->inicio=NULL;
    return l;
}

int vazia(Fila* f){
    if (f->inicio==NULL)
    {
        return 1;
    }
    return 0;
}

void enfileirar(Fila* l, int valor){
    No* novo = (No *)malloc(sizeof(No));
    if (novo==NULL)
    {
        printf("Erro de alocacao de memoria!");
        exit(1);
    }
    novo->dado=valor;
    novo->prox=NULL;
    if (vazia(l))
    {
        l->inicio=novo;
        l->fim=novo;
    }else{
        l->fim->prox=novo;
        l->fim=novo;
    }    
}

int desenfileirar(Fila *f){
    if (!vazia(f))
    {
        No* aux = f->inicio;
        int val = aux->dado;
        if (f->inicio == f->fim)
        {
            free(aux);
            f->inicio=NULL;
            f->fim=NULL;
            return val;
        }
        f->inicio = f->inicio->prox;
        free(aux);
        return val;
    }
    printf("Erro, tentativa de desenfileirar uma fila vazia!");
    exit(1);
}

void imprimir(Fila *f){
    if (vazia(f))
    {
        printf("Lista vazia!");
        return;
    }
    Fila* aux = inicializar();
    while (!vazia(f))
    {
        int valor = desenfileirar(f);
        printf("%d -> ", valor);
        enfileirar(aux, valor);
    }
    printf("NULL");
    while (!vazia(aux))
    {
        int valor = desenfileirar(aux);
        enfileirar(f,valor);
    }   
}

void liberarFila(Fila* f){
    if (vazia(f))
    {
        return;
    }else{
        while (!vazia(f))
        {
            No* aux = f->inicio;
            f->inicio = f->inicio->prox;
            free(aux);
        }
        printf("Lista liberada!");
    }
    
}

void reverso(Fila *f){
    if (vazia(f))
    {
        printf("Fila vazia!");
        return;
    }
    
    No* aux = f->inicio;
    int qtd=0;
    while (aux!=NULL)
    {
        qtd++;
        aux = aux->prox;
    }
    
    int *elementos = (int *)malloc(qtd * sizeof(int));
    if (elementos == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }

    for (int i = 0; i < qtd; i++) {
        elementos[i] = desenfileirar(f);
    }

    for (int i = qtd - 1; i >= 0; i--) {
        enfileirar(f, elementos[i]);
    }

    free(elementos);   
}

int par(Fila* f){
    int contPar=0;
    if (vazia(f))
    {
        return 0;
    }else{
        Fila* aux = inicializar();
        while (!vazia(f))
        {
            enfileirar(aux, desenfileirar(f));
            if (aux->fim->dado%2==0)
            {
                contPar++;
            }        
        }
        while (!vazia(aux))
        {
            enfileirar(f, desenfileirar(aux));
        } 
    }
    return contPar;
}

int main() {
    Fila *fila = inicializar();

    // Adicionar elementos à fila
    enfileirar(fila, 1);
    enfileirar(fila, 2);
    enfileirar(fila, 3);
    enfileirar(fila, 4);
    enfileirar(fila, 46);
    enfileirar(fila, 54);
    enfileirar(fila, 79);

    printf("Fila original: ");
    imprimir(fila);
    printf("\n%d valores pares.", par(fila));

    // Reverter a fila
    reverso(fila);

    printf("\nFila apos reverso: ");
    imprimir(fila);

    liberarFila(fila);
    return 0;
}