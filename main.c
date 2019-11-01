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
    Item *itens = NULL;

    int C= 40;
    int maior = 0;
    int num = 1;
    int *ptxMaior = &maior;

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
        printf("%s", nomeArq);
        arq = fopen(nomeArq, "r");
        if(arq == NULL){
            printf("Arquivo inexistente!\n");
            return 0;
        } else{
            fscanf(arq, "%d", &maxTam);
            itens = (Item*) malloc(maxTam*sizeof(Item));
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
                printCombination(itens, maxTam, i, C, ptxMaior);
                printf("%d Maior: %d\n", num, maior);
                num++;
            }
            tempo = clock() - tempo;
            printf("Tempo = %lf",((double)tempo)/CLOCKS_PER_SEC);
        }
    }else
        if(option == 2){
            printf("FIM!\n");
            free(itens);
            return 0;
    }else
        printf("Opção inválida!!\n");
}