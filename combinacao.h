//
// Created by lazarus on 29/10/19.
//
#include <stdio.h>
#include "tadMochila.h"

void printCombination(Item *item, int n, int r, int C, int *maior);
void combinationUtil(Item *item,int data[], int valComb[], int start, int end, int index, int r, int capacidade, int *maior);

void leArquivo(FILE *arq, Item itens[], int maxTam);
