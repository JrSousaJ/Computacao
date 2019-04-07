#include<bits/stdc++.h>

using namespace std;

int main()
{
    char ces[1001];
    int chave;
    FILE *pf = fopen("cesar.txt", "r");
    fscanf(pf, "%d %s",&chave, ces);
    fclose(pf);
    for(int i=0;i<strlen(ces);i++)
    {
        if(ces[i]<'A'+chave)
            ces[i] = 'Z'-chave + (ces[i]-'A')+1;
        else ces[i]-= chave;
    }
    printf("String descriptada: %s\n",ces);
    return 0;
}
