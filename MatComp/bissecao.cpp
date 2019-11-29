#include<bits/stdc++.h>
using namespace std;
double Erro = 0.01;

double funcao(double x)
{
    return x*x - 10;
}
void bissecao(double a, double b)
{
    if (funcao(a) * funcao(b) >= 0)
    {
        printf("Voce nao definiu direito um A e B\n");
        return;
    }
    double c = a;
    while ((b-a) >= Erro)
    {
        c = (a+b)/2;

        if (funcao(c) == 0.0)
            break;
        else if (funcao(c)*funcao(a) < 0)
            b = c;
        else
            a = c;
    }
    printf("O valor da raiz e de: %.4lf\n",c);
}
int main()
{
    double a,b;
    printf("Entre com o A e o B!\n");
    scanf("%lf %lf",&a,&b);
    bissecao(a, b);
    return 0;
}
