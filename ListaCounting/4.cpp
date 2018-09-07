#include<bits/stdc++.h>

using namespace std;
void CS(int x[],int siz)
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
	int v[n];
	for(int i=0;i<n;i++)
	{
		double x;scanf("%lf",&x);
		v[i]=x*100;
	}
	CS(v,n);
	for(int i=0;i<n;i++)
	{
		double x=v[i]/100.00;
		printf(" %.2lf",x);
	}
	return 0;
}
