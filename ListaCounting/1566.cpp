#include <bits/stdc++.h>
     
using namespace std;
void CS(int x[],int siz)
{
    int m[siz];
    int cc[250];memset(cc,0,sizeof cc);
    for(int i=0;i<siz;i++)cc[x[i]]++;
    for(int i=1;i<=245;i++)cc[i]+=cc[i-1];
    for(int i=0;i<siz;i++)
    {
        m[cc[x[i]]-1]=x[i];
        cc[x[i]]--;
    }
for(int i=0;i<siz;i++)x[i]=m[i];
}
int main()
{
    int n;scanf("%d",&n);
    while(n--)
    {
        int x;scanf("%d",&x);
        int v[x];
        for(int i=0;i<x;i++)scanf("%d",&v[i]);
        CS(v,x);
        for(int i=0;i<x;i++)
        {
            if(!i)printf("%d",v[i]);
            else printf(" %d",v[i]);
        }
        printf("\n");
    }
   	return 0;
}
