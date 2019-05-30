#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#define tam 3


/*--------ESCOPOS--------*/
void menu();
void telaFim();
void telaFinal();
void telaExibi();

void cadastrar();
void ordemNome();
void exibiStruct();
void ordemCrescente();
/*--------ESCOPOS--------*/

typedef struct
{
    char nome[30];
    float preco;
    float maxPercent;
    float maxDesconto;
}Dados;

Dados cadastro[tam];


int main()
{
    setlocale(LC_ALL,"Portuguese");
    int op=100;
    do
    {

        menu();
        printf("\n\nDIGITE SUA OPÇÃO: ");
        scanf("%d", &op);
        fflush(stdin);
        system ("cls");
        switch (op)
        {
        case 1:
            cadastrar();
            telaFim();
            system ("cls");
            printf("\nDados cadastrados!\n\n\n");
            exibiStruct(cadastro);
            system("pause");
            break;

        case 2:
            ordemCrescente(cadastro);
            system("pause");
            break;

        case 3:
            ordemDecrescente(cadastro);
            system("pause");
            break;

        case 4:
            ordemNome();
            system("pause");
            break;
        }
        //telaFim();
        system ("cls");
    }
    while(op != 0);
    system ("cls");
    telaFinal();
    return 0;
}








/*----------FUNÇÕES---------*/
void menu()
{

    printf("\t********Menu********\n\n\n");
    printf("1. Cadastrar Produto\n");
    printf("2. Ordem Crescente (Valor com desconto)\n");
    printf("3. Ordem Decrescente (Valor com desconto)\n");
    printf("4. Ordenar por Nome\n");
    printf("0. Sair\n");

};

void telaFim()
{
    //Letreiro
    char tela[16] = "---Finalizando---";
    printf("\n\n\n");
    for(int j=0; j<sizeof(tela); j++)
    {
        printf("%c",tela[j]);
        Sleep(100);
    };
    //Fim Letreiro
};

void telaFinal()
{
    //Letreiro
    char tela[25] = "---Programa Finalizado---";
    printf("\n\n\n");
    for(int j=0; j<sizeof(tela); j++)
    {
        printf("%c",tela[j]);
        Sleep(100);
    };
    //Fim Letreiro
};
void telaExibi()
{
    char tela[30] = "------------------------------";
    for(int j=0; j<sizeof(tela); j++)
    {
        printf("%c",tela[j]);
        Sleep(10);
    };
};






void cadastrar()
{
    float valor=0.0, perc;
    int i;
    for(i=0; i<tam; i++)
    {
        printf("Nome do Produto: ");
        fgets(cadastro[i].nome, 30, stdin);
        printf("\nValor do Produto: ");
        scanf("%f", &cadastro[i].preco);
        fflush(stdin);
        printf("\nPorcentagem máxima de desconto: ");
        scanf("%f", &cadastro[i].maxPercent);
        fflush(stdin);
        valor = cadastro[i].preco;
        perc = cadastro[i].maxPercent;
        cadastro[i].maxDesconto = valor - (valor*(perc / 100));
    }
};


void ordemNome()
{
    //Dados ordemNome[tam];
    char aux[30];
    float preco, max, per;
    for( int i = 1; i < tam; i++ )
    {
        for( int j = i; j > 0; j-- )
        {
            if( strcoll(cadastro[j].nome, cadastro[j-1].nome) < 0)
            {
                strcpy(aux,cadastro[j].nome);
                strcpy(cadastro[j].nome,cadastro[j-1].nome);
                strcpy(cadastro[j-1].nome,aux);

                preco = cadastro[j].preco;
                cadastro[j].preco = cadastro[j-1].preco;
                cadastro[j-1].preco = preco;

                per = cadastro[j].maxPercent;
                cadastro[j].maxPercent = cadastro[j-1].maxPercent;
                cadastro[j-1].maxPercent = per;

                max = cadastro[j].maxDesconto;
                cadastro[j].maxDesconto = cadastro[j-1].maxDesconto;
                cadastro[j-1].maxDesconto = max;

            }
        }
    }
    exibiStruct(cadastro);

};

void ordemCrescente()
{

    char aux[30];
    float preco, max, per;
    for( int i = 1; i < tam; i++ )
    {
        for( int j = i; j > 0; j-- )
        {
            if(cadastro[j].maxDesconto < cadastro[j-1].maxDesconto)
            {
                strcpy(aux,cadastro[j].nome);
                strcpy(cadastro[j].nome,cadastro[j-1].nome);
                strcpy(cadastro[j-1].nome,aux);

                preco = cadastro[j].preco;
                cadastro[j].preco = cadastro[j-1].preco;
                cadastro[j-1].preco = preco;

                per = cadastro[j].maxPercent;
                cadastro[j].maxPercent = cadastro[j-1].maxPercent;
                cadastro[j-1].maxPercent = per;

                max = cadastro[j].maxDesconto;
                cadastro[j].maxDesconto = cadastro[j-1].maxDesconto;
                cadastro[j-1].maxDesconto = max;

            }
        }
    }
    exibiStruct(cadastro);

};

void ordemDecrescente()
{

    char aux2[30];
    float preco2, max2, per2;
    for( int i = 1; i < tam; i++ )
    {
        for( int j = i; j > 0; j-- )
        {
            if(cadastro[j].maxDesconto > cadastro[j-1].maxDesconto)
            {
                strcpy(aux2,cadastro[j].nome);
                strcpy(cadastro[j].nome,cadastro[j-1].nome);
                strcpy(cadastro[j-1].nome,aux2);

                preco2 = cadastro[j].preco;
                cadastro[j].preco = cadastro[j-1].preco;
                cadastro[j-1].preco = preco2;

                per2 = cadastro[j].maxPercent;
                cadastro[j].maxPercent = cadastro[j-1].maxPercent;
                cadastro[j-1].maxPercent = per2;

                max2 = cadastro[j].maxDesconto;
                cadastro[j].maxDesconto = cadastro[j-1].maxDesconto;
                cadastro[j-1].maxDesconto = max2;

            }
        }
    }
    exibiStruct(cadastro);

};









void exibiStruct(Dados exibi[tam])
{

    printf("\n\n\n");
    for(int i=0; i< tam; i++)
    {
        printf("\tProduto: %s \n", exibi[i].nome);
        telaExibi();
        printf("\nValor bruto: R$ %.2f \n", exibi[i].preco);
        telaExibi();
        printf("\nPorcentagem máxima para desconto:  %.0f % \n", exibi[i].maxPercent);
        telaExibi();
        printf("\nValor com desconto: R$ %.2f\n\n\n", exibi[i].maxDesconto);

    }
};





