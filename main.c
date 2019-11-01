#include <stdio.h>
#include "combinacao.h"
#include <time.h>
#include <string.h>
#include <malloc.h>

int main() {
    clock_t tempo;

    int maxTam = 0;
    int option = 0;
    char nomeArq[20];
    int qtd = 0;

    int pesoTot = 0;
    int valTot = 0;

    int maior = 0;
    int num = 1;
    int *ptxMaior = &maior;

    Mochila mochila;
    mochila.capacidade = 50;


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

    if(option == 1){
        printf("Nome: ");
        fgets(nomeArq, 20, stdin);
        nomeArq[strlen(nomeArq)-1] = '\0';
        arq = fopen(nomeArq, "r");
        if(arq == NULL){
            printf("Arquivo inexistente!\n");
            return 0;
        }
        Item itens[maxTam];
        if(arq != NULL){
            fscanf(arq, "%d", &maxTam);
            CriaVetor(&mochila, maxTam);
            Item itens[maxTam];
            leArquivo(arq, itens, maxTam);
            for (int j = 0; j < maxTam; ++j) {
                printf("Peso: %d  Valor: %d", itens[j].peso, itens[j].valor);
                printf("\n");
            }
            printf("\n");
            printf("\n");
            printf("\n");

            tempo = clock();

            for (int i = 1; i <= maxTam ; ++i) {
                printCombination(itens, &mochila, maxTam, i, mochila.capacidade, ptxMaior, &qtd);
                printf("%d Maior: %d\n", num, maior);
                num++;
            }
            printf("\n");

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

            tempo = clock() - tempo;
            printf("\n");
            printf("Tempo = %lf segundos\n",((double)tempo)/CLOCKS_PER_SEC);

            printf("-------------------------------------------\n");
        }
    }else
        if(option == 2){
            printf("FIM!\n");
            return 0;
    }else
        printf("Opção inválida!!\n");
}