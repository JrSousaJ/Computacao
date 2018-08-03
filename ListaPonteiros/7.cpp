#include<bits/stdc++.h>
using namespace std;
int n,n2;
void calcula(int *x,int *y)
{
    int aux=*x;
    *x=*x+*y;
    *y=aux-*y;
}
int main()
{
    
    scanf("%d%d",&n,&n2);
    calcula(&n,&n2);
    printf("%d %d\n",n,n2);
    return 0;
}
