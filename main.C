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

int main(void) {
  Armazem meuArmazem = {NULL, 0, 0};

  for (int x = 0; x < 10; ++x) {
    if (meuArmazem.count >= meuArmazem.capacidade) {
      if (meuArmazem.capacidade == 0)
        meuArmazem.capacidade = 256;
      else
        meuArmazem.capacidade *= 2;

      meuArmazem.veiculos =
          realloc(meuArmazem.veiculos,
                  meuArmazem.capacidade * sizeof(*meuArmazem.veiculos));
      if (meuArmazem.veiculos == NULL) {
        printf("Erro de memoria\n");
        exit(1);
      }
    }

    sprintf(meuArmazem.veiculos[meuArmazem.count].placa, "ABC000%d",
            x); // impossivel em C calcular numero com string, entao tem que
                // apenas adicionar
    strcpy(meuArmazem.veiculos[meuArmazem.count].modelo,
           "Honda Civic"); // tive que pesquisar, nao pode usar = para comparar
                           // string, essa funcao copia
    meuArmazem.veiculos[meuArmazem.count].ano = 2020 + x;
    meuArmazem.veiculos[meuArmazem.count].preco = 90000.0;

    meuArmazem.count++;
  }

  for (size_t i = 0; i < meuArmazem.count; i++) {
    printf("Vaga %zu | Placa: %s | Modelo: %s | Ano: %d | Preco: R$ %.2f\n", i,
           meuArmazem.veiculos[i].placa, meuArmazem.veiculos[i].modelo,
           meuArmazem.veiculos[i].ano, meuArmazem.veiculos[i].preco);
  }

  // esse free aqui e so pra liberar memoria
  free(meuArmazem.veiculos);

  return 0;
}