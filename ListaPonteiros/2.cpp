#include<bits/stdc++.h>
using namespace std;

int semid(char *c1,char *c2, int n)
{
    int c=0;
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
    int z;
    scanf(" %[^\n]",s);
    z=strlen(s);
    z=semid(s,s1,z);
    printf("%s %d\n",s1,z);
    return 0;
}
