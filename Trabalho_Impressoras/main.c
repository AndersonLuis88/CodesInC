#include"stdio.h"
#include"stdlib.h"
#include"locale.h"
#include"windows.h"
int cc=0, ads=100;
typedef struct dados{
	int id_impressora;
	struct dados *proximo;
}impressora;

impressora *criar(){
	impressora *novo = (impressora*)malloc(sizeof(impressora));
	novo->proximo = NULL;
	return novo;
}
impressora push(impressora *PILHA){
    impressora *novo=criar();
    novo->proximo = NULL;

    if(PILHA==NULL)
        PILHA->proximo=novo;
    else
    {
        impressora *tmp = PILHA->proximo;

        while(tmp->proximo != NULL)
            tmp = tmp->proximo;

        tmp->proximo = novo;
    }
}
void telaFim(){
    //Letreiro
    char tela [34] = "--------Retornando ao menu--------";
    printf("\n\n\n");
    int j;
    for(j=0; j<sizeof(tela); j++)
    {
        printf("%c",tela[j]);
        Sleep(80);
    };
    //Fim Letreiro
};
impressora *pop(impressora *PILHA){
    if(PILHA->proximo == NULL)
    {
        printf("Pilha vazia\n\n");
        telaFim();
        cc = 2;
        return NULL;
    }
    else
    {
        impressora *ultimo = PILHA->proximo,
                    *penultimo = PILHA;

        while(ultimo->proximo != NULL)
        {
            penultimo = ultimo;
            ultimo = ultimo->proximo;
        }

        penultimo->proximo = NULL;
        return ultimo;
    }
}


impressora *ad_impressora(impressora *inicio){
	impressora *temp = inicio;
	int ad;
	system("cls");
	printf("=== Adicionar Impressora ===\n\n\n");
	printf("1 - Impressão da gerência\n2 - Impressão da subgerência\n3 - Impressão do atendimento\n0 - Para altos investimentos\n\n---\n");
	do{
		scanf("%d",&ad);
		ads = ad;
		fflush(stdin);
	}while(ad<0||ad>4);
	if(inicio==NULL){
		inicio = criar();
		inicio->id_impressora = ad;
	}
	else if(ad>=inicio->id_impressora){
		inicio = criar();
		inicio->id_impressora = ad;
		inicio->proximo = temp;
	}
	else{
		while(inicio->proximo!=NULL&&inicio->proximo->id_impressora>=ad){
			inicio = inicio->proximo;
		}
		impressora *aux = inicio->proximo;
		inicio->proximo = criar();
		inicio = inicio->proximo;
		inicio->id_impressora = ad;
		inicio->proximo = aux;
		inicio = temp;
	}
	return inicio;
}

void imprimir(impressora *inicio){
	system("cls");
	if(inicio==NULL){
		printf("=== Fila de Impressão ===\n\n\nNão tem impressão para fila de espera no momento!\n\n\n");
		telaFim();
	}
	else{
		impressora *temp = inicio, *prox;

	while(cc != 2){

		printf("=== Fila de Impressão ===\n\n\n");
		while(temp!=NULL){
			printf("Imprimindo %s\n",temp->id_impressora==0?"alto investimento":temp->id_impressora==1?"gerência":temp->id_impressora==2?"subgerência":"atendimento");
			temp = temp->proximo;
		}
		printf("\n\n");

		printf("1. Imprimir Primeiro Item\n\n");
        printf("2. Retornar Menu Principal\n\n");
        scanf("%d", &cc);
                if (cc==1){
                    prox = inicio;
                    pop(inicio);
                    temp = prox;
                    system("cls");

                }
		}
	}
	//system("pause");
	cc=0;
}

void menu(impressora *inicio){
	int var_menu;
	do{
		system("cls");
		printf("=== C - Investimentos ===\n\n\n");
		printf("1 - Adicionar impressora na fila de impressão\n2 - Iniciar impressão(ões)\n3 - Sair\n\n---\n");
		do{
			scanf("%d",&var_menu);
			fflush(stdin);
		}while(var_menu<1||var_menu>3);
		switch(var_menu){
			case 1:
				inicio = ad_impressora(inicio);
				break;
			case 2:
				imprimir(inicio);
				break;
			case 3:
				free(inicio);
				exit(0);
		}
	}while(var_menu!=3);
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	impressora *principal = NULL;
	menu(principal);
	return 0;
}
