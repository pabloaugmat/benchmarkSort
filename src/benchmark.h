#ifndef BENCHMARK_H
#define BENCHMARK_H

// Struct com contadores de metricas para o benchmark
typedef struct SortMetrics
{
    long long numComparisons;
    long long numCopies;
    double timeSpent;
} SortMetrics;

// Recebe o ponteiro para uma das funções de algoritmos de ordenação, ponteiro para o array e o nome do algoritmo, para realizar o benchmark
void benchmark(void (*sortFunc)(int *, int, SortMetrics *), int arr[], int n, const char *sortName);

#endif // BENCHMARH_H