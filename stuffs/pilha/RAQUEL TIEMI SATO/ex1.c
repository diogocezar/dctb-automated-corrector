#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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

int ordered (Stack *s) {
	if (isEmptyStack(s)) {
		return 0;
	} else {
		Node *t = s->top;
		Node *n = t->next;
		while (t->next != NULL) {
			if (t->value <= n->value) {
				t= t->next;
				n = n->next;
				
			} else {
				return 0;
			}
		}
		return 1;
		
	}
	
}

Stack *inverte (Stack *p1) {
	Stack *p2;
	p2 = create();
	Node *t = p1->top;
	while (t != NULL){
		push(p2, t->value);
		
		
		t = t->next;
	}
	
	return p2;
}

int numerosPrimos (Stack *s) {
	Node *t = s->top;
	int cont = 0, x;
	while (t!= NULL) {
		x = primo (t->value);
		if (x ==1) {
			cont+=1;
		}
		t = t->next;
	}
	return cont;
}

int primo (n) {
	int p = 1;
	int div = 2;
	if (n <= 1) {
		p = 0;
	} 
	while (p==1 && div <= n/2) {
		if (n % div ==0) {
			p =0;
			div+=1;
		}
	}
	if (p == 1) {
	
		return 1;
	}	else {
		return 0;
	}

}



int StackIgual (Stack *s, Stack *a) {
	Node *x, *b;
	x = s->top;
	b = a->top;
	if (x == NULL && b == NULL) {
		printf ("Ambas as pilhas estão vazias.\n");
		return 1;
	} else if( x == NULL ^ b == NULL) {
		return 0;
	} else {
		int comp = compara (x, b);
		return comp;
		}
}
	
int compara (Node *x, Node *b) {
	if (x->next == NULL && b->next == NULL) {
		return (x->value == b->value);
	}else {
	compara (x->next, b->next);
	return (x->value == b->value);
	}
}



int main(){
	
	setlocale(LC_ALL, "Portuguese");
    Stack * s, *p, *y;
    s = create();
    y = create();
    Node * searched = NULL;
    int ordem, cont, igual;
    printf("A pilha está vazia (0,1) : %d\n", isEmptyStack(s));
    display(s);
    //push(s, 2);
    push(s, 30);
    push(s, 20);
    push(s, 10);
    push(s, 3);
    printf("A pilha está vazia (0,1) : %d\n", isEmptyStack(s));
    display(s);
    ordem = ordered(s);
    printf ("\n--------------------------------------\n");
    printf ("A pilha está em ordem crescente (0,1) : %d\n", ordem);
    printf ("\n--------------------------------------\n");
    printf("Buscando elemento:\n");
	searched = search(s, 10);
	if(searched != NULL){
		printf("Encontrou o elemento: %d\n", searched->value);
	}
    
    p = inverte(s);
    printf ("\n--------------------------------------\n");
    printf ("Pilha invertida:\n");
    display(p);
    printf ("\n--------------------------------------\n");
    cont = numerosPrimos(s);
    printf ("A quantidade de números primos na pilha é: %d\n", cont);
    printf ("\n--------------------------------------\n");
    printf ("Comparando as duas pilhas:\n");
    printf ("Primeira pilha:\n");
    display (s);
    printf (" ");
    
    
    push(y, 30);
    push(y, 20);
    push(y, 10);
    push(y, 3);
    
    printf ("Segunda pilha:\n");
    display (y); 
    igual = StackIgual(s,y);
    if (igual == 1) {
    	printf ("As duas pilhas são iguais.\n");
	} else {
	printf ("As duas pilhas não são iguais.\n");
	}
    printf ("\n--------------------------------------\n");
    printf("Removendo elemento: %d\n", pop(s));
    printf("Liberando a pilha.\n");
    freeStack(s);
    return 0;
}