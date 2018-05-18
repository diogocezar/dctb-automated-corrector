#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

typedef struct Node{
	int value;
	struct Node *next;
} Node;

typedef struct Stack{
	Node *top;
} Stack;

Stack *create(){
	Stack *q = (Stack*) malloc(sizeof(Stack));
	
	q->top = NULL;
	return q;
}

void push(Stack *s, int value){
	Node *new = (Node*) malloc(sizeof(Node));
	
	new->value = value;
	new->next = s->top;
	s->top = new;
}

void push1(Stack *s1, int value){
	Node *new = (Node*) malloc(sizeof(Node));
	
	new->value = value;
	new->next = s1->top;
	s1->top = new;
}

int isEmptyStack(Stack *s){
    return(s->top == NULL);
}

void display(Stack *s){
    Node *p = s->top;
    
    if(isEmptyStack(s)){
        printf("\nA pilha está vazia!\n");
    
	} else{
        while(p != NULL){
            printf("%d  ", p->value);
            p = p->next;
        }
    }
}

void freeStack(Stack *s){
	Node *p = s->top;
	
	while(p != NULL){
		Node * t = p->next;
		
		free(p);
		p = t;
    }
    free(p);
}

int pop(Stack *s){
	Node *t;
	int v;
	
	if(isEmptyStack(s)){
		printf("\nPilha está vazia\n");
		return 0;
	}
	
    t = s->top;
    v = t->value;
    s->top = t->next;
	free(t);
	
	return v;
}

int primo(Stack *s) {
	Node *p = s->top;
	int i;
	int contP = 0;
	
	for (p = s->top; p != NULL; p = p->next) {
		int cont = 0;
		for (i = 2; i < p->value; i++) {
			if (p->value % i == 0) {
				cont++;
			}
		}
		if (cont == 0) {
			contP++;
		}
	} 
	return contP;
}

int igual(Stack *s, Stack *s1) {
	Node *p = s->top;
	Node *p1 = s1->top;
	
	while ((p != NULL) && (p1 != NULL)) {
		if (p->value != p1->value){
			return 0;
		
		} else {
			p = p->next;
			p1 = p1->next;			
		}
	}
	
	return 1;
}

int ordem(Stack *s){
	Node *p = s->top;
	
	if(isEmptyStack(s)){
    	printf("A pilha está vazia!\n");
    
	} else{
		while (p->next != NULL) {
			if (p->value > p->next->value) {
				return 0;
			}
			p = p->next;
		}
	}
	return 1;
	
}

Stack* printInverted(Stack *s){
	Stack *aux;
	int x;
	
	aux = create();
	
	while (!isEmptyStack(s)) {
		x =	pop(s);
		push(aux, x);
	}
	return aux;
}

int main(){
    Stack *s;
    Stack *s1;
    Stack *print;
    Stack *print1;
    int pri, pri1, i, ord, ord1;
    
    s = create();
    s1 = create();
    print = create();
    print1 = create();

    setlocale(LC_ALL,"portuguese");
    
    printf("Pilha P1: ");
    push(s, 6);
    push(s, 5);
    push(s, 4);
    display(s);
    
    printf("\nPilha P2: ");
    push(s1, 1);
    push(s1, 2);
    push(s1, 3);
    display(s1);
    printf("\n");
    
    ord = ordem(s);
	if (ord == 1) {
		printf ("\nA pilha 1 está ordenada em ordem crescente\n");
	} else {
		printf("\nA pilha 1 não está ordenada em ordem crescente\n");
	}
	
	ord1 = ordem(s1);
	if (ord1 == 1) {
		printf ("A pilha 2 está ordenada em ordem crescente\n");
	} else {
		printf("A pilha 2 não está ordenada em ordem crescente\n");
	}
    
    pri = primo(s);
    printf("\nQuantidade de números primos da pilha 1: %d\n", pri);
    pri1 = primo(s1);
    printf("Quantidade de números primos da pilha 2: %d\n", pri1);
    
    
    print = printInverted(s);
    printf("\nPilha 1 impressa de forma invertida: ");
    display(print);
    
    print1 = printInverted(s1);
    printf("\nPilha 2 impressa de forma invertida: ");
    display(print1);
    printf("\n");
    
    i = igual(s, s1);
    if (i == 1) {
    	printf("\nAs pilhas 1 e 2 são iguais!\n");
	} else {
		printf("\nAs pilhas são diferentes!\n");
	}
    
    printf("\nLiberando as pilhas\n");
    freeStack(s1);
    freeStack(s);
    
    return 0;
}

