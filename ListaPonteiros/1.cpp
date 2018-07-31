#include<bits/stdc++.h>
using namespace std;
int x[10]={2,3,5,7,11,13,17,19,23,29};
int fatr(int v[101],int n,int *pont)
{
    int c=0;
    int c1=0;
    while(n!=1)
    {
        while(n%x[c]==0)
        {
            n/=x[c];
            v[c1++]=x[c];
        }
            c++;
    }
    *pont=c1;
    if(*pont>10)return 1;
    else return 0;
}

int main()
{
    int n,b[101];
    int z;
    scanf("%d",&n);

    cout << fatr(b,n,&z) << endl;

    return 0;
}
