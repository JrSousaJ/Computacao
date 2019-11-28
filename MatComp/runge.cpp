#include <bits/stdc++.h>

using namespace std;

double f(double x, double y)
{
	return 2*x-2;
}

void runge(double a, double b, int m, double y0)
{
	double VX[m+1];
	double VY[m+1];

	double h = (b - a)/m;
	double xt = a;
	double yt = y0;

	VX[0] = xt;
	VY[0] = yt;
	double k1,k2,k3,k4;
	for(int i = 1 ; i <= m ;i++)
	{
		double x = xt;
		double y = yt;

		k1 = f(x,y);

		x = xt + h/2;
		y = yt + h/2*k1;

		k2 = f(x,y);
		y = yt + h/2*k2;

		k3 = f(x,y);

		x = xt + h;
		y = yt + h*k3;
		k4 = f(x,y);
		xt = a+i*h;
		yt = yt + h/6*(k1 + 2*(k2 + k3) + k4);
		printf("K1 = %.5lf |  K2 = %.5lf | K3 = %.5lf | K4 = %.5lf\n",k1*h,k2*h,k3*h,k4*h);
		printf("X = %.5lf | Y = %.5lf\n",xt,yt);

		VX[i] = xt;
		VY[i] = yt;
	}
}

int main()
{
	double a,b,y0;
	int m;
	printf("Algoritmo de Runge Kutta!\n");
	printf("Digite o limite inferior, superior, numero de intervalos e valor inicial, respectivamente:\n");
	scanf("%lf%lf%d%lf",&a,&b,&m,&y0);
	runge(a,b,m,y0);
}
