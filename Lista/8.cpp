#include<bits/stdc++.h>
#include<Windows.h>
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
void uniao(lista *q, lista *p)
{
    struct no *atual;
    atual=q->inicio;
    set<int>scr;
   while(atual!=NULL)
   {
        scr.insert(atual->n);
        atual=atual->prox;
   }
   atual=p->inicio;
    while(atual!=NULL)
   {
        scr.insert(atual->n);
        atual=atual->prox;
   }
   set<int>::iterator it;
   for(it=scr.begin();it!=scr.end();it++)
   {
        int a=(int)*it;
        inserir(&ans,a);
   }
}
void dif(lista *q, lista *p)
{
    struct no *atual;
    atual=q->inicio;
    set<int>scr;
    while(atual!=NULL)
    {
        scr.insert(atual->n);
        atual=atual->prox;
    }
    atual=p->inicio;
    while(atual!=NULL)
   {
        if(scr.find(atual->n)==scr.end())inserir(&ans,atual->n);
        atual=atual->prox;
   }
   scr.clear();
   atual=p->inicio;
   while(atual!=NULL)
   {
        scr.insert(atual->n);
        atual=atual->prox;
   }
    atual=q->inicio;
    while(atual!=NULL)
   {
        if(scr.find(atual->n)==scr.end())inserir(&ans,atual->n);
        atual=atual->prox;
   }
}
bool pert(lista q, int x)
{
    struct no *aux;
    aux=q.inicio;
    while(aux!=NULL)
    {
        if(aux->n==x)return 1;
        aux=aux->prox;
    }
    return 0;
}
void inter(lista *q, lista *q2)
{
    struct no *atual;
    atual=q->inicio;
    set<int>scr;
    while(atual!=NULL)
    {
        scr.insert(atual->n);
        atual=atual->prox;
    }
    atual=q2->inicio;
    while(atual!=NULL)
    {
        if(scr.find(atual->n)!=scr.end())inserir(&ans,atual->n);
        atual=atual->prox;
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
    int n=1,m=1;
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
    while(m)
    {
       create(&ans);
       printf("\n\n1-Conjunto uniao entre as duas listas\n");
       printf("2-Conjunto Interseccao entre as duas listas\n");
       printf("3-Conjunto pertence\n");
       printf("4-Conjunto Diferenca entre as duas listas\n");
       printf("0-Sair\n");
       scanf("%d",&m);
      // system("cls");
       if(m==1)
       {
            printf("Uniao entre a lista A e B\n");
            uniao(&q,&q2);
            print(ans);
       }
       else if(m==2)
       {
            printf("Interseccao entre a lista A e B\n");
            inter(&q,&q2);
            print(ans);
       }
       else if(m==3)
       {
            printf("Digite o valor e o conjunto que se quer saber se pertence: \n");
            printf("Valor: ");
            int x;scanf("%d",&x);
            printf("\nConjunto: ");
            int l;scanf("%d",&l);
            if(l==1)
            {
                if(pert(q,x))printf("O valor %d pertence ao conjunto %d\n",x,l);
                else printf("O valor %d nao pertence ao conjunto %d\n",x,l);
            }
            else if(l==2)
            {
                if(pert(q2,x))printf("O valor %d pertence ao conjunto %d\n",x,l);
                else printf("O valor %d nao pertence ao conjunto %d\n",x,l);
            }
            else printf("Conjunto nao existe\n");
       }
       else if(m==4)
       {
            printf("A diferenca entre o primeiro e segundo conjunto eh: \n");
            dif(&q,&q2);
            print(ans);
       }

    } 
}
