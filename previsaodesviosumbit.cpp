#include<bits/stdc++.h>

using namespace std;
/*
    Algoritmo de previsão dinâmica de desvios considerando 2 bits.
    Aluno: Jairo de Sousa Júnior.
    4º Período - IFSULDEMINAS.
    Disciplina: Arquitetura e Organização de Computadores.
*/
int main()
{
    FILE *entrada;
    //Entrada de dados pelo arquivo dados.txt
    entrada = fopen("dados.txt", "r");
    char s[100000];
    //Leitura do arquivo
    fscanf(entrada," %s",&s);
    fclose(entrada);
    //Encerramento da entrada de dados.
    //Inicialização das variáveis de acertos e erros.
    int e=0,a=0;
    int contador = 0;
    int est = 0;
    //Mapa só para controlar os true e false.
    map<char,int>mapa;
    mapa['N'] = 0;
    mapa['T'] = 1;
     //Laço para percorrer a string.
    for(int i=0;i<strlen(s);i++)
    {
        //printf("%d %d %d i\n",i,mapa[s[i]],est);
        //Se o estado atual for igual á letra atual, o número de acertos aumenta e o contador zera.
        if(mapa[s[i]] == est)
        {

            a++;
            contador=0;
        }
        else //Se o estado atual for diferente da letra atual, o número de erros aumenta e o contador de erros aumenta,
        {
            e++;
            contador++;
        }
        if(contador == 1) //Se o meu contador chegar a um, ele muda de estado e zera o contador.
        {
            est= (est+1)%2;
            contador=0;
        }
    }
    printf("Numero de acertos: %d\n",a);
    printf("Numero de erros: %d\n",e);

    return 0;
}
