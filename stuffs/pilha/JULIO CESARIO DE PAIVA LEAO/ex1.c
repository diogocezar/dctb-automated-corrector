/**
*
*
 Julio Cesario de Paiva Leão
 RA: 1916033
 Engenharia de Software
 Estrutura de Dados - 2018/01

 EXERCICIO
 > implemente uma função que verifica se os elementos de uma pilha estão ordenados de forma crescente;
 > faça uma função que receba uma Pilha P1 e retorne P1 com os elementos invertidos;
 > construa uma função que retorne a quantidade de números primos em uma pilha;
 > implemente uma função que verifique se duas pilhas são iguais;

*
*
*/

#include <stdio.h>
#include <stdlib.h>

int cont = 0;

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
        printf("A pilha esta vazia!\n");
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
		printf("\nPilha ja vazia!\n");
		return 0;
	}
    t = s->top;
    v = t->value;
    s->top = t->next;
	free(t);
	return v;
}

// Função para verificar se a pilha está em ordem crescente ou não
void verifiedCrescentOrder(Stack * s){
    Node * p;
    for(p=s->top; p->next!=NULL; p=p->next){
        if(p->value > p->next->value){
			printf("A pilha 1 nao esta em ordem crescente!\n");
            return;
		}
    }
	printf("A pilha 1 esta em ordem crescente!\n");
    return;
}

// Função para verificar se duas pilhas são iguais ou não
void verifiedIguality(Stack * s, Stack * s2){
    Node * p;
	Node * p2 = s2->top;
    for(p=s->top; p!=NULL; p=p->next){
        if(p->value != p2->value){
			printf("As pilhas sao diferentes!\n");
        	return;
		}
		p2 = p2->next;
    }
	printf("As pilhas sao iguais!\n");
    return;
}

// Função para contar quantos numeros primos existem na pilha
int primeNumbersQtd(Stack * s){
    Node * p;
	int aux = 0, i;

    for(p=s->top; p!=NULL; p=p->next){
			for(i=p->value; i > 0; i--){
				if (p->value % i == 0) {
					aux++;
				}
			}
			if (aux == 2) {
				cont ++;
			}
			aux = 0;
    }
    return cont;
}

// Função para inserir no final da pilha
void insertAtBottom(Stack * s, int item){
    if (isEmptyStack(s))
        push(s, item);
    else{
        int temp = pop(s);
        insertAtBottom(s, item);
        push(s, temp);
    }    
}

// Função para inverter a pilha 1
void reverse(Stack * s){
    if (!isEmptyStack(s)){
        int temp = pop(s);
        reverse(s);
        insertAtBottom(s, temp);
    }   
}



int main(){
    Stack * s;
	Stack * s2;
    s = create();
	s2 = create();
    Node * searched = NULL;
    printf("A pilha 1 esta vazia (0,1) : %d\n", isEmptyStack(s));
	printf("A pilha 2 esta vazia (0,1) : %d\n", isEmptyStack(s2));
	printf("\nInserindo elementos...\n");

    push(s, 30);
    push(s, 20);
    push(s, 7);
  
  	push(s2, 30);
    push(s2, 20);
    push(s2, 7);
  

    printf("\nA pilha 1 esta vazia (0,1) : %d\n", isEmptyStack(s));
    printf("A pilha 2 esta vazia (0,1) : %d\n", isEmptyStack(s2));
    printf("\n");
	printf("Pilha 1\n");
    display(s);
    printf("\n");
	printf("Pilha 2\n");
	display(s2);
	printf("\n");

	verifiedIguality(s, s2);
	verifiedCrescentOrder(s);
	reverse(s);
	printf("\nPilha 1 invertida\n");
	display(s);
	printf("\n");
	verifiedIguality(s, s2);
	verifiedCrescentOrder(s);
	printf("\nExiste %d numero(s) primo(s) na pilha 1\n", primeNumbersQtd(s));

    printf("Buscando elemento:\n");
	searched = search(s, 30);
	if(searched != NULL){
		printf("\nEncontrou o elemento: %d\n", searched->value);
	}

    display(s);
    printf("\nRemovendo elemento: %d\n", pop(s));
    display(s);
    printf("\nLiberando as pilhas.\n\n");
    freeStack(s);
    freeStack(s2);
    system("pause");
    return 0;
}
