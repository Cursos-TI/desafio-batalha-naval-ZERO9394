#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0)
                printf("0 ");
            else if (tabuleiro[i][j] == 3)
                printf("3 ");
            else if (tabuleiro[i][j] == 5)
                printf("5 ");
        }
        printf("\n");
    }
}

// Função para aplicar a área de efeito de cone
void aplicarHabilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemX, int origemY) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = i; j < TAMANHO_HABILIDADE; j++) {
            int x = origemX + i;
            int y = origemY - j + i;
            if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO)
                tabuleiro[x][y] = 5;
        }
    }
}

// Função para aplicar a área de efeito de cruz
void aplicarHabilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemX, int origemY) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        int x = origemX;
        int y = origemY - TAMANHO_HABILIDADE / 2 + i;
        if (y >= 0 && y < TAMANHO_TABULEIRO)
            tabuleiro[x][y] = 5;

        x = origemX - TAMANHO_HABILIDADE / 2 + i;
        y = origemY;
        if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO)
            tabuleiro[x][y] = 5;
    }
}

// Função para aplicar a área de efeito de octaedro
void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemX, int origemY) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int x = origemX - TAMANHO_HABILIDADE / 2 + i;
            int y = origemY - TAMANHO_HABILIDADE / 2 + j;

            if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO) {
                if (abs(i - j) <= 1)
                    tabuleiro[x][y] = 5;
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};  // Inicializando o tabuleiro com água (0)

    // Posicionamento dos navios (exemplo)
    tabuleiro[2][2] = 3;  // Navio na posição (2, 2)
    tabuleiro[3][2] = 3;  // Navio na posição (3, 2)
    tabuleiro[4][2] = 3;  // Navio na posição (4, 2)

    // Aplica as habilidades no tabuleiro
    aplicarHabilidadeCone(tabuleiro, 5, 5);   // Cone a partir de (5, 5)
    aplicarHabilidadeCruz(tabuleiro, 3, 5);   // Cruz a partir de (3, 5)
    aplicarHabilidadeOctaedro(tabuleiro, 7, 7); // Octaedro a partir de (7, 7)

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
