#include<bits/stdc++.h>
#define MAX 100

struct node
{
    int value[MAX];
    struct node *keys[MAX+1];
    struct node *parent;
    int keyCount;
} *tRoot = NULL;
int treeOrder;

struct node* novono(int v,struct node *parent)
{
       struct node *root = (struct node*)malloc(sizeof(struct node));
       root->value[0] = v;
       root->keyCount = 2;
       root->parent = parent;

       for (int i=1;i<=treeOrder+2;i++)
       {
           root->value[i] = (int)NULL;
           root->keys[i] = NULL;
       }
       return root;
}
struct node* insertN(int value,struct node *root,struct node *parent)
{
       int i = 0, j;

       if (root == NULL){
          return novono(value,parent);
       } else {
          while(1){
             if ( (void*)root->value[i] != NULL ){
                if (value == root->value[i]){
                   printf("O valor digitado j� existe!\n");
                   break;
                } else if ( value > root->value[i] ){
                   if (root->keys[i+1] != NULL && root->keys[i+1]->keyCount < treeOrder + 1) {
                       root->keys[i+1] = insertN(value,root->keys[i+1],root);
                       break;
                   } else i++;

                   continue;
                } else {
                   if (root->keys[i] != NULL && root->keys[i]->keyCount < treeOrder + 1) {
                       root->keys[i] = insertN(value,root->keys[i],root);
                       break;
                   } else {
                     for (j = treeOrder - 2; j >= i; j--) root->value[j+1] = root->value[j];
                     root->value[i] = value;
                     root->keyCount++;


                     break;
                   }

                }
             } else {
               root->value[i] = value;
               root->keyCount++;

               printf("Chaves: %d\n",root->keyCount);
               break;
             }

             i++;
          }

          if (root->keyCount > treeOrder){
             int left = (treeOrder-1)/2 - 1;
             int right = (treeOrder-1)/2 + 1;
             int mid = (treeOrder-1)/2;

             printf("Overflow! Divis�o e Promo��o de n�...\n");
             struct node *leftHalf = NULL;
             struct node *rightHalf = NULL;

             for (i = 0; i <= left; i++){
                 leftHalf = insertN(root->value[i],leftHalf,NULL);
             }

             for (i = right; i < treeOrder; i++){
                 rightHalf = insertN(root->value[i],rightHalf,NULL);
             }

             struct node *tempRoot = root;
             root = insertN(root->value[mid],parent,parent);

             if (parent == NULL){
               leftHalf->parent = root;
               rightHalf->parent = root;
               root->keys[0] = leftHalf;
               root->keys[1] = rightHalf;
             } else {
               for (i = 0; i < tempRoot->parent->keyCount; i++){
                   if (tempRoot->parent->keys[i] == tempRoot){
                      tempRoot->parent->keys[i]   = leftHalf;
                      tempRoot->parent->keys[i+1] = rightHalf;
                   }
               }
             }
             free(tempRoot);
          }
       }

       return root;
}





void inOrder(struct node *root)
{
     int i;
     if (root == NULL)
           return;
     else
     {
          for (i = 0; i < root->keyCount - 1; i++)
          {
            inOrder(root->keys[i]);
            printf("~%d~\n",root->value[i]);
          }
     }
}

void levelOrder(struct node *root)
{
     int i;
     if (root == NULL) return;
     else {
          for (i = 0; i < root->keyCount - 1; i++){
             printf("%d ",root->value[i]);
          }
          printf("   ");
          if (root->parent == NULL) printf("\n");
          else {
               for (i = 0; i < root->parent->keyCount; i++){
                   if (root->parent->keys[i] == root){
                      if (root->parent->keys[i+1] == NULL) printf("\n");
                      break;
                   }
               }
          }

          for (i = 0; i < root->keyCount; i++){
            levelOrder(root->keys[i]);
          }
     }
}


void nivel(struct node *root)
{
     if (root == NULL) return;
     else {
          for (int i=0;i<root->keyCount-1;i++){
             printf("%d ",root->value[i]);
          }
          printf("   ");
          if (root->parent == NULL) printf("\n");
          else {
               for (int i=0;i<root->parent->keyCount;i++){
                   if (root->parent->keys[i]==root){
                      if (root->parent->keys[i+1]==NULL)printf("\n");
                      break;
                   }
               }
          }
          for (int i=0;i<root->keyCount;i++){
            nivel(root->keys[i]);
          }
     }
}


int main()
{


    printf("Arvore B\n");
    printf("Qual a ordem minima da arvore?\n");
    scanf("%d",&treeOrder);
    int x=1;
    while(x)
    {
      printf("1)Inserir na arvore\n");
      printf("2)Mostrar em ordem de nivel\n");
      printf("0)Sair.\n");
      scanf("%d",&x);
      if(x==1)
      {
        printf("Valor a ser inserido: ");
        int a;scanf("%d",&a);
        printf("\n");
        tRoot = insertN(a,tRoot,NULL);
      }
      else if(x==2)
      {
          if(tRoot==NULL)printf("Arvore vazia!\n");
          else nivel(tRoot);
      }
    }
    return 0;
}
