
typedef struct Node{
  int value;
  struct Node * next;
} Node;

typedef struct Stack{
  Node* top;
} Stack;

//==============================================================================

Stack * create(){
  Stack * q = (Stack*) malloc(sizeof(Stack));
  q->top = NULL;
  return q;
}
//==============================================================================
void push(Stack * s, int value){
  Node * new = (Node*) malloc(sizeof(Node));
  new->value = value;
  new->next = s->top;
  s->top = new;
}
//==============================================================================
int isEmptyStack(Stack * s){
  return(s->top == NULL);
}
//==============================================================================
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
//==============================================================================
Node * search(Stack * s, int value){
  Node * p;
  for(p = s->top; p != NULL; p = p->next){
    if(p->value == value)
    return p;
  }
  return NULL;
}
//==============================================================================
int pop(Stack * s){
  Node * t = s->top;
  int v;
  if(isEmptyStack(s)){
    printf("\nPilha já vazia!\n");
  }else{
    t = s->top;
    v = t->value;
    s->top = t->next;
    free(t);
    return v;
  }
}
//==============================================================================

int order(Stack* s){

  int p;
  Node* aux = s->top;

  for(aux = s->top;aux != NULL;aux = aux->next){
    if(aux->value < aux->next){
      p = 1;
    }else{
      p = 0;
    }
  }
  return p;
}

//==============================================================================

Stack* print_Inverted(Stack* s, Stack* pull){

Stack* aux = s;

  for(aux = s;(!isEmptyStack(aux));aux->top = aux->top->next){
    push(pull,aux->top->value);
  }
  return pull;


}


//==============================================================================

int cousin(Stack* s){

  Node* aux = s->top;
  int i,cont,c = 0;

  do{
cont = 0;
    for(i = 1;i <= aux->value;){
      if(aux->value % i == 0){
        cont++;
        i++;

      }else{
        i++;
      }
    }
    if(cont == 2){
      c++;
    }
    aux = aux->next;

  }while(aux != NULL);
return c;
}

//==============================================================================

int compare(Stack* s, Stack* s2){

  int cont;
  Node* aux = s->top;
  Node* aux2 = s2->top;

  if(isEmptyStack(s)){
    printf("\nPilha vazia\n");
  }

  for(aux = s->top;aux != NULL;aux = aux->next){
    for(aux2 = s2->top;aux2 != NULL;aux2 = aux2->next){
      if(aux->value == aux2->value){
        cont = 1;
      }else if(aux < aux2 || aux > aux2){
        cont = 0;
        }
    }
  }
  return cont;
}
