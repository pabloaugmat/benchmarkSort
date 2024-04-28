#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "readFile.h"

#include "insertionSort.h"
#include "selectionSort.h"
#include "mergeSort.h"
#include "quickSort.h"
// #include "cubeSort.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_list.txt>\n", argv[0]);
        return 1;
    }

    FILE *fileList = fopen(argv[1], "r");
    if (!fileList) {
        perror("Error opening file");
        return 1;
    }

    char filePath[1024];  // Define um buffer para os caminhos dos arquivos
    while (fgets(filePath, sizeof(filePath), fileList)) {
        // Remove qualquer newline lido por fgets
        filePath[strcspn(filePath, "\n")] = 0;

        int *arr;
        int n;
        SortMetrics metrics = {0};  // Inicialize as métricas para cada arquivo.

        printf("Processing file: %s\n", filePath);
        readFile(filePath, &arr, &n);

        // Benchmark de cada algoritmo para o arquivo atual
        benchmark(insertionSort, arr, n, "Insertion Sort");
        benchmark(selectionSort, arr, n, "Selection Sort");
        benchmark(mergeSortWrapper, arr, n, "Merge Sort");
        benchmark(quickSortWrapper, arr, n, "Quick Sort");

        // Libera a memória alocada para o array
        free(arr);
    }

    fclose(fileList);
    return 0;
}