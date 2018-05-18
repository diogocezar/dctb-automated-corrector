#include <stdio.h>
#include <stdlib.h>

typedef struct N{
	int value;
	struct N * next;
} N;

typedef struct pilha{
	N * top;
} pilha;

pilha * create(){
	pilha * q = (pilha*) malloc(sizeof(pilha));
	q->top = NULL;
	return q;
}

void push(pilha * s, int value){
	N * new = (N*) malloc(sizeof(N));
	new->value = value;
	new->next = s->top;
	s->top = new;
}

int isEmptypilha(pilha * s){
    return(s->top == NULL);
}

void display(pilha * s){
    N * p = s->top;
    if(isEmptypilha(s)){
        printf("NAO HA ELEMENTOS\n");
    }
    else{
        while(p != NULL){
            printf("%d\n", p->value);
            p = p->next;
        }
    }
}

N * search(pilha * s, int value){
    N * p;
    for(p=s->top; p!=NULL; p=p->next){
        if(p->value == value)
            return p;
    }
    return NULL;
}

void freepilha(pilha * s){
	N * p = s->top;
	while(p != NULL){
		N * t = p->next;
		free(p);
		p = t;
    }
    free(p);
}

int pop(pilha * s){
	N * t;
	int v;
	if(isEmptypilha(s)){
		printf("\n\tNAO HA ELEMENTOS\n");
		return 0;
	}
    t = s->top;
    v = t->value;
    s->top = t->next;
	free(t);
	return v;
}
pilha* inverte(pilha *s) {
	N *q=s->top;
    pilha *outra = create();
    while (	q != NULL) {
 	   	   push(outra,q->value);
    	q=q->next;
    	 }
    return outra;
}
int main(){
    pilha * s;
    s = create();
    N * searched = NULL;
    display(s);
    push(s, 7);
    push(s, 14);
    push(s, 98);
    display(s);
    printf("BUSCAR ELEMENTO:\n");
	searched = search(s, 14);
	s=inverte(s);
	if(searched != NULL){
		printf("ELEMENTO: %d\n", searched->value);
	}
    display(s);
    printf("REMOVENDO: %d\n", pop(s));
    printf("PILHA LIBERADA\n");
    freepilha(s);
    return 0;
}

