#include <bits/stdc++.h>

using namespace std;
/*
Implementação da Mochila 0-1 na matéria de Algoritmos e Estruturas de dados III do curso de Ciência da Computação.
By: Jairo

*/
const int NMAX = 1e3;
const int MMAX = 1e2;
int v[NMAX],p[NMAX];
int dp[NMAX][MMAX];
int n,m;
int mochila(int pos, int peso)
{
    if(pos==n)return 0;
    if(dp[pos][peso]!=-1)return dp[pos][peso];
    int ans = mochila(pos+1,peso);
    int k=-1;
    if(peso>=p[pos])
    {
            k = mochila(pos+1,peso-p[pos])+v[pos];
    }

    return dp[pos][peso] = max(ans,k);

}
int main()
{
    scanf("%d %d",&n,&m);
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)
        scanf("%d %d",&v[i],&p[i]);

    printf("%d\n",mochila(0,m));
    return 0;
}


