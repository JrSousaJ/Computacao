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
        printf("%d ",t->n);
        preorder(t->esq);
        preorder(t->dir);
    }
}
void inOrder(Arvore t)
{
    if(t!=NULL)
    {
        inOrder(t->esq);
        printf("%d ", t->n);
        inOrder(t->dir);
    }
}
void posOrder(Arvore t)
{
    if (t != NULL)
    {
        posOrder(t->esq);
        posOrder(t->dir);
        printf("%d ", t->n);
    }
}
int b=1;
void deletar(struct no *root,struct no *d_node) 
{ 
    queue<struct no*> q; 
    q.push(root); 
  
    // Do level order traversal until last node 
    struct no* temp; 
    while(!q.empty()) 
    { 
        temp = q.front(); 
        q.pop(); 
  
        if (temp->dir) 
        { 
            if (temp->dir == d_node) 
            { 
                temp->dir = NULL; 
                delete(d_node); 
                return; 
            } 
            else
                q.push(temp->dir); 
        } 
  
        if (temp->esq) 
        { 
            if (temp->esq == d_node) 
            { 
                temp->esq=NULL; 
                delete(d_node); 
                return; 
            } 
            else
                q.push(temp->esq); 
        } 
    } 
} 
void removeNode(struct no *t, int v)
{   
    queue<struct no*>q;
    q.push(t);
    struct no *temp;
    struct no *key=NULL;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->n==v)key=temp;
        if(temp->dir!=NULL)q.push(temp->dir);
        if(temp->esq!=NULL)q.push(temp->esq);
    }
    int ab=temp->n;
    deletar(t,temp);
    key->n=ab;
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
    removeNode(a,8);

    printf("Pre ordem depois da exclusao do elemento 8\n");
    preorder(a);
    printf("\n");
     removeNode(a,7);
    printf("Em ordem apos excluir elemento 7\n");
    inOrder(a);
    printf("\n");
     removeNode(a,9);
    printf("Pos ordem apois exluir o elemento 9\n");
    posOrder(a);



 }
