#include <stdio.h>
#include "combinacao.h"
#include <time.h>

int main() {
    clock_t tempo;

    int maxTam = 0;

    FILE *arq = NULL;

    arq = fopen("testes.txt", "r");
    fscanf(arq, "%d", &maxTam);
    Item itens[maxTam];
    leArquivo(arq, itens, maxTam);
    for (int j = 0; j < maxTam; ++j) {
        printf("Peso: %d  Valor: %d", itens[j].peso, itens[j].valor);
        printf("\n");
    }
    printf("\n");
    printf("\n");
    int C= 40;
    int maior = 0;
    int num = 1;
    int *ptxMaior = &maior;
  //  int n = sizeof(m)/sizeof(peso[0]);
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