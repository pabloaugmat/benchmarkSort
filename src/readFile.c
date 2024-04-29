#include <stdio.h>
#include <stdlib.h>
#include "readFile.h"

void readFile(char *filename, int **arr, int *size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Falha ao abrir arquivo");
        *arr = NULL;
        *size = 0;
        return;
    }

    if (fscanf(file, "%d", size) != 1 || *size <= 0) {
        fprintf(stderr, "Tamanho invalido ou nenhum dado para ler do arquivo: %s\n", filename);
        *arr = NULL;
        *size = 0;
        fclose(file);
        return;
    }

    *arr = malloc(*size * sizeof(int));
    if (!*arr) {
        perror("Falha na alocacao de memoria");
        *size = 0;
        fclose(file);
        return;
    }

    for (int i = 0; i < *size; i++) {
        if (fscanf(file, "%d", &(*arr)[i]) != 1) {
            fprintf(stderr, "Erro ao ler dados no elemento %d do arquivo: %s\n", i, filename);
            free(*arr);
            *arr = NULL;
            *size = i;
            fclose(file);
            return;
        }
    }

    fclose(file);
    printf("Arquivo '%s' lido com sucesso com  %d elementos.\n", filename, *size);
}
