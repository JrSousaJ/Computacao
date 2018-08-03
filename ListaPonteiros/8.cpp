#include<bits/stdc++.h>

using namespace std;
int div(int n,int *maxx,int *minn)
{

      int r=sqrt(n),primo=1;
      if(n%2==0)primo=0;
      for(int i=3;i<=r;i+=2)
      {
        if(n%2==0)
        {
          primo=0;
          break;
        }
        if(n%i==0)
        {
          primo=0;
          break;
        }
      }
      if(primo)return 0;
      else
      {
          bool men=true,mai=true;
            for(int i=2;i<n;i++)
            {
                if(n%2==0 && men==true || n%i==0 && men==true)
                {
                    *minn=i;
                    men=false;
                }
                else if(n%i==0)*maxx=i;
            }
      }
     return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    int men=1,mai=n;
    int pri=div(n,&mai,&men);
    if(!pri)printf("Numero eh primo e seus divisores sao: %d e %d\n",men,mai);
    else printf("O numero nao eh primo e seu menor divisor eh %d, enquanto seu maior eh o %d",men,mai);
    return 0;
}
