#include "../src/insertionSort.h"
#include <stdio.h>
#include <stdbool.h>

// Função para verificar se o array está ordenado
bool isSorted(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

// Função para imprimir o array
void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função de teste para o insertionSort
void test() {
    // Array estático para teste
    int testArray[] = {5, 3, 8, 4, 2};
    int n = sizeof(testArray) / sizeof(testArray[0]);

    // Inicializa as métricas
    SortMetrics metrics = {0, 0};

    // Chama o insertionSort
    insertionSort(testArray, n, &metrics);

    // Verifica se o array está ordenado
    if (isSorted(testArray, n)) {
        printf("Teste PASSOU. Array está ordenado.\n");
    } else {
        printf("Teste FALHOU. Array NÃO está ordenado.\n");
    }

    // Imprime o array ordenado
    printf("Array ordenado: ");
    printArray(testArray, n);
}

int main() {
    test();
    return 0;
}