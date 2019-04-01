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
    printf("Descompactando ...\n");
    FILE *pf = fopen("compactado.txt","r");
    vector<int> desc;
    char s[1000];
    fscanf(pf,"%s",s);
    fclose(pf);
    for(int i=0;i<strlen(s);i++)
    {
        int x=s[i];
        desc.push_back(x);
    }
    vector<string>v;
    for(int i=0;i<desc.size();i++)
    {
        v.push_back(toBin(desc[i]));
    }
    FILE *xa = fopen("descompactado.txt","w");
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
        fprintf(pf,"%s",ans.c_str());
        cout << ans;
    }
    printf("\n");
    return 0;
}
