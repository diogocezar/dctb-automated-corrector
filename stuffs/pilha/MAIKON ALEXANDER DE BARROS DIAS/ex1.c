//Nome : Maikon Alexander de Barros Dias
//RA : 1706330

/*1- implemente uma função que verifica se os elementos de uma pilha estão ordenados de forma crescente;
  2- faça uma função que receba uma Pilha P1 e retorne P1 com os elementos invertidos;
  3- construa uma função que retorne a quantidade de números primos em uma pilha;
  4- implemente uma função que verifique se duas pilhas são iguais;
*/
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

int checkStack(Stack * s){
    Node *t = s->top;
    if(t == NULL){
        return 1;
    }
    while(t->next != NULL){
        if(t->value < t->next->value)
            return 0;

        t = t->next;
    }
    return 1;
}
int isPrime(int n){
    int j, i = 0;
    for(j = 2; j <= n; j++){
        if(n % j == 0)
        i++;
    }
    return i;
}

int checkPrimeInStack(Stack * s){
    Node *t = s->top;
    int pnum, in;
    if(t == NULL){
        return -1;
    }
    pnum = 0;
    while(t != NULL){
            if(1 == isPrime(t->value))
                pnum++;

            t = t->next;
    }
    printf("temos %d numeros primos\n", pnum);
    return 1;
}

int compareStack(Stack *s, Stack *p){
    Node *a = s->top;
    Node *b = p->top;

    while(a != NULL && b != NULL){
        if(a->value != b->value)
            return 0;
        b = b->next;
        a = a->next;
    }

    if(a != NULL || b != NULL)
        return 0;

    return 1;
}
void invertStack(Stack * p){
    Stack * temp;
    Node * aux;
    aux = p->top;
    temp = create();
    while(aux != NULL){
        push(temp, aux->value);
        aux = aux->next;
    }
    aux = temp->top;
    printf("Pilha Invertida: \n");
    while(aux != NULL){
        printf("\n%d", aux->value);
        aux = aux->next;
    }
    freeStack(temp);
}

int main(){
    Stack * s;
    s = create();
    Node * searched = NULL;
    printf("A pilha está vazia (0,1) : %d\n", isEmptyStack(s));
    display(s);
    push(s, 2);
    push(s, 7);
    push(s, 7);
    push(s, 11);
    push(s, 20);
    push(s, 29);
    push(s, 30);
    Stack *p;
    p = create();
    push(p, 2);
    push(p, 8);
    push(p, 10);
    push(p, 11);
    push(p, 20);
    push(p, 29);
    push(p, 30);
    printf("A pilha está vazia (0,1) : %d\n", isEmptyStack(s));
    display(s);
    printf("Buscando elemento:\n");
	searched = search(s, 10);
	if(searched != NULL){
		printf("Encontrou o elemento: %d\n", searched->value);
	}
    display(s);
    printf("Segunda Pilha.:\n");
    display(p);
    if(compareStack(s,p))
        printf("Pilhas identicas\n\n");
    else
        printf("Pilhas diferentes\n\n");
    if(checkStack(s)){
        printf("Pilha em ordem crescente!!!\n");
    }
    else{
        printf("Pilha nao esta em ordem crescente!!!\n");
    }
    checkPrimeInStack(s);
    invertStack(s);
    printf("\nRemovendo elemento: %d\n", pop(s));
    printf("Liberando a pilha.\n");

    freeStack(s);
    return 0;
}
