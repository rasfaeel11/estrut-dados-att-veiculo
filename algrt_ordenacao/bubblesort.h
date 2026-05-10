#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include <stdio.h>

void bubbleSort(int arr[], int n, int print_steps) {
  int i, j, temp, k;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // Troca
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;

        // Imprime o passo a passo se solicitado
        if (print_steps) {
          printf("Trocando %d e %d -> ", arr[j + 1], arr[j]);
          for (k = 0; k < n; k++)
            printf("%d ", arr[k]);
          printf("\n");
        }
      }
    }
  }
}

#endif