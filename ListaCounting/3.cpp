#include<bits/stdc++.h>

using namespace std;
void CS(long long int x[],int siz)
{
	int m[siz];
	long long int cc[200001];memset(cc,0,sizeof cc);
	for(int i=0;i<siz;i++)cc[x[i]]++;
	for(int i=1;i<=200000;i++)cc[i]+=cc[i-1];
	for(int i=0;i<siz;i++)
	{
		m[cc[x[i]]-1]=x[i];
		cc[x[i]]--;
	}
	for(int i=0;i<siz;i++)x[i]=m[i];
}
int main()
{
	int n;
	printf("Tamanho do vetor: ");
	scanf("%d",&n);
	long long int v[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&v[i]);
		v[i]+=100000;
	}
	CS(v,n);
	for(int i=0;i<n;i++)
	{
		v[i]-=100000;
		printf(" %d",v[i]);
	}
	return 0;
}
