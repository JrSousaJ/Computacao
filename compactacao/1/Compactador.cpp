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
    FILE *pf=fopen("compactado.txt","w");

    for(int i=0;i<v.size();i++)
    {
        printf("%c",toDec(v[i]));
        fprintf(pf,"%c",toDec(v[i]));
    }
    fclose(pf);
    printf("\n");

    return 0;
}
