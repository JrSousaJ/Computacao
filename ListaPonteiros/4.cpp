#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a=2,b=3,c=4,d=5;
    float e=6,f=7,g=8,h=9;
    char s[10]={'t','e','x','t','o','.','t','x','t','t'};
    int x=25;
    int *ptr=&a;
    cout << *ptr << endl;
    ptr++;
    if(*ptr!=a)printf("O valor do ponteiro agora nao tem mais o valor de a e sim da variavel declarada apos ele: %d\n",*ptr);

   //Isso acontece pois eu andei 1 posição na memória, sendo assim ele apontou para a proxima variavel na memória, no meu caso o b
    
   
    return 0;
}
