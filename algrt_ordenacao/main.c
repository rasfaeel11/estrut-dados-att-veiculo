#include <stdio.h>

#include "utils.h"

int main() {
  int opcao;

  do {
    printf("\n========================================\n");
    printf("      ANALISADOR DE ORDENACAO EM C      \n");
    printf("========================================\n");
    printf("1. Inserir array manualmente (Passo a Passo)\n");
    printf("2. Demonstracao de Eficiencia (30.000 elementos)\n");
    printf("3. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      runManualMode();
      break;
    case 2:
      runBenchmark();
      break;
    case 3:
      printf("Saindo do programa...\n");
      break;
    default:
      printf("Opcao invalida. Tente novamente.\n");
    }

  } while (opcao != 3); // O loop continua até o usuário escolher 3

  return 0;
}