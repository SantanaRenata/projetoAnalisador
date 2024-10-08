
#include <stdio.h>
#define tam 5

 void mergeSort(int vetor[], int aux[], int inicio, int fim){
    int meio, i, j, k;
    
    if (inicio < fim){
        meio = (inicio + fim) / 2;
        
        mergeSort(vetor, aux, inicio, meio);
        mergeSort(vetor, aux, meio+1, fim);
        
        i= inicio;
        j = meio +1;
        k = inicio;
        
        while(i <= meio && j <= fim){
            
             if(vetor[i] < vetor[j]){
                 aux [k] = vetor[i];
                 i++;
                 k++; 
             } else{
                 aux[k] = vetor[j];
                 j++;
                 k++;
             }
        }
        
        while(i <= meio){
            aux[k] = vetor[i];
            k++;
            i++;
        }
        
        while(j <= fim){
            aux[k] = vetor[j];
            k++;
            j++;
        }
        for(i = inicio; i <= fim; i++){
            vetor[i] = aux[i];
        }
    }
}

  void imprimirVetorOrdenado(int vetor[]){
      int i;
      printf("Impressão do vetor ordenado: \n");
      for (i=0; i < tam; i++){
          printf("%i ", vetor[i]);
      }
  }
  
int main()
{
    int vetor[tam] = {7, 4, 2, 3, 1} ;
    int aux[tam];
    mergeSort(vetor, aux, 0, tam-1);
    imprimirVetorOrdenado(vetor);
    
    return 0;
}


