#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Modulos utilitarios
#include "readFile.h"
#include "writeFile.h"
#include "aleatorios.h"

// Modulos de algoritmos de ordenação
#include "insertionSort.h"
#include "selectionSort.h"
#include "mergeSort.h"
#include "quickSort.h"
// #include "cubeSort.h"

const int Seed = 2616; // Seed para que as funções de aleatoriedade sempre gerem os mesmos numeros

// Gera arrays aleatorios e os persistir em txt
void randomGeneration(FILE *sizeFile);
// Processa os arquivos com arrays aleatorios para realização do benckmark
void processFiles(FILE *fileList);
// Inicializa o programa checando argumentos, como o arquivo(dataList.txt) com o caminho para os demais
int initializeAndCheckArgs(int argc, char *argv[], FILE **fileList);

int main(int argc, char *argv[])
{
    FILE *fileList;
    if (initializeAndCheckArgs(argc, argv, &fileList) != 0)
    {
        return 1;
    }

    // Processa o primeiro arquivo que contém os tamanhos dos arrays
    char firstFilePath[1024];
    if (!fgets(firstFilePath, sizeof(firstFilePath), fileList))
    {
        perror("Falha ao ler o primeiro caminho do arquivo");
        fclose(fileList);
        return 1;
    }
    firstFilePath[strcspn(firstFilePath, "\n")] = 0; // Remove nova linha
    firstFilePath[strcspn(firstFilePath, "\r")] = 0; // Remove retorno de carro

    FILE *sizeFile = fopen(firstFilePath, "r");
    if (!sizeFile)
    {
        perror("Erro ao abrir o arquivo de tamanhos.");
        fclose(fileList);
        return 1;
    }
    randomGeneration(sizeFile);
    fclose(sizeFile);

    // Processa o resto dos arquivos de entrada
    processFiles(fileList);
    fclose(fileList);

    return 0;
}

int initializeAndCheckArgs(int argc, char *argv[], FILE **fileList)
{
    if (argc != 2)
    {
        printf("Uso: %s <file_list.txt>\n", argv[0]);
        return 1;
    }
    *fileList = fopen(argv[1], "r");
    if (!*fileList)
    {
        perror("Erro ao abrir arquivo");
        return 1;
    }
    return 0;
}

void randomGeneration(FILE *sizeFile)
{
    int size;
    while (fscanf(sizeFile, "%d", &size) == 1)
    {
        int *arr;
        char filename[256];

        // Gera um um array de aleatorios desordenados e persiste em txt
        arr = geraAleatorios(size, Seed);
        sprintf(filename, "random_%d.txt", size);
        writeFile(filename, arr, size);
        free(arr);

        // Gera um um array de aleatorios 90% ordenados e persiste em txt
        arr = geraQuaseOrdenados(size, 10, Seed);
        sprintf(filename, "nearly_sorted_%d.txt", size);
        writeFile(filename, arr, size);
        free(arr);

        // Gera um um array de aleatorios em ordem crescente e persiste em txt
        arr = geraOrdenados(size, 0);
        sprintf(filename, "sorted_asc_%d.txt", size);
        writeFile(filename, arr, size);
        free(arr);

        // Gera um um array de aleatorios em ordem decrescente e persiste em txt
        arr = geraOrdenados(size, 1);
        sprintf(filename, "sorted_desc_%d.txt", size);
        writeFile(filename, arr, size);
        free(arr);
    }
}

void processFiles(FILE *fileList)
{
    char filePath[1024];
    while (fgets(filePath, sizeof(filePath), fileList))
    {
        filePath[strcspn(filePath, "\n")] = 0; // Remove nova linha
        filePath[strcspn(filePath, "\r")] = 0; // Remove retorno de carro
        int *arr;
        int n;
        printf("Processando arquivo: %s\n", filePath);
        readFile(filePath, &arr, &n);

        // Benchmark cada algoritmo de ordenação para o arquivo atual
        benchmark(insertionSort, arr, n, "Insertion Sort");
        benchmark(selectionSort, arr, n, "Selection Sort");
        benchmark(mergeSortWrapper, arr, n, "Merge Sort");
        benchmark(quickSortWrapper, arr, n, "Quick Sort");
        printf("_______________________________________________________________________________________\n");

        free(arr);
    }
}
