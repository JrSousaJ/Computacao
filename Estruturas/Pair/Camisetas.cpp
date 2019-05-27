#include<bits/stdc++.h>

using namespace std;
int main()
{
    int k;
    bool q=true;
    while(~scanf("%d",&k))
    {
        if(!k)break;
        if(q)
        {
            q=false;
        }
        else if(!q)printf("\n");
        vector<pair<string,pair<int,string> > >v;
        map<int,char>kk;
        kk[0]='P';
        kk[1]='M';
        kk[2]='G';
        for(int i=0;i<k;i++)
        {
            char nome[10000],cor[1000],t;
            scanf(" %[^\n]",nome);
            scanf(" %s %c",cor,&t);
            v.push_back(make_pair(cor,make_pair((t=='P')? 0 : (t=='M')? 1 : 2,nome)));
        }
        sort(v.begin(),v.end());
        for(int i=0;i<k;i++)
        {
            printf("%s %c %s\n",v[i].first.c_str(),kk[v[i].second.first],v[i].second.second.c_str());
        }
    }
    return 0;
}