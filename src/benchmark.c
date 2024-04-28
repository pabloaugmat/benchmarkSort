#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SortMetrics{
    long long numComparisons;
    long long numCopies;
    double timeSpent;
} SortMetrics;

void benchmark(void (*sortFunc)(int*, int, SortMetrics*), int arr[], int n, const char* sortName) {
    SortMetrics metrics = {0, 0, 0.0};
    struct timeval start, end;

    //int *arrCopy = malloc(n * sizeof(int));
    //memcpy(arrCopy, arr, n * sizeof(int));

    gettimeofday(&start, NULL);
    sortFunc(arr, n, &metrics);
    gettimeofday(&end, NULL);

    metrics.timeSpent = (end.tv_sec - start.tv_sec) * 1000.0;      // sec to ms
    metrics.timeSpent += (end.tv_usec - start.tv_usec) / 1000.0;   // us to ms

    printf("%s: Array size: %d, Comparisons: %lld, Copies: %lld, Time spent: %f ms\n", sortName, n, metrics.numComparisons, metrics.numCopies, metrics.timeSpent);

    // TODO: APAGAR
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //free(arrCopy);
}