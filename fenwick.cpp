#include<bit/stdc++.h>

using namespace std;
int bitt[10000];
const int maxind=10000;
int getS(int index,int m)
{
	int soma=0;
	while(index>m)
	{
		soma+=bitt[index];
		index-=index & (-index);
	}
	return soma;
}
void update(int index,int val)
{
	while(index<=maxind)
	{
		bitt[index]+=val;
		index+=index & (-index);
	}
}
int main()
{

	return 0;
}
