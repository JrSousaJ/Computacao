#include <bits/stdc++.h>

using namespace std;
#define N 4
int n;
int verifica(int k[N][N],int x,int y)
{
    for(int i=y;i<n;i++)if(k[x][i]==1)return 0;
    for(int i=y;i>=0;i--)if(k[x][i]==1)return 0;
    for(int i=x;i<n;i++)if(k[i][y]==1)return 0;
    for(int i=x;i>=0;i--)if(k[i][y]==1)return 0;

    for(int i=x,j=y;i<n && j<n;i++,j++)
    {
            if(i==j && k[i][j])return 0;
    }
    for(int i=x-1,j=y-1;i>=0 && j>=0;i--,j--)
    {
             if(i==j && k[i][j])return 0;
    }
     for(int i=y,j=x;i<n && j<n;i++,j++)
    {
            if(i==j && k[i][j])return 0;
    }
   for(int i=y-1,j=x-1;i>=0 && j>=0;i--,j--)
    {
             if(i==j && k[i][j])return 0;
    }
    return 1;
}
void solve()
{
    int v[N][N];
    memset(v,0,sizeof v);
    v[0][0]=1;
    printf("%d",verifica(v,2,3));

}
int main()
{
    solve();
    return 0;
}


