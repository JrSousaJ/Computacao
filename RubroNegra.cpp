#include<bits/stdc++.h>
struct no
{
    int id;
    char cor;
    struct no *pai;
    struct no *dir;
    struct no *esq;
};
struct no *rubro;
typedef struct no *rn;

void left_rotate(rn *T, struct no *x)
{
	struct no *y = x->dir;
	x->dir= y->esq;

	if(y->esq!=rubro)y->esq->pai=x;

	y->pai = x->pai;
	if(x->pai==rubro)(*T)= y;
	else if(x==x->pai->esq)x->pai->esq=y;
	else x->pai->dir = y;

	y->esq=x;
	x->pai=y;
}
void right_rotate(rn *T, struct no *x)
{
	struct no *y = x->esq;
    x->esq = y->dir;
    if(y->dir != rubro)y->dir->pai = x;

    y->pai = x->pai;
    if(x->pai == rubro)
    	(*T) = y;
    else if(x == x->pai->esq)
    	x->pai->esq = y;
    else
       x->pai->dir = y;

    y->dir = x;
    x->pai = y;
}
void rb_insert_fix(rn *T, struct no *z)
{
	struct no *y;
	if(z->pai==rubro)
	{
		(*T)->cor = 'P';
		return ;
	}
	while(z->pai->cor == 'V')
	{
		if(z->pai == z->pai->pai->esq)
		{
			y=z->pai->pai->dir;
			if(y->cor == 'V')
			{
				z->pai->cor = 'P';
				y->cor = 'P';
				z->pai->pai->cor = 'V';
				z = z->pai->pai;
			}
			else
			{
				if(z==z->pai->dir)
				{
					z = z->pai;
					left_rotate(&(*T),z);
				}
				z->pai->cor = 'P';
				z->pai->pai->cor = 'V';
				right_rotate(&(*T),z->pai->pai);
			}
		}
		else if(z->pai == z->pai->pai->dir)
		{
			y=z->pai->pai->esq;
			if(y->cor == 'V')
			{
				z->pai->cor = 'P';
				y->cor = 'P';
				z->pai->pai->cor = 'V';
				z = z->pai->pai;
			}
			else
			{
				if(z==z->pai->esq)
				{
					z = z->pai;
					right_rotate(&(*T),z);
				}
				z->pai->cor = 'P';
				z->pai->pai->cor = 'V';
				left_rotate(&(*T),z->pai->pai);
			}
		}

	}
	(*T)->cor='P';
}
void rb_insert(rn *T, int val)
{
	struct no *y = rubro;
	struct no *x = *T;

	struct no *z = (struct no*)malloc(sizeof(struct no));
	z->id = val;
	z->dir = rubro;
	z->esq= rubro;

	if(*T == NULL)
	{
		z->pai=rubro;
		z->cor='P';
		*T=z;
		return ;
	}
	while(x!=rubro) 
	{
		y=x;
		if(z->id<x->id)
			x = x->esq;
		else x = x->dir;
	}
	z->pai = y;

	if(y==rubro)
		*T = z;
	else if(z->id < y->id)
		y->esq = z;
	else y->dir = z;

	z->cor = 'V';
	rb_insert_fix(&(*T),z);
}
void prefix(rn t)
{
	if(t!=rubro && t!=NULL)
	{
		printf("%d\n",t->id);
		prefix(t->esq);
		prefix(t->dir);
	}
}
int main()
{
	int op;
	rn rune = NULL;

	rubro = (struct no*)malloc(sizeof(struct no));
	rubro->cor = 'P';
	rubro->dir=rubro;
	rubro->esq=rubro;
	for(;;)
	{
		printf("1-Inserir na Arvore\n");
		printf("2-Mostrar a Arvore\n");
		printf("0-Sair\n");
		scanf("%d",&op);
		if(!op)break;

		if(op==1)
		{
			printf("Qual valor deseja inserir?\n");
			int a;scanf("%d",&a);
			rb_insert(&rune,a);
		}
		else
		{
			printf("Mostrando os valores na forma prefixa\n");
			prefix(rune);
		}
	}
	return 0;
}
