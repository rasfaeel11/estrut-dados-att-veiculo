#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct No {
    char nome[50];
    struct No* esquerda;
    struct No* direita;
} No;


No* criarLocal(const char* nome) {
    No* novoNo = (No*)malloc(sizeof(No));
    strcpy(novoNo->nome, nome);
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}


int mostrarCaminho(No* raiz, const char* destino, char caminho[][50], char direcoes[][15], int nivel) {
    if (raiz == NULL) return 0;

    
    strcpy(caminho[nivel], raiz->nome);

    
    if (strcmp(raiz->nome, destino) == 0) {
        printf("=== AVENTURA CONCLUIDA ===\n");
        printf("Destino: %s\n", destino);
        printf("Trilha percorrida:\n");
        
        for (int i = 0; i <= nivel; i++) {
            printf("[%s]", caminho[i]);
            if (i < nivel) {
                printf(" --(%s)--> ", direcoes[i]);
            }
        }
        printf("\n\n");
        return 1;
    }

    strcpy(direcoes[nivel], "esquerda");
    if (mostrarCaminho(raiz->esquerda, destino, caminho, direcoes, nivel + 1)) {
        return 1;
    }

    
    strcpy(direcoes[nivel], "direita");
    if (mostrarCaminho(raiz->direita, destino, caminho, direcoes, nivel + 1)) {
        return 1;
    }

    return 0;   
}

void limparFloresta(No* raiz) {
    if (raiz == NULL) return;
    limparFloresta(raiz->esquerda);
    limparFloresta(raiz->direita);
    free(raiz);
}

int main() {

    No* raiz = criarLocal("Entrada da Floresta");
    raiz->esquerda = criarLocal("Trilha antiga");
    raiz->direita = criarLocal("Rio tranquilo");

    // NÍVEL 2: Caminhos a partir da Trilha antiga
    raiz->esquerda->esquerda = criarLocal("Ponte quebrada");
    raiz->esquerda->direita = criarLocal("Caverna escura");

    // NÍVEL 2: Caminhos a partir do Rio tranquilo
    raiz->direita->esquerda = criarLocal("Ruinas esquecidas");
    raiz->direita->direita = criarLocal("Clareira secreta");

    // NÍVEL 3 (Finais): Caminhos a partir da Ponte quebrada
    raiz->esquerda->esquerda->esquerda = criarLocal("Perdido");
    raiz->esquerda->esquerda->direita = criarLocal("Furtivo");

    // NÍVEL 3 (Finais): Caminhos a partir da Caverna escura
    raiz->esquerda->direita->esquerda = criarLocal("Tesouro antigo");
    raiz->esquerda->direita->direita = criarLocal("Guardiao");

    // NÍVEL 3 (Finais): Caminhos a partir das Ruinas esquecidas
    raiz->direita->esquerda->esquerda = criarLocal("Monstro");
    raiz->direita->esquerda->direita = criarLocal("Cristal antigo");

    // NÍVEL 3 (Finais): Caminhos a partir da Clareira secreta
    raiz->direita->direita->esquerda = criarLocal("Ajudante");
    raiz->direita->direita->direita = criarLocal("Chefe Final");
    
    // Matrizes para guardar o histórico do percurso e as direções tomadas
    char caminho[10][50];
    char direcoes[10][15];


    mostrarCaminho(raiz, "Ajudante", caminho, direcoes, 0);


    mostrarCaminho(raiz, "Tesouro antigo", caminho, direcoes, 0);

    limparFloresta(raiz);

    return 0;
}