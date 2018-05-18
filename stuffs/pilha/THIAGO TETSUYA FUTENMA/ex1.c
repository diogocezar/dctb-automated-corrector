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



//implementacao


int verificaOrdem(Stack*s){
	Node*t;
	int v=1;
	//repeticao pra ver se esta em ordem
	for(t=s->top->next ; t!=NULL ; t=t->next){
		Node *x = s->top;
		if(x->value<=t->value && v==1) v=1;
		else v=0;
	}
	
	return v;
	
}


Stack * invertePilha(Stack*p1){
	//cria uma pilha
	Stack * p2 = create();	
	Node * t;
	
	//faz uma repeticao pra inverter a pilha
	for(t=p1->top ; t!=NULL ; t=t->next){	
		Node * new= (Node*) malloc(sizeof(Node));	
		new->value = t->value;
		new->next = p2->top;
		p2->top = new;
	}
	
	return p2;
	
}


int numerosPrimos(Stack * s){
	int i=0;
	
	Node*t;
	for(t=s->top;t!=NULL;t=t->next){
		int x;
		int y=0;
		//faz o loop pra ver se o numero só é divisivel por 1 e por ele mesmo
		//x vai do 2 ate n-1 porque só o 1 e o proprio numero sao divisores de um numero primo
		for(x=2;x<t->value;x++){
			//se for divisivel por outro numero y++
			if(t->value % x == 0) y++;	
		}
		//se o y=0, o numero é primo entao i++;
		if(y==0)i++;		
	}
	
	return i;
	
}

int saoIguais(Stack * s1 , Stack * s2){
	int i=1;
	int qtds1=0;
	int qtds2=0;
	Node *t1;
	Node *t2;
	
	for(t1=s1->top;t1!=NULL;t1=t1->next){
		qtds1++;
	}
	for(t1=s2->top;t1!=NULL;t1=t1->next){
		qtds2++;
	}
	if(qtds1!=qtds2){
		i=0;
		return i;
	} else{
		t1 = s1->top;
		t2 = s2->top;
		while(t1!=NULL){
			if(t1->value == t2->value && i==1) i=1;
			else i=0;
			t1=t1->next;
			t2=t2->next;
		}
		
		
		
	}
	return i;
		
}
	





int main(){
    Stack * s;
    s = create();
    
    Stack * t;
    t = create();
    
    Stack * x;
    
    push(s, 5);
    push(s, 100);
    push(s, 2);
    push(s, 22);
    
    push(t, 5);
    push(t, 100);
    push(t, 2);
    push(t, 22);
    
    display(s);
    display(t);

    
    //implementacao
    //verifica se a pilha esta em ordem
    printf("\n\nA fila esta em ordem: %d\n\n", verificaOrdem(s));
    
    //inverte a pilha s e aloca na x
    x = invertePilha(s);
    
    printf("\n\nInvertendo a fila\n");
    display(x);
    
    //mostra a quantidade de numeros primos em s
    printf("\n\nQuantidade de numeros primos: %d\n", numerosPrimos(s));
    
    //mostra se as pilhas T e S sao iguais (1 = sim, 0 = nao)
    printf("\n\nPilhas T e S sao iguais: %d\n", saoIguais(t,s));
    //mostra se as pilhas X e S sao iguais (1 = sim, 0 = nao)
    printf("\n\nPilhas X e S sao iguais: %d\n", saoIguais(x,s));
    
    
    printf("\n\nLiberando a pilha.\n");
    freeStack(s);
    freeStack(x);
    freeStack(t);
    
    return 0;
}
