#include<bits/stdc++.h>
#include<Windows.h>
using namespace std;
int siz=0;
typedef struct 
{
    int id;
    double co;
    int exp;
    
}poli;
struct no
{
   poli n;
    struct no *prox;
};
typedef struct
{
    struct no *inicio;
}lista;
lista ans;

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
void inserir(lista *q,poli d)
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
        while(atual!=NULL)
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
            printf("Id-%d ",aux->n.id);
            printf("Polinomio %.2lfx^%d\n",aux->n.co,aux->n.exp);
            aux=aux->prox;
        }
    }
}
void soma(lista l, int n1, int m)
{
    poli a,b;
    struct no *aux;
    aux=l.inicio;
    while(aux!=NULL)
    {
        if(aux->n.id==n1)a=aux->n;
        else if(aux->n.id==m)b=aux->n;
        aux=aux->prox;
    }
    printf("A soma dos polinomios de id %d e %d eh :\n\n",n1,m);
    if(b.exp==a.exp)printf("%.2lfX^%d\n",(a.co+b.co),a.exp);
    else printf("%.2lfX^%d + %.2lfX^%d\n",a.co,a.exp,b.co,b.exp);
}
void mult(lista l, int n1, int m)
{
    poli a,b;
    struct no *aux;
    aux=l.inicio;
    while(aux!=NULL)
    {
        if(aux->n.id==n1)a=aux->n;
        else if(aux->n.id==m)b=aux->n;
        aux=aux->prox;
    }
    printf("A multiplicacao dos polinomios de id %d e %d eh :\n\n",n1,m);
    printf("%.2lfX^%d\n",(a.co*b.co),(a.exp+b.exp));
}
void der(lista l,int n1)
{
    poli a;
    struct no *aux;
    aux=l.inicio;
    while(aux!=NULL)
    {
        if(aux->n.id==n1)
        {
                a=aux->n;
                break;
        }
        aux=aux->prox;
    }
    printf("A derivado do polinomio de ID %d eh:\n",n1);
    printf("%.2lfX^%d\n",a.co*a.exp,a.exp-1);
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
    int c=1;
    lista q;
    create(&q);
    while(n)
    {
        printf("\n\n1-Inserir polinomio\n");
        printf("2-Somar 2 polinomios\n");
        printf("3-Multiplicar 2 polinomios\n");
        printf("4-Derivar um polinomio\n");
        printf("0-Sair\n");
        scanf("%d",&n);
        //system("cls");
        if(n==1)
        {
            int x;
            double x2;
            scanf("%lfx%d",&x2,&x);
            poli ajuda;
            ajuda.id=c++;
            ajuda.co=x2;
            ajuda.exp=x;
            inserir(&q,ajuda);
        }
        if(n==2)
        {
            printf("Id's dos polinomios a serem somados\n");
            int y,yy;scanf("%d%d",&y,&yy);
            soma(q,y,yy);
        }
        if(n==3)
        {
            printf("Id's dos polinomios a serem multiplicados\n");
            int y,yy;scanf("%d%d",&y,&yy);
            mult(q,y,yy);
        }
        if(n==4)
        {
            printf("Id do polinomio a ser derivado\n");
            int y;scanf("%d",&y);
            der(q,y);
        }
        printf("\n\n\nPolinomios armazenados: \n");   
        print(q);
    }
}
