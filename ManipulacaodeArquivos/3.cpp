#include<bits/stdc++.h>

using namespace std;
struct alunos
{
    int matricula;
    char nome[50], endereco[50], curso[15];
}v[50];
int main()
{
    FILE *fp;
    bool op=false;
    fp = fopen("bin.dat", "wb+");
    int i=0,j=0;
    for(;;)
    {
        printf("1) Inserir Aluno.\n");
        printf("2) Gravar alunos e sair.\n");
        printf("0) Sair\n");
        int a;scanf("%d",&a);
        if(!a)break;
        if(a==1)
        {
            printf("Matricula: ");
            scanf("%d",&v[i].matricula);
            printf("\nNome: ");
            scanf(" %[^\n]",v[i].nome);
            printf("\nEndereco: ");
            scanf(" %[^\n]",v[i].endereco);
            printf("\nCurso: ");
            scanf(" %[^\n]",v[i].curso);
            printf("\n");
            i++;
        }
        else if(a==2)
        {
            printf("Gravando no arquivo bin.dat\n");
            fwrite(&v, sizeof(struct alunos), i, fp);
            printf("Saindo...\n");
            break;
        }

    }
    fclose(fp);
    return 0;
}
