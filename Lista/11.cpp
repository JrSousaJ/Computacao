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
        q->inicio=aux->ant;
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
    int n;
    lista q,q2;
    create(&q);
    create(&q2);
    printf("Primeira lista\n");
    printf("Digite o numero '0' para terminar a leitura\n");
    while(scanf("%d",&n),n)
    {
        inserir(&q,n);
    }
    printf("Segunda lista\n"); 
    printf("Digite o numero '0' para terminar a leitura\n");
    while(scanf("%d",&n),n)
    {
        inserir(&q2,n);
    } 
    printf("**Primeira Lista**\n");
    print(q);
    printf("\n**Segunda lista**\n");
    print(q2);
    concatenar(&q,&q2);
    printf("**Lista depois de concatenar\n");
    print(q);
}
