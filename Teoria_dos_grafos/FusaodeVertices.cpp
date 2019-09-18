#include <bits/stdc++.h>

using namespace std;

int n;
/*
    Algoritmo de fusão de vértices
    Disciplina: Teoria dos grafos 4º período
    Aluno: Jairo de Sousa Júnior
    Github: github.com/JrSousaJ

*/
struct M
{
    int mat[105][105];

    M operator += (const M& q) const
    {
        M w;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n; j++)
                w.mat[i][j] = mat[i][j] + q.mat[i][j];
        }

        return w;
    }
};
M transformar(M a)
{
     for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(i == j)
                    a.mat[i][j] = 0;
                else if(a.mat[i][j] > 1)
                   a.mat[i][j] = 1;
            }
        }
    return a;
}
void fusao(M x)
{
    int tem = 1, f=1;
    while(tem && n)
    {
        x = transformar(x);
        tem = 0;

        int va,vb;

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(x.mat[i][j])
                {
                    tem = 1;
                    va = i;
                    vb = j;
                    f=0;
                    break;
                }
            }
            if(!f)break;
        }

        if(!tem)
            break;
        M nova;

        for(int i = 0 ; i < n ; i++)
        {
            x.mat[va][i] += x.mat[vb][i];
        }
        for(int i = 0 ; i < n ; i++)
        {
            x.mat[i][va] += x.mat[i][vb];
        }
        int p,q;
        for(int i = 0 , p = 0; i < n ; i++, p++)
        {
            if(i==vb)
            {
                p--;
            }
            else
            {
                for(int j = 0 ,q = 0; j < n ; j++, q++)
                {
                    if(j==vb)
                    {
                        q--;
                        continue;
                    }
                    nova.mat[p][q] = x.mat[i][j];
                }
            }

        }
        n--;
        x = nova;
    }

    if(n==1)
        printf("Grafo conexo!\n");
    else
        printf("Grafo nao conexo | %d componentes!\n", n);
}

int main()
{
   scanf("%d",&n);

    M x;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0; j < n ; j++) scanf("%d",&x.mat[i][j]);
    }

    fusao(x);
}
