#include<bits/stdc++.h>

using namespace std;

/*
	Aluno: Jairo Sousa Júnior
	Disciplina: Matemática Computacional
	Conteúdo: Implementação do método dos mínimos quadrados
*/

struct pontos
{
	double x,y;
};
pontos v[10000];
int main()
{
	printf("Qual a quantidade de pontos?\n");
	int n;scanf("%d",&n);
	printf("Entre com os pontos\n");
	for(int i=0;i<n;i++)
	{
		scanf("%lf%lf",&v[i].x, &v[i].y);
	}
	double somx=0,somy=0,xy=0,x2=0;
	for(int i=0;i<n;i++)
	{
		somx+=v[i].x;
		somy+=v[i].y;
		xy+= (v[i].x*v[i].y);
		x2+= (v[i].x*v[i].x);
	}
	printf("%.4lf\n",somx*somy);
	double b1 = ((somx * somy) - (n*xy))/((somx*somx)- (double)n*x2);
	double b0 = (double)(somy - b1*somx)/n;
	printf("Equacao da reta que passa proxima a todos os pontos dados:\n");
	printf("M = %.4lf + (%.4lf)X\n",b0,b1);

	return 0;
}
