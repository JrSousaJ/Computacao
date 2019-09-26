#include<bits/stdc++.h>

using namespace std;
/*
    Algoritmo de Kruskal para resolução da Árvore  Geradora Mínima|Minimum Spanning Tree
    Para a implementação fui utilizado vector e os algoritmos de unionset e findset.
    Disciplina: Teoria dos Grafos
    Aluno: Jairo de Sousa Júnior
*/
struct arestas
{
    int a,b,w;
    bool operator <(const arestas& q)const
    {
        return w<q.w;
    }
};
vector<arestas>v;
int p[500];
int findset(int a)
{
    if(p[a] == a)
        return a;

    return findset(p[a]);
}
void unionset(int a,int b)
{
    int x = a;
    int y = b;

    p[x] = y;
}
int main()
{
    for(int i=0;i<500;i++)
        p[i] = i;

    printf("Quantos vertices? ");
    int n;
    scanf("%d",&n);
    printf("Entre com o(s) vertice(s) A, B e o(s) seu(s) peso(s)!\n");
    for(int i=0;i<n;i++)
    {
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        v.push_back({a,b,w});
    }
    sort(v.begin(),v.end());
    int mst=0;
    for(int i=0;i<(int)v.size();i++)
    {
        int a = v[i].a;
        int b = v[i].b;
        int w = v[i].w;

        if(findset(a)!=findset(b))
        {
            unionset(a,b);
            mst+=w;
        }
    }
    printf("O valor da soma dos pesos da Minima Arvore Geradora foi %d",mst);
    return 0;
}
