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
int main()
{
    Arvore a = NULL;
    insertNode(&a,17);
    insertNode(&a,11);
    insertNode(&a,15);
    insertNode(&a,5);
    insertNode(&a,10);
    printf("Deve ser usado a funcao posOrder para printar na sequencia 10, 5, 15, 11 e 17")
    posOrder(a);

}
