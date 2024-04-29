#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Struct com contadores de metricas para o benchmark
typedef struct SortMetrics
{
    long long numComparisons;
    long long numCopies;
    double timeSpent;
} SortMetrics;

// Recebe o ponteiro para uma das funções de algoritmos de ordenação, ponteiro para o array e o nome do algoritmo, para realizar o benchmark
void benchmark(void (*sortFunc)(int *, int, SortMetrics *), int arr[], int n, const char *sortName)
{
    SortMetrics metrics = {0, 0, 0.0}; // inicializa os contadores
    struct timeval start, end;

    //a função utiliza a biblioteca time para calcular o tempo de ordenação
    gettimeofday(&start, NULL);
    sortFunc(arr, n, &metrics);
    gettimeofday(&end, NULL);

    metrics.timeSpent = (end.tv_sec - start.tv_sec) * 1000.0;    // segundos para milisegundos
    metrics.timeSpent += (end.tv_usec - start.tv_usec) / 1000.0; // soma os demais microsegundos convertidos para milisegundos

    printf("%s: Tamanho do array: %d, Comparacoes: %lld, Copias: %lld, Tempo gasto: %f ms\n", sortName, n, metrics.numComparisons, metrics.numCopies, metrics.timeSpent);
}