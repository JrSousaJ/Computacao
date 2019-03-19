#include<bits/stdc++.h>

using namespace std;

int main(int arg, char *argv[])
{
    FILE *pf=fopen(argv[1],"r");
    FILE *fp=fopen(argv[2],"w");
    char s[1001];
    fgets(s,100,pf);
    fputs(s,fp);
    fclose (pf);
    fclose(fp);

}
