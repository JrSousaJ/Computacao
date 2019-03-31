#include<bits/stdc++.h>

using namespace std;
int toDec(string sz)
{
    int ans=0,k=7;

    for(int i=0;i<sz.size();i++)
    {
        if(sz[i]=='1')ans+=pow(2,k);
        k--;
    }
    return ans;
}
string toBin(int x)
{
    string aux;
    while(x>0)
    {
        aux+=(x%2)+'0';
        x/=2;
    }
    reverse(aux.begin(),aux.end());
    return aux;
}
int main()
{
    char s[1000];
    scanf("%s",s);
    string aux;
    vector<string>v;
    int c=0;
    for (int i = 0; i < strlen(s); i++)
    {
        if(s[i]=='a')
            aux+="00";
        if(s[i]=='b')
            aux+="01";
        if(s[i]=='c')
            aux+="10";
        if(s[i]=='d')
            aux+="11";

        if(aux.size()==8)
        {
            v.push_back(aux);
            aux.clear();
        }
    }
    printf("A string %s ficou com %d bits depois da compactacao e ficou assim : ",s,v.size());
    vector<int> desc;
    for(int i=0;i<v.size();i++)
    {
        desc.push_back(toDec(v[i]));
        printf("%c",toDec(v[i]));
    }
    printf("\n");
    printf("Descompactando ...\n");
    v.clear();
    for(int i=0;i<desc.size();i++)
    {
        v.push_back(toBin(desc[i]));
    }
    for(int i=0;i<v.size();i++)
    {
        string ans;
        if(v[i].size()==6)ans+='a';
        for(int j=0;j<v[i].size();j+=2)
        {
            if(v[i][j]=='0' && v[i][j+1]=='0')ans+='a';
            else if(v[i][j]=='0' && v[i][j+1]=='1')ans+='b';
            else if(v[i][j]=='1' && v[i][j+1]=='0')ans+='c';
            else if(v[i][j]=='1' && v[i][j+1]=='1')ans+='d';
        }
        cout << ans;
    }
    printf("\n");
    return 0;
}
