#include<bits/stdc++.h>

using namespace std;
struct comp
{
	int codigo;
	string nome;
	long long int tempo;
};
vector<comp>v;
void ordena(int n1)
{
	for(int i=0;i<v.size()-1;i++)
			{
				int min=i;
				for(int j=i+1;j<v.size();j++)
				{
					if(n1==1)
					{
						if(v[j].codigo<v[min].codigo)
						{
							min=j;
						}
					}
					else if(n1==2)
					{
						if(v[j].nome<v[min].nome)
						{
							min=j;
						}
					}
					else if(n1==3)
					{
						if(v[j].tempo<v[min].tempo)
						{
							min=j;
						}
					}

				}
				if(i!=min)swap(v[i],v[min]);
			}
}
int main()
{
	int a=6;
	for(int i=0;i<10;i++)
	{
		string nome;
		int codigo;
		int tempo,m;
		printf("\nCodigo: ");
		cin >> codigo;
		printf("\nNome: ");
		cin >> nome;
		printf("\nTempo no formato minutos:segundos(Ex.:10:20): ");
		scanf("%d:%d",&m,&tempo);
		tempo+=(m*60);
		v.push_back({codigo,nome,tempo});
	}
	while(a)
	{
		printf("1-Ordenar por codigo\n");
		printf("2-Ordenar por nome\n");
		printf("3-Resultado final da corrida\n");
		printf("4-Sair\n");
		scanf("%d",&a);
		if(a==1)
		{
			ordena(a);
			for(int i=0;i<v.size();i++)
			{
				cout << "Codigo: " << v[i].codigo << endl;
				cout << "Nome: " << v[i].nome << endl;
				int m=v[i].tempo/60;
				int seg=v[i].tempo%60;
				cout << "Tempo: " << m << ":" << seg << endl;
			}
		}
		if(a==2)
		{
			ordena(a);
			for(int i=0;i<v.size();i++)
			{
				cout << "Codigo: " << v[i].codigo << endl;
				cout << "Nome: " << v[i].nome << endl;
				int m=v[i].tempo/60;
				int seg=v[i].tempo%60;
				cout << "Tempo: " << m << ":" << seg << endl;
			}
		}
		else if(a==3)
		{
			ordena(a);
			for(int i=0;i<v.size();i++)
			{
				printf("Posicao: %d\n",i+1);
				cout << "Codigo: " << v[i].codigo << endl;
				cout << "Nome: " << v[i].nome << endl;
				int m=v[i].tempo/60;
				int seg=v[i].tempo%60;
				cout << "Tempo: " << m << ":" << seg << endl << endl;
			}
		}
	}

	return 0;
}
