#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
} Node;

typedef struct Stack{
    Node *top;
} Stack;

int isEmptyStack(Stack *s){
    return(s->top == NULL);
}

Stack *create(){
    Stack *q = (Stack*) malloc(sizeof(Stack));
    q->top = NULL;
    return q;
}

void freeStack(Stack *s){
	Node *p = s->top;
	while(p != NULL){
	   Node *t = p->next;
	   free(p);
	   p = t;
	}
	free(p);
}

void push(Stack *s, int value){
    Node *new = (Node*) malloc(sizeof(Node));
    new->value = value;
    new->next = s->top;
    s->top = new;
}

void display(Stack *s){
    Node *p = s->top;
    if(isEmptyStack(s)){
        printf("A pilha está vazia!\n");
    }
    else{
        while(p != NULL){
            printf("[%d]\n", p->value);
            p = p->next;
        }
    }
}

int pop(Stack *s){
	Node *n;
	int v;
	if(isEmptyStack(s)){
		printf("\nPilha ja vazia!\n");
		return 0;
	}
    n = s->top;
    v = n->value;
    s->top = n->next;
	free(n);
	return v;
}

int verifyStack(Stack *s){
	Node *n = s->top;
	do{
		if(n->value < n->next->value){
			n = n->next;
		}else{
		    printf("A pilha nao esta ordenada de forma crescente\n");
			return 0;
		}
	}while(n->next != NULL);
	printf("A pilha esta ordenada de forma crescente\n");
}

void insertBottom(Stack *s, int value){
    if (isEmptyStack(s))
        push(s, value);
    else{
        int temp = pop(s);
        insertBottom(s, value);
        push(s, temp);
    }
}

void invert(Stack *s){
    if (!isEmptyStack(s)){
        int temp = pop(s);
        invert(s);
        insertBottom(s, temp);
    }
}

void verifiedIguality(Stack *s, Stack *s2){
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

int countingPrime(Stack *s){
  int prime = 0, num;
  Node *n = s->top;
  if(isEmptyStack(s)){
    printf("A pilha está vazia!\n");
  }else{
    while(n != NULL){
      int cont = 0;
      for(num = n->value; num > 0; num--){
        if(n->value%num == 0){
          cont++;
        }
      }
      if(cont == 2){
        prime++;
      }
      n = n->next;
    }
  }
  return prime;
}

int main(){

  Stack *s;
  Stack *s2;
	s = create();
  s2 = create();
	display(s);
	push(s, 2);
  push(s, 4);
	push(s, 3);
	push(s, 6);
	display(s);
  verifyStack(s);
  push(s2, 2);
  push(s2, 4);
	push(s2, 3);
	push(s2, 6);
  display(s2);
  verifiedIguality(s, s2);
  invert(s);
  display(s);
  printf("A pilha contem %d numeros primos\n", countingPrime(s));
  printf("Liberando a pilha.\n");
  freeStack(s);

  return 0;
}
