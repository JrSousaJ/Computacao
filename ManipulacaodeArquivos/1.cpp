#include<bits/stdc++.h>

using namespace std;

int main(int arg, char *argv[])
{
    FILE *pf=fopen(argv[1],"w");

    char s[1001];
    scanf(" %[^\n]",s);
    fprintf(pf,"%s\n",s);
    fclose (pf);

}
