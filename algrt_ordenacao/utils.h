#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bubblesort.h"
#include "quicksort.h"
#include "selectsort.h"


#define SIZE 30000
#define MAX_MANUAL 1000

// Funções auxiliares
void resetArray(int original[], int target[], int n) {
  for (int i = 0; i < n; i++)
    target[i] = original[i];
}

void fillRandom(int arr[], int n) {
  for (int i = 0; i < n; i++)
    arr[i] = rand() % 100000;
}

void fillReverse(int arr[], int n) {
  for (int i = 0; i < n; i++)
    arr[i] = n - i;
}

// Lógica da Opção 1 (Modo Manual)
void runManualMode() {
  int manual_arr[MAX_MANUAL];
  int work_arr[MAX_MANUAL];
  int num, count = 0;
  clock_t start, end;

  printf("\n--- MODO MANUAL (PASSO A PASSO) ---\n");
  printf("Digite os numeros para compor o array.\n");
  printf("Digite -1 para finalizar a insercao.\n");

  while (count < MAX_MANUAL) {
    printf("Valor %d: ", count + 1);
    scanf("%d", &num);
    if (num == -1)
      break;
    manual_arr[count] = num;
    count++;
  }

  if (count == 0) {
    printf("Nenhum numero inserido.\n");
    return;
  }

  printf("\nArray original: ");
  for (int i = 0; i < count; i++)
    printf("%d ", manual_arr[i]);
  printf("\n\n");

  printf(">> Executando BUBBLE SORT...\n");
  resetArray(manual_arr, work_arr, count);
  start = clock();
  bubbleSort(work_arr, count, 1);
  end = clock();
  printf("Tempo: %f segundos\n\n", ((double)(end - start)) / CLOCKS_PER_SEC);

  printf(">> Executando SELECTION SORT...\n");
  resetArray(manual_arr, work_arr, count);
  start = clock();
  selectionSort(work_arr, count, 1);
  end = clock();
  printf("Tempo: %f segundos\n\n", ((double)(end - start)) / CLOCKS_PER_SEC);

  printf(">> Executando QUICK SORT...\n");
  resetArray(manual_arr, work_arr, count);
  start = clock();
  quickSortWrapper(work_arr, count, 1);
  end = clock();
  printf("Tempo: %f segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);
}

// Lógica da Opção 2 (Modo Benchmark 30k)
void runBenchmark() {
  int *arr_base = (int *)malloc(SIZE * sizeof(int));
  int *arr_work = (int *)malloc(SIZE * sizeof(int));
  clock_t start, end;

  srand(time(NULL));

  printf("\n--- DEMONSTRACAO DE EFICIENCIA (%d elementos) ---\n", SIZE);

  printf("\n[ CENARIO 1: DADOS ALEATORIOS ]\n");
  fillRandom(arr_base, SIZE);

  resetArray(arr_base, arr_work, SIZE);
  start = clock();
  bubbleSort(arr_work, SIZE, 0);
  end = clock();
  printf("Bubble Sort   : %f segundos\n",
         ((double)(end - start)) / CLOCKS_PER_SEC);

  resetArray(arr_base, arr_work, SIZE);
  start = clock();
  selectionSort(arr_work, SIZE, 0);
  end = clock();
  printf("Selection Sort: %f segundos\n",
         ((double)(end - start)) / CLOCKS_PER_SEC);

  resetArray(arr_base, arr_work, SIZE);
  start = clock();
  quickSortWrapper(arr_work, SIZE, 0);
  end = clock();
  printf("Quick Sort    : %f segundos\n",
         ((double)(end - start)) / CLOCKS_PER_SEC);

  printf("\n[ CENARIO 2: DADOS EM ORDEM INVERSA (PIOR CASO) ]\n");
  fillReverse(arr_base, SIZE);

  resetArray(arr_base, arr_work, SIZE);
  start = clock();
  bubbleSort(arr_work, SIZE, 0);
  end = clock();
  printf("Bubble Sort   : %f segundos\n",
         ((double)(end - start)) / CLOCKS_PER_SEC);

  resetArray(arr_base, arr_work, SIZE);
  start = clock();
  selectionSort(arr_work, SIZE, 0);
  end = clock();
  printf("Selection Sort: %f segundos\n",
         ((double)(end - start)) / CLOCKS_PER_SEC);

  resetArray(arr_base, arr_work, SIZE);
  start = clock();
  quickSortWrapper(arr_work, SIZE, 0);
  end = clock();
  printf("Quick Sort    : %f segundos\n",
         ((double)(end - start)) / CLOCKS_PER_SEC);

  free(arr_base);
  free(arr_work);
}

#endif