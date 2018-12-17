#include<bits/stdc++.h>

using namespace std;
struct no
{
    struct no *esq;
    struct no *dir;
    int n;
};
typedef struct no *Arvore;
void insertNode(Arvore *t, int d)
{
    if (*t == NULL)
    {
        *t = (struct no*) malloc(sizeof(struct no));
    if ( *t != NULL )
    {
        (*t)->esq = NULL;
        (*t)->dir = NULL;
        (*t)->n = d;
    }
    else
        printf("Memoria insuficiente");
    }
    else
        if (d < (*t)->n)
            insertNode(&(*t)->esq, d);
    else
        if (d > (*t)->n)
            insertNode(&(*t)->dir, d);
        else
            printf("Duplicacao de no");
}
void preorder(Arvore t)
{
    if(t!=NULL)
    {
        printf("%d\n",t->n);
        preorder(t->esq);
        preorder(t->dir);
    }
}
void inOrder(Arvore t)
{
    if(t!=NULL)
    {
        inOrder(t->esq);
        printf("%d\n", t->n);
        inOrder(t->dir);
    }
}
void posOrder(Arvore t)
{
    if (t != NULL)
    {
        posOrder(t->esq);
        posOrder(t->dir);
        printf("%d\n", t->n);
    }
}
void atualizar(Arvore t,int x,int at)
{
    if(t!=NULL)
    {
        if(t->n==x)t->n=at;
        atualizar(t->dir,x,at);
        atualizar(t->esq,x,at);
    }
}
void menorq(Arvore t,int x)
{
    if(t!=NULL)
    {
        if(t->n<x)printf("%d\n",t->n);
        menorq(t->esq,x);
        menorq(t->dir,x);
    }
}
int main()
{
    Arvore a = NULL;

    insertNode(&a,9);
    insertNode(&a,4);
    insertNode(&a,12);
    insertNode(&a,2);
    insertNode(&a,6);
    insertNode(&a,10);
    insertNode(&a,16);
    insertNode(&a,7);
    insertNode(&a,11);
    insertNode(&a,13);
    insertNode(&a,18);
    insertNode(&a,8);
    insertNode(&a,14);

    printf("Todos os valores em ordem\n");
    inOrder(a);
    printf("Todos os valores em ordem com o 100 no lugar do 12\n");
    atualizar(a,12,100);
    inOrder(a);


 }
