#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    FILE *arquivo;
    char linha[1000];

    arquivo = fopen("algoritmo.c", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("\n------------------------------------------\n");

    int numeroDeLoopsFor = 0, numeroDeLoopsDoWhile = 0;
    int forAninhado = 0, doWhileAninhado = 0;
    int contagemSubprogramas = 0;
    int nivelAninhamentoFor = 0;  // Nível de aninhamento para 'for'
    bool isMergeSort = false; // Flag para identificar Merge Sort

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);

        // Verifica se há subprogramas
        if (strstr(linha, "int main(") != NULL){
        	// do nothing
		} else if (strstr(linha, "void ") != NULL || 
            strstr(linha, "int ") != NULL || strstr(linha, "float ") != NULL || 
            strstr(linha, "double ") != NULL || strstr(linha, "char ") != NULL || 
            strstr(linha, "bool ") != NULL) {

		    if (strstr(linha, "(") != NULL) {
                contagemSubprogramas++;
            }
        }

        if (strstr(linha, "mergeSort") != NULL) {
            isMergeSort = true;
        }

        if (strstr(linha, "for(") != NULL) {
            numeroDeLoopsFor++;

            if (numeroDeLoopsFor > 1) {
                forAninhado = numeroDeLoopsFor;
            }
        }

        if (strstr(linha, "do {") != NULL || strstr(linha, "while(") != NULL) {
            numeroDeLoopsDoWhile++;
            if (numeroDeLoopsDoWhile > 1) {
                doWhileAninhado = numeroDeLoopsDoWhile; 
            }
        }

      
    }

    fclose(arquivo);

 printf("\n------------------------------------------\n");
    if (isMergeSort) {
        printf("Nível de complexidade do algoritmo: O(n log n)\n");
    } else if (forAninhado == 1 || doWhileAninhado ==1 ) {
        printf("Nível de complexidade do algoritmo: O(n^%i)\n", forAninhado);
    } else if (forAninhado == 0 || doWhileAninhado ==0 ) {
    printf("Nível de complexidade do algoritmo: O(n)\n");
}
    printf("Quantidade de subprogramas: %i \n", contagemSubprogramas);

    return 0;
}

