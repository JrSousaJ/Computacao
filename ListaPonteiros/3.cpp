#include<bits/stdc++.h>
using namespace std;
vector<string>sz;
void semidnv(char *c1,char *c2)
{
    int c=0;

         while(*c1!='\0')
        {
            if(*c1==' ')*c1='\n';
            *c2=*c1;
            c1++;
            c2++;
            c++;

        }
         *c2='\0';
}
int main()
{
    char s[100],s1[100];
    int z,c=0;
    scanf(" %[^\n]",s);
    z=strlen(s);
    semidnv(s,s1);
    printf("%s",s1);
    return 0;
}
