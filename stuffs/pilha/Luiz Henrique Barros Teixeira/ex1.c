/**
* Professor Diogo Cezar Teixeira Batista
* <diogo@diogocezar.com>
* <diogoc@utfpr.edu.br>
* Exemplo de Pilha
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

int elem_ordenated(Stack *s){

     Node * temp = s->top;

	if(isEmptyStack(s)){
		printf("Pilha vazia\n");
		return 0;
	}

	do{
        if(temp->value > temp->next->value){
            temp->value = temp->next->value;

        }
        else{
            return 0;
        }
	}while(temp->value > temp->next->value);

	return 1;
}

void prime_number(Stack *s){

    Node *temp;
    int i,div=0,prime_counter=0;

    for(temp=s->top;temp!=NULL;temp=temp->next){
        for(i=1;i<=temp->value;i++){
            if(temp->value % i == 0){
                div++;
            }
        }

        if(div==2){
            prime_counter++;
        }
    }

    printf("A Pilha tem %d Numeros primos \n",prime_counter);

}

int compare_Stack(Stack *s,Stack *x){

    Node *tempSs = s->top;
    Node *tempSx = x->top;

    if(tempSs->value == tempSx->value){

        while(tempSs->value == tempSx->value){
            tempSs = tempSs->next;
            tempSx = tempSx->next;
        }
        return 1;
    }
    else{
        return 0;
    }

}

int main(){
    Stack * s;
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

    printf("esta ordenado(0,1) = %d\n",elem_ordenated(s));

    prime_number(s);

    Stack * x;
    x = create();
     display(x);
    push(x, 10);
    push(x, 20);
    push(x, 30);

    printf("sao iguais(0,1) = %d\n",compare_Stack(s,x));

    printf("Removendo elemento: %d\n", pop(s));
    printf("Liberando a pilha.\n");
    freeStack(s);
    return 0;
}
