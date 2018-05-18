/*implemente uma função que verifica se os elementos de uma pilha estão ordenados de forma crescente;
    faça uma função que receba uma Pilha P1 e retorne P1 com os elementos invertidos;
    construa uma função que retorne a quantidade de números primos em uma pilha;
    implemente uma função que verifique se duas pilhas são iguais;
*/
//Mateus Yi Muraoka - 1885200
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

int checkStack(Stack * s){
    Node *t = s->top;
    if(t == NULL){
        return 1;
    }
    while(t->next != NULL){
        if(t->value < t->next->value)
            return 0;

        t = t->next;
    }
    return 1;
}
int primeNumber(int n){
    int j, i = 0;
    for(j = 2; j <= n; j++){
        if(n % j == 0)
        i++;
    }
    return i;
}

int checkPrimeNumber(Stack * s){
    Node *np = s->top;
    int pnum, in;
    if(np == NULL){
        return -1;
    }
    pnum = 0;
    while(np != NULL){
            if(1 == primeNumber(np->value))
                pnum++;

            np = np->next;
    }
    printf("\nNa pilha encontra-se: %d numero(s) primo(s)!\n", pnum);
    return 1;
}

int stackCompare(Stack *s, Stack *m){
    Node *a = s->top;
    Node *b = m->top;

    while(a != NULL && b != NULL){
        if(a->value != b->value)
            return 0;
        b = b->next;
        a = a->next;
    }

    if(a != NULL || b != NULL)
        return 0;

    return 1;
}
void stackInvert(Stack * m){
    Stack * temp;
    Node * aux;
    aux = m->top;
    temp = create();
    while(aux != NULL){
        push(temp, aux->value);
        aux = aux->next;
    }
    aux = temp->top;
    printf("\nPilha Invertida: \n");
    while(aux != NULL){
        printf("\n%d", aux->value);
        aux = aux->next;
    }
    freeStack(temp);
}

int main(){
    Stack * s;
    s = create();
    Node * searched = NULL;
    printf("A pilha esta vazia (0,1) : %d\n", isEmptyStack(s));
    display(s);
    push(s, 7);
    push(s, 9);
    push(s, 9);
    push(s, 15);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    Stack *m;
    m = create();
    push(m, 7);
    push(m, 9);
    push(m, 12);
    push(m, 15);
    push(m, 20);
    push(m, 30);
    push(m, 40);
    printf("A pilha esta vazia (0,1) : %d\n", isEmptyStack(s));
    display(s);
    printf("Buscando elemento:\n");
	searched = search(s, 12);
	if(searched != NULL){
		printf("Encontrou o elemento: %d\n", searched->value);
	}
    display(s);
    printf("Segunda Pilha.:\n");
    display(m);
    if(stackCompare(s,m))
        printf("Pilhas Semelhantes\n\n");
    else
        printf("Pilhas Diferentes\n\n");
    if(checkStack(s)){
        printf("Pilha esta em Ordem Crescente!!!\n");
    }
    else{
        printf("Pilha nao esta em Ordem Crescente!!!\n");
    }
    checkPrimeNumber(s);
    stackInvert(s);
    printf("\n\nRemovendo elemento: %d\n", pop(s));
    printf("\nLiberando a pilha.\n");

    freeStack(s);
    return 0;
}
