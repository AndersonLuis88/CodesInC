#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>
#define tam 3


/*--------ESCOPOS--------*/
void menu();
void telaFim();
void telaFinal();
void telaExibi();

int numero();
void primoProximo();
int quantPrimo();

/*--------ESCOPOS--------*/


int main()
{
    setlocale(LC_ALL,"Portuguese");
    int op=100, num=0;
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
            num = numero(num);
            break;

        case 2:
            primoProximo(num);
            system("pause");
            break;

        case 3:
            quantPrimo(num);
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
    printf("1. Informar número\n");
    printf("2. Número primo mais próximo\n");
    printf("3. Quantidade de primos até o número\n");
    printf("0. Sair\n");

};


int numero(int num1){
    printf("Digite o número: ");
    scanf("%d", &num1);
    return num1;
};
/* RETORNA VERDADEIRO SE O NÚMERO FOR PRIMO. */
bool Primo(int num2){

    int cont=0;
    bool v=false;
    for (int i = 2; i <= num2 / 2; i++) {
    if (num2 % i == 0) {
       cont++;
       break;
    }
 }

 if (cont == 0){
    v = true;
    return v;
 }
 else{
    return v;
 }
};
/* EXIBE OS NÚMEROS PRIMOS, ATÉ O VALOR DIGITADO. */
int quantPrimo(int num2){
    bool vv=true;
    for(int i=2;i<=num2;i++){
            if(Primo(i)== vv){
                printf("Número %d é primo!\n", i);
            }
    }

};
/* RETORNA O PRIMO MAIS PRÓXIMO, DO VALOR DIGITADO. */
void primoProximo(int num2){

    bool vv=true;
    int n1,n2,n=0,m=0;
    n1 = num2;
    n2 = num2;

        for(int i=0;i<num2;i++){

        if(Primo(n1)== vv){
                n1 = n1;
                break;
            }
            n1++;
        }

        for(int i=0;i<num2;i++){

        if(Primo(n2)== vv){
                n2 = n2;
                break;
            }
            n2--;
        }


    //printf("Número primo mais próximo: %d\n", n1);
    //printf("Número primo mais próximo: %d\n", n2);

    int cmpAbaixo, cmpAcima;
    cmpAbaixo = num2 - n2;
    cmpAcima = n1 - num2;


    if (cmpAcima == cmpAbaixo){
        printf("\n\n\tDistâncias iguais\n\n\n");
    }else{
            if (cmpAcima > cmpAbaixo){
                printf("Número primo mais próximo: %d\n", n2);
            }else{
                printf("Número primo mais próximo: %d\n", n1);
            }
        }


}








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






