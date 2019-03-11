#include<bits/stdc++.h>

using namespace std;
int main()
{
	int n;scanf("%d",&n);
	while(n--)
	{
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		double k=(b*b)-(4*a*c);
		printf("%.2lf\n",abs(k/(4*a)));
	}
	return 0;
}
