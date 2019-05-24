#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    map<double,string>m;
    while(n--)
    {
        char nome[1000];
        double sal;
        scanf(" %[^\n]",nome);
        scanf("%lf",&sal);
        m[sal] = nome;
    }
    map<double,string>::iterator it,aux;

    for(it=m.begin();it!=m.end();it++)
    {
        if(it==m.begin())printf("O funcionario com menor salario eh o %s\n",it->second.c_str());
        if(it!=m.end())aux = it;
    }
    printf("O funcionario com maior salario eh o %s\n",aux->second.c_str());



    return 0;
}
