#include<bits/stdc++.h>

using namespace std;
int siz=0;
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
void concatenar(lista *q, lista *p)
{
    struct no *atual,*aux;
    atual=q->inicio;
   while(atual!=NULL)
   {
        aux=atual;
        atual=atual->prox;
   }
    aux->prox=p->inicio;  
}
void remove(lista *q,int pos)
{
    struct no *aux, *atual, *anterior;
    if(pos==0)
    {
        aux=q->inicio;
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
int main()
{
    int n=1;
    lista l,l2;
    create(&l);
    create(&l2);
    int x;
    printf("Quantos elementos deseja incluir na primeira lista? ");
    scanf("%d",&x);
    printf("\nIncluindo elementos na primeira lista...\n\n");
    while(x--)
    {
        int a;scanf("%d",&a);
        inserir(&l,a);
    }
    printf("Quantos elementos deseja incluir na segunda lista? ");
    scanf("%d",&x);
    printf("\nIncluindo elementos na segunda lista...\n\n");
    while(x--)
    {
        int a;scanf("%d",&a);
        inserir(&l2,a);
    }
    printf("Listas sem concatenar: \n");
    printf("Lista 1\n");
    print(l);
    printf("Lista 2\n");
    print(l2);
    printf("Exibindo as listas concatenadas\n");
    concatenar(&l,&l2);
    print(l);
}
