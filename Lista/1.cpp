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
void inserir(lista *q,int d,int pos)
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
        while(atual!=NULL && pos--)
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
        while(atual!=NULL && pos--)
        {
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
    lista l;
        create(&l);
    while(n)
    {
        printf("\n1-Inserir no inicio\n");
        printf("2-Inserir no meio\n");
        printf("3-Inserir no fim\n");
        printf("4-Retirar do inicio\n");
        printf("5-Retirar do meio\n");
        printf("6-Retirar no fim\n");
        printf("7-Buscar\n");
        printf("8-Imprimir\n");
        printf("0-Sair\n\n");
        scanf("%d",&n);

        if(n==1)
        {
            int x;
            printf("Valor a ser inserido: ");
            scanf("%d",&x);
            inserir(&l,x,0);
        }
        if(n==2)
        {
            int x,y;
            printf("Valor a ser inserido: ");
            scanf("%d",&x);
            printf("\nPosicao a ser inserido: ");
            scanf("%d",&y);
            inserir(&l,x,y);
        }
        if(n==3)
        {
            int x;
            printf("Valor a ser inserido: ");
            scanf("%d",&x);
            inserir(&l,x,siz);
        }
        if(n==4)
        {

            printf("Retirando do comeco\n");
            remove(&l,0);
        }
        if(n==5)
        {
            printf("Posicao a ser retirada: ");
            int x;scanf("%d",&x);
            remove(&l,x);
        }
        if(n==6)
        {
            printf("Retirando do final\n");
             remove(&l,siz);
        }

        print(l);
    }
}

