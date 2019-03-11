#include<bits/stdc++.h>

using namespace std;
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		int ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				{
					int x;scanf("%d",&x);
					ans+=x;
				}
		}
		int qtd=ans/60;
		ans-=(60*qtd);
		printf("%d saca(s) e %d litro(s)\n",qtd,ans);
	}
	return 0;
}
