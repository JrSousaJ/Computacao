#include<bits/stdc++.h>

using namespace std;
//Definicão de "infinito" para valores inteiros.
const int oo = 0x3f3f3f3f;
int g[100][100],n;
//Matriz de memorização
//1LL << n tem como função jogar 1 bit à n posições para esquerda.
int memo[n][1LL<<n];
int pd(int v,int mask)
{
	//Verificação se já passei por todas as cidades.
	if(__builtin_popcount(mask)==n)
		return g[v][0];
	//Defino minha resposta inicial como "infinito".
	int ans = oo;
	//Verifico se já calculei anteriormente o meu estado atual.
	if(memo[v][mask]!=-1)
		return memo[v][mask];
	//Percorro as cidades.
	for(int i=0;i<n;i++)
	{
		//Verifico se a cidade atual já foi visitada.
		if(!((mask>>i)&1))
		{
			//Chamada recursiva buscando o menor valor possível entre a resposta atual
			//e a da próxima chamada recursiva.
			ans=min(ans,pd(i,mask|1<<i)+g[v][i])
		}
	}
	//Retorno minha resposta para minha matriz de memorização e para minha pilha recursiva.
	return memo[v][mask]=ans;
}

int main()
{
	return 0;
}
