/* Atividade: T15 - Pilhas
 * Aluno: Eduardo Quintanilha
 * Disciplina: Estrutura de Dados
 * Data: 14/05/2018
*/

#include <stdlib.h>
#include <stdio.h>

#define MAX 10

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

/* 1. implemente uma função que verifica se os elementos de uma pilha estão ordenados de forma crescente; */
int isCrescentOrdened(Stack * s){
    Node * p = s->top;
    Node * aux = p->next;
    int ordened = 1;
    if(!isEmptyStack(s)){
        while(ordened == 1 && aux != NULL){
            if(aux->value <= p->value){
                p = p->next;
                aux = p->next;
            }else{
                ordened = 0;
            }
        }
    }else{
        printf("A pilha está vazia!");
        ordened = 0;
    }
    return ordened;
}

/*
 * 2. faça uma função que receba uma Pilha P1 e retorne P1 com os elementos invertidos;
 * 
 */
Stack * invertStack(Stack* s){
    Node* aux = s->top;
    //aux = aux->next;
    Stack* stackAux;
    stackAux = create();
    Node* nodeAux = stackAux->top;

    if(isEmptyStack(s)){
        printf("Pilha está vazia!");
        return NULL;
    }else{
        while(aux != NULL){
            push(stackAux, aux->value);
            aux = aux->next;
        }
        s->top = stackAux->top;         
        return(s);
    }    
}

/*
 * 3. construa uma função que retorne a quantidade de números primos em uma pilha;
 */ 
int quantyPrime(Stack* s){
    Node* aux = s->top;
    int quant = 0;
    while(aux != NULL){
        int q = 0;        
        
        for(int i=1; i <= aux->value; i++){
            if(aux->value % i == 0){
                q+=1;
                //printf("%d é divisivel por %d\n",aux->value,i);
            }
        }
        if(q == 2){
            quant += 1;
            printf("---> %d É primo!\n",aux->value);
        }else{
            printf("---> %d NÃO É primo!\n",aux->value);
        }
        aux = aux->next;
        }
    return(quant);
    }

/*
 * 4. implemente uma função que verifique se duas pilhas são iguais;
 * 
 */
int isEquals(Stack* s1, Stack* s2){
    Node * aux1 = s1->top;
    Node * aux2 = s2->top;
    int equal = 1;

    if(isEmptyStack(s1) || isEmptyStack(s2)){
        printf("Pilhas vazias!");
        return 0;
    }else{
        while(aux1 != NULL && aux2 != NULL && equal == 1){
            if(aux1->value != aux2->value){
                equal = 0;
            }
            aux1 = aux1->next;
            aux2 = aux2->next;
        }
    }
    return equal;
}

/* Função principal com os testes das funções implementadas
 *
 */
void main(){
    Stack * s;
    s = create();
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 11);
    push(s, 13);

    Stack * s2;
    s2 = create();
    push(s2, 1);
    push(s2, 2);
    push(s2, 3);
    push(s2, 4);
    push(s2, 5);
    push(s2, 6);
    push(s2, 7);
    push(s2, 8);
    push(s2, 9);
    push(s2, 11);
    push(s2, 13);

    printf("\nPilha inserida: \n");
    display(s);

    printf("\nVerificando se a pilha está ordenada (0 = False | 1 = True) --> %d\n",isCrescentOrdened(s));

    printf("\nPilha sem inversão: \n");
    display(s);

   
    s = invertStack(s);
    printf("\nPilha invertida: \n");
    display(s);
    //display(s);

    int q = quantyPrime(s);// Cria pilha 2
    s2 = invertStack(s2);//Inverte pilha 2 para ficar igual a pilha 1
    printf("\nQuantidade de Primos da pilha => %d\n\n", q);

    if(isEquals(s, s2)){
        printf("\nPilha 1 é igual a Pilha 2 \n");
    }else{
        printf("\nPilha 1 não é igual a Pilha 2\n");
    }
    

}