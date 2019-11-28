#include<bits/stdc++.h>

using namespace std;
double funcao(double x, double y)
{
    return 2*x - 2;
}
int main()
{
    double a,b,m,y;
    scanf("%lf %lf %lf %lf",&a,&b,&m,&y);
    double h = (b-a)/m;
    double x = a;
    for(int i=1;i<=m;i++)
    {
        printf("%d %.5lf %.5lf \n",i,x,y);
        y = y + h*funcao(x,y);
        x+=h;
    }
    printf("%.4lf\n",y);
    return 0;
}
