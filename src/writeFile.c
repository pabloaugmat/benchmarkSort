#include <stdio.h>
#include <stdlib.h>

#include "writeFile.h"

void dataListpersist(const char *dataList, const char *filePath) {
    FILE *dataListFile = fopen(dataList, "a"); // Abre o arquivo dataList em modo de adição
    if (dataListFile == NULL) {
        perror("Nao eh possivel abrir o arquivo dataList.txt");
        exit(EXIT_FAILURE);
    }

    fprintf(dataListFile, "%s\n", filePath); // Escreve o caminho do arquivo no arquivo de log
    fclose(dataListFile); // Fecha o arquivo de log
}

void writeFile(char *filename, int *arr, int size)
{   
    char filePath[1024];
    sprintf(filePath, "../data/%s", filename); // Cria o caminho do arquivo
    FILE *file = fopen(filePath, "w");
    if (file == NULL)
    {
        perror("Falha ao abrir arquivo");
        return;
    }
    fprintf(file, "%d\n", size);
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d\n", arr[i]);
    }
    fclose(file);
    dataListpersist("dataList.txt", filePath);
}