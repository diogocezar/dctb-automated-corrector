#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	int value;
	struct Node *next;
}Node;

typedef struct Stack{
	Node * top;
}Stack;

//prototipos
int isEmpty(Stack *stk);
void printStack(Stack *stk);
void push(Stack *stk, int value);
Node * search(Stack *stk, int value);
void freeStack(Stack *stk);
void freeStack(Stack *stk);
int pop(Stack *stk);
//fim prototipos.

//Função para iniciar a pilha.
Stack *create(){
	Stack *aux = (Stack*) malloc(sizeof(Stack));
	aux->top = NULL;
	return aux;
}

//função para imprimir elementos.

void printStack(Stack *stk){
	Node *aux = stk->top;
	if(isEmpty(stk)){
		printf("\nPilha vazia!\n");
	}else{
		while(aux != NULL){
			printf("\nElemento impresso: %d\n", aux->value);
			aux = aux->next;
		}
	}
}

//verifica se a pilha está ou não vazia.
int isEmpty(Stack *stk){
	return(stk->top == NULL);
}

//função para inserir um novo elemento no topo da pilha
void push(Stack *stk, int value){
	Node *new = (Node*) malloc (sizeof(Node));
	new->value = value;
	new->next = stk->top;
	stk->top = new;
}

//função para procurar elemento na pilha
Node * search(Stack *stk, int value){
	Node *aux;
	for(aux=stk->top; aux != NULL; aux=aux->next){
		if(aux->value == value){
			return aux;
		}		
	}
	return NULL;
}

//função para liberar memória usada pela fila.
void freeStack(Stack *stk){
	Node *aux = stk->top;
	while(aux != NULL){
		Node *aux2 = aux->next;
		free(aux);
		aux = aux2;
	}
	free(aux);
}

//função para retirar um elemento da pilha(o ultimo)
int pop(Stack *stk){
	Node * aux;
	int valueAux;
	if(isEmpty(stk)){
		system("cls");
		printf("\nA pilha já está vazia!\n\n");
		return 0;
	}
	aux = stk->top;
	valueAux = aux->value;
	stk->top = aux->next;
	free(aux);
	return valueAux;
}

//funções do exercicio T015:

int checkCres(Stack *stk){
	
	int check = 1;
	
	Node *aux;
	aux = stk->top;
	while(aux->next != NULL){
		if(aux->value < aux->next->value){
			check = 0;
		}
		aux = aux->next;
	}
	return check;	
}
//função que reverte os elementos de uma pilha.
Stack *revertStack(Stack *stk){
	Node *aux;
	Stack *revertedStack;
	revertedStack = create();
	
	int valueAux;
	aux = stk->top;
	
	while(aux != NULL){
		valueAux = aux->value;
		push(revertedStack, valueAux);
		aux = aux->next;
	}
	//stk = revertedStack;
	return(revertedStack);
	//return(stk);	
}

int checkEquals(Stack *stk1, Stack *stk2){
	Node * aux1;
	Node * aux2;
	
	aux1 = stk1->top;
	aux2 = stk2->top;
	int isEquals = 1;
	
	while ((aux1 != NULL) || (aux2 != NULL)){
		if(aux1->value != aux2->value){
			isEquals = 0;
		}
		aux1 = aux1->next;
		aux2 = aux2->next;		
	}
	return isEquals;	
}

int checkPrimes(Stack *stk){
	Node *aux = stk->top;
	int value, i = 1, result, count = 0, primeQtd=0;
	
	do{	
		value = aux->value;
		count = 0;
		for(i = 1; i <= value; i++){
			result = (value%i);
			if(result == 0){
				count++;	
			}
		}
		if(count <= 2){
			primeQtd++;
		}
		aux = aux->next;
	}while(aux!= NULL);
	
	return primeQtd;	
}

int primeStack(Stack * s){
	Node *t = s->top;
	int v, i = 1, result, count = 0, primeQtd=0;
	
	do{	
		v = t->value;
		count = 0;
		for(i = 1; i <= v; i++){
			result = (v%i);
			if(result == 0){
				count++;	
			}
		}
		if(count <= 2){
			primeQtd++;
		}
		t = t->next;
	}while(t!= NULL);
	
	return primeQtd;
}










