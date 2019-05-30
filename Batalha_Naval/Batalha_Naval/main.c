#include <stdio.h>
#include <stdlib.h>

int main()
{
    //===============INICIO CRIAR E PRINTAR BATALHA ===================================

    int batalha[6][6],batalha2[6][6];
    int i,j,z=0, z2=0;


    for(i=0; i<6;i++){

        for(j=0;j<6;j++){
            batalha[i][j] = z;
            z+= 1;
        }
        batalha[i][0] = z2;
        z2+= 1;
    }



    for(i=1; i <6;i++){

        for(j=1;j<6;j++){
            batalha[i][j] = 0;
        }
    }


    for(i=0; i <6;i++){

        for(j=0;j<6;j++){
            printf("\t\t%d  ", batalha[i][j]);
        }
        printf("\n\n");
    }


    //===============FIM CRIAR E PRINTAR BATALHA ===================================


    int cx,cy,cc=0;

    while(cc != 3){
    printf("Digite a coordenada x (Linha): \n");
    scanf("%d", &cx);
    printf("Digite a coordenada y (Coluna): \n");
    scanf("%d", &cy);

    batalha[cx][cy] = 1;
    cc+=1;
    };

    cc=0;

    while(cc != 4){
    printf("Digite a coordenada x (Linha), da bomba %d: \n", cc+1);
    scanf("%d", &cx);
    printf("Digite a coordenada y (Coluna), da bomba %d: \n", cc+1);
    scanf("%d", &cy);



    if(batalha[cx][cy] == 1)
    {
        printf("Na mosca.\n");
        batalha[cx][cy] = 10;
    }else{
        printf("Tiro N'agua.\n");
    }
    cc+=1;
    };

    for(i=0; i <6;i++){

        for(j=0;j<6;j++){
            printf("\t\t%d  ", batalha[i][j]);
        }
        printf("\n\n");
    }




















    return 0;
}
