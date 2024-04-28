#include "quickSort.h"
#include "benchmark.h"

int particiona(int arr[], int inicio, int fim, SortMetrics *metrics)
{
    int pos = inicio;
    int pivo = arr[inicio];
    int aux;
    for (int i = inicio + 1; i <= fim; i++)
    {
        metrics->numComparisons++; // Cada comparação com o pivô
        if (arr[i] < pivo)
        {
            pos++;
            aux = arr[pos];
            arr[pos] = arr[i];
            arr[i] = aux;
            metrics->numCopies += 3; // Três cópias durante a troca
        }
    }
    // Trocar o pivô para a posição correta
    aux = arr[pos];
    arr[pos] = arr[inicio];
    arr[inicio] = aux;
    metrics->numCopies += 3; // Três cópias durante a troca final

    return pos;
}

void quickSort(int arr[], int inicio, int fim, SortMetrics *metrics)
{
    int pivo;
    if (inicio < fim)
    {
        pivo = particiona(arr, inicio, fim, metrics);
        quickSort(arr, inicio, pivo - 1, metrics);
        quickSort(arr, pivo + 1, fim, metrics);
    }
}

void quickSortWrapper(int arr[], int n, SortMetrics *metrics)
{
    quickSort(arr, 0, n - 1, metrics);
}