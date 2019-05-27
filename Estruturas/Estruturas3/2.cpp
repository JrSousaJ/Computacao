#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    set<string>sera;
    queue<string>plc;
    while(1)
    {
    	printf("1-Adicionar carro\n");
	    printf("2-Retirar carro\n");
	    printf("3-Estado do Estacionamento\n");
	    printf("0-Sair\n");
	    scanf("%d",&n);
	    if(!n)break;
	    
	    if(n==1)
	    {
	    	printf("Qual a placa do carro? (Ex.: AAA-9999)\n");
	    	char s[100];
	    	scanf(" %[^\n]",s);
	    	while(strlen(s)!=8)
	    	{
	    		printf("Placa invalida, siga do exemplo: AAA-9999\n");
	    		scanf(" %[^\n]",s);
	    	}
	    	plc.push(s);
	    	sera.insert(s);
	    }
	    else if(n==2)
	    {
	    	printf("Placa do carro que se deseja retirar: ");
	    	char s[100];
	    	scanf(" %[^\n]",s);
	    	if(sera.find(s)!=sera.end())
	    	{
	    		printf("Retirando...\n");
	    		while(plc.front()!=s)
	    		{
	    			string k = plc.front();
	    			plc.pop();
	    			plc.push(k);
	    		}
	    		plc.pop();
	    		sera.erase(s);
	    	}
	    	else
	    		printf("Placa nao encontrada\n");
	    }
	    else if(n==3)
	    {
	    	printf("Quantidade de carros: %d\n",plc.size());
	    	int c=1;
	    	while(c<=plc.size())
	    	{

	    		string k = plc.front();
	    		plc.pop();
	    		plc.push(k);
	    		printf("Carro %d : %s\n",c,k.c_str());
	    		c++;
	    	}
	    }
    }
   
    return 0;
}