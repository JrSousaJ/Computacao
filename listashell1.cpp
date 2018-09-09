#include<bits/stdc++.h>

using namespace std;
struct produtos
{
	int codigo;
	string descricao,tipo;
	double preco;
};
vector<produtos>v;
void ordena(int tip)
{
	produtos ch;
	int pp=1;
	while(pp<v.size())
	{
		pp=3*pp+1;
	}
	while(pp>1)
	{
		pp/=3;
		for(int i=pp;i<v.size();i++)
		{
			ch=v[i];
			int j=i-pp;
			if(tip==2)
			{
				while(j>=0 && ch.tipo<v[j].tipo)
				{
					v[j+pp]=v[j];
					j-=pp;
				}
			}
			else if(tip==3)
			{
				while(j>=0 && ch.codigo<v[j].codigo)
				{
					v[j+pp]=v[j];
					j-=pp;
				}
			}
			
			v[j+pp]=ch;
		}
	}
		
}
int busca(int x)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i].codigo==x)return i;
    }
    return -1;
}
int main()
{
	int x=1;
	int ret=0;
	while(x!=5)
	{
		printf("\n1-Cadastro de produtos\n");
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
			scanf("%lf",&preco);
			v.push_back({codigo,descricao,tipo,preco});
		}
		if(x==2)
		{

			if(!v.size())printf("Nao existem produtos cadastrados\n\n");
			else
            {
                ordena(x);
                    for(int i=0;i<v.size();i++)
                {
                    printf("Codigo: %d\n",v[i].codigo);
                    cout << "Descricao: " << v[i].descricao << endl;
                    cout << "Tipo: " << v[i].tipo << endl;
                    printf("Valor: R$%.2lf\n\n",v[i].preco);
                }

            }

		}
		if(x==3)
		{

			if(!v.size())printf("Nao existem produtos cadastrados\n");
			else
            {
                ordena(x);
                for(int i=0;i<v.size();i++)
                {
                    printf("Codigo: %d\n",v[i].codigo);
                    cout << "Descricao: " << v[i].descricao << endl;
                    cout << "Tipo: " << v[i].tipo << endl;
                    printf("Valor: R$%.2lf\n\n",v[i].preco);
                }

            }
		}
		else if(x==4)
		{
		    int ans=-1;
            printf("Qual o codigo do produto que deseja apagar? ");
            int a;scanf("%d",&a);
            ans=busca(a);
            if(ans==-1)
            {
                printf("Produto nao encontrado\n\n");
            }
            else
            {
                v.erase(v.begin()+ans);
                printf("Produto apagado\n\n");
            }
		}
	}



	return 0;
}
