#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

typedef struct Node
{
	int value;
	struct Node * next;
} Node;

typedef struct Stack
{
	Node * top;
} Stack;


int OrdVerify(Stack *s)
{
	Node *p;
	p = s->top;
	while (p->next != NULL)
	{
		if ((p->value > p->next->value))
		{
			return 1;
		}
		p = p->next;
	}
	return 0;
}

Stack * create()
{
	Stack * q = (Stack*) malloc(sizeof(Stack));
	q->top = NULL;
	return q;
}

int verPrime(int value) {
	int i = 0;
	for (i = 1; i < value-1; i++)
	{
		if (value % i == 0)
		{
			return 1;
		}
	}
	return 0;
}

int CountPrimes(Stack *s)
{
	int count = 0;
	Node *p = s->top;
	while (p != NULL)
	{
		if (verPrime (p->value) == 0)
		{
			count ++;
		}
		p = p-> next;
	}
	return count;
}



void push(Stack * s, int value)
{
	Node * new = (Node*) malloc(sizeof(Node));
	new->value = value;
	new->next = s->top;
	s->top = new;
}

Stack * invert (Stack *s)
{
	Node *p = s->top;
	Stack *j = create();

	while (p != NULL)
	{
		push(j, p->value);
		p = p->next;
	}

	return j;
}

int isEmptyStack(Stack * s)
{
	return(s->top == NULL);
}

void display(Stack * s)
{
	Node * p = s->top;
	if(isEmptyStack(s))
	{
		printf("A pilha está vazia!\n");
	}
	else
	{
		while(p != NULL)
		{
			printf("%d\n", p->value);
			p = p->next;
		}
	}
}

Node * search(Stack * s, int value)
{
	Node * p;
	for(p = s->top; p != NULL; p = p->next)
	{
		if(p->value == value)
			return p;
	}
	return NULL;
}
int CompareStacks (Stack *s, Stack *r) {
	Node *p = s->top;
	Node *q = r->top;
	while (p != NULL) {
		if (p->value != q->value) {
			return 0;
		}
		p = p->next;
		q = q->next;
	}
	return 1;
}
void freeStack(Stack * s)
{
	Node * p = s->top;
	while(p != NULL)
	{
		Node * t = p->next;
		free(p);
		p = t;
	}
	free(p);
}

int pop(Stack * s)
{
	Node * t;
	int v;
	if(isEmptyStack(s))
	{
		printf("\nPilha já vazia!\n");
		return 0;
	}
	t = s->top;
	v = t->value;
	s->top = t->next;
	free(t);
	return v;
}
int main()
{
	Stack * s, *r;
	setlocale(LC_ALL, "portuguese");
	s = create();
	printf("A pilha está vazia (0,1) : %d\n", isEmptyStack(s));
	display(s);

	push(s, 3);
	push(s, 2);
	push(s, 1);
	
	
	push(r, 3);
	push(r, 2);
	push(r, 1);

	printf("TOPO:  %d\n", s->top->value);
	if (OrdVerify(s) == 1)
	{
		printf("Não está ordenado.");
	}
	else
	{
		printf("Está ordenado");
	}

	
		if (CompareStacks(s,r) == 1) {
		printf("\nElas são iguais");
	} else {
		printf("\nElas são diferentes");
	}
	s = invert(s);
	printf("\n\nInvertido:\n");
	display(s);
	return 0;
}
