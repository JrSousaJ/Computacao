#include<bits/stdc++.h>

using namespace std;
int siz=0;
int x,c;
typedef struct  
{
	char nome[100];
	int id;
}aluno;
struct no
{
   	aluno n;
    struct no *prox;
};
typedef struct
{
    struct no *inicio;
    struct no *fim;
}listac;

void create(listac *l)
{
    siz=0;
    l->inicio=NULL;
}
bool Empty(listac q)
{
    if(q.inicio==NULL)return true;
    return false;
}
void inserir(listac *q,aluno d)
{
    struct no *aux;
    if(q->inicio == NULL)
    {
    	aux= (struct no *) malloc(sizeof(struct no));
    	aux->n=d;
    	q->inicio=aux;
    	q->fim=aux;
    	aux->prox=q->inicio;
    	siz++;
    	return ;
    }
   aux= (struct no *) malloc(sizeof(struct no));
   aux->n=d;
   aux->prox=q->inicio;
   q->fim->prox=aux;
   q->fim=aux;
    siz++;
}

void remover(listac *q,aluno d)
{
    struct no *aux, *atual, *anterior;
   	if(d.id==(q->inicio)->n.id)
   	{
   		aux=q->inicio;
   		if(q->inicio==q->fim)q->inicio = NULL;

   
	   	else
	   	{
	   		q->inicio = q->inicio->prox;
	   		q->fim->prox=q->inicio;
	   	}
   		free(aux);
   }
   else 
   {
   		anterior=q->inicio;
   		atual=q->inicio->prox;
   		while(atual!=q->inicio && atual->n.id !=d.id)
   		{
   			anterior=atual;
   			atual=atual->prox;
   		}
   		if(atual!=q->inicio)
   		{
   			aux=atual;
   			anterior->prox=atual->prox;
   			free(aux);
   		}
   }
    siz--;
}
int busca(listac q,int val)
{
	struct no *aux;
	aux=q.inicio;
	if(!Empty(q))
    {
        while(aux!=NULL && val--)
        {
        	if(!val)return aux->n.id;
        	aux=aux->prox;
        }
    }
    printf("Nao encontrado\n");
}
void print(listac l)
{
    struct no *aux;
    
    if(!Empty(l))
    {
    	aux= l.inicio;
        if(aux!=l.fim)
        {
        	do
        	{
        		printf("%d->%d ",aux->n,aux->prox->n);
        		aux=aux->prox;
        	}while(aux!=l.inicio);
        }
        else printf("%d->NULL ",aux->n);
    }
}
void rodar(listac q)
{
	struct no *aux;
	if(!Empty(q))
	{
		aux=q.inicio;
		if(siz==1)
		{
			printf("%d\n",aux->n.id);
			return ;
		}
		while(siz>1)
		{
			remover(&q,aux->n);
			aux=(aux->prox)->prox;
		}
	}
	printf("%d\n",siz);
	printf("Nome %s\n",aux->n.nome);
	printf("Id %d\n",aux->n.id);
	
}
int main()
{
	listac q;
	create(&q);
	printf("Deseja inserir quantos alunos? ");
	int x;scanf("%d",&x);
	while(x--)
	{
		char s[100];
		int a;
		printf("\nNome: ");
		scanf(" %[^\n]",s);
		printf("\nID do aluno: ");
		scanf("%d",&a);
		aluno aux;
		strcpy(aux.nome,s);
		aux.id=a;
		inserir(&q,aux);
	}
	rodar(q);
}
