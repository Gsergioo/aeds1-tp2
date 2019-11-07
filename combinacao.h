//
// Created by lazarus on 29/10/19.
//
#include <stdio.h>
#include "Mochila.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include <malloc.h>

void resolverProblema(Item *item, Mochila *mochila, int n, int r, int C, int *maior, int *qtd);
void fazCombinacoes(Item *item, Item *tupla, int data[], int valComb[], int start, int end, int index, int r, int capacidade, int *maior, int *qtd);

void CriaVetor(Mochila *mochila, int n);
void leArquivo(FILE *arq, Item itens[], int maxTam);
void imprimeResultados(Mochila mochila, int qtd, clock_t tempo);
