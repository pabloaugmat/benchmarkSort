

#include <stdlib.h>
#include <time.h>

#include "aleatorios.h"

int* geraAleatorios(int tam, int semente) {
    int *arr = (int*) malloc(tam * sizeof(int));
    srand(semente); // Inicializa o gerador de números aleatórios com a semente fornecida

    for (int i = 0; i < tam; i++) {
        arr[i] = rand(); // Gera um número aleatório e armazena no vetor
    }

    return arr;
}

int* geraQuaseOrdenados(int tam, int porcentagem, int semente) {
    int *arr = geraAleatorios(tam, semente); // Gera dados aleatórios primeiro
    int numDesordenados = (tam * porcentagem) / 100; // Calcula quantos elementos devem ser desordenados

    // Ordena os primeiros 90% do array
    qsort(arr, tam - numDesordenados, sizeof(int), compara);

    // Embaralha os últimos 10%
    for (int i = tam - numDesordenados; i < tam; i++) {
        int j = i + rand() % (tam - i);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    return arr;
}

int compara(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int* geraOrdenados(int tam, int ordem) {
    int *arr = (int*) malloc(tam * sizeof(int));
    for (int i = 0; i < tam; i++) {
        arr[i] = i + 1; // Gera dados em ordem crescente
    }

    if (ordem == 1) { // Se a ordem for decrescente, inverte o array
        for (int i = 0; i < tam / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[tam - 1 - i];
            arr[tam - 1 - i] = temp;
        }
    }

    return arr;
}
