#include <stdio.h>
#include <stdlib.h>
#include "benchmark.h"
#include "quickSort.h"
#include "mergeSort.h"

const int CUBE_SIZE = 8;

void cubeSort(int arr[], int n, SortMetrics *metrics)
{
    // Ordenar os cubos individualmente
    for (int i = 0; i < n; i += CUBE_SIZE)
    {
        int currentCubeSize = (i + CUBE_SIZE <= n) ? CUBE_SIZE : n - i; // verifica se o índice inicial do cubo atual mais o tamanho padrão do cubo é menor ou igual ao tamanho total do array para para não permitir acessar uma chave alem do tamanho do array
        quickSortWrapper(arr + i, currentCubeSize, metrics);            // Reaproveita o Quick Sort ja implementado no sistema
    }

    // Fusão dos cubos ordenados
    for (int size = CUBE_SIZE; size < n; size *= 2)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1;                                         // Ajustar para que 'mid' seja o índice do último elemento do primeiro subarray
            int right = left + 2 * size - 1 < n ? left + 2 * size - 1 : n - 1; // Calcular o índice correto do último elemento do segundo subarray
            if (mid < right)
            {                                          // Evitar chamadas desnecessárias para merge se não houver segundo subarray
                merge(arr, left, mid, right, metrics); // Reaproveita o Merge Sort ja implementado no sistema
            }
        }
    }
}