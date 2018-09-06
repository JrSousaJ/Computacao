#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n[2001];memset(n,0,sizeof n);
	int x;scanf("%d",&x);
	while(x--)
	{
		int y;scanf("%d",&y);
		n[y]++;
	}
	for(int i=1;i<=2000;i++)
	{
		if(n[i]>0)printf("%d aparece %d vez(es)\n",i,n[i]);
	}
	return 0;
}
