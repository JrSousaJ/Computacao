#include<bits/stdc++.h>

using namespace std;

int main()
{
    char ces[1001];
    int chave;
    printf("Qual a chave? ");
    scanf("%d",&chave);
    printf("\n");
    printf("String a ser criptografada: ");
    scanf(" %[^\n]",ces);
    printf("\n");
    for(int i=0;i<strlen(ces);i++)
    {
        if(isupper(ces[i]))
            ces[i] = (ces[i]+chave-65)%26 + 65;
        else ces[i] = (ces[i]+chave-97)%26 + 97;
    }
    printf("String criptografada : %s\n",ces);
    FILE *fp = fopen("cesar.txt", "w+");
    fprintf(fp,"%d %s",chave,ces);
    fclose(fp);
    return 0;
}
