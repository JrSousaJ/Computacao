#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll soma,prod;
int func(ll *ptr,ll *ptr2)
{
    soma=*ptr+*ptr2;
    prod=*ptr * *ptr2;
    if(soma>INT_MAX || prod>INT_MAX)return -1;
    if(*ptr==*ptr2)return 1;
    return 0;

}
int main()
{
    ll n,n2;
    scanf("%lld%lld",&n,&n2);
    int sera=func(&n,&n2);
    if(sera==1)printf("Os numeros sao iguais\n");
    else if(!sera)printf("Os numeros sao diferentes\n");
    else printf("Os numeros somados ou multiplicados estouram a variavel do tipo int\n");
    printf("Soma de %lld + %lld = %lld\n",n,n2,soma);
    printf("Produto de %lld * %lld = %lld\n",n,n2,prod);
    return 0;
}
