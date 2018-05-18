#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>



typedef struct Data
{
  int value;
  struct Data *next;
}Data;

typedef struct Stack
{
  Data *top;
}Stack;



Stack* new();
int empty(Stack *myStack);
int pop(Stack *myStack);
void pull(Stack *myStack, int value);
Stack* invert(Stack *myStack);
void print(Stack *myStack);
int checkOrdAsc(Stack *myStack);
int ckeck(Stack *myStack);
int checkIquals(Stack *my1, Stack *my2);

int main(int argc, char const *argv[])
{
  Stack *myStack = new(), *myStack2 = new();
  int i;

  //srand(time(NULL));

  for (i = 1; i < 18; i++) {
    pull(myStack, i);
  }
  for (i = 1; i < 18; i++) {
    pull(myStack2, i);
  }

  if (checkIquals(myStack, myStack2)) {
    printf("Iguais\n");
  }else{
    printf("Diferentes\n");
  }

  print(myStack);

  if (checkOrdAsc(myStack)) {
    printf("Esta em ordem crescente\n");
  }else{
    printf("Esta desordenado\n");
  }

  myStack = invert(myStack);

  print(myStack);

  if (checkOrdAsc(myStack)) {
    printf("Esta em ordem crescente\n");
  }else{
    printf("Esta desordenado\n");
  }
  printf("Quantidade de numeros primos = %d\n", ckeck(myStack));

  return 0;
}


int ckeck(Stack *myStack)
{
  Data *aux = myStack->top;
  int cont = 0, i, check = 0;

  if (aux != NULL)
  {
    while (aux != NULL) {
      check = 0;
      for (i = 1; i <= aux->value; i++) {
        if ((aux->value % i) == 0) {
          check++;
        }
      }
      if (check == 2) {
        printf("Primo %d\n", aux->value);
        cont++;
      }
      aux = aux->next;
    }
    return cont;
  }else
  {
    printf("Pilha vazia\n");
  }
  return 0;
}

int checkIquals(Stack *my1, Stack *my2)
{
  int cont = 0;
  Data *aux1 = my1->top, *aux2 = my2->top;

  while (aux1 != NULL && aux2 != NULL) {
    if (aux1->value == aux2->value) {
      cont = 1;
    }else{
      cont = 0;
      break;
    }
    aux1 = aux1->next;
    aux2 = aux2->next;
  }
  return cont;
}


Stack* new()
{
  Stack *new = malloc(sizeof(Stack));
  new->top = NULL;
  return new;
}

void pull(Stack *myStack, int value)
{
  Data *new = malloc(sizeof(Data));
  new->value = value;
  new->next = myStack->top;
  myStack->top = new;
}

int empty(Stack *myStack)
{
  return (myStack->top == NULL);
}


void print(Stack *myStack)
{
  Data *aux;

  printf("Impressao: ");
  for (aux = myStack->top; aux != NULL; aux = aux->next) {
    printf("[%d] ", aux->value);
  }
  printf("\n");
}

int pop(Stack *myStack)
{
  int value;
  Data *aux;
  if (empty(myStack))
  {
    printf("Pilha vazia\n");
  }else
  {
    value = myStack->top->value;
    aux = myStack->top;
    myStack->top = aux->next;
    free(aux);
    return value;
  }
  return 0;
}

int checkOrdAsc(Stack *myStack)
{
  int check = 0;
  Data *aux;

  for (aux = myStack->top; aux->next != NULL; aux = aux->next) {
    if (aux->value < aux->next->value && aux->next != NULL) {
      check = 1;
    }else{
      check = 0;
      break;
    }
  }
  return check;
}

Stack* invert(Stack *myStack)
{
  Stack *aux = myStack, *myStack2 = new();
  printf("Invertendo\n");
  for (aux = myStack; !empty(aux); aux->top = aux->top->next) {
    pull(myStack2, aux->top->value);
  }
  return myStack2;
}
