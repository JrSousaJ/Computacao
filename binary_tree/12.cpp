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
int b=1;
void removeNode(Arvore *t, int v)
{	
	if(v<(*t)->n)
	{
		*t->esq=removeNode(&(*t)->esq,v);
	}
	else if(v>(*t)->n)
	{
		*t->dir = removeNode(&(*t)->dir,v);
	}
	else
	{
		if((*t)->esq==NULL && (*t)->dir==NULL)
		{
			delete(root);
			root = NULL;
		}
		else if((*t)->esq==NULL)
		{
			Arvore *temp = t;
			*t= t->dir;
			delete temp;
		}
		else if((*t)->dir==NULL)
		{
			Arvore *temp = t;
			*t = t->esq;
			delete(temp);
		}
		else
		{
			Arvore *temp = t;
			*t = NULL;
		}
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
     removeNode(&a,8);
   	printf("Pre ordem depois da exclusao do elemento 8\n");
   	
   	posOrder(a);

 }
