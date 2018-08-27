#include<bits/stdc++.h>

using namespace std;
struct autom
{
	string marca,placa;
	int ano;
	int estoque;
};
vector<autom>v;
void ordano()
{
	for(int i=0;i<v.size()-1;i++)
			{
				int min=i;
				for(int j=i+1;j<v.size();j++)
				{
					if(v[j].ano<v[min].ano)
					{
						min=j;
					}
				}
				if(i!=min)swap(v[i],v[min]);
			}
}
void ordmarca()
{
	 for(int i=0;i<v.size()-1;i++)
			{
				int min=i;
				for(int j=i+1;j<v.size();j++)
				{
					if(v[j].marca<v[min].marca)
					{
						min=j;
					}
				}
				if(i!=min)swap(v[i],v[min]);
			}
}
void ordplaca()
{
	 for(int i=0;i<v.size()-1;i++)
		{
				int min=i;
				for(int j=i+1;j<v.size();j++)
				{
					if(v[j].placa<v[min].placa)
					{
						min=j;
					}
				}
				if(i!=min)swap(v[i],v[min]);
		}
}
void ordestoque()
{
	 for(int i=0;i<v.size()-1;i++)
		{
				int min=i;
				for(int j=i+1;j<v.size();j++)
				{
					if(v[j].estoque<v[min].estoque)
					{
						min=j;
					}
				}
				if(i!=min)swap(v[i],v[min]);
		}
}
int main()
{
	int n=1;
	while(n)
	{
		printf("\n1-Cadastro de carros\n");
		printf("2-Ordenar por ano\n");
		printf("3-Ordenar por marca\n");
		printf("4-Ordenar pelo numero da placa\n");
		printf("5-Ordenar pelo estoque\n");
		printf("0-Parar ;D\n");
		scanf("%d",&n);
		if(n==1)
		{
			printf("Quantos carros deseja cadastrar? ");
			int x;scanf("%d",&x);
			for(int i=0;i<x;i++)
			{
				string marca,placa;
				int ano,estoque;
				printf("\nMarca: ");
				cin >> marca;
				printf("\nAno: ");
				scanf("%d",&ano);
				printf("\nPlaca: ");
				cin >> placa;
				printf("\nEstoque: ");
				scanf("%d",&estoque);
				v.push_back({marca,placa,ano,estoque});
			}
		}
		else if(n==2)
		{
			ordano();
			for(int i=0;i<v.size();i++)
            {
                cout << "\nMarca: " << v[i].marca << "\n";
                cout << "Placa: " << v[i].placa << "\n";
                cout << "Ano: " << v[i].ano << "\n";
                cout << "Estoque: " << v[i].estoque << "\n";
            }
		}
		else if(n==3)
        {
           ordmarca();
			for(int i=0;i<v.size();i++)
            {
                cout << "\nMarca: " << v[i].marca << "\n";
                cout << "Placa: " << v[i].placa << "\n";
                cout << "Ano: " << v[i].ano << "\n";
                cout << "Estoque: " << v[i].estoque << "\n";
            }

        }
        else if(n==4)
        {
           ordplaca();
			for(int i=0;i<v.size();i++)
            {
                cout << "\nMarca: " << v[i].marca << "\n";
                cout << "Placa: " << v[i].placa << "\n";
                cout << "Ano: " << v[i].ano << "\n";
                cout << "Estoque: " << v[i].estoque << "\n";
            }
        }
        else if(n==5)
        {
           ordestoque();
			for(int i=0;i<v.size();i++)
            {
                cout << "\nMarca: " << v[i].marca << "\n";
                cout << "Placa: " << v[i].placa << "\n";
                cout << "Ano: " << v[i].ano << "\n";
                cout << "Estoque: " << v[i].estoque << "\n";
            }
        }
	}
	return 0;
}
