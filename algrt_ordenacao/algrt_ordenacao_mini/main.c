#include <stdio.h>

void imprimirArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void trocar(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// 1. BUBBLE SORT

void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {

        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// 2. SELECTION SORT

void selectionSort(int arr[], int n) {
  int i, j, min_idx;
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++) {

      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }

    if (min_idx != i) {
      int temp = arr[min_idx];
      arr[min_idx] = arr[i];
      arr[i] = temp;
    }
  }
}

// 3. QUICK SORT

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {

    if (arr[j] < pivot) {
      i++;
      trocar(&arr[i], &arr[j]);
    }
  }
  trocar(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  printf("=== DEMONSTRACAO DE ALGORITMOS DE ORDENACAO ===\n\n");

  int array1[] = {64, 34, 25, 12, 22, 11, 90};
  int array2[] = {64, 34, 25, 12, 22, 11, 90};
  int array3[] = {64, 34, 25, 12, 22, 11, 90};

  int n = sizeof(array1) / sizeof(array1[0]);

  printf("Array original (desordenado):\n");
  imprimirArray(array1, n);
  printf("-------------------------------------------------\n");

  // Teste 1: Bubble Sort
  printf("\n[1] Aplicando Bubble Sort...\n");
  bubbleSort(array1, n);
  imprimirArray(array1, n);

  // Teste 2: Selection Sort
  printf("\n[2] Aplicando Selection Sort...\n");
  selectionSort(array2, n);
  imprimirArray(array2, n);

  // Teste 3: Quick Sort
  printf("\n[3] Aplicando Quick Sort...\n");
  quickSort(array3, 0, n - 1);
  imprimirArray(array3, n);

  printf("\nTodos os algoritmos executados com sucesso!\n");

  return 0;
}