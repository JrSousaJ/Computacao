#include<bits/stdc++.h>

using namespace std;
struct alunos
{
	string nome;
	double n1,n2;
	double media;
	bool aprovado;
};
vector<alunos>v;
void ordena(int x)
{
	alunos ch;
	for(int i=1;i<v.size();i++)
	{
		ch=v[i];
		int j=i-1;
		if(x==1)
        {
            while(j>=0 && v[j].media>ch.media)
            {
			v[j+1]=v[j];
			j--;
            }
        }
        else if(x==2)
        {
            while(j>=0 && v[j].n1>ch.n1)
            {
			v[j+1]=v[j];
			j--;
            }
        }
        else if(x==3)
        {
        	while(j>=0 && v[j].nome>ch.nome)
            {
			v[j+1]=v[j];
			j--;
            }
        }
		v[j+1]=ch;
	}
}
int main()
{
	for(int i=0;i<8;i++)
	{
		string nome;
		double n1,n2;
		double media;
		bool aprovado=false;

		printf("\nNome: ");
		getline(cin,nome);
		printf("\nNota 1(0-10): ");
		while(scanf("%lf",&n1),n1<0 || n1>10)printf("\nNota 1(0-10): ");
		printf("\nNota 2(0-10): ");
		while(scanf("%lf",&n2),n2<0 || n2>10)printf("\nNota 2(0-10): ");
		media=((n1*2+n2*3)/5.0);
		if(media>=7.0)aprovado=true;
		v.push_back({nome,n1,n2,media,aprovado});
		getchar();
	}
	printf("Alunos ordenados pela media ponderada de suas notas\n");
	ordena(1);
	for(int i=0;i<v.size();i++)
	{
		cout << "Nome: " << v[i].nome << endl;
		printf("Media: %.2lf\n\n",v[i].media);
	}
	printf("Alunos ordenados da pior nota da primeira prova ate a melhor nota\n");
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

