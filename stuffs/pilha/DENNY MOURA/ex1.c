#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int valor;
	struct No * prox;
} No;

typedef struct Stack{
	No * top;
} Stack;

Stack * criar(){
	Stack * q = (Stack*) malloc(sizeof(Stack));
	q->top = NULL;
	return q;
}

void push(Stack * s, int valor){
	No * new = (No*) malloc(sizeof(No));
	new->valor = valor;
	new->prox = s->top;
	s->top = new;
}

int VazioStack(Stack * s){
    return(s->top == NULL);
}

void display(Stack * s){
    No * p = s->top;
    if(VazioStack(s)){
        printf("A pilha esta vazia!\n");
    }
    else{
        while(p != NULL){
            printf("%d\n", p->valor);
            p = p->prox;
        }
    }
}

No * procurar(Stack * s, int valor){
    No * p;
    for(p=s->top; p!=NULL; p=p->prox){
        if(p->valor == valor)
            return p;
    }
    return NULL;
}

void LivreStack(Stack * s){
	No * p = s->top;
	while(p != NULL){
		No * t = p->prox;
		free(p);
		p = t;
    }
    free(p);
}

int pop(Stack * s){
	No * t;
	int v;
	if(VazioStack(s)){
		printf("\nA pilha ja esta vazia!\n");
		return 0;
	}
    t = s->top;
    v = t->valor;
    s->top = t->prox;
	free(t);
	return v;
}

int VerificaStack(Stack * s){
    No *t = s->top;
    if(t == NULL){
        return 1;
    }
    while(t->prox != NULL){
        if(t->valor < t->prox->valor)
            return 0;

        t = t->prox;
    }
    return 1;
}
int isPrime(int n){
    int j, i = 0;
    for(j = 2; j <= n; j++){
        if(n % j == 0)
        i++;
    }
    return i;
}

int VerificaPrimeStack(Stack * s){
    No *t = s->top;
    int pnum, in;
    if(t == NULL){
        return -1;
    }
    pnum = 0;
    while(t != NULL){
            if(1 == isPrime(t->valor))
                pnum++;

            t = t->prox;
    }
    printf("ha %d numeros primos\n ", pnum);
    return 1;
}

int compareStack(Stack *s, Stack *p){
    No *a = s->top;
    No *b = p->top;

    while(a != NULL && b != NULL){
        if(a->valor != b->valor)
            return 0;
        b = b->prox;
        a = a->prox;
    }

    if(a != NULL || b != NULL)
        return 0;

    return 1;
}
void invertStack(Stack * p){
    Stack * temp;
    No * auxi;
    auxi = p->top;
    temp = criar();
    while(auxi != NULL){
        push(temp, auxi->valor);
        auxi = auxi->prox;
    }
    auxi = temp->top;
    printf(" Pilha Invertida: \n");
    while(auxi != NULL){
        printf("\n%d", auxi->valor);
        auxi = auxi->prox;
    }
    LivreStack(temp);
}

int main(){
    Stack * s;
    s = criar();
    No * buscar = NULL;
    printf("Esta pilha esta vazia (0,1) : %d\n", VazioStack(s));
    display(s);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 13);
    push(s, 22);
    push(s, 29);
    push(s, 34);
    Stack *p;
    p = criar();
    push(p, 2);
    push(p, 6);
    push(p, 12);
    push(p, 11);
    push(p, 19);
    push(p, 27);
    push(p, 31);
    printf("Esta pilha esta vazia (0,1) : %d\n", VazioStack(s));
    display(s);
    printf("Buscando elemento:\n");
	buscar = procurar(s, 10);
	if(buscar != NULL){
		printf("O elemento encontrado eh: %d\n", buscar->valor);
	}
    display(s);
    printf("Segunda Pilha:\n");
    display(p);
    if(compareStack(s,p))
        printf("As pilhas sao identicas\n\n");
    else
        printf("As pilhas sao diferentes\n\n");
    if(VerificaStack(s)){
        printf("A pilha esta em ordem crescente! \n");
    }
    else{
        printf("A pilha nao esta em ordem crescente! \n");
    }
    VerificaPrimeStack(s);
    invertStack(s);
    printf("\nRemovendo elemento: %d\n", pop(s));
    printf("Liberando a pilha.\n");

    LivreStack(s);
    return 0;
}
