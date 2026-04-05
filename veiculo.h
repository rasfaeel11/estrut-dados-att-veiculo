#ifndef VEICULO_H
#define VEICULO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Veiculo {
  char placa[8];
  char modelo[50];
  int ano;
  float preco;
} Veiculo;

typedef struct Armazem {
  Veiculo *veiculos;
  size_t count; // tipo especial para tamanhos de arrays
  size_t capacidade;
} Armazem;

void adicionarVeiculo(Armazem *meuArmazem, char *placa, char *modelo, int ano,
                      float preco) {

  if (meuArmazem->count >= meuArmazem->capacidade) {
    if (meuArmazem->capacidade == 0)
      meuArmazem->capacidade = 256;
    else
      meuArmazem->capacidade *= 2;

    meuArmazem->veiculos =
        realloc(meuArmazem->veiculos,
                meuArmazem->capacidade * sizeof(*meuArmazem->veiculos));

    if (meuArmazem->veiculos == NULL) {
      printf("Erro de memoria\n");
      exit(1);
    }
  }

  strcpy(meuArmazem->veiculos[meuArmazem->count].placa, placa);
  strcpy(meuArmazem->veiculos[meuArmazem->count].modelo,
         modelo); // tive que pesquisar, nao pode usar = para atribuir string,
                  // essa funcao copia
  meuArmazem->veiculos[meuArmazem->count].ano = ano;
  meuArmazem->veiculos[meuArmazem->count].preco = preco;

  meuArmazem->count++;
}

void buscarVeiculoPorIndice(Armazem *meuArmazem, int indice) {
  if (indice < 0 || (size_t)indice >= meuArmazem->count) {
    printf("\nErro: Vaga vazia ou inexistente!\n");
    return;
  }

  printf("\n--- VEICULO NA VAGA %d ---\n", indice);
  printf("Placa: %s | Modelo: %s | Ano: %d | Preco: R$ %.2f\n",
         meuArmazem->veiculos[indice].placa,
         meuArmazem->veiculos[indice].modelo, meuArmazem->veiculos[indice].ano,
         meuArmazem->veiculos[indice].preco);
}

void removerVeiculo(Armazem *meuArmazem, int indice) {
  if (indice < 0 || (size_t)indice >= meuArmazem->count) {
    printf("\nErro: Vaga vazia ou inexistente. Nao ha o que remover.\n");
    return;
  }

  for (size_t i = indice; i < meuArmazem->count - 1; i++) {
    meuArmazem->veiculos[i] = meuArmazem->veiculos[i + 1];
  }

  meuArmazem->count--;
  printf("\nVeiculo removido! A fila andou para tapar o buraco.\n");
}

#endif