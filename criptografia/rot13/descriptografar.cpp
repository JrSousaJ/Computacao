#include<bits/stdc++.h>

using namespace std;

int main()
{
    char s[1000];
    FILE *pf = fopen("rot13.txt", "r");
    fscanf(pf," %[^\n]",s);
    string ans = "";
    for(int i=0;i<strlen(s);i++)
    {
        s[i] = toupper(s[i]);
        int som = s[i] - 13;
        if(s[i]==' ')
            ans+=" ";
        else if(som < 65)
        {
            som+=26;
            ans+=som;
        }
        else
            ans+=som;
    }
    printf("A string %s, depois de descriptografada se torna: %s\n",s,ans.c_str());
    fclose(pf);
    return 0;
}
