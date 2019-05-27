#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    printf("Qual o tamanho do conjunto?\n");
    scanf("%d",&n);
    set<int>conj1,conj2;
    while(n--)
    {
        int a;scanf("%d",&a);
        conj1.insert(a);
    }
    printf("Qual o tamanho do conjunto?\n");
    scanf("%d",&n);
    while(n--)
    {
        int a;scanf("%d",&a);
        conj2.insert(a);
    }
    set<int>uniao;
    set<int>::iterator it,ti;
    for(it = conj1.begin();it!=conj1.end();it++)
    {
        uniao.insert(*it);
    }
    for(it = conj2.begin();it!=conj2.end();it++)
    {
        uniao.insert(*it);
    }
    printf("Uniao entre o conjunto A e B \n");
    for(it = uniao.begin();it!=uniao.end();it++)
    {
        printf("%d\n",*it);
    }
    set<int>inter;
    for(it = conj1.begin();it!=conj1.end();it++)
    {
        if(conj2.find(*it)!=conj2.end())inter.insert(*it);
    }
    for(it = conj2.begin();it!=conj2.end();it++)
    {
        if(conj1.find(*it)!=conj1.end())inter.insert(*it);
    }
    printf("Interseccao entre o conjunto A e B \n");
    for(it = inter.begin();it!=inter.end();it++)
    {
        printf("%d\n",*it);
    }
    set<int>dif;
    for(it = conj1.begin();it!=conj1.end();it++)
    {
        if(conj2.find(*it)==conj2.end())dif.insert(*it);
    }
    printf("Diferenca entre o conjunto A e B \n");
    for(it = dif.begin();it!=dif.end();it++)
    {
        printf("%d\n",*it);
    }
    return 0;
}