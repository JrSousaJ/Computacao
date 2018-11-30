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
    struct no *fim;
}listac;

void create(listac *l)
{
    siz=0;
    l->inicio=NULL;
}
bool Empty(listac q)
{
    if(q.inicio==NULL)return true;
    return false;
}
void inserir(listac *q,int d)
{
    struct no *aux;
    if(q->inicio == NULL)
    {
    	aux= (struct no *) malloc(sizeof(struct no));
    	aux->n=d;
    	q->inicio=aux;
    	q->fim=aux;
    	aux->prox=q->inicio;
    	siz++;
    	return ;
    }
   aux= (struct no *) malloc(sizeof(struct no));
   aux->n=d;
   aux->prox=q->inicio;
   q->fim->prox=aux;
   q->fim=aux;
    siz++;
}

void remover(listac *q,int d)
{
    struct no *aux, *atual, *anterior;
   	if(d==(q->inicio)->n)
   	{
   		aux=q->inicio;
   		if(q->inicio==q->fim)q->inicio = NULL;

   
	   	else
	   	{
	   		q->inicio = q->inicio->prox;
	   		q->fim->prox=q->inicio;
	   	}
   		free(aux);
   }
   else 
   {
   		anterior=q->inicio;
   		atual=q->inicio->prox;
   		while(atual!=q->inicio && atual->n !=d)
   		{
   			anterior=atual;
   			atual=atual->prox;
   		}
   		if(atual!=q->inicio)
   		{
   			aux=atual;
   			anterior->prox=atual->prox;
   			free(aux);
   		}
   }
    siz--;
} 
void print(listac l)
{
    struct no *aux;
    
    if(!Empty(l))
    {
    	aux= l.inicio;
        if(aux!=l.fim)
        {
        	do
        	{
        		printf("%d->%d ",aux->n,aux->prox->n);
        		aux=aux->prox;
        	}while(aux!=l.inicio);
        }
        else printf("%d->NULL ",aux->n);
    }
}
void rodar(listac q, int pulo)
{
	struct no *aux;
	if(!Empty(q))
	{
		aux=q.inicio;
		if(siz==1)
		{
			printf("%d\n",aux->n);
			return ;
		}
		while(siz>1)
		{
			for(int i=1;i<pulo;i++)aux=aux->prox;
			//print(q);
			remover(&q,aux->n);
			aux=aux->prox;	
		}
	}
	printf("%d\n",aux->n);
}
int main()
{
	listac q;
	create(&q);
	int x;scanf("%d",&x);
	while(x--)
	{
		create(&q);
		int n,n2;scanf("%d%d",&n,&n2);
		for(int i=1;i<=n;i++)inserir(&q,i);
		rodar(q,n2);
	}
}
