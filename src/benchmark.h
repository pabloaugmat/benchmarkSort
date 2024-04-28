#ifndef BENCHMARK_H
#define BENCHMARK_H

typedef struct SortMetrics{
    long long numComparisons;
    long long numCopies;
    double timeSpent;
} SortMetrics;

void benchmark(void (*sortFunc)(int *, int, SortMetrics *), int arr[], int n, const char *sortName);

#endif // BENCHMARH_H