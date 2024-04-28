#include "selectionSort.h"
#include "benchmark.h"

void selectionSort(int arr[], int n, SortMetrics *metrics)
{
    int marcador = 0, menor, aux;
    while (marcador < n - 1)
    {
        menor = marcador;
        for (int i = marcador + 1; i < n; i++)
        {
            metrics->numComparisons++;  // Incrementa cada vez que uma comparação é feita
            if (arr[i] < arr[menor])
            {
                menor = i;
            }
        }
        if (menor != marcador)  // Só faz a troca se necessário
        {
            aux = arr[marcador];
            arr[marcador] = arr[menor];
            arr[menor] = aux;
            
            metrics->numCopies += 3;  // Conta as três cópias envolvidas na troca
        }
        marcador++;
    }
}
