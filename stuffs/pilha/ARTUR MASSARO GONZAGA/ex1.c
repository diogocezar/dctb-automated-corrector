
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



int verfCresc(Stack * s){
    Node * a = s->top;
    Node * p = a->next;

    if(isEmptyStack(s)){
        printf("A pilha está vazia!\n");
    }
    else{
        while(p != NULL){

            if(a->value > p->value){

                printf("\n\nA pilha nao esta em ordem crescente !\n");

                return 0;
            }
            a = p;
            p = p->next;

        }
    }


    printf("\n\nA pilha esta em ordem crescente\n");
    return 1;


}

Stack * invertPilha(Stack * s){

    Node * p = s->top;
    Stack * s2 = create();
    if(isEmptyStack(s)){
        printf("A pilha está vazia!\n");
    }
    else{
        while(p != NULL){
            push(s2, p->value);
            p = p->next;
        }
    }

    return s2;

}


int contPrimo(Stack * s){
    Node * p = s->top;
    int prim = 0, i = 0;
    int cont = 1;
    if(isEmptyStack(s)){
        printf("A pilha está vazia!\n");
    }
    else{
        while(p != NULL){
            for(cont = p->value; cont > 1; cont--){
                if((p->value % cont) == 0){
                    i++;
                }
            }

            if(i == 1){
                prim++;
            }
            p = p->next;
        }
    }

    return prim;

}





int main(){
    Stack * s;
    s = create();
    Node * searched = NULL;

    push(s, 30);
    push(s, 20);
    push(s, 10);
    push(s, 2);


    display(s);

    verfCresc(s);


    s = invertPilha(s);

    display(s);

    printf("\n\nPrimos = %d\n\n", contPrimo(s));

    freeStack(s);
    return 0;
}
