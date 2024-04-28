#ifndef MERGESORT_H
#define MERGESORT_H

#include "benchmark.h"

void mergeSortWrapper(int arr[], int n, SortMetrics *metrics);
void mergeSort(int arr[], int inicio, int fim, SortMetrics *metrics);
void merge(int arr[], int inicio, int meio, int fim, SortMetrics *metrics);

#endif // MERGESORT_H