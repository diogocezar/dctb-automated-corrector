#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int conteudo;
    struct No* prox;
}No;
typedef struct Pilha {
    struct No* topo;
    int size;
}Pilha;

void push(Pilha* p, int valor) {
    No* aux = (No*)malloc(sizeof(No));
    aux->conteudo = valor;
    aux->prox = p->topo;
    p->topo = aux;
    p->size++;
}

int pop(Pilha *pilha) {
    char valor;
    No *aux = NULL;
    if (pilha->size == 0) {
        printf("\nPilha vazia para retirar\n");
        return -1;
    }
    else if((pilha->topo) != NULL) {
        aux = pilha->topo->prox;
        valor = pilha->topo->conteudo;
        free(pilha->topo);
        pilha->topo = aux;
        pilha->size--;
        return valor;
    }
}
Pilha* criaPilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    p->size = 0;
    return p;
}

void display(Pilha * s){
    No * p = s->topo;
    if(isEmptyStack(s)){
        printf("A pilha esta vazia!\n");
    }
    else{
        while(p != NULL){
            printf("%d\n", p->conteudo);
            p = p->prox;
        }
    }
}//printar elementos

int isEmptyStack(Pilha * s){
    return(s->topo == NULL);
}//verififcar se a lista esta vazia


Pilha* ordenaPilha(Pilha* p, Pilha* p2) {
    int elemento;
    int max;
    int aux = NULL; int c = 0, x = 0;
    while (p->topo != NULL) {
        max = NULL;
        while (p->topo != NULL) {
            elemento = pop(p);
            if (elemento > max) {
                max = elemento;
            }
            push(p2, elemento);
        }
        while (p2->size != 0) {
            elemento = pop(p2);
            if (elemento == max) {
                aux = elemento;
            }
            else {
                push(p, elemento);
            }
        }
        push(p2, aux);
        p2->size--;
        max = aux;
    }
    return p2;
}

int main()
{
    Pilha* p1 = criaPilha();
    Pilha* p2 = criaPilha();
    printf("\nOrdenamento da Pilha P1 (3,4,1,2) \n");
    push(p1, 2);
    push(p1, 1);
    push(p1, 4);
    push(p1, 3);
    display(p1);
    printf("\nOrdenamento da Pilha P1 de forma crescente \n");
    p1 = ordenaPilha(p1, p2);

    display(p1);
    system("pause");
    return 0;
}
