/**
* Samuel Bordini Bolsanello
* Estrutura de dados
* Engenharia de Software
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

int isOrdered(Stack * s){
    Node * p = s->top;
    if(isEmptyStack(s)){
        printf("A pilha está vazia!\n");
    }
    else{
        while(p->next != NULL){
            if(p->value > p->next->value){
	    	return 0;
	    } 
	    p = p->next;
        }
	return 1;
    }
}

Stack * reverse(Stack * s) {
    Node * p = s->top;
    Stack * aux = create();
    while (p != NULL) {
        push(aux,p->value);
	p = p->next;
    }
    return aux;
}

int totalPrimes(Stack * s){
    int aux, cont = 0;
    Node * p = s->top;
    if(isEmptyStack(s)){
        printf("A pilha está vazia!\n");
    }
    else{
        while(p != NULL){
            aux = p->value - 1;
	    for(aux;aux > 1; aux--){
		if(p->value % aux == 0){
			break;		
		}
	    }
	    if(aux == 1) 
	        cont++;
            p = p->next;
        }
    }
    return cont;
}

int compare(Stack * s, Stack * s2){
	Node * p = s->top;
	Node * p2 = s2->top;
        if(isEmptyStack(s) || isEmptyStack(s2)){
        	printf("Uma das pilhas está vazia!\n");
    	}
        else{
        while((p != NULL) && (p2 != NULL)){
            if(p->value != p2->value)
		return 0;
            p = p->next;
 	    p2 = p2->next;
        }
	if((p != NULL) || (p2 != NULL))
		return 0;
	else 
		return 1;
    }
	
}
int main(){
    Stack * s2 = create();
    Stack * s;
    s = create();
    Node * searched = NULL;
    printf("A pilha está vazia (0,1) : %d\n", isEmptyStack(s));
    display(s);
    push(s, 3);
    push(s, 2);
    push(s, 1);
    push(s, 4);	
    push(s2, 3);
    push(s2, 2);
    push(s2, 1);
    push(s2, 4);
    printf("A pilha está vazia (0,1) : %d\n", isEmptyStack(s));
    display(s);
    printf("A pilha está ordenada (0,1) : %d\n", isOrdered(s));
    pop(s);
    display(s);
    printf("A pilha está ordenada (0,1) : %d\n", isOrdered(s));
    printf("Pilha 1 : \n");
    display(s);
    printf("Pilha 2 : \n");
    display(s2);
    printf("As pilhas sao iguais (0,1) : %d\n", compare(s,s2));
    pop(s2);
    printf("Pilha 1 : \n");
    display(s);
    printf("Pilha 2 : \n");
    display(s2);
    printf("As pilhas sao iguais (0,1) : %d\n", compare(s,s2));
    display(s);
    printf("Invertendo ...\n");
    s = reverse(s);
    display(s);
    printf("O total de primos e de : %d\n", totalPrimes(s));
    printf("Buscando elemento:\n");
	searched = search(s, 10);
	if(searched != NULL){
		printf("Encontrou o elemento: %d\n", searched->value);
	}
    display(s);
    printf("Removendo elemento: %d\n", pop(s));
    printf("Liberando a pilha.\n");
    freeStack(s);
    return 0;
}
