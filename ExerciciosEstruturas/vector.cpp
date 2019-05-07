#include<bits/stdc++.h>

using namespace std;

int main()
{
  //Algoritmo para exibir a maior soma de uma subsequência contígua num vetor
	int n;scanf("%d",&n);
	vector<int>v,aux,at;
	int atual=0,maior=-1;
	for(int i=0;i<n;i++)
	{
		int x;scanf("%d",&x);
		v.push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		if(v[i]>=atual+v[i])
		{
			atual = v[i];
			aux.clear();
			aux.push_back(v[i]);
		}
		else if(v[i]<atual+v[i])
		{
			atual+=v[i];
			aux.push_back(v[i]);
		}
		if(atual>maior)
		{
			at = aux;
			maior = atual;
		}
	}
	printf("Lista da maior subsequencia contigua no vetor\n");
	for(int i=0;i<at.size();i++)printf("%d ",at[i]);

	printf("\nMaior Soma possivel: %d\n",maior);
	return 0;
}
