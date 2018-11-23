#include<bits/stdc++.h>

using namespace std;
int siz=0;
int x,c;
struct no
{
    int n;
    struct no *prox;
    struct no *ant;
};
typedef struct
{
    struct no *inicio;
    struct no *fim;
}lista;
void create(lista *l)
{
    siz=0;
    l->inicio=NULL;
    l->fim=NULL;
}
bool Empty(lista q)
{
    if(q.inicio==NULL)return true;
    return false;
}
void inserir(lista *q,int d)
{
    struct no *aux,*anterior;

    if(q->inicio == NULL)
    {
        aux=(struct no*)malloc(sizeof(struct no));
        aux->n=d;
        q->inicio=aux;
        q->fim=aux;
        aux->prox=NULL;
        aux->ant=NULL;
        siz++;
        return ;
    }
    aux=(struct no*)malloc(sizeof(struct no));
    aux->n=d;
    aux->prox=NULL;
    aux->ant=q->fim;
    q->fim->prox=aux;
    q->fim=aux;
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
void remover(lista *q,int d)
{
    struct no *aux, *atual, *anterior;
    if(d==(q->inicio)->n)
    {
        aux=q->inicio;
       if(q->inicio->prox==NULL)
       {
            q->inicio=NULL;
            q->fim=NULL;
       }
       else
       {
        q->inicio = aux->prox;
        q->inicio=ant=aux->ant;
       }
        free(aux);
    }
    else
    {
        anterior = q->inicio;
        atual=(q->inicio)->prox;
        while(atual!=NULL && atual->dado!=d)
        {
            anterior = atual;
            atual = atual->prox;
        }
        if(atual!=NULL)
        {
            aux= atual;
            anterior->prox = atual->prox;
            atual->prox->ant=atual->ant;
            if(atual->prox==NULL)
            {
                anterior->prox=NULL;
                q->fim=anterior;
            }
            free(aux);
        }
    }
    siz--;
}
void reverter(lista *q)
{
	


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
