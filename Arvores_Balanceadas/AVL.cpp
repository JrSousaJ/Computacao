#include<bits/stdc++.h>
using namespace std;
struct no
{
	int id,alt;
	struct no *left;
	struct no *right;
};
typedef struct no* avl;

int altura(struct no *a)
{
	if(a==NULL)return -1;
	return a->alt;
}

void rotsimplesesq(avl *a)
{
	struct no *aux;
	aux = (*a)->left;
	(*a)->left = aux->right;
	aux->right = *a;
	(*a)->alt = (altura((*a)->left)>altura((*a)->right))? altura((*a)->left)+1 : altura((*a)->right)+1;
	aux->alt = (altura(aux->left)>altura(aux->right))? altura(aux->left)+1 : altura(aux->right)+1;
	*a = aux;
}

void rotsimplesdir(avl *a)
{
	struct no *aux;
	aux = (*a)->right;
	(*a)->right = aux->left;
	aux->left = *a;
	(*a)->alt = (altura((*a)->left)>altura((*a)->right))? altura((*a)->left)+1 : altura((*a)->right)+1;
	aux->alt = (altura(aux->left)>altura(aux->right))? altura(aux->left)+1 : altura(aux->right)+1;
	*a = aux;
}
void rotesqdir(avl *a)
{
	rotsimplesesq(&(*a)->left);
	rotsimplesdir(a);
}
void rotdiresq(avl *a)
{
	rotsimplesdir(&(*a)->left);
	rotsimplesesq(a);
}
int FB(struct no *a)
{
	return abs(altura(a->right) - altura(a->left));
}
int inserir(avl *a, int n)
{
	int ff;
	if(*a==NULL)
	{
		struct no *aux = (struct no*)malloc(sizeof(struct no));
		if(aux == NULL)
		{
			printf("Sem memoria\n");
			return 0;
		}
		aux->id=n;
		aux->alt=0;
		aux->left = NULL,aux->right = NULL;
		*a = aux;
		return 1;
	}
	struct no *atual = *a;
	if(n < atual->id)
	{
		if((ff = inserir(&(atual->left),n)) == 1 )
		{
			if(FB(atual)>=2)
			{
				if(n < (*a)->left->id)rotsimplesesq(a);
				else rotesqdir(a);
			}
		}
	}
	else
	{
		if(n > atual->id)
		{
			if((ff = inserir(&(atual->right),n))==1)
			{
				if(FB(atual)>=2)
				{
					if(n > (*a)->right->id)rotsimplesdir(a);
					else rotdiresq(a);
				}
			}
		}
		else
		{
			printf("Duplicado\n");
			return 0;
		}
	}
	atual->alt = max(altura(atual->left),altura(atual->right))+1;
	return ff;

}
struct no* menor(struct no *atual)
{
	struct no *a=atual;
	struct no *b= atual->left;

	while(b!=NULL)
	{
		a=b;
		b = b->left;
	}
	return a;
}
int remover(avl *t, int n)
{
	if(*t == NULL)
	{
		printf("Arvore sem valores\n");
		return 0;
	}
	int ff;
	if(n < (*t)->id)
	{
		if((ff = remover(&(*t)->left,n)) == 1 )
		{
			if(FB(*t)>=2)
			{
				if(altura((*t)->right->left)<=altura((*t)->right->right))
					rotsimplesdir(t);
				else rotdiresq(t);
			}
		}
	}
	if(n > (*t)->id)
	{
		if((ff = remover(&(*t)->right,n)) == 1 )
		{
			if(FB(*t)>=2)
			{
				if(altura((*t)->left->right)<=altura((*t)->left->left))
					rotsimplesesq(t);
				else rotesqdir(t);
			}
		}
	}
	if((*t)->id == n)
	{
		if(((*t)->left==NULL || (*t)->right == NULL))
		{
			struct no *del = *t;
			if((*t)->left!=NULL)(*t) = (*t)->left;
			else (*t)=(*t)->right;

			free(del);
		}
		else
		{
			struct no *ach = menor((*t)->right);
			(*t)->id = ach->id;
			remover(&(*t)->right,(*t)->id);
			if(altura(*t)>=2)
			{
				if(altura((*t)->left->right)<=altura((*t)->left->left))
					rotsimplesesq(t);
				else rotesqdir(t);
			}
		}
		return 1;
	}
	return ff;
}
void print(avl t)
{
    if(t!=NULL)
    {
        printf("%d ",t->id);
        print(t->left);
        print(t->right);
    }

}

int main()
{
	int xx=1;
	avl AVL = NULL;
	while(xx)
	{
		printf("1-> Inserir na arvore\n");
		printf("2->Remover da Arvore\n");
		printf("0-Sair\n");
		scanf("%d",&xx);
		if(xx==1)
		{
			int aa;scanf("%d",&aa);
			inserir(&AVL,aa);
		}
		else if(xx==2)
		{
			int aa;scanf("%d",&aa);
			remover(&AVL,aa);
		}
		else break;
		print(AVL);
		printf("\n");
	}
	return 0;
}
