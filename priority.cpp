#include<bits/stdc++.h>

using namespace std;
int c=0;
struct paciente
{
    int id;
    string nome,telefone;
    int grau;
};
vector<paciente>v;
int main()
{
    int n;
    priority_queue<pair<int,int> >k;
    while(1)
    {
        printf("1) Inserir na lista de espera.\n");
        printf("2) Doação disponível.\n");
        printf("3) Tamanho da fila.\n");
        printf("0) Sair\n");
        scanf("%d",&n);

        if(n==1)
        {
            char nome[1000],telefone[10];
            int grau,id=c++;
            scanf(" %[^\n]",nome);
            scanf(" %s",telefone);
            scanf("%d",&grau);
            v.push_back({id,nome,telefone,grau});
            k.push(make_pair(grau,id));
        }
        else if(n==2)
        {
            printf("Id do paciente: %d\n",v[k.top().second].id);
            printf("Nome do paciente: %s\n",v[k.top().second].nome.c_str());
            printf("Grau de urgencia do paciente: %d\n",v[k.top().second].grau);
            printf("Telefone do paciente: %s\n",v[k.top().second].telefone.c_str());
            k.pop();
        }
        else if(n==3)
        {
            printf("O tamanho da fila eh %d\n",v.size());
        }
        else if(n==0)
        {
            printf("Saindo...\n");
            break;
        }
        else printf("Operacao invalida\n");
    }

    return 0;
}
