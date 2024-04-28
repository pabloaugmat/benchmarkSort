#include "mergeSort.h"
#include "benchmark.h"

void merge(int arr[], int inicio, int meio, int fim, SortMetrics *metrics)
{
    int tamanhoEsq = meio + 1 - inicio;
    int tamanhoDir = fim - meio;
    int vetEsq[tamanhoEsq], vetDir[tamanhoDir], vetAux[fim - inicio + 1];
    int esquerda = 0, direita = 0, indexAux = 0;

    // Copiando para arrays temporários
    for (int i = 0; i < tamanhoEsq; i++)
    {
        vetEsq[i] = arr[inicio + i];
        metrics->numCopies++;
    }
    for (int i = 0; i < tamanhoDir; i++)
    {
        vetDir[i] = arr[meio + 1 + i];
        metrics->numCopies++;
    }

    // Mesclando arrays temporários de volta para o array original
    while (esquerda < tamanhoEsq && direita < tamanhoDir)
    {
        metrics->numComparisons++; // Incrementar para cada comparação entre vetEsq e vetDir
        if (vetEsq[esquerda] < vetDir[direita])
        {
            vetAux[indexAux] = vetEsq[esquerda];
            esquerda++;
        }
        else
        {
            vetAux[indexAux] = vetDir[direita];
            direita++;
        }
        indexAux++;
        metrics->numCopies++;
    }

    // Copiando os elementos restantes
    while (esquerda < tamanhoEsq)
    {
        vetAux[indexAux++] = vetEsq[esquerda++];
        metrics->numCopies++;
    }
    while (direita < tamanhoDir)
    {
        vetAux[indexAux++] = vetDir[direita++];
        metrics->numCopies++;
    }

    // Copiando de volta para o array original
    for (int i = 0; i < indexAux; i++)
    {
        arr[inicio + i] = vetAux[i];
        metrics->numCopies++;
    }
}

void mergeSort(int arr[], int inicio, int fim, SortMetrics *metrics)
{
    int meio = (inicio + fim) / 2;
    if (inicio < fim)
    {
        mergeSort(arr, inicio, meio, metrics);
        mergeSort(arr, meio + 1, fim, metrics);
        merge(arr, inicio, meio, fim, metrics);
    }
}

void mergeSortWrapper(int arr[], int n, SortMetrics *metrics)
{
    mergeSort(arr, 0, n - 1, metrics);
}
