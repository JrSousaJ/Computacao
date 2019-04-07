#include<bits/stdc++.h>

using namespace std;

int main()
{
    char ces[1001];
    printf("String a ser criptografada: ");
    scanf(" %[^\n]",ces);
    for(int i=0;i<strlen(ces);i++)
    {
        if(ces[i]>='A' && ces[i]<='M'|| ces[i]>='a' && ces[i]<='m')
            ces[i]+=13;
        else if(ces[i]>'M' && ces[i]<='Z'|| ces[i]>'m' && ces[i]<='z')
            ces[i]-=13;
    }
    printf("String criptografada com rot13: %s\n",ces);
    FILE *fp = fopen("rot13.txt", "w");
    fprintf(fp, "%s",ces);
    fclose(fp);
    return 0;
}
