#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#define SIZE 6 //Quantidade de opções do Menu 

typedef struct Node
{
	int value;
	struct Node *next;
} Node;

typedef struct Stack
{
	Node *top;
} Stack;

int dir();
int menu();
void returnMenu();

Stack * create()
{
	Stack * q = (Stack*) malloc(sizeof(Stack));
	q->top = NULL;
	return q;
}

void push(Stack * s, int value)
{
	Node * New = (Node*) malloc(sizeof(Node));
	New->value = value;
	New->next = s->top;
	s->top = New;
}

int isEmptyStack(Stack * s)
{
	return(s->top == NULL);
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

int check(Stack *s)
{
	if(isEmptyStack(s))
	{
		printf("A pilha está vazia!\n");
	}
	Node *p = s->top;
	int larger = s->top->value;
	while(p != NULL)
	{
		if(larger < p->value)
		{
			return 1;
		}
		p = p->next;
	}
	return 0;
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

int checkEqual(Stack *s, Stack *s1)
{
	if(isEmptyStack(s)||isEmptyStack(s1))
	{
		printf("\nPilha já vazia!\n");
		return 0;
	}
	Node *p = s->top;
	Node *p1 = s1->top;

	while(p != NULL)
	{
		if(p->value != p1->value)
			return 1;
		p = p->next;
		p1 = p1->next;
	}
	return 0;
}

int countPrime(Stack *s)
{
	if(isEmptyStack(s))
	{
		printf("\nPilha já vazia!\n");
		return 0;
	}
	Node *p = s->top;
	int Prime = 0;
	while(p != NULL)
	{
		if(p->value % 2 == 0)
		{
			Prime += 1;
		}
		p = p->next;
	}
	return Prime;
}

Stack * invertStack(Stack *s)
{
	if(isEmptyStack(s))
	{
		printf("\nPilha já vazia!\n");
		return 0;
	}
	Node *p = s->top;
	Stack *s1;
	s1 = create();
	while(p != NULL)
	{
		push(s1, p->value);
		p = p->next;
	}
	return s1;
}

int main(int argc, char** argv)
{
	Stack *s, *s2;
	s = create();
	s2 = create();
	int asw, i = 0, num = 0;
	setlocale(LC_ALL, "Portuguese");
	do
	{
		asw = menu();
		switch(asw)
		{
		case 1:
			system("cls");
			printf("Deseja inserir um valor em qual pilha:");
			printf("\n<1> - Pilha 1\n<2> - Pilha 2\n\n--> ");
			scanf("%d", &i);
			if(i == 1)
			{
				system("cls");
				printf("Digite o valor a ser inserido na Pilha 1: ");
				scanf("%d", &num);
				push(s, num);
			}
			else
			{
				system("cls");
				printf("Digite o valor a ser inserido na Pilha 2: ");
				scanf("%d", &num);
				push(s2, num);
			}
			printf("\n\n\nValor inserido com sucesso!!\n\n");
			returnMenu();
			break;
		case 2:
			system("cls");
			printf("Deseja printar qual pilha:");
			printf("\n<1> - Pilha 1\n<2> - Pilha 2\n\n--> ");
			scanf("%d", &i);
			if(i == 1)
			{
				system("cls");
				display(s);
			}
			else
			{
				system("cls");
				display(s2);
			}
			returnMenu();
			break;
		case 3:
			system("cls");
			printf("Deseja verificar a ordenação de qual pilha:");
			printf("\n<1> - Pilha 1\n<2> - Pilha 2\n\n--> ");
			scanf("%d", &i);
			if(i == 1)
			{
				if(check(s) == 1)
				{
					printf("Pilha não ordenada de forma crescente");
				}
				else
				{
					printf("Pilha ordenada de forma crescente");
				}
			}
			else
			{
				system("cls");
				if(check(s2) == 1)
				{
					printf("Pilha não ordenada de forma crescente");
				}
				else
				{
					printf("Pilha ordenada de forma crescente");
				}
			}
			returnMenu();
			break;
		case 4:
			system("cls");
			if(checkEqual(s, s2) == 0)
			{
				printf("As duas pilhas são iguais");
			}
			else
			{
				printf("As duas pilhas são diferentes");
			}
			returnMenu();
			break;
		case 5:
			system("cls");
			printf("Deseja printar qual pilha:");
			printf("\n<1> - Pilha 1\n<2> - Pilha 2\n\n--> ");
			scanf("%d", &i);
			if(i == 1)
			{
				system("cls");
				printf("A pilha contém %d números primos", countPrime(s));
			}
			else
			{
				system("cls");
				printf("A pilha contém %d números primos", countPrime(s2));
			}
			returnMenu();
			break;
		case 6:
			system("cls");
			printf("Deseja inverter os valores de qual pilha:");
			printf("\n<1> - Pilha 1\n<2> - Pilha 2\n\n--> ");
			scanf("%d", &i);
			if(i == 1)
			{
				system("cls");
				s = invertStack(s);
				printf("Pilha invertida com suvesso!!!");
			}
			else
			{
				system("cls");
				s2 = invertStack(s2);
				printf("Pilha invertida com suvesso!!!");
			}
			returnMenu();
			break;
		}
	}
	while(asw != 7);

	return 0;
}

int dir()
{
	int i;
	do
	{
		i = getch();
	}
	while(i != 72 && i != 80 && i != 13);
	return i;
}


int menu()
{
	char frase[SIZE][100] = {("Inserir"), ("Printar Pilha"), ("Verificar ordenação"),
							 ("Verificar se duas pilhas são iguais"), ("Contar números primos"),
							 ("Inverter valores da pilha")
							};

	char seta[2][4] = {("   "), (">")};
	int aux[SIZE] = {(0), (0)};
	int i = 0, j = 0, k;

	aux[0] = 1;
	do
	{
		system("cls");
		printf("\n\n\n\n\n\n");
		printf("\t\t----------------------------------------------------\n");
		printf("\t\t----------------------------------------------------\n");
		printf("\t\t%s  %s\n", seta[aux[0]], frase[0]);
		printf("\t\t%s  %s\n", seta[aux[1]], frase[1]);
		printf("\t\t%s  %s\n", seta[aux[2]], frase[2]);
		printf("\t\t%s  %s\n", seta[aux[3]], frase[3]);
		printf("\t\t%s  %s\n", seta[aux[4]], frase[4]);
		printf("\t\t%s  %s\n", seta[aux[5]], frase[5]);
		printf("\t\t----------------------------------------------------\n");
		printf("\t\t----------------------------------------------------\n");
		i = dir();
		if(i == 72)
		{
			if(j == 0)
			{
				j = (SIZE - 1);
			}
			else
			{
				j--;
			}
		}

		if(i == 80)
		{
			if(j == (SIZE - 1))
			{
				j = 0;
			}
			else
			{
				j++;
			}
		}

		for(k = 0; k < SIZE; k++)
		{
			aux[k] = 0;
		}
		aux[j] = 1;
	}
	while(i != 13);
	return j + 1;
}

void returnMenu()
{
	printf("\n\nAperte qualquer tecla para retornar ao menu . . .");
	getch();
}
