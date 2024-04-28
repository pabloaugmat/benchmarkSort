#include <stdio.h>
#include <stdlib.h>
#include "readFile.h"

void readFile(char *filename, int **arr, int *size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        *arr = NULL;
        *size = 0;
        return;
    }

    // Lê o primeiro valor do arquivo, que indica o número de elementos a seguir
    fscanf(file, "%d", size);
    if (*size <= 0) {
        // Se o tamanho for 0 ou negativo, não faz sentido continuar
        printf("Invalid size or no data to read\n");
        *arr = NULL;
        fclose(file);
        return;
    }

    // Aloca memória com base no tamanho fornecido
    *arr = malloc(*size * sizeof(int));
    if (*arr == NULL) {
        perror("Memory allocation failed");
        *size = 0;
        fclose(file);
        return;
    }

    // Lê os números do arquivo e os armazena no array
    for (int i = 0; i < *size; i++) {
        if (fscanf(file, "%d", &(*arr)[i]) != 1) {
            // Se a leitura falhar no meio, lidar com a limpeza
            printf("Error reading data at element %d\n", i);
            free(*arr);
            *arr = NULL;
            *size = i;  // Quantos elementos foram lidos com sucesso
            fclose(file);
            return;
        }
    }

    // Fecha o arquivo ao final da leitura
    fclose(file);
}


