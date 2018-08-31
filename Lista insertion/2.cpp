#include<bits/stdc++.h>

using namespace std;
struct produtos
{
	int codigo;
	string descricao,tipo;
	double preco;
};
vector<produtos>v;
void ordena(int tam)
{
	int ch;
	for(int i=1;i<tam-tam;i++)
	{
		ch=v[i].tipo;
		int j=i-1;
		while(j>=0 && v[j].tipo>ch)
		{
			v[j+1]=v[j];
			j--;
		}
		v[j+1]=ch;
	}
}
int main()
{
	int x=1;
	int ret=0;
	while(x!=5)
	{
		printf("1-Cadastro de produtos\n");
		printf("2-Consultar produtos por tipo\n");
		printf("3-Consultar produtos por codigo\n");
		printf("4-Remover produto da lista\n");
		printf("5-Sair\n");
		scanf("%d",&x);
		if(x==1)
		{
			int codigo;
			string descricao,tipo;
			double preco;
			printf("\nCodigo: ");
			scanf("%d",&codigo);
			getchar();
			printf("\nDescricao: ");
			getline(cin,descricao);
			printf("\nTipo: ");
			cin >> tipo;
			printf("\nValor : R$");
			scanf("%lf",preco);
			v.push_back({codigo,descricao,tipo,preco});
		}
		if(x==2)
		{
			ordena(ret);

		}
	}
	

	
	return 0;
}
