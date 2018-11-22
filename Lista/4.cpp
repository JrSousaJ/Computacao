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

void print(lista l,no *at)
{
       if(at==NULL)return ;
     
       printf("%d\n",at->n);
         print(l,at->prox);
}
void remover(lista *q,int pos,int *ae)
{
    struct no *aux, *atual, *anterior;
    if(pos==0)
    {
        aux=q->inicio;
        cout << aux->n << endl;
        *ae=aux->n;
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
            *ae=aux->n;
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
    struct no *aux=q.inicio;
    aux= q.inicio;
    print(q,aux);
}
