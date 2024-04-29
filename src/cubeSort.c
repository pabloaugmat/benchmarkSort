#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "benchmark.h"
#include "cubeSort.h"

const int CUBE_SIZE = 8;

int min(int x, int y)
{
    return x < y ? x : y;
}

// Função para comparar dois elementos (necessária para qsort)
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void cubeSort(int arr[], int n, SortMetrics *metrics)
{
    // Dividir o array em cubos de tamanho CUBE_SIZE e ordenar cada cubo
    for (int i = 0; i < n; i += CUBE_SIZE)
    {
        int currentCubeSize = (i + CUBE_SIZE <= n) ? CUBE_SIZE : n - i;
        qsort(arr + i, currentCubeSize, sizeof(int), compare);
        metrics->numCopies += currentCubeSize;                              // Estimativa, uma vez que o qsort não expõe diretamente esses dados
        metrics->numComparisons += currentCubeSize * log2(currentCubeSize); // Estimativa baseada na complexidade média do quicksort
    }

    // Variável temporária para armazenar a união dos cubos
    int *temp = (int *)malloc(n * sizeof(int));
    if (temp == NULL)
    {
        perror("Failed to allocate memory");
        exit(1);
    }

    // Unir os cubos
    int currentSize = CUBE_SIZE;
    while (currentSize < n)
    {
        for (int i = 0; i < n; i += 2 * currentSize)
        {
            int left = i;
            int mid = min(i + currentSize, n);
            int right = min(i + 2 * currentSize, n);
            int k = left;
            int start1 = left, end1 = mid, start2 = mid, end2 = right;

            // Fundir duas partes
            while (start1 < end1 && start2 < end2)
            {
                metrics->numComparisons++;
                if (arr[start1] < arr[start2])
                {
                    temp[k++] = arr[start1++];
                }
                else
                {
                    temp[k++] = arr[start2++];
                }
                metrics->numCopies++;
            }

            // Copiar os elementos restantes
            while (start1 < end1)
            {
                temp[k++] = arr[start1++];
                metrics->numCopies++;
            }
            while (start2 < end2)
            {
                temp[k++] = arr[start2++];
                metrics->numCopies++;
            }
        }

        // Copiar de temp[] para arr[] e dobrar o tamanho do cubo
        memcpy(arr, temp, n * sizeof(int));
        metrics->numCopies += n;
        currentSize *= 2;
    }

    free(temp);
}
