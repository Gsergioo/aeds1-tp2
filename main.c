#include "combinacao.h"


int main() {
    clock_t tempo;

    int maxTam = 0; //tamanho maximo das entradas
    int option = 0; //opção
    char nomeArq[20]; //nome do arquivo
    int qtd = 0; //quantidade de itens da combinação atual

    int maior = 0; //mostra qual o maior valor agregado da melhor combinacao atual
    int *ptxMaior = &maior; //ponteiro pra receber o valor de "maior" que esta dentro da funcao fazCombinacao

    Mochila mochila;
    mochila.capacidade = 40;


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

            printf("\n");
            printf("Calculando...\n");
//--------------------------Comeca a calcular o tempo e as combinacoes--------------------------------------------------

            tempo = clock();

            for (int i = 1; i <= maxTam ; ++i) {
                resolverProblema(itens, &mochila, maxTam, i, mochila.capacidade, ptxMaior, &qtd);
            }

            tempo = clock() - tempo;
            printf("\n");
//----------------------------------impressao do resultado final--------------------------------------------------------

           imprimeResultados(mochila, qtd, tempo);

        }

        fclose(arq);

    }else
        if(option == 2){
            printf("FIM!\n");
            return 0;
    }else
        printf("Opção inválida!!\n");
}
