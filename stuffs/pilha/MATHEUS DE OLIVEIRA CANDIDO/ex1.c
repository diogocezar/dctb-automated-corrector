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

void invertStack(Stack * s){
    Node * aux = NULL;
    Stack * invert = create();

    while(aux!=NULL){
        push(invert, s->top->value);
        aux = s->top;
        s->top = s->top->next;
        free(aux);
    }

    s = inverted;
}

int checkOrdened(Stack * s){
    Node * aux = s->top;

    while(aux->next != null){
        if(!(aux->value < aux->next->value)){
            return 0;
        }
        aux = aux->next;
    }

    return 1;
}

int countStack(Stack * s){
    int count = 0;
    Node * aux = s->top;
    while(aux!=NULL){
        count++;
    }

    return count;
}

int stacksEquals(Stack * a, Stack * b){
    Node * auxA = a->top;
    Node * auxB = b->top;
    if(countStack(a) == countStack(b)){
        while((auxA!=NULL)&&(auxB!=NULL)){
            if(auxA != auxB){
                return 0;
            }
        }
        return 1;
    }

    return 0;
}


int countPrimeStack(Stack * s){
    int count = 0;
    Node * aux = s->top;
     int div = 0;
    while(aux!=NULL){
        div = 0;
        for (i = 2; i < x; i++){
            if (x % i == 0){
                div++;
            }
        }
        if(div == 0){
            count++;
        }
    }

    return count;
}
