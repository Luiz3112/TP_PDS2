#include "doctest.h"
#include "Lig4.hpp"
#include <iostream>
#include <sstream>

TEST_CASE("Teste de iniciar e imprimir o tabuleiro") {
    Lig4 lig4;
    lig4.iniciar();
    
    // Captura a saída do tabuleiro
    std::ostringstream output;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    lig4.imprimirTabuleiro();
    std::cout.rdbuf(oldCoutStreamBuf);

    // Verifica se o tabuleiro inicial está correto
    std::string tabuleiroEsperado = 
        "\nEstado atual do tabuleiro de Lig4:\n"
        "| | | | | | | |\n"
        "| | | | | | | |\n"
        "| | | | | | | |\n"
        "| | | | | | | |\n"
        "| | | | | | | |\n"
        "| | | | | | | |\n"
        " 0 1 2 3 4 5 6 \n";
    CHECK(output.str() == tabuleiroEsperado);
}

TEST_CASE("Teste de jogadas válidas e alternância de jogadores") {
    Lig4 lig4;
    lig4.iniciar();

    // Jogador X realiza uma jogada na coluna 0
    lig4.realizarJogada(0, 0);

    // Captura a saída do tabuleiro após a jogada
    std::ostringstream output;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    lig4.imprimirTabuleiro();
    std::cout.rdbuf(oldCoutStreamBuf);

    // Verifica se a jogada foi registrada corretamente
    std::string tabuleiroEsperado =
        "\nEstado atual do tabuleiro de Lig4:\n"
        "| | | | | | | |\n"
        "| | | | | | | |\n"
        "| | | | | | | |\n"
        "| | | | | | | |\n"
        "| | | | | | | |\n"
        "|X| | | | | | |\n"
        " 0 1 2 3 4 5 6 \n";
    CHECK(output.str() == tabuleiroEsperado);

    // Verifica alternância de jogador
    lig4.realizarJogada(0, 1); // Jogador O
    output.str(""); // Limpa o buffer
    lig4.imprimirTabuleiro();
    CHECK(output.str().find("|O|") != std::string::npos);
}

TEST_CASE("Teste de jogada inválida") {
    Lig4 lig4;
    lig4.iniciar();

    // Realiza jogadas válidas para preencher a coluna 0
    for (int i = 0; i < 6; ++i) {
        lig4.realizarJogada(0, 0);
    }

    // Tenta realizar uma jogada inválida na coluna 0, que já está cheia
    std::ostringstream output;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    lig4.realizarJogada(0, 0);
    std::cout.rdbuf(oldCoutStreamBuf);

    // Verifica se a mensagem de erro foi exibida
    CHECK(output.str().find("ERRO: jogada inválida") != std::string::npos);
}

TEST_CASE("Teste de verificação de vitória") {
    Lig4 lig4;
    lig4.iniciar();

    // Simula uma sequência de jogadas que resulta em vitória para o jogador X
    lig4.realizarJogada(0, 0); // X
    lig4.realizarJogada(0, 1); // O
    lig4.realizarJogada(1, 0); // X
    lig4.realizarJogada(0, 2); // O
    lig4.realizarJogada(2, 0); // X
    lig4.realizarJogada(0, 3); // O
    lig4.realizarJogada(3, 0); // X

    CHECK(lig4.verificarVitoria() == true);
}
