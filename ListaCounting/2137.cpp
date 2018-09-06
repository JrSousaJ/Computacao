#include <bits/stdc++.h>
     
using namespace std;
void CS(int x[],int siz)
{
    int m[siz];
    int cc[10000];memset(cc,0,sizeof cc);
    for(int i=0;i<siz;i++)cc[x[i]]++;
    for(int i=1;i<=10000;i++)cc[i]+=cc[i-1];
    for(int i=0;i<siz;i++)
    {
        m[cc[x[i]]-1]=x[i];
        cc[x[i]]--;
    }
for(int i=0;i<siz;i++)x[i]=m[i];
}
int main()
{
   int x;
   while(~scanf("%d",&x))
   {
   		int v[x];
   		for(int i=0;i<x;i++)scanf("%d",&v[i]);

   		CS(v,x);

   		for(int i=0;i<x;i++)printf("%.4d\n",v[i]);
   }
   	return 0;
}
