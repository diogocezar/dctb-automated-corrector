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

int isStackOrdered(Stack *s){
    Node *p = s->top;
    Node *q = s->top->next;
    if(isEmptyStack(s)){
		printf("\nPilha já vazia!\n");
		return 0;
	}
    while (q != NULL){
        if (p->value > q->value){
            return 0;
        }
        p = q;
        q = q->next;
    }
    return 1;
}

int primeNumbers(Stack *s){
    int cont = 0, prime = 0, i = 0;
    Node *p = s->top;
    if(isEmptyStack(s)){
		printf("\nPilha já vazia!\n");
		return 0;
	}
    while (p != NULL){
        cont = 1;
        for (i = p->value; i > 1; i--){
            if ((p->value)%i == 0){
                cont++;
            }
        }
        if (cont == 2){
            prime++;
        }
        p = p->next;
    }
    return prime;
}

Stack* invertedStack(Stack * s){
    Stack * s2 = create();
    Node *p = s->top;
    while (p != NULL){
        push (s2, p->value);
        p = p->next;
    }
    return s2;
}

int compareStacks(Stack *s, Stack *s2){
    Node *p = s->top;
    Node *q = s2->top;
    if(isEmptyStack(s)){
		printf("\nPilha já vazia!\n");
		return 0;
	}
    if(isEmptyStack(s2)){
		printf("\nPilha já vazia!\n");
		return 0;
	}
    if (p != NULL || q != NULL){
        if (p->value != q-> value){
            return 0;
        }
        p = p->next;
        q = q->next;
    }
    return 1;
}

void main(){
    Stack * s;
    Stack * s2;
    s = create();
    Node * searched = NULL;
    printf("A pilha está vazia (0,1) : %d\n", isEmptyStack(s));
    display(s);
    push(s, 10);
    push(s, 20);
    push(s, 30);
    printf("A pilha está vazia (0,1) : %d\n", isEmptyStack(s));
    display(s);
    printf("Buscando elemento:\n");
	searched = search(s, 10);
	if(searched != NULL){
		printf("Encontrou o elemento: %d\n", searched->value);
	}
    display(s);
    printf ("A lista esta ordenada crescentemente? <0,1>: %d\n", isStackOrdered(s));
    printf ("A lista contem %d numeros primos. \n", primeNumbers(s));
    printf ("Pilha antes da inversao. \n");
    display(s);
    printf ("Invertendo a pilha. \n");
    s2 = invertedStack(s);
    display(s2);
    printf ("As duas pilhas sao iguais?<0,1>: %d\n", compareStacks(s,s2));
    freeStack(s);
}
