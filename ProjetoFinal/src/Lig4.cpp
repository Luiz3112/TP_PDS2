#include "Lig4.hpp"
#include <iostream>

void Lig4::iniciar() {
    tabuleiro = std::vector<std::vector<char>>(6, std::vector<char>(7, ' '));
    jogadorAtual = 'X';
    imprimirTabuleiro();
}

void Lig4::imprimirTabuleiro() {
    std::cout << "Estado atual do tabuleiro de Lig4:" << std::endl;
    for (const auto& linha : tabuleiro) {
        for (const auto& celula : linha) {
            std::cout << "|" << (celula == ' ' ? ' ' : celula);
        }
        std::cout << "|" << std::endl;
    }
}

bool Lig4::validarJogada(int linha, int coluna) {
    return jogadaValida(coluna);
}

bool Lig4::verificarVitoria() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (tabuleiro[i][j] != ' ' && (
                verificarVitoriaNaDirecao(i, j, 1, 0) || 
                verificarVitoriaNaDirecao(i, j, 0, 1) || 
                verificarVitoriaNaDirecao(i, j, 1, 1) || 
                verificarVitoriaNaDirecao(i, j, 1, -1)   
            )) {
                return true;
            }
        }
    }
    return false;
}

void Lig4::realizarJogada(int linha, int coluna) {
    if (jogadaValida(coluna)) {
        realizarJogadaNaColuna(coluna);
        alternarJogador();
        imprimirTabuleiro();
    } else {
        std::cout << "ERRO: jogada inválida" << std::endl;
    }
}

void Lig4::alternarJogador() {
    jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
}

bool Lig4::jogadaValida(int coluna) {
    return tabuleiro[0][coluna] == ' ';
}

void Lig4::realizarJogadaNaColuna(int coluna) {
    for (int i = 5; i >= 0; --i) {
        if (tabuleiro[i][coluna] == ' ') {
            tabuleiro[i][coluna] = jogadorAtual;
            break;
        }
    }
}

bool Lig4::verificarVitoriaNaDirecao(int linha, int coluna, int dLinha, int dColuna) {
    char jogador = tabuleiro[linha][coluna];
    int contagem = 0;

    for (int i = 0; i < 4; ++i) {
        int novaLinha = linha + i * dLinha;
        int novaColuna = coluna + i * dColuna;

        if (novaLinha >= 0 && novaLinha < 6 && novaColuna >= 0 && novaColuna < 7 && tabuleiro[novaLinha][novaColuna] == jogador) {
            contagem++;
        } else {
            break;
        }
    }

    return contagem == 4;
}
