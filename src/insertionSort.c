#include "insertionSort.h"
#include "benchmark.h"

void insertionSort(int *arr, int n, SortMetrics *metrics)
{
    int pos, aux;
    for (int i = 1; i < n; i++)
    {
        pos = i - 1;
        aux = arr[i];
        metrics->numCopies++;
        while (pos >= 0 && aux < arr[pos])
        {
            metrics->numComparisons++;
            arr[pos + 1] = arr[pos];
            metrics->numCopies++;
            pos--;
        }
        arr[pos + 1] = aux;
        metrics->numCopies++;
    }
}
