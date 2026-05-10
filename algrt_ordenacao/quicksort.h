#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int arr[], int low, int high, int n, int print_steps) {
  int pivot = arr[high];
  int i = (low - 1);
  int j, k;

  for (j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
      if (print_steps && i != j) {
        printf("Quick (menor q pivo %d) -> ", pivot);
        for (k = 0; k < n; k++)
          printf("%d ", arr[k]);
        printf("\n");
      }
    }
  }
  swap(&arr[i + 1], &arr[high]);

  if (print_steps && (i + 1) != high) {
    printf("Quick (posicionando pivo %d) -> ", pivot);
    for (k = 0; k < n; k++)
      printf("%d ", arr[k]);
    printf("\n");
  }
  return (i + 1);
}

void quickSort(int arr[], int low, int high, int n, int print_steps) {
  if (low < high) {
    int pi = partition(arr, low, high, n, print_steps);
    quickSort(arr, low, pi - 1, n, print_steps);
    quickSort(arr, pi + 1, high, n, print_steps);
  }
}

void quickSortWrapper(int arr[], int n, int print_steps) {
  quickSort(arr, 0, n - 1, n, print_steps);
}

#endif