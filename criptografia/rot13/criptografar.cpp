#include<bits/stdc++.h>

using namespace std;

int main()
{
    char ces[1001];
    printf("String a ser criptografada: ");
    scanf(" %[^\n]",ces);
    string ans = "";
    for(int i=0;i<strlen(ces);i++)
    {
        ces[i] = toupper(ces[i]);
        int som = ces[i] + 13;
        if(ces[i]==' ')
            ans+=" ";
        else if(som > 90)
        {
            som-=26;
            ans+=som;
        }
        else
            ans+=som;
    }
    printf("String criptografada com rot13: %s\n",ans.c_str());
    FILE *fp = fopen("rot13.txt", "w");
    fprintf(fp, "%s",ans.c_str());
    fclose(fp);
    return 0;
}
