//
// Created by lazarus on 29/10/19.
//

#include "combinacao.h"
#include <stdio.h>
#include <stdlib.h>

void combinationUtil(Item *item, Item *tupla,int data[], int valComb[], int start, int end, int index, int r, int capacidade, int *maior, int *qtd)
{
    int i, j, somaPeso = 0, somaVal = 0;

    if (index == r)
    {
        for (j=0; j<r; j++) {
            somaPeso += data[j];
            somaVal += valComb[j];
        }
        if( somaPeso <= capacidade){
            if (somaVal > *maior){
                *maior = somaVal;
                *qtd = r;
                for (int i = 0; i < r; i++){
                    tupla[i].valor = valComb[i];
                    tupla[i].peso = data[i];
                }
            }
            if (somaVal == *maior && *qtd < r){
                *maior = somaVal;
                *qtd = r;
                for (int i = 0; i < r; i++){
                    tupla[i].valor = valComb[i];
                    tupla[i].peso = data[i];
                }
            }
        }
        return;
    }

    for (i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = item[i].peso;
        valComb[index] = item[i].valor;
        combinationUtil(item, tupla, data, valComb, i+1, end, index+1, r, capacidade, maior, qtd);
    }
}

void printCombination(Item *item, Mochila *mochila, int n, int r, int C, int *maior, int *qtd)
{
    int data[r];
    int valComb[r];

    combinationUtil(item, mochila->item, data, valComb, 0, n-1, 0, r, C, maior, qtd);
}

void CriaVetor (Mochila *mochila, int n){
    mochila->item = (Item * ) malloc(n * sizeof(Item));
}

void leArquivo(FILE *arq, Item *item, int maxTam){
    char barraN;                  //captura os \n
    for (int i = 0; i < maxTam; i++) {
        fscanf(arq, "%d %d", &item[i].peso, &item[i].valor);
        barraN = fgetc(arq);
    }
}