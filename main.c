#include <stdio.h>
#include "combinacao.h"
#include <time.h>
#include <string.h>
#include <malloc.h>

int main() {
    clock_t tempo;

    int maxTam = 0; //tamanho maximo das entradas
    int option = 0; //opção
    char nomeArq[20]; //nome do arquivo
    int qtd = 0;

    int pesoTot = 0; //peso total
    int valTot = 0; //valor total

    int maior = 0; //mostra qual o maior valor agregado da melhor combinacao atual
    int *ptxMaior = &maior; //ponteiro pra receber o valor de "maior" que esta dentro da funcao combinationUtil
    int num = 1; //num serve pra mostrar combinacao de quanto a quanto que foi processada

    Mochila mochila;
    mochila.capacidade = 140;


    FILE *arq = NULL;

    printf("|------------------------------------------\n");
    printf("|                                         |\n");
    printf("| (1) Inserir o nome do arquivo           |\n");
    printf("| (2) Sair                                |\n");
    printf("|                                         |\n");
    printf("|-----------------------------------------|\n");
    printf("Opção: ");
    scanf("%d", &option);
    getchar();

//----------------------------------leitura do arquivo------------------------------------------------------------------

    if(option == 1){
        printf("Nome: ");
        fgets(nomeArq, 20, stdin);
        nomeArq[strlen(nomeArq)-1] = '\0';
        arq = fopen(nomeArq, "r");
        if(arq == NULL){
            printf("Arquivo inexistente!\n");
            return 0;
        }
        //Item itens[maxTam];
        if(arq != NULL){
            fscanf(arq, "%d", &maxTam);
            CriaVetor(&mochila, maxTam);
            Item itens[maxTam];
            leArquivo(arq, itens, maxTam);

//---------------------------Imprime os dados lidos do arquivo----------------------------------------------------------

            for (int j = 0; j < maxTam; ++j) {
                printf("(%d) Peso: %d  Valor: %d", j, itens[j].peso, itens[j].valor);
                printf("\n");
            }
            printf("\n");
            printf("\n");
            printf("\n");

//--------------------------Comeca a calcular o tempo e as combinacoes--------------------------------------------------

            tempo = clock();

            for (int i = 1; i <= maxTam ; ++i) {
                printCombination(itens, &mochila, maxTam, i, mochila.capacidade, ptxMaior, &qtd);
                printf("%d Maior: %d\n", num, maior);
                num++;
            }

            tempo = clock() - tempo;
            printf("\n");
//----------------------------------impressao do resultado final--------------------------------------------------------

            printf("-----------------------------------------\n");
            printf("Capacidade da mochila: %d\n", mochila.capacidade);
            printf("Melhor combinação: ");

            for (int i = 0; i < qtd; i++){
                printf("(%d %d)", mochila.item[i].peso, mochila.item[i].valor);
                pesoTot += mochila.item[i].peso;
                valTot += mochila.item[i].valor;
            }
            printf("\n");
            printf("Peso total: %d/%d\n", pesoTot, mochila.capacidade);
            printf("Valor agregado: %d", valTot);

            printf("\n");
            printf("Tempo = %lf segundos\n",((double)tempo)/CLOCKS_PER_SEC);

            printf("-------------------------------------------\n");
        }

        fclose(arq);

    }else
        if(option == 2){
            printf("FIM!\n");
            return 0;
    }else
        printf("Opção inválida!!\n");
}