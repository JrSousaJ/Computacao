#include<bits/stdc++.h>

using namespace std;
struct no{
	int n;
	struct no *prox;
};

typedef struct
{
	struct no *inicio;
	struct no *fim;
}listaC;

void create(listaC *q)
{
    q->inicio=NULL;
}
bool isEmpty(listaC q)
{
    if (q.inicio==NULL)
        return true;
    return false;
}
void insert(listaC *q, int d)
{
    struct no *aux;
	if (q->inicio == NULL)
	{
		aux= (struct no *) malloc(sizeof(struct no));
		aux->n = d;
		q->inicio = aux;
		q->fim = aux;
		aux->prox = q->inicio;
		return ;
	}
	aux= (struct no *) malloc(sizeof(struct no));
	aux->n = d;
	aux->prox = q->inicio;
	q->fim->prox = aux;
	q->fim = aux;
}

void imprime(listaC q)
{
	struct no *aux;
	if (!isEmpty(q))
	{
		aux = q.inicio;
		if (aux != q.fim)
		{
			do
			{
				printf("%d ", aux->n);
				aux = aux->prox;
			} while (aux != q.inicio);
		}
		else
			printf("%d->NULL ", aux->n);
	}
}

void remover(listaC *q, int d)
{
	struct no *aux, *atual, *anterior;
	if (d == (q->inicio)->n)
	{
		aux = q->inicio;
		if (q->inicio == q->fim)
			q->inicio = NULL;
		else
		{
			q->inicio = q->inicio->prox;
			q->fim->prox = q->inicio;
		}
		free(aux);
		return ;
	}
	else
	{
		anterior = q->inicio;
		atual = (q->inicio)->prox;
		while (atual != q->inicio && atual->n != d)
		{
			anterior = atual; 
			atual = atual->prox;
		}
		if (atual != q->inicio)
		{
			aux = atual;
			anterior->prox = atual->prox;
			free(aux);
		}
	}
}

void insrini(listaC *q, int d){
	struct no *aux;
	aux= (struct no *) malloc(sizeof(struct no));
	
	aux->n = d;
	q->inicio = aux;
	q->fim = aux;
	aux->prox = (q->inicio);
}

void insrfim(listaC *q, int d){
	struct no *aux;
	aux= (struct no *) malloc(sizeof(struct no));
	
	aux->n = d;
	aux->prox = q->inicio;
	q->fim->prox = aux;
	q->fim = aux;
}

void insirmid(listaC *q, int d, int pos){
	int i;
	struct no *aux, *atual, *anterior;
	aux= (struct no *) malloc(sizeof(struct no));
	
	aux->n= d;
	anterior=q->inicio;
	atual=anterior->prox;
	
	for(i=1; i<pos-1; i++){
		atual = atual->prox;
		anterior = anterior->prox;
	}
	aux->prox = atual;
	anterior->prox = aux;
}

void prinp(listaC *q){
	struct no *aux;
	aux= (struct no *) malloc(sizeof(struct no));
	aux = q->inicio;
	printf("Primeiro elemento: %d.\n", aux->n);
}

void prinpu(listaC *q){
	struct no *aux;
	aux= (struct no *) malloc(sizeof(struct no));
	aux = q->fim;
	printf("Ultimo elemento: %d.\n", aux->n);
}

void prinm(listaC *q, int Pos){
	int i;
	struct no *aux;
	aux= (struct no *) malloc(sizeof(struct no));
	aux = q->inicio;
	
	for(i =1; i<Pos; i++){
		aux = aux->prox;
	}
	printf("O elemento eh o: %d.\n", aux->n);
}

int siz(listaC *q){
	int Cont = 1;
	struct no *aux;
	aux= (struct no *) malloc(sizeof(struct no));
	aux = q->inicio;
	
	while(aux->prox != q->inicio){
		Cont++;
		aux = aux->prox;
	}
	return Cont;
}

int som(listaC *q){
	int Cont = 0;
	struct no *aux;
	aux= (struct no *) malloc(sizeof(struct no));
	aux = q->inicio;
	
	do{
		Cont += aux->n;
		aux = aux->prox;
	}while(aux != q->inicio);
	
	return Cont;
}

void copia(listaC *q, listaC *l){
	struct no *aux1, *aux2;
	aux1= (struct no *) malloc(sizeof(struct no));
	aux2= (struct no *) malloc(sizeof(struct no));
	
	aux1 = q->inicio;
	aux2 = aux1;
	l->inicio = aux2;
	aux2 = l->inicio;
	
	do{
		aux1 = aux1->prox;
		aux2 = aux1;
		aux2->n = aux1->n;
	}while(aux1 != q->inicio);
	aux2 = NULL;
}
void invert()
{
	printf("Deu certo nao\n");
}

void concatenar(listaC *q1, listaC *q2){
	struct no *aux1, *aux2;
	aux1= (struct no *) malloc(sizeof(struct no));
	aux2= (struct no *) malloc(sizeof(struct no));
	
	aux2 = q2->inicio;
	do{
		insrfim(q1, aux2->n);
		aux2 = aux2->prox;
	}while(aux2 != q2->inicio);
}




int main()
{	
	int x=1;
	listaC l;
	listaC aux;
	create(&l);
	create(&aux);
	while(x)
	{
		printf("\n1_ Inserir um elemento n no inicio da lista.\n");
		printf("2_ Inserir um elemento n no final da lista.\n");
		printf("3_ Inserir um elemento n no na k-esima posicao da lista.\n");
		printf("4_ Imprimir apenas o primeiro elemento da lista.\n");
		printf("5_ Imprimir apenas o ultimo elemento da lista.\n");
		printf("6_ Imprimir apenas o n-esimo elemento da lista.\n");
		printf("7_ Retornar a quantidade de nos existentes na lista.\n");
		printf("8_ Retornar a soma dos valores dos nos.\n");
		printf("9_ Faca uma funcao que faca a copia de uma lista.\n");
		printf("10_ Faca uma funcao que inverta a ordem dos elementos de uma lista.\n");
		printf("11_ Faca uma funcao que concatene duas listas\n");
		printf("0_ Sair.\n");
		scanf("%d",&x);
		if(x==1)
		{
			int a;scanf("%d",&a);
			insrini(&l,a);
		}
		if(x==2)
		{
			int a;scanf("%d",&a);
			insrfim(&l,a);
		}
		if(x==3)
		{
			int a,x;scanf("%d%d",&a,&x);
			insirmid(&l,a,x);
		}
		if(x==4)
		{
			prinp(&l);
		}
		if(x==5)prinpu(&l);
		if(x==6)
		{
			int x;scanf("%d",&x);
			prinm(&l,x);
		}
		if(x==7)cout << siz(&l) << endl;
		if(x==8)cout << som(&l) << endl;
		if(x==9)copia(&l,&aux);
		if(x==10)invert();
		if(x==11)
		{
			concatenar(&l,&aux);
			imprime(l);
		}
	}
	
	
    return 0;
}
