#include<bits/stdc++.h>

using namespace std;
double Toler = 0.01;
int Iter = 0, c;
double funcao(double x)
{
    return x*x - 10;
}
double derivada(double x)
{
    return 2*x;
}
double newton(double x)
{
    double funcaox = funcao(x);
    if(funcaox<Toler)
        return x;
     c=0;
    while(abs(funcaox)>=Toler)
    {
        if(c==Iter)return -1;
        x-= (funcaox/derivada(x));
        funcaox = funcao(x);
        c++;
    }
    return x;
}
int main()
{
    printf("Entre com o x0, numero de iteracoes!\n");
    double val;scanf("%lf %d",&val,&Iter);
    if(newton(val) == -1)printf("Numero de iteracoes excedido!\n");
    else printf("X = %.4lf \nIter = %d\n",newton(val),c);

    return 0;
}
