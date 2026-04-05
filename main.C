#include "veiculo.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Armazem meuArmazem = {NULL, 0, 0};
  int opcao;

  do {
    printf("\n--- MENU DO ARMAZEM ---\n");
    printf("1. Adicionar Veiculo\n");
    printf("2. Listar Veiculos\n");
    printf("3. Buscar por Vaga (Indice)\n");
    printf("4. Remover Veiculo\n");
    printf("0. Sair\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1: {
      char placa[8], modelo[50];
      int ano;
      float preco;

      printf("Digite a Placa: ");
      scanf("%s", placa);

      printf("Digite o Modelo: ");
      scanf("%s", modelo);

      printf("Digite o Ano: ");
      scanf("%d", &ano);

      printf("Digite o Preco: ");
      scanf("%f", &preco);

      adicionarVeiculo(&meuArmazem, placa, modelo, ano, preco);
      printf("Adicionado com sucesso!\n");
      break;
    }

    case 2: {
      printf("\n--- SEUS VEICULOS ---\n");
      if (meuArmazem.count == 0) {
        printf("O estacionamento esta vazio.\n");
      } else {
        for (size_t i = 0; i < meuArmazem.count; i++) {
          printf(
              "Vaga %zu | Placa: %s | Modelo: %s | Ano: %d | Preco: R$ %.2f\n",
              i, meuArmazem.veiculos[i].placa, meuArmazem.veiculos[i].modelo,
              meuArmazem.veiculos[i].ano, meuArmazem.veiculos[i].preco);
        }
      }
      break;
    }

    case 3: {
      int indice;
      printf("Digite o numero da vaga para buscar: ");
      scanf("%d", &indice);

      buscarVeiculoPorIndice(&meuArmazem, indice);
      break;
    }

    case 4: {
      int indice;
      printf("Digite o numero da vaga para remover o veiculo: ");
      scanf("%d", &indice);

      removerVeiculo(&meuArmazem, indice);
      break;
    }

    case 0:
      printf("Saindo...\n");
      break;

    default:
      printf("Opcao invalida!\n");
    }
  } while (opcao != 0);

  // esse free aqui e so pra liberar memoria
  free(meuArmazem.veiculos);

  return 0;
}