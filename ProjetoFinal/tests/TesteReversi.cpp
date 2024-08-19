#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Reversi.hpp"
#include <iostream>

// Função auxiliar para contar o número de peças de um jogador no tabuleiro
int contarPecas(const Reversi& jogo, char jogador) {
    int contagem = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (jogo.tabuleiro[i][j] == jogador) {
                ++contagem;
            }
        }
    }
    return contagem;
}

// Teste para inicialização do jogo
TEST_CASE("Teste de inicialização do jogo de Reversi") {
    Reversi jogo;
    jogo.iniciar();

    // Verifica se o tabuleiro foi inicializado corretamente
    CHECK(jogo.tabuleiro[3][3] == 'O');
    CHECK(jogo.tabuleiro[3][4] == 'X');
    CHECK(jogo.tabuleiro[4][3] == 'X');
    CHECK(jogo.tabuleiro[4][4] == 'O');
    CHECK(jogo.jogadorAtual == 'X');
}

// Teste para validação de jogadas
TEST_CASE("Teste de validação de jogadas no Reversi") {
    Reversi jogo;
    jogo.iniciar();

    // Verifica se uma jogada válida é aceita
    CHECK(jogo.validarJogada(2, 3) == true);

    // Verifica se uma jogada inválida é rejeitada
    CHECK(jogo.validarJogada(0, 0) == false);
}

// Teste para alternância de jogadores
TEST_CASE("Teste de alternância de jogadores no Reversi") {
    Reversi jogo;
    jogo.iniciar();

    // Verifica a alternância após uma jogada válida
    jogo.realizarJogada(2, 3);
    CHECK(jogo.jogadorAtual == 'O');

    // Verifica a alternância após uma jogada válida pelo segundo jogador
    jogo.realizarJogada(2, 2);
    CHECK(jogo.jogadorAtual == 'X');
}

// Teste para verificação de vitória
TEST_CASE("Teste de verificação de vitória no Reversi") {
    Reversi jogo;
    jogo.iniciar();

    // Simula um cenário onde o jogo deveria continuar
    CHECK(jogo.verificarVitoria() == false);

    // Simula um cenário onde o jogo termina
    // Configurando manualmente o tabuleiro para um estado sem jogadas válidas
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            jogo.tabuleiro[i][j] = 'X';
        }
    }
    CHECK(jogo.verificarVitoria() == true);
}

// Teste para realização de jogadas e virar peças
TEST_CASE("Teste de realização de jogadas e virada de peças no Reversi") {
    Reversi jogo;
    jogo.iniciar();

    // Realiza uma jogada válida que deve virar uma peça do oponente
    jogo.realizarJogada(2, 3);
    CHECK(jogo.tabuleiro[3][3] == 'X'); // A peça foi virada

    // Verifica o número de peças após a jogada
    CHECK(contarPecas(jogo, 'X') == 4);
    CHECK(contarPecas(jogo, 'O') == 1);
}
