#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int v;
    struct Node *next;
}Node;

typedef struct Stack {
    Node *top;
    int size;
}Stack;


Stack * create () {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

void push (Stack *s, int e) {
    Node * n = (Node *) malloc(sizeof(Node));
    n->v = e;
    n->next = s->top;
    s->top = n;
    s->size +=1;
}

void display (Stack *s) {

    Node *tmp = s->top;
    if (tmp != NULL ) {
        while (tmp != NULL) {
            printf("[%d]\n", tmp->v);
            tmp = tmp->next;
        }
    } else {
        printf("Empty Stack");
    }

}

int isEmptyStack(Stack *s) {
    return (s->top == NULL);
}

int search (Stack *s, int v) {
    Node *tmp;

    for (tmp = s->top; tmp != NULL; tmp = tmp->next){
        if (tmp->v == v) {
            return v;
        }
    }

    return 0;
}

int pop (Stack *s) {
    if (!isEmptyStack(s)) {
        Node * tmp = s->top;
        int v = tmp->v;
        s->top = tmp->next;
        s->size -=1;
        free(tmp);
        return v;
    } else {
        printf("\nEmpty Stack\n");
        return -1;
    }
}

int growingStack (Stack *s) {
    Node *tmp = s->top;
    if (tmp != NULL ) {
        while (tmp->next != NULL) {
            if (tmp->v > tmp->next->v) 
                return 0;
            tmp = tmp->next;
        }

        return 1;
    } else {
        printf("\nEmpty Stack\n");
        return -1;;
    }
}

Stack * inverse (Stack *s) {
    Node *tmp = s->top;
    Stack *inverse = create();

    if (tmp != NULL ) {
        while (tmp != NULL) {
            push(inverse, tmp->v);
            tmp = tmp->next;
        }
        return inverse;
    } else {
        printf("Empty Stack");
    }
}

int itsPrime (int n) {
    int ct = 1;
    for (int i = 2; i < n; i++) {
        if ((n%i) == 0)
            ct = 0;
    }
    return ct;
}

int amountPrimeNumbersOnStack (Stack *s) { // hue 
    Node *tmp = s->top;
    int amount = 0;
    if (tmp != NULL ) {
        while (tmp->next != NULL) {
            if (itsPrime(tmp->v) == 1) 
                amount += 1;
            tmp = tmp->next;
        }
        return amount;
    } else {
        printf("\nEmpty Stack\n");
        return -1;
    }
}

int equalStacks (Stack *s, Stack *s_1) {

    if (!isEmptyStack(s) && !isEmptyStack(s_1) && s->size == s_1->size) {
        Node *tmp = s->top;
        Node *tmp_1 = s_1->top;
        int ct = 0;
        while (tmp != NULL) {
            if (tmp->v == tmp_1->v)
                ct +=1;
            tmp = tmp->next;
            tmp_1 = tmp_1->next;
        }
        return (ct == s->size)?1:0;
    } else 
        return 0;
}