# benchmarkSort

O projeto `benchmarkSort` é uma aplicação desenvolvida em C que compara o desempenho de diversos algoritmos de ordenação. Este projeto inclui implementações de Insertion Sort, Selection Sort, Merge Sort, Quick Sort e Cube Sort.

## Pré-requisitos

Para compilar e executar este projeto, você precisará do GCC instalado em seu sistema. O GCC pode ser instalado em sistemas baseados em Debian com o seguinte comando:

```bash
sudo apt-get install gcc
```
## Compilação
Para compilar o projeto, siga os passos abaixo. Certifique-se de estar no diretório que contém o arquivo main.c.

Execute o comando:

```bash
gcc -o main main.c benchmark.c readFile.c writeFile.c aleatorios.c insertionSort.c selectionSort.c mergeSort.c quickSort.c cubeSort.c -lm
```
Este comando compila o código e gera um executável chamado main.

## Execução

Após a compilação, você pode executar o programa com:

```bash
./main
```
Certifique-se de que todos os arquivos necessários estão disponíveis no mesmo diretório do executável, ou especifique os caminhos corretos ao executar o programa.

## Estrutura do Projeto

| Arquivo          | Descrição                                                             |
|------------------|-----------------------------------------------------------------------|
| `main.c`         | Arquivo principal que inicia a execução do programa.                  |
| `benchmark.c`    | Contém funções para medir e comparar os tempos de execução dos algoritmos de ordenação. |
| `aleatorios.c`   | Funções para gerar arrays de inteiros aleatorios.                     |
| `writeFile.c`    | Funções para escrever dados em arquivos que serão ordenados.          |
| `readFile.c`     | Funções para ler dados de arquivos que serão ordenados.               |
| `insertionSort.c`| Implementação do algoritmo Insertion Sort.                            |
| `selectionSort.c`| Implementação do algoritmo Selection Sort.                            |
| `mergeSort.c`    | Implementação do algoritmo Merge Sort.                                |
| `quickSort.c`    | Implementação do algoritmo Quick Sort.                                |
| `cubeSort.c`     | Implementação do algoritmo Cube Sort.                                 |


## Contribuindo
Contribuições são sempre bem-vindas! Se você tem melhorias ou correções, sinta-se à vontade para forkar o repositório e enviar um pull request com suas mudanças.



