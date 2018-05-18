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

// Verifica se a pilha esta ordenada
int isOrderStack(Stack* head) {
	Node* p;
	p = head->top;
	if(isEmptyStack(head)){
		printf("Esta pilha está vazia!\n");
	}
	else{
		while(p->next != NULL){
			if(p->value > p->next->value) return 0;
			p = p->next;
		}
	}
	return 1;	
}

// Inverte a pilha
Stack* stackReverse(Stack* s) {
	Stack *s2;
	s2 = create();
	while( !isEmptyStack(s)) push(s2, pop(s));
	return s2;
}

// Conta a quantidade de numeros primos na pilha
int countPrimo(Stack* s) {
	Node* p;
	int contPrimo = 0;
	int isPrimo = 0;
	int i;
	p = s->top;

	if(isEmptyStack(s))	return 0;
	else {
		while(p->next != NULL){
			for(i = 2; i < p->value; i++) 
				if(p->value % i == 0) isPrimo++;
			
			if(isPrimo != 0) p = p->next;
			else {
				contPrimo++;
				p = p->next;
			}
			isPrimo = 0;
		}
	}
	return contPrimo;	
}

// Compara se as pilhas são iguais
int isEqualStack(Stack* s1, Stack* s2)
{
	if(isEmptyStack(s1) && isEmptyStack(s2)) return 0;
	
	Node* p1 = s1->top;
	Node* p2 = s2->top;

	while(p1 != NULL || p2 != NULL) {

		if(p1->value != p2->value) return 0;

		p1 = p1->next;
		p2 = p2->next;
	}
	return 1;
}

int main(){
    Stack * s;
    Stack * s2;
    Stack * invert;
    s = create();
    s2 = create();
	invert = create();

    Node * searched = NULL;
    printf("A pilha está vazia (0,1) : %d\n", isEmptyStack(s));
    display(s);
    push(s, 50);
    push(s, 7);
    push(s, 5);
    push(s2, 7);
    push(s2, 60);
    printf("A pilha está vazia (0,1) : %d\n", isEmptyStack(s));
    display(s);

	// Exercicio 1
	printf("A pilha esta ordenada : %d\n", isOrderStack(s));

	// Exercicio 2
	invert = stackReverse(s);
	printf("Invertendo Pilhas \n");
	display(invert);

	// Exercicio 3
	printf("A quantidade de primos na pilha e : %d\n", countPrimo(invert));

	// Exercicio 4
	printf("As pilhas sao iguais: %d\n",isEqualStack(invert,s2));


    printf("Buscando elemento:\n");
	searched = search(invert, 10);
	if(searched != NULL){
		printf("Encontrou o elemento: %d\n", searched->value);
	}
    display(invert);
    printf("Removendo elemento: %d\n", pop(invert));
    printf("Liberando a pilha.\n");
    freeStack(invert);
    return 0;
}