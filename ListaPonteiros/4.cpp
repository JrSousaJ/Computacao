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
    if(*ptr==a)printf("Tem o valor de 'a'\n");
    else if(*ptr==b)printf("Tem valor de 'b'\n");
    else if(*ptr==c)printf("Tem valor de 'c'\n");
    else if(*ptr==d)printf("Tem valor de 'd'\n");
    else if(*ptr==e)printf("Tem valor de 'e'\n");
    else if(*ptr==f)printf("Tem valor de 'f'\n");
    else if(*ptr==g)printf("Tem valor de 'g'\n");
    else if(*ptr==s[0])printf("Tem valor de 's' na posicao 0\n");
    else if(*ptr==x)printf("Tem valor de 'x'\n");
    else printf("Nao conincidiu com nenhum endereco");


   //Isso acontece pois eu andei 1 posição na memória, sendo assim ele apontou para a proxima variavel na memória
    
   
    return 0;
}
