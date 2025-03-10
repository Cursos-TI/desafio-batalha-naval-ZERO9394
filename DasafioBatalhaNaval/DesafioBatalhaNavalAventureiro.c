#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se uma posição está dentro dos limites do tabuleiro
int posicaoValida(int linha, int coluna) {
    return (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO);
}

// Função para verificar se uma posição já está ocupada por outro navio
int posicaoOcupada(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    return tabuleiro[linha][coluna] == 3;
}

// Função para posicionar um navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se as posições estão dentro dos limites e não se sobrepõem
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0; // Fora do limite
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (posicaoOcupada(tabuleiro, linha, coluna + i)) return 0; // Já ocupada
    }
    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
    return 1; // Sucesso
}

// Função para posicionar um navio verticalmente
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se as posições estão dentro dos limites e não se sobrepõem
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0; // Fora do limite
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (posicaoOcupada(tabuleiro, linha + i, coluna)) return 0; // Já ocupada
    }
    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
    return 1; // Sucesso
}

// Função para posicionar um navio na diagonal (principal)
int posicionarNavioDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se as posições estão dentro dos limites e não se sobrepõem
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0; // Fora do limite
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (posicaoOcupada(tabuleiro, linha + i, coluna + i)) return 0; // Já ocupada
    }
    // Posiciona o navio na diagonal principal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = 3;
    }
    return 1; // Sucesso
}

// Função para posicionar um navio na diagonal (secundária)
int posicionarNavioDiagonalSecundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se as posições estão dentro dos limites e não se sobrepõem
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna - TAMANHO_NAVIO < -1) return 0; // Fora do limite
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (posicaoOcupada(tabuleiro, linha + i, coluna - i)) return 0; // Já ocupada
    }
    // Posiciona o navio na diagonal secundária
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = 3;
    }
    return 1; // Sucesso
}

int main() {
    // Inicializa o tabuleiro com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posicionamento dos navios
    int linha, coluna;

    // Navio Horizontal
    linha = 2; coluna = 1;
    if (!posicionarNavioHorizontal(tabuleiro, linha, coluna)) {
        printf("Não foi possível posicionar o navio horizontal na posição (%d, %d)\n", linha, coluna);
    }

    // Navio Vertical
    linha = 5; coluna = 4;
    if (!posicionarNavioVertical(tabuleiro, linha, coluna)) {
        printf("Não foi possível posicionar o navio vertical na posição (%d, %d)\n", linha, coluna);
    }

    // Navio Diagonal Principal
    linha = 0; coluna = 0;
    if (!posicionarNavioDiagonalPrincipal(tabuleiro, linha, coluna)) {
        printf("Não foi possível posicionar o navio diagonal principal na posição (%d, %d)\n", linha, coluna);
    }

    // Navio Diagonal Secundária
    linha = 0; coluna = 9;
    if (!posicionarNavioDiagonalSecundaria(tabuleiro, linha, coluna)) {
        printf("Não foi possível posicionar o navio diagonal secundária na posição (%d, %d)\n", linha, coluna);
    }

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
