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
			printf("Duplicação de no");
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
int ContaNos(Arvore t)
{
	if(t== NULL)return 0;
	return ContaNos(t->esq)+ContaNos(t->dir)+1;
}
int c=0;
void ContaFiD(Arvore t)
{
	
	if(t==NULL)return ;
	if(t->esq!=NULL)c++;
	ContaFiD(t->dir);
	ContaFiD(t->esq);
}
int Altura(Arvore t) 
{
    int u, v;
    if (t == NULL) 
       return -1;
    u = Altura(t->esq);
    v = Altura(t->dir);
    if (u > v) 
       return u+1;
    else 
        return v+1;
}
int ContaFolhas(Arvore t) 
{
	if(t==NULL)
	   return 0;
    if (t->esq == NULL && t->dir == NULL ) 
       return 1;
    else
        return  ContaFolhas(t->esq) + ContaFolhas(t->dir);
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
	ContaFiD(a);
	printf("Numero de nos: %d\n",ContaNos(a));
	printf("Numero de folhas: %d\n",ContaFolhas(a));
	printf("Numero de filhos a direta: %d\n",c);
}