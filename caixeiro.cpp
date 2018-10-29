#include<bits/stdc++.h>

using namespace std;
const int oo = 0x3f3f3f3f;
int g[100][100],n;
int memo[n][1<<n];
int pd(int v,int mask)
{
	if(__builtin_popcount(mask)==n)return g[v][0];
	int ans = oo;
	if(memo[v][mask]!=-1)return memo[v][mask];
	for(int i=0;i<n;i++)
	{
		if(!((mask>>i)&1))
		{
			ans=min(ans,pd(i,mask|1<<i)+g[v][i])
		}
	}
	return memo[v][mask]=ans;
}

int main()
{
	return 0;
}
