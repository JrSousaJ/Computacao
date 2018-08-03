#include<bits/stdc++.h>
using namespace std;
int v[3];
int prim,seg,terc;
void ord(int *a,int *b,int *c)
{
    prim=min((int)*a,min((int)*b,(int)*c));
    terc=max((int)*a,max((int)*b,(int)*c));
    if(*a!=prim && *a!=terc)seg=*a;
    else if(*b!=prim && *b!=terc)seg=*b;
    else if(*c!=prim && *c!=terc)seg=*c;
    *a=prim;
    *b=seg;
    *c=terc;
}
int main()
{
    //Fiz com vetor para tirar algumas dúvidas no que eu poderia usar ;v
    for(int i=0;i<3;i++)scanf("%d",&v[i]);
    ord(&v[0],&v[1],&v[2]);
    printf("A:%d, B:%d, C:%d\n",v[0],v[1],v[2]);
    return 0;
}
