#include<bits/stdc++.h>

using namespace std;
/*
	Multiplicação de matrizes de adjacência para verificação se a mesma é conexa
	Aluno: Jairo de Sousa Júnior
	Período: 4º período
	Disciplina: Teoria dos Grafos
	Professor: Ricardo Martins
*/

int n,m;
int main()
{

	
	printf("Digite quantidade de vertices\n");
	scanf("%d",&n);
	int principal[n][n],secondaria[n][n],auxiliar[n][n],resposta[n][n];

	memset(principal,0,sizeof principal);
	memset(secondaria,0,sizeof secondaria);
	memset(auxiliar,0,sizeof auxiliar);
	memset(resposta,0,sizeof resposta);

	printf("Entre com a matriz!\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&principal[i][j]);
			resposta[i][j] = secondaria[i][j] = principal[i][j];
		}
	}
	for (int k = 1; k < n-1; k++)
	{
		for(int i=0;i<n;i++)
		{
			
			for(int j=0;j<n;j++)
			{
				auxiliar[i][j]=0;
				for(int z=0;z<n;z++)
				{
					auxiliar[i][j]+= secondaria[i][z] * principal[z][j];
				}
			}
		}
		
		for(int i=0;i<n;i++)
		{
				for(int j=0;j<n;j++)
				{
					principal[i][j]=auxiliar[i][j];
					resposta[i][j]+=principal[i][j];
				}
		}
		
	}
	printf("Resultado da matriz^%d\n",n-1);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ", resposta[i][j]);
		}
		printf("\n");
	}
	return 0;
}
