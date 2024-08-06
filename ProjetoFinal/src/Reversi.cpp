#include "Reversi.hpp"
#include <iostream>

void Reversi::iniciar() {
    tabuleiro = std::vector<std::vector<char>>(8, std::vector<char>(8, ' '));
    tabuleiro[3][3] = 'O';
    tabuleiro[3][4] = 'X';
    tabuleiro[4][3] = 'X';
    tabuleiro[4][4] = 'O';
    jogadorAtual = 'X';
    imprimirTabuleiro();
}

void Reversi::imprimirTabuleiro() {
    std::cout << "Estado atual do tabuleiro de Reversi:" << std::endl;
    for (const auto& linha : tabuleiro) {
        for (const auto& celula : linha) {
            std::cout << "|" << (celula == ' ' ? ' ' : celula);
        }
        std::cout << "|" << std::endl;
    }
}

bool Reversi::validarJogada(int linha, int coluna) {
    return jogadaValida(linha, coluna, jogadorAtual);
}

bool Reversi::verificarVitoria() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (jogadaValida(i, j, 'X') || jogadaValida(i, j, 'O')) {
                return false;
            }
        }
    }
    return true;
}

void Reversi::realizarJogada(int linha, int coluna) {
    if (jogadaValida(linha, coluna, jogadorAtual)) {
        tabuleiro[linha][coluna] = jogadorAtual;
        virarPecas(linha, coluna, jogadorAtual);
        alternarJogador();
        imprimirTabuleiro();
    } else {
        std::cout << "ERRO: jogada inválida" << std::endl;
    }
}

void Reversi::alternarJogador() {
    jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
}

bool Reversi::jogadaValida(int linha, int coluna, char jogador) {
    if (tabuleiro[linha][coluna] != ' ') {
        return false;
    }
    for (int dLinha = -1; dLinha <= 1; ++dLinha) {
        for (int dColuna = -1; dColuna <= 1; ++dColuna) {
            if (dLinha != 0 || dColuna != 0) {
                if (verificarDirecao(linha, coluna, dLinha, dColuna, jogador)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Reversi::verificarDirecao(int linha, int coluna, int dLinha, int dColuna, char jogador) {
    char oponente = (jogador == 'X') ? 'O' : 'X';
    int i = linha + dLinha;
    int j = coluna + dColuna;
    bool encontrouOponente = false;

    while (i >= 0 && i < 8 && j >= 0 && j < 8) {
        if (tabuleiro[i][j] == oponente) {
            encontrouOponente = true;
        } else if (tabuleiro[i][j] == jogador) {
            return encontrouOponente;
        } else {
            break;
        }
        i += dLinha;
        j += dColuna;
    }
    return false;
}

void Reversi::virarPecas(int linha, int coluna, char jogador) {
    for (int dLinha = -1; dLinha <= 1; ++dLinha) {
        for (int dColuna = -1; dColuna <= 1; ++dColuna) {
            if (dLinha != 0 || dColuna != 0) {
                if (verificarDirecao(linha, coluna, dLinha, dColuna, jogador)) {
                    virarDirecao(linha, coluna, dLinha, dColuna, jogador);
                }
            }
        }
    }
}

void Reversi::virarDirecao(int linha, int coluna, int dLinha, int dColuna, char jogador) {
    char oponente = (jogador == 'X') ? 'O' : 'X';
    int i = linha + dLinha;
    int j = coluna + dColuna;

    while (i >= 0 && i < 8 && j >= 0 && j < 8 && tabuleiro[i][j] == oponente) {
        tabuleiro[i][j] = jogador;
        i += dLinha;
        j += dColuna;
    }
}