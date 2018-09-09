#include<bits/stdc++.h>

using namespace std;
struct alunos
{
	string nome;
	double n1,n2,n3;
	double media;
	bool aprovado;
};
vector<alunos>v;
void ordena(int tip)
{
	alunos ch;
	int pu=1;
	while(pu<v.size())
	{
		pu=3*pu+1;
	}
	while(pu>1)
	{
		pu/=3;
		for(int i=pu;i<v.size();i++)
		{
			ch=v[i];
			int j=i-pu;
			if(tip==1)
			{
				while(j>=0 && ch.media<v[j].media)
				{
					v[j+pu]=v[j];
					j-=pu;
				}
			}
			else if(tip==2)
			{
				while(j>=0 && ch.n1>v[j].n1)
				{
					v[j+pu]=v[j];
					j-=pu;
				}
			}
			else if(tip==3)
			{
				
					while(j>=0 && ch.nome<v[j].nome)
					{
						v[j+pu]=v[j];
						j-=pu;
					}
				
			}
			v[j+pu]=ch;
		}
	}
		
}
int main()
{
	for(int i=0;i<8;i++)
	{
		string nome;
		double n1,n2,n3;
		double media;
		bool aprovado=false;

		printf("\nNome: ");
		getline(cin,nome);
		printf("\nNota 1(0-10): ");
		while(scanf("%lf",&n1),n1<0 || n1>10)printf("\nNota 1(0-10): ");
		printf("\nNota 2(0-10): ");
		while(scanf("%lf",&n2),n2<0 || n2>10)printf("\nNota 2(0-10): ");
		printf("\nNota 3(0-10): ");
		while(scanf("%lf",&n3),n3<0 || n3>10)printf("\nNota 3(0-10): ");
		media=((n1*2+n2*3+n3*4)/9.0);
		if(media>=7.0)aprovado=true;
		v.push_back({nome,n1,n2,n3,media,aprovado});
		getchar();
	}
	printf("Alunos ordenados pela media ponderada de suas notas\n");
	ordena(1);
	for(int i=0;i<v.size();i++)
	{
		cout << "Nome: " << v[i].nome << endl;
		printf("Media: %.2lf\n\n",v[i].media);
	}
	printf("Alunos ordenados da melhor nota da primeira prova ate a pior nota\n");
	ordena(2);
	for(int i=0;i<v.size();i++)
	{
		cout << "Nome: " << v[i].nome << endl;
		printf("Nota da primeira prova: %lf\n\n",v[i].n1);
	}
	printf("Alunos aprovados\n");
	ordena(3);
	for(int i=0;i<v.size();i++)
	{
	    if(v[i].aprovado==true)
        {
            cout << "Nome: " << v[i].nome << endl;
            printf("Media %.2lf\n\n",v[i].media);
        }

	}
	return 0;
}
