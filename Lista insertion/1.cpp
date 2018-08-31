#include<bits/stdc++.h>

using namespace std;
int v[10];
void ordena(int tam)
{
	int ch;
	for(int i=1;i<tam;i++)
	{
		ch=v[i];
		int j=i-1;
		while(j>=0 && v[j]>ch)
		{
			v[j+1]=v[j];
			j--;
		}
		v[j+1]=ch;
	}
}
int main()
{
	
	for(int i=0;i<10;i++)
	{
		scanf("%d",&v[i]);
	}
	ordena(10);
	int me=v[0],ma=v[9];
	int i=0;
	int cm=0,cma=0;
	while(v[i]<=me)
	{
		if(v[i]==me)cm++;
		i++;
	}
	i=9;
	while(v[i]>=ma)
	{
		if(v[i]==ma)cma++;
		i--;
	}
	printf("O menor valor eh: %d e ele aparece %d vez(es)\n",me,cm);
	printf("O maior valor eh: %d e ele aparece %d vez(es)\n",ma,cma);

	return 0;
}
