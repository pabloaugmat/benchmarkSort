// aleatorios.h

#ifndef ALEATORIOS_H
#define ALEATORIOS_H

#include <stdlib.h> // Necessário para a função malloc

// Gera um vetor de números aleatórios de tamanho 'tam' usando 'semente' para inicializar o gerador.
int* geraAleatorios(int tam, int semente);

// Gera um vetor de números quase ordenados de tamanho 'tam' com uma certa 'porcentagem' de desordem.
int* geraQuaseOrdenados(int tam, int porcentagem, int semente);

// Gera um vetor de números ordenados de tamanho 'tam'. Se 'ordem' for 0, ordena de forma crescente; se 1, de forma decrescente.
int* geraOrdenados(int tam, int ordem);

int compara(const void *a, const void *b);

#endif // ALEATORIOS_H
