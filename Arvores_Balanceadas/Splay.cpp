#include<bits/stdc++.h>

using namespace std;

struct Node
{
    Node *left;
    Node *right;
    Node *p;
    int v; 
}*root;

void rightRotate(Node *P)
{
    Node *T=P->left;
    Node *B=T->right;
    Node *D=P->p;
    if(D)
    {
        if(D->right==P)D->right=T;
        else D->left=T;
    }
    if(B)B->p=P;

    T->p=D;
    T->right=P;

    P->p=T;
    P->left=B;
}
void leftRotate(Node *P)
{
    Node *T=P->right;
    Node *B=T->left;
	Node *D=P->p;
	if(D)
	{
		if(D->right==P) D->right=T;
		else D->left=T;
	}
	if(B)
		B->p=P;
	T->p=D;
	T->left=P;
	
	P->p=T;
	P->right=B;
}
void Splay(Node *T)
{
    for(;;)
    {
        Node *p=T->p;
        if(!p) break;
        Node *z=p->p;
        if(!z)
        {
            if(p->left==T)rightRotate(p);
            else leftRotate(p);
            break;
        }
        if(z->left==p)
        {
            if(p->left==T)
            {
                rightRotate(z);
                rightRotate(p);
            }
            else 
            {
                leftRotate(p);
                rightRotate(z);
            }
        }
        else
        {
            if(p->left==T)
            {
                rightRotate(p);
                leftRotate(z);
            }
            else
            {
                leftRotate(z);
                leftRotate(p);
            }
            
        }
    }
    root=T;
}
void Inserir(int v)
{
    if(!root)
    {
        root=(Node *)malloc(sizeof(Node));
        root->left=NULL;
        root->right=NULL;
        root->p=NULL;
        root->v=v;
        return ;
    }
    Node *P= root;
    for(;;)
    {
        if(P->v==v)break;
        if(v < (P->v))
        {
            if(P->left)P=P->left;
            else
            {
                P->left=(Node *)malloc(sizeof(Node));
				P->left->p=P;
				P->left->right=NULL;
				P->left->left=NULL;
				P->left->v=v;
				P=P->left;
				break;
            }
        }
        else
        {
                if(P->right)P=P->right;
                P->right=(Node *)malloc(sizeof(Node));
				P->right->p=P;
				P->right->left=NULL;
				P->right->right=NULL;
				P->right->v=v;
				P=P->right;
				break;
        }
    }
    Splay(P);
}
void inorder(Node *R)
{
    if(!R)return ;
    printf("Valor : %d\n",R->v);
    inorder(R->left);
    inorder(R->right);
}
Node* busca(int v)
{
    if(!root)return NULL;
    Node *p=root;
    while(p)
    {
        if(p->v==v)break;
        if(v<(p->v))
        {
            if(p->left)p=p->left;
            else break;
        }
        else
        {
            if(p->right)p->right;
            else break;
        }
    }
    Splay(p);
    if(p->v==v)return p;
    else return NULL;
    

}
int main()
{
    for(;;)
    {
        int x;
        printf("1)Inserir na arvore\n");
        printf("2)Printar InOrder\n");
        printf("3)Procurar um valor\n");
        printf("0)Sair\n");
        scanf("%d",&x);
        if(!x)break;
        if(x==1)
        {
            printf("Quer inserir qual valor? ");
            int a;scanf("%d",&a);
            Inserir(a);
            printf("Inserido com sucesso\n");
        }
        else if(x==2)
        {
            printf("Printando em Ordem\n");
            inorder(root);
        }
        else if(x==3)
        {
            printf("Deseja procurar qual valor? ");
            int a;scanf("%d",&a);
            printf("\n");
            printf("%s\n",(!busca(a))? "Encontrado" : "Nao Encontrado");
        }
    }
}