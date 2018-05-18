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
//=================================================//

void verCresc(Stack * s){
	Node * p = s->top;
	int cont=0;
    if(isEmptyStack(s)){
        printf("A pilha está vazia!\n");
    }
    else{
        while(p->next != NULL){
            if(p->value >= p->next->value){
            	cont=1;

			}
            p = p->next;
        }

	    if(cont==0){
	    	printf("\nEsta em ordem crescente!");
		}else{
				printf("Nao esta em ordem crescente!");
		}
	}
}
/*/=================================================//

Node * invert(Stack * s){
	Node * p = s->top;
	Node * aux = (Node*) malloc(sizeof(Node));
	int cont=0,i,aux2,w;

    if(isEmptyStack(s)){
        printf("A pilha está vazia!\n");
    }
    else{
        while(p != NULL){
        	cont++;
            p = p->next;
        }
        aux2 = cont;
        w = cont;
        i = 0;



        while(i<cont){
        	p = s->top;
        	while(w<aux2){
        		p = p->next;
			}
			w--;
        	aux->next = p;
        	aux = aux->next;
        	i++;
		}

	}
	return aux;
}
//=================================================/*/
Stack * invert(Stack * s, Stack * inverted){
	Stack * aux = s;


			for(aux = s;(!isEmptyStack(s)); aux->top = aux->top->next){
				push(inverted,aux->top->value);
			}
			return inverted;
		}

//====================================================//
//overflow?
void numPrimo(Stack * s){
	Node * aux = s->top;
	int cont = 0, primo = 0, i = 2;
	//printf("Pl entr");
    if(isEmptyStack(s)){
        printf("A pilha está vazia!\n");
    }
    else{

        while(aux->next != NULL){
        	//printf("Pl entr");
        	cont = 0;
        	do{
        		if(aux->value % i == 0){
        			cont++;
				}
				i++;
			}while ((i<aux->value)&&(cont<3));

			if(cont==0){
				primo++;
			}
        	aux = aux->next;
		}
	printf("\nA pilha possui %d numero(s) primo(s)",primo);
	}
}
//=================================================//

void verIgual(Stack * s, Stack * t){
    Node * p = s->top;
    Node * q = t->top;
    int cont=0, cont2=0, ver=0;
    if(isEmptyStack(s)){
        printf("\nA pilha está vazia!\n");
    }
    while(p != NULL){
        cont++;
        p = p->next;
    }

    while(q != NULL){
       cont2++;
       q = q->next;
    }

    p = s->top;
    q = t->top;

    if(cont == cont2){
    	while(p != NULL){
    		if(p->value == q ->value){
    		ver++;
    	}
    		p = p->next;
    		q = q->next;
		}
	}else{
		printf("\nPilhas diferentes.");
	}

    if(ver == cont){
    	printf("\nPilhas iguais.");
	}else{
		printf("\ndiferent somehow");
	}

}
//=================================================//

int main(){
    Stack * s, * t,* inverted;
    s = create();
    t = create();
		inverted = create();
  	Node * searched = NULL;
    push(s, 9);
    push(s, 7);
    push(s, 11);
    push(s, 6);
    push(t, 9);
    push(t, 7);
    push(t, 11);
    push(t, 6);
    display(s);
    verCresc(s);
    numPrimo(s);
    verIgual(s,t);
		invert(s,inverted);
		display(inverted);

}
