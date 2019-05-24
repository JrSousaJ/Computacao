#include<bits/stdc++.h>

using namespace std;
int main()
{
    vector<pair<int,pair<int,pair<int,string> > > > v;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        string s;
        int o,p,b;
        cin >> s >> o >> p >> b;
        v.push_back(make_pair(-o,make_pair(-p,make_pair(-b,s))));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        printf("%s %d %d %d\n",v[i].second.second.second.c_str(), -v[i].first, -v[i].second.first, -v[i].second.second.first);
    }
    return 0;
}
