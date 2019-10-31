//
// Created by lazarus on 29/10/19.
//

#include "combinacao.h"
#include <stdio.h>
#include <stdlib.h>

void combinationUtil(Item *item,int data[], int valComb[], int start, int end, int index, int r, int capacidade, int *maior)
{
    int i, j, somaPeso = 0, somaVal = 0;

    if (index == r)
    {
        for (j=0; j<r; j++) {
            somaPeso += data[j];
            somaVal += valComb[j];
            if(somaPeso <= capacidade){
                if(somaVal > *maior){
                    *maior = somaVal;
                }
            }
        }
        return;
    }

    for (i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = item[i].peso;
        valComb[index] = item[i].valor;
        combinationUtil(item, data, valComb, i+1, end, index+1, r, capacidade, maior);
    }
}

void printCombination(Item *item, int n, int r, int C, int *maior)
{
    int data[r];
    int valComb[r];

    combinationUtil(item, data, valComb, 0, n-1, 0, r, C, maior);
}


void leArquivo(FILE *arq, Item *item, int maxTam){
    char barraN;                  //captura os \n
    for (int i = 0; i < maxTam; i++) {
        fscanf(arq, "%d %d", &item[i].peso, &item[i].valor);
        barraN = fgetc(arq);
    }
}