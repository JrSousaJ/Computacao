#include<bits/stdc++.h>
//corrigir questão do vetor pra armazenar os dados da decomposicao
using namespace std;

int fatr(int v[10],int n,int *pont)
{
    int c=0;
    int c1=0;
    while(n!=1)
    {
        while(n%v[c]==0)
        {
            n=n/v[c];
            c1++;
        }
            c++;
    }
    *pont=c1;
    if(*pont>10)return 1;
    else return 0;
}

int main()
{
    int x[10]={2,3,5,7,11,13,17,19,23,29};
    int n;
    int z;
    scanf("%d",&n);

    cout << fatr(x,n,&z) << endl;

    return 0;
}
