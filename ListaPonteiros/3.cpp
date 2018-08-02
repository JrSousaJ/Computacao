#include<bits/stdc++.h>
using namespace std;
int semidnv(char *c1,char *c2, int n)
{
    int c=0;
    c1+=n;
    while(*c1!=' ')
    {
        if(*c1==' ')break;
        *c2=*c1;
        c1++;
        c2++;
        c++;

    }
    *c2='\0';
    return c;

}
int main()
{
    char s[100],s1[100];
    int z,c=0;
    scanf(" %[^\n]",s);
    z=strlen(s);
    for(int i=0;i<z-1;i++)
    {
        i+=semidnv(s,s1,i);
        printf("%s\n",s1);
    }
    
   
    return 0;
}
