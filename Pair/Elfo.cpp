#include<bits/stdc++.h>

using namespace std;
int main()
{
    vector<pair<int,pair<int, pair<double, string> > > > v;
    int n;
    scanf("%d",&n);
    int c=1;
    while(n--)
    {
        int m,k;scanf("%d %d ",&m,&k);
        for(int i=0;i<m;i++)
        {
            string nome;
            int peso,idade;
            double altura;
            cin >> nome >> peso >> idade >> altura;
            v.push_back(make_pair(-peso, make_pair(idade, make_pair(altura, nome))));
        }
        sort(v.begin(),v.end());
        printf("CENARIO {%d}\n",c++);
        for(int i=0;i<k;i++)
        {
            printf("%d - %s\n",i+1,v[i].second.second.second.c_str());
        }
        v.clear();
    }

    return 0;
}
