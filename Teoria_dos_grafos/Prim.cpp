#include <bits/stdc++.h>

using namespace std;

/*
    Implementação do Algoritmo de Prim utilizando a linguagem C++.
    Disciplina: Teoria dos Grafos.
    Aluno: Jairo de Sousa Júnior.
*/
vector<int>vis;
int n,m;

vector<vector<pair<int,int> > >g;
priority_queue<pair<int,int> >fila;

void pro(int ix)
{
    vis[ix] = 1;
    for(int i=0;i<g[ix].size();i++)
    {
        int a = g[ix][i].first, b = g[ix][i].second;
        if(!vis[a])
        fila.push({-b,a});
    }

}
int main()
{
    printf("Digite o numero de vertices e arestas:\n");
    scanf("%d %d",&n,&m);
    int mst = 0;
    g.assign(n+1, vector<pair<int,int> >());

    for(int i=0;i<m;i++)
    {
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);

        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    vis.assign(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {

            vis[i] = 1;
            pro(i);

            while(!fila.empty())
            {

                pair<int,int>aux = fila.top();
                fila.pop();

                int a = aux.second;
                int b = -aux.first;

                if(!vis[a])
                {
                    mst += b;
                    pro(a);
                }
            }
        }
    }

    printf("Valor da arvore spanning minima utilizando Prim e: %d\n",mst);


}
