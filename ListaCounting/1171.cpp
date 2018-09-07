#include<bits/stdc++.h>

using namespace std;
void CS(int x[],int siz)
{
	int m[siz];
	long long int cc[2001];memset(cc,0,sizeof cc);
	for(int i=0;i<siz;i++)cc[x[i]]++;
	for(int i=1;i<=2000;i++)cc[i]+=cc[i-1];
	for(int i=0;i<siz;i++)
	{
		m[cc[x[i]]-1]=x[i];
		cc[x[i]]--;
	}
	for(int i=0;i<siz;i++)x[i]=m[i];
}
int main()
{
	int x;scanf("%d",&x);
	int v[x];
	for(int i=0;i<x;i++)scanf("%d",&v[i]);
	CS(v,x);
	int at=v[0],cc=1;
	for(int i=1;i<x;i++)
	{
		if(at==v[i])cc++;
		else
		{
			printf("%d aparece %d vez(es)\n",at,cc);
			at=v[i];
			cc=1;
		}
	}
	printf("%d aparece %d vez(es)\n",at,cc);
	return 0;
}
