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
void printa(lista l,int no)
{
    struct no *aux;
    aux= l.inicio;
    if(aux->n==no)
    {
        printf("Nenhum\n");
        return ;
    }
    while(aux!=NULL)
    {
        if(aux->n<no)
        {
            printf("%d andar\n",aux->n);
        }
        aux=aux->prox;
    }
    
}
void printd(lista l,int no)
{

    struct no *aux;
    aux= l.inicio;
    int c=0;
    while(aux!=NULL)
    {
        if(aux->n>no)
        {
            printf("%d andar\n",aux->n);
            c++;
        }
        
        aux=aux->prox;
    }
    if(c==0)printf("Nenhum\n");
}
   
int main()
{
    lista q;
    create(&q);
    for(int i=1;i<=10;i++)
    {
         inserir(&q,i);
    }
    int n,x=1;
    while(n)
    {
        printf("\n\nAndar atual: %d\n",x);
        printf("1-Andares possiveis de ir\n");
        printf("2-Subir\n");
        printf("3-Descer\n");
        printf("0-Sair\n");
        scanf("%d",&n);
        system("cls");
        if(n==1)
        {
            printf("**Eh possivel subir para os andares**\n");
            printa(q,x);
            printf("**Eh possivel descer para os andares**\n");
            printd(q,x);
        }
        else if(n==2)
        {
            printf("Deseja subir para qual andar?\n");
            int b;scanf("%d",&b);
            if(b<x && b>0)x=b;
            else printf("Nao foi possivel subir\n");
        }
        else if(n==3)
        {
            printf("Deseja descer para qual andar?\n");
            int b;scanf("%d",&b);
            if(b>x && b<=10)x=b;
            else printf("Nao foi possivel descer\n");
        }
    }
   
}
