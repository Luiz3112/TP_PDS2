#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "IA.hpp"
#include "Reversi.hpp"
#include "Lig4.hpp"

// Teste para o construtor da classe IA
TEST_CASE("Teste de criação de IA") {
    IA ia("IA Teste", "IA1");

    CHECK(ia.getNome() == "IA Teste");
    CHECK(ia.getApelido() == "IA1");
}

// Teste para o método calcularJogada
TEST_CASE("Teste de cálculo de jogada pela IA") {
    IA ia("IA Teste", "IA1");

    SUBCASE("Jogo Reversi") {
        Reversi reversi;

        // Situação inicial do jogo, IA deve encontrar a primeira jogada válida
        reversi.iniciar();
        std::pair<int, int> jogada = ia.calcularJogada(&reversi);
        CHECK(reversi.validarJogada(jogada.first, jogada.second) == true);
    }

    SUBCASE("Jogo Lig4") {
        Lig4 lig4;

        // Situação inicial do jogo, IA deve encontrar a primeira jogada válida
        lig4.iniciar();
        std::pair<int, int> jogada = ia.calcularJogada(&lig4);
        CHECK(lig4.validarJogada(jogada.first, jogada.second) == true);
    }

    SUBCASE("Nenhuma jogada válida") {
        Reversi reversi;

        // Preencher o tabuleiro inteiro para que não haja jogadas válidas
        for (int i = 0; i < reversi.getAltura(); ++i) {
            for (int j = 0; j < reversi.getLargura(); ++j) {
                reversi.realizarJogada(i, j);
            }
        }

        std::pair<int, int> jogada = ia.calcularJogada(&reversi);
        CHECK(jogada == std::make_pair(-1, -1)); // Nenhuma jogada válida encontrada
    }
}
