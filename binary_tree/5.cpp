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
        printf("%c\n",t->n);
        preorder(t->esq);
        preorder(t->dir);
    }
}
void inOrder(Arvore t)
{
    if(t!=NULL)
    {
        inOrder(t->esq);
        printf("%c", t->n);
        inOrder(t->dir);
    }
}
void posOrder(Arvore t)
{
    if (t != NULL)
    {
        posOrder(t->esq);
        posOrder(t->dir);
        printf("%c", t->n);
    }
}
void ContaFolhas(Arvore t,int val) 
{
    if(t==NULL)
       return ;
    if (t->n==val)printf("O seu valor na memoria eh de %d\n",&t->n);
    ContaFolhas(t->esq,val);
    ContaFolhas(t->dir,val);
}
int main()
{
    Arvore a = NULL;
    printf("Quer inserir quantos valores? \n");
    int x;scanf("%d",&x);
    while(x--)
    {
        int aa;scanf("%d",&aa);
        insertNode(&a,aa);
    }
    printf("Qual valor a ser buscado? ");
    int xx;scanf("%d",&xx);
    ContaFolhas(a,xx);
}
