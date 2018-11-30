#include<bits/stdc++.h>

using namespace std;
int siz=0;
int x,c;
typedef struct  
{
	int nom;
	int id;
}engrenagens;
struct no
{
   	engrenagens n;
   	struct no *ant;
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
void inserir(listac *q,engrenagens d)
{
    struct no *aux;
    if(q->inicio == NULL)
    {
    	aux= (struct no *) malloc(sizeof(struct no));
    	aux->n=d;
    	q->inicio=aux;
    	q->fim=aux;
    	aux->prox=q->inicio;
    	aux->ant=aux;
    	siz++;
    	return ;
    }
   aux= (struct no *) malloc(sizeof(struct no));
   aux->n=d;
   aux->prox=q->inicio;
   aux->ant=q->fim;
   q->fim->prox=aux;
   q->fim=aux;
   q->inicio->ant=q->fim;
    siz++;
}
int busca(listac q,int val)
{
	struct no *aux;
	aux=q.inicio;
	if(!Empty(q))
    {
        while(aux!=NULL && val--)
        {
        	if(!val)return aux->n.id;
        	aux=aux->prox;
        }
    }
    printf("Nao encontrado\n");
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
int rodar(listac q, listac q2)
{
	struct no *aux,*aux2;
	int c=1;
	aux=q.inicio;
	aux2=q2.inicio;
	int ini1=aux->n.id;
	int ini2=aux2->n.id;
	aux=aux->prox;
	aux2=aux2->ant;
	while(ini1 != aux->n.id && ini2 != aux2->n.id)
	{
		c++;
		aux=aux->prox;
		aux2=aux2->ant;
	}
	return c;
	
}
int main()
{
	listac l,l2;
	create(&l);
	create(&l2);
	int cc=1;
	int x;
	printf("Digite -1 para parar de ler a lista\n");
	while(scanf("%d",&x),x!=-1)
	{
		engrenagens alo;
		alo.id=cc++;
		alo.nom=x;
		inserir(&l,alo);
	}
	printf("Digite -1 para parar de ler a lista\n");
	while(scanf("%d",&x),x!=-1)
	{
		engrenagens alo;
		alo.id=cc++;
		alo.nom=x;
		inserir(&l2,alo);
	}
	
	printf("As engrenagens rodaram %d vez(es)\n",rodar(l,l2));
}
