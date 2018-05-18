/*
 * autor..: EDUARDO DOS SANTOS SPAGNA
 * disc...: ESTRUTURA DE DADOS
 *
 * PILHA
 */

#include <stdio.h> 	
#include <locale.h>
#include <stdlib.h>

typedef struct Idade{
	int idade;
	struct Idade * prox;
} Idade;

typedef struct Pilha{
	Idade * topo;
} Pilha;

Pilha* criar()
{
	Pilha* q = (Pilha*) malloc(sizeof(Pilha));
	q->topo = NULL;
	return q;
}

void inserir(Pilha* p, int idade)
{
	Idade *new = (Idade*) malloc(sizeof(Idade));
	new->idade = idade;
	new->prox = p->topo;
	p->topo = new;
}

int pilhaVazia(Pilha* p){
    return(p->topo == NULL);
}

void imprimir(Pilha * p)
{
	Idade * s;
	s = p->topo;
	
	if(pilhaVazia(p)){
		printf("Esta fila está vazia!\n");
	}
	else{
		while(s != NULL){
			printf("Idade.: %d\n", s->idade);
			s = s->prox;
		}
	}
}

Idade* buscar(Pilha* p, int idade)
{
    Idade* s;
    for(s = p->topo; s != NULL; s = s->prox){
        if(s->idade == idade)
            return s;
    }
    return NULL;
}

int remover(Pilha *p)
{
   Idade * t;
   int v;
   if(pilhaVazia(p)){
      printf("\nPilha já vazia!\n");
      return 0;
   }
   t = p->topo;
   v = t->idade;
   p->topo = t->prox;
   free(t);
   return v;
}

void liberarPilha(Pilha *p)
{
	Idade *s = p->topo;
	while(s != NULL){
		Idade *t = s->prox;
		free(s);
		s = t;
    }
    free(s);
    printf("\nPilha liberada...");
}

int PilhaOrdenada(Pilha* p)
{
	Idade* s;
	s = p->topo;
	if(pilhaVazia(p)){
		printf("Esta pilha está vazia!\n");
	}
	else{
		while(s->prox != NULL){
			if(s->idade > s->prox->idade)
				return 0;
			s = s->prox;
		}
	}
	return 1;	
}

int verifPrimo(int num)
{
    int i;
	int valor;
	int vzs = 0;
	
    for (i = 1; i <= num && vzs <= 3; i++)               
    {    
        if (num % i == 0 || num == 2)
        	vzs ++;
    }
    
    if(vzs == 2)
    	return 1;

    else  
     	return 0;
}

int contaNumPrimos(Pilha* p)
{
	Idade* s;
	int contPrimos = 0;
	int primo = 0;	
	s = p->topo;
	
	if(pilhaVazia(p)){
		printf("Esta pilha está vazia!\n");
	}
	else{
		while(s->prox != NULL){
			primo = verifPrimo(s->idade);
			if(primo == 1)
				contPrimos++;
			s = s->prox;
		}
	}
	return contPrimos;	
}

void comparaPilhas(Pilha* p1, Pilha* p2)
{
	if(pilhaVazia(p1) && pilhaVazia(p2)){
		printf("\n\nAs pilhas já estao vazias!\n");
		return;
	}
	
	Idade* k1 = p1->topo;
	Idade* k2 = p2->topo;
	
	if(k1->idade == k2->idade){
		if(k1->prox == NULL && k2->prox == NULL){
			printf("\n\nAs filas sao iguais!\n\n");
			return;
		}
		
		p1->topo = k1->prox;
		p2->topo = k2->prox;
		comparaPilhas(p1, p2);
	}
	else
		printf("\n\nAs pilhas não são iguais!\n\n");
}

Pilha* imprimirInvertido(Pilha* p)
{
	Pilha* aux = criar();
	Idade* s = p->topo;

	while(!pilhaVazia(p))
		inserir(aux, remover(p));
		
	return aux;
}

int main()
{
	setlocale(LC_ALL,"portuguese");
	
	Pilha *p;
	Pilha *p2;
	Pilha *aux;
	Idade *k;
	
	p = criar();
	p2 = criar();
	aux = criar();
	
	Idade *buscarIdade = NULL;
	
	printf("A pilha 1 está vazia (0,1) : %d\n", pilhaVazia(p));
	printf("A pilha 2 está vazia (0,1) : %d\n", pilhaVazia(p2));
	
	printf("\nInserindo elementos...\n");
	
	inserir(p, 82);
	inserir(p, 71);
	inserir(p, 35);
	inserir(p, 5);
	inserir(p, 2);
	
	inserir(p2, 0); 
	inserir(p2, 73);
	inserir(p2, 5); 
	inserir(p2, 6); 
	inserir(p2, 1);
	
	printf("\n===== Pilha 1 =====\n\n");
	imprimir(p);
	printf("\n===== Pilha 2 =====\n\n");
	imprimir(p2);
	
	printf("\n\nA pilha 1 está vazia (0,1) : %d\n", pilhaVazia(p));
	printf("A pilha 2 está vazia (0,1) : %d\n", pilhaVazia(p2));	
	
	printf("\n\nBuscando elemento:\n");
	buscarIdade = buscar(p, 35);
	if(buscarIdade != NULL){
		printf("\tEncontrou o elemento: %d\n", buscarIdade->idade);
	}	
		
	printf("\n\nA pilha 1 está ordenada (0,1) : %d\n", PilhaOrdenada(p));
	printf("A pilha 2 está ordenada (0,1) : %d\n", PilhaOrdenada(p2));
	
		
	printf("\n\nQuantidade de números primos na pilha 1..: %d\n", contaNumPrimos(p));
	printf("Quantidade de números primos na pilha 2..: %d\n", contaNumPrimos(p2));
	
	printf("\nRemovendo elemento: %d\n\n", remover(p));
	
	imprimir(p);
	
	comparaPilhas(p, p2);
	
	printf("\n===== PILHA 1 INVERTIDA =====\n\n");	
	aux = imprimirInvertido(p);
	imprimir(aux);	
	
	liberarPilha(aux);
	liberarPilha(p2);
}
