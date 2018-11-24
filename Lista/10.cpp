#include<bits/stdc++.h>
#include<Windows.h>
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
int sizel(lista l)
{
    struct no *aux;
    int cc=0;
    aux= l.inicio;
    if(Empty(l))return 0;
    while(aux!=NULL)
    {
            cc++;
            aux=aux->prox;
    }
    return cc;
}
bool busca(lista q,int val)
{
    struct no *aux;
    aux=q.inicio;
    if(!Empty(q))
    {
        while(aux!=NULL)
        {
            if(aux->n==val)
            {
                return true;
            }
            aux=aux->prox;
        }
    }
    return false;
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
        q->inicio->ant=aux->ant;
       }
        free(aux);
    }
    else
    {
        anterior = q->inicio;
        atual=(q->inicio)->prox;
        while(atual!=NULL && atual->n!=d)
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
void concatenar(lista *q,lista *g)
{
    q->fim->prox=g->inicio;
}
int main()
{
    int n=1;
    lista q;
    create(&q);
    while(n)
    {
        printf("\n\n\n\n1-Inserir elemento na lista\n");
        printf("2-Remover elemento na lista\n");
        printf("3-Busca elemento na lista\n");
        printf("4-Imprimir elementos da lista\n");
        printf("5-Contar elementos da lista\n");
        printf("0-Sair\n");
        scanf("%d",&n);
        system("cls");
        if(n==1)
        {
            printf("Inserir qual valor? \n");
            int x;scanf("%d",&x);
            inserir(&q,x);
        }
        else if(n==2)
        {
            printf("Remover qual valor? \n");
            int x;scanf("%d",&x);
            remover(&q,x);
        }
        else if(n==3)
        {
            printf("Buscar qual valor? \n");
            int x;scanf("%d",&x);
            if(busca(q,x))printf("%d foi encontrado!\n",x);
            else printf("Nao foi encontrado!\n");
        }
        else if(n==4)
        {
            printf("Imprimindo valores da lista\n");
            print(q);
        }
        else if(n==5)
        {
            printf("A lista tem tamanho %d\n",sizel(q));
        }
    }
}
