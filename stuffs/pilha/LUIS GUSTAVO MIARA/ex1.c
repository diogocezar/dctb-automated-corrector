#include<stdio.h>
#include<stdlib.h>
/*
* Estrutura da pilha
*/
typedef struct Node
{
    int value;
    struct Node * next;
} Node;

typedef struct Stack
{
    Node * top;
} Stack;


/*
* Metódos para manipulação da pilha
*/

Stack * create()
{
    Stack * q = (Stack*) malloc(sizeof(Stack));
    q->top = NULL;
    return q;
}

void push(Stack * s, int value)
{
    Node * new = (Node*) malloc(sizeof(Node));
    new->value = value;
    new->next = s->top;
    s->top = new;
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
    for(p=s->top; p!=NULL; p=p->next)
    {
        if(p->value == value)
            return p;
    }
    return NULL;
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

int ordenate(Stack * s)
{
    Node * p;
    int aux = 0;
    for(p=s->top; p!=NULL; p=p->next)
    {
        if(p->next != NULL && p->value < p->next->value)
        {
            aux++;
        }
    }
    return aux;
}

int primeNumber(Stack * s)
{
    Node * p = s->top;
    int primeNumber = 0;
    int div = 0;
    while(p != NULL)
    {
        for (int i = 1; i <= p->value; i++)
        {
            if (p->value % i == 0)
            {
                div++;
            }
        }

        if (div == 2)
        {
            printf("O número %d é primo!\n", p->value);
            primeNumber++;
        }
        else
        {
            printf("O número %d não é primo!\n", p->value);
        }

        div = 0;
        p = p->next;
    }
    return primeNumber;
}

int stackEquals(Stack * s1, Stack * s2)
{
    Node * p1 = s1->top;
    Node * p2 = s2->top;
    int aux = 0;
    while(p1 != NULL && p2 != NULL)
    {
        if(p1->value != p2->value){
            aux++;
        }
        p1=p1->next;
        p2=p2->next;
    }

    if(p1 != NULL || p2 != NULL)
    {
        aux++;
    }
    return aux;
}
Stack * invertStack(Stack * s1)
{
    Node * p1 = s1->top;
    Stack * s2;
    s2 = create();
    int i = 0;

    //int v = pop(s1);
    while(s1->top != NULL){
        push(s2, pop(s1));
    }

    return s2;
}

