#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node * next;
} Node;

typedef struct Stack{
	Node * top;
} Stack;

Stack * create(){
	Stack * q = (Stack*) malloc(sizeof(Stack));
	q->top = NULL;
	return q;
}

void push(Stack * s, int value){
	Node * new = (Node*) malloc(sizeof(Node));
	new->value = value;
	new->next = s->top;
	s->top = new;
}

int isEmptyStack(Stack * s){
    return(s->top == NULL);
}

void display(Stack * s){
    Node * p = s->top;
    if(isEmptyStack(s)){
        printf("A pilha está vazia!\n");
    }
    else{
        while(p != NULL){
            printf("%d\n", p->value);
            p = p->next;
        }
    }
}

int verifOrdem(Stack * s){
    Node * p;
    for(p=s->top; p!=NULL; p=p->next){
        if(p->value > p->next->value){
            return 1;
		}
    }
    return 0;
}

Node * search(Stack * s, int value){
    Node * p;
    for(p=s->top; p!=NULL; p=p->next){
        if(p->value == value)
            return p;
    }
    return NULL;
}

void freeStack(Stack * s){
	Node * p = s->top;
	while(p != NULL){
		Node * t = p->next;
		free(p);
		p = t;
    }
    free(p);
}

int pop(Stack * s){
	Node * t;
	int v;
	if(isEmptyStack(s)){
		printf("\nPilha já vazia!\n");
		return 0;
	}
    t = s->top;
    v = t->value;
    s->top = t->next;
	free(t);
	return v;
}

Stack * pilhaInvertida(Stack * s){
    Stack * aux;
    int v;
    aux = create();
    v = pop(s);
    do{
    push(aux, v);
    v = pop(s);
    }while(v != 0);
    return aux;

}

int numPrimos(Stack * s){
    Node * p = s->top
    int n = 0;
    int div = 0;
    while(p != NULL){

        for (i = 1; i <= p->value; i++) {
            if (x % i == 0) {
                div++;
            }
        }
        if (div == 2){
            n++;
        }
    }
    return n;
}

int main(){
    Stack * s;
    s = create();
    Node * searched = NULL;
    int verificado = 2,primos = 0;
    printf("A pilha está vazia (0,1) : %d\n", isEmptyStack(s));
    display(s);
    push(s, 30);
    push(s, 20);
    push(s, 10);
    printf("A pilha está vazia (0,1) : %d\n", isEmptyStack(s));
    display(s);
    printf("Buscando elemento:\n");
	searched = search(s, 10);
	if(searched != NULL){
		printf("Encontrou o elemento: %d\n", searched->value);
	}
    display(s);
    printf("Removendo elemento: %d\n", pop(s));
    printf("verificando ordem da pilha.\n");
    verificado = verifOrdem(s);
    if(verificado == 1){
		printf("A pilha não está em ordem crescente.\n");
	}else if(verificado == 1){
		printf("A pilha está em ordem crescente.\n");
	}
	printf("invertendo lista.\n");
	s = pilhaInvertida(s);
	printf("verificando quantidade de primos.\n")
	primos = numPrimos(s);
	printf("a quantidade de numeros primos e : %d\n",primos);
	display(s);
    printf("Liberando a pilha.\n");
    freeStack(s);
    return 0;
}
