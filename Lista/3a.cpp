#include<bits/stdc++.h>

using namespace std;
int siz=0;
int x,c;
struct no
{
    int n;
    struct no *prox;
};
typedef struct
{
    struct no *inicio;
}lista;
void create(lista *l)
{
    siz=0;
    l->inicio=NULL;
}
bool Empty(lista q)
{
    if(q.inicio==NULL)return true;
    return false;
}
void inserir(lista *q,int d)
{
    struct no *aux, *atual, *anterior;

    aux=(struct no *)malloc(sizeof(struct no));
    if(aux!=NULL)
    {
        aux->n = d;
        aux->prox=NULL;
        anterior=NULL;
        atual=q->inicio;
        int c=0;
        while(atual!=NULL  && d > atual->n)
        {
            anterior= atual;
            atual = atual->prox;
        }
        if(anterior == NULL)
        {
            aux->prox = q->inicio;
            q->inicio = aux;
        }
        else
        {
            anterior->prox=aux;
            aux->prox=atual;
        }
    }
    siz++;
}
void print(lista l)
{
    struct no *aux;
    aux= l.inicio;
    if(!Empty(l))
    {
        while(aux!=NULL)
        {
            printf("%d\n",aux->n);
            aux=aux->prox;
        }
    }
}
void remover(lista *q,int pos)
{
    struct no *aux, *atual, *anterior;
    if(pos==0)
    {
        aux=q->inicio;
        cout << aux->n << endl;
      
        q->inicio = (q->inicio)->prox;
        free(aux);
    }
    else
    {
        anterior = q->inicio;
        atual=(q->inicio)->prox;
        while(atual!=NULL)
        {
        	if(!pos)break;
            anterior = atual;
            atual = atual->prox;
        }
        if(atual!=NULL)
        {

            aux= atual;
            
            anterior->prox = atual->prox;
            free(aux);
        }
    }
    siz--;
}
int busca(lista q,int val)
{
	struct no *aux;
	aux=q.inicio;
	if(!Empty(q))
    {
        while(aux!=NULL && val--)
        {
        	if(!val)return aux->n;
        	aux=aux->prox;
        }
    }
    printf("Nao encontrado\n");
}
void reverter(lista *q)
{
	struct no *aux,*aux2,*t;
	aux=NULL;
	aux2=q->inicio;
	t=aux2->prox;
	while(aux2!=NULL)
	{
		aux2->prox=aux;
		aux=aux2;
		aux2=t;
		if(t!=NULL)
		{
			t=t->prox;
		}
	}
	t=q->inicio;
	t->prox=NULL;
	q->inicio=t;
}
int main()
{
	lista q;
	create(&q);
	printf("Deseja inserir quantos numeros? \n");
	scanf("%d",&x);
	c=x;
	for(int i=0;i<x;i++)
	{
		int a;scanf("%d",&a);
		inserir(&q,a);
	}
	printf("**Lista antes de inverter**\n");
	print(q);
	printf("\n**Lista depois de inverter**\n");
	reverter(&q);
	print(q);
}
