#include<bits/stdc++.h>

using namespace std;
void cs(int x[],int siz)
{
	int m[siz];
	int cc[300];memset(cc,0,sizeof cc);
	for(int i=0;i<siz;i++)cc[x[i]]++;
	for(int i=1;i<=127;i++)cc[i]+=cc[i-1];
	for(int i=0;i<siz;i++)
	{
		m[cc[x[i]]-1]=x[i];
		cc[x[i]]--;
	}
	for(int i=0;i<siz;i++)x[i]=m[i];

}
int main()
{
	char s[1000];
	scanf(" %[^\n]",s);
	int q=strlen(s);
	int v[q];
	for(int i=0;i<q;i++)
	{
		int x=s[i];
		v[i]=x;
	}
	cs(v,q);
	for(int i=0;i<q;i++)
	{
		printf("%c",v[i]);
	}
	return 0;
}
