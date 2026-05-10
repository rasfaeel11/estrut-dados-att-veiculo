#ifndef SELECTSORT_H
#define SELECTSORT_H
#include <stdio.h>

void selectionSort(int arr[], int n, int print_steps) {
  int i, j, min_idx, temp, k;
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    if (min_idx != i) {
      // Troca
      temp = arr[min_idx];
      arr[min_idx] = arr[i];
      arr[i] = temp;

      // Imprime o passo a passo se solicitado
      if (print_steps) {
        printf("Trocando %d e %d -> ", arr[i], arr[min_idx]);
        for (k = 0; k < n; k++)
          printf("%d ", arr[k]);
        printf("\n");
      }
    }
  }
}

#endif