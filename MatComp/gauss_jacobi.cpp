#include <bits/stdc++.h>
using namespace std;

/*
	Aluno: Jairo Sousa Júnior
	Disciplina: Matemática Computacional
	Conteúdo: Implementação do método de Gauss Jacobi
*/

const int MAXN = 10005;
vector<vector<double> >AUX;
double A[MAXN][MAXN];
double b[MAXN],x[MAXN],v[MAXN];
int IterMax,n;
double Toler = 0.05;
vector<int>inds; 

void Jacobi(int n)
{

	printf("Digite o numero maximo de iteracoes: ");
	scanf("%d",&IterMax);

	printf("Digite o vetor independente\n");
	for(int i = 0 ; i < n ; i++)
	{
		scanf("%lf",&b[inds[i]]);
		x[inds[i]] = b[inds[i]];
	}


	printf("Matriz de coenfientes apos as permutacoes de linha para que fosse possivel o metodo:\n");
	
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			
			A[i][j] = AUX[inds[i]][j];
			printf("%.2lf ",A[i][j]);
		}
		printf("\n");
	}



	for(int i = 0 ; i < n ; i++)
	{
		double r = 1.0/A[i][i];
		for(int j = 0 ; j < n ;j++)
		{
			if(i != j)
			{
				A[i][j] *= r;
				
			}
		}
		b[i] = b[i]*r;
		x[i] = b[i];

	}


	int iter = IterMax;
	double difmax;

	while(iter--)
	{

		for(int i = 0 ; i < n ; i++)
		{
			double soma = 0;
			for(int  j = 0 ; j < n ; j++)
			{
				if(i != j)
				{
					soma += A[i][j] * x[j];
				}
			}
		
			v[i] = b[i] - soma;
			
		}
		double normal1 = 0;
		double normal2 = 0;
		for(int i = 0 ; i < n ;i++)
		{
			if(fabs(v[i] - x[i]) > normal1)
				normal1 = fabs(v[i] - x[i]);
			if(fabs(v[i]) > normal2)
				normal2 = fabs(v[i]);
			x[i] = v[i];
		}

		difmax = normal1/normal2;


		if(difmax <= Toler)
		{
			break;
		}
		printf("\nValor das variaveis com taxa de erro %.4lf e %d iteracoes\n",difmax, IterMax - iter);
		for(int i = 0 ; i < n ; i++)
				printf("X[%d] = %.4lf\n",i+1,x[i]);

		printf("\n");
	}
	double erro = difmax;
	printf("Fim do metodo, pois temos uma taxa de erro menor que a tolerada, ou ultrapassamos o limite de iteracoes!\n\n");
	printf("\nValor das variaveis com taxa de erro %.4lf e %d iteracoes\n",erro, IterMax - iter);
	for(int i = 0 ; i < n ; i++)
		printf("X[%d] = %.4lf\n",i+1,x[i]);
	return;

}
int main()
{
	printf("------Gauss Jacobi------\n");
	
	printf("Digite a ordem da Matriz: ");
	scanf("%d",&n);

	AUX.assign(n, vector<double>());

	inds.clear();

	for(int i =  0 ; i < n ;i++)
		inds.push_back(i);

	printf("Digite a matriz de coeficientes do sistema linear:\n");

	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			double x;
			scanf("%lf",&x);
			AUX[i].push_back(x);
		}
			
	}
	
	printf("Teste para saber se e possivel aplicar o metodo de Gauss Jacobi!\n");
	bool possivel = false;

	do
	{

		int cont = n;
		for(int i = 0 ; i < n ; i++)
		{
			double sum = 0;
			for(int j = 0 ; j < n ; j++)
			{
				
				if(inds[i] != inds[j])
					sum += AUX[inds[i]][j];
			}
			
			
			if(fabs(sum) <= fabs(AUX[inds[i]][i]))
				cont--;
		}
		if(!cont)
		{
			possivel = true;
			break;
		}
	}while(next_permutation(inds.begin(),inds.end()));

	if(possivel)
	{		
		printf("\nEsse e um sistema linear onde Gauss Jacobi e aplicavel!\n");
		Jacobi(n);
	}
	else
	{
		printf("\nEsse e um sistema linear impossivel de ser aplicado o metodo Gauss Jacobi!\n");
		printf("Encerrando programa!\n");
		return 0;
	}
}
