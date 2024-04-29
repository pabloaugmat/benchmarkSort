#ifndef CUBESORT_H
#define CUBESORT_H

#include "benchmark.h"

// Função auxiliar para encontrar o mínimo entre dois números
int min(int x, int y);

// Função para comparar dois elementos (necessária para qsort)
int compare(const void *a, const void *b);

// Algoritmo de ordenação Cube Sort com rastreamento de métricas
void cubeSort(int arr[], int n, SortMetrics *metrics);

#endif // CUBESORT_H
