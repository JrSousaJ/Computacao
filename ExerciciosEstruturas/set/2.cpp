#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    set<int>A,B,C;
    for(int i=0;i<n;i++)
    {
        int a;scanf("%d",&a);
        A.insert(a);
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;scanf("%d",&a);
        B.insert(a);
    }
    set<int>::iterator it;
    for(it = A.begin();it!=A.end();it++)
    {
        if(B.count(*it))
            C.insert(*it);
    }
    for(it = B.begin();it!=B.end();it++)
    {
         if(A.count(*it))
            C.insert(*it);
    }
    printf("Conjunto gerado: \n");
    for(it = C.begin();it!=C.end();it++)
    {
        printf("%d ",*it);
    }

    return 0;
}
