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
        printf("\n\nDIGITE SUA OP��O: ");
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








/*----------FUN��ES---------*/
void menu()
{

    printf("\t********Menu********\n\n\n");
    printf("1. Informar n�mero\n");
    printf("2. N�mero primo mais pr�ximo\n");
    printf("3. Quantidade de primos at� o n�mero\n");
    printf("0. Sair\n");

};


int numero(int num1){
    printf("Digite o n�mero: ");
    scanf("%d", &num1);
    return num1;
};
/* RETORNA VERDADEIRO SE O N�MERO FOR PRIMO. */
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
/* EXIBE OS N�MEROS PRIMOS, AT� O VALOR DIGITADO. */
int quantPrimo(int num2){
    bool vv=true;
    for(int i=2;i<=num2;i++){
            if(Primo(i)== vv){
                printf("N�mero %d � primo!\n", i);
            }
    }

};
/* RETORNA O PRIMO MAIS PR�XIMO, DO VALOR DIGITADO. */
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


    //printf("N�mero primo mais pr�ximo: %d\n", n1);
    //printf("N�mero primo mais pr�ximo: %d\n", n2);

    int cmpAbaixo, cmpAcima;
    cmpAbaixo = num2 - n2;
    cmpAcima = n1 - num2;


    if (cmpAcima == cmpAbaixo){
        printf("\n\n\tDist�ncias iguais\n\n\n");
    }else{
            if (cmpAcima > cmpAbaixo){
                printf("N�mero primo mais pr�ximo: %d\n", n2);
            }else{
                printf("N�mero primo mais pr�ximo: %d\n", n1);
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






