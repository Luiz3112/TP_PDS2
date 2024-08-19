#include "doctest.h"
#include "Jogador.hpp"
#include <iostream>
#include <sstream> 

TEST_CASE("Teste do construtor e métodos de acesso") {
    Jogador jogador("apelido1", "Nome1");

    CHECK(jogador.getApelido() == "apelido1");
    CHECK(jogador.getNome() == "Nome1");
}

TEST_CASE("Teste de adicionar vitórias e derrotas") {
    Jogador jogador("apelido1", "Nome1");

    // Testando vitórias
    jogador.adicionarVitoria("R");
    jogador.adicionarVitoria("L");

    // Testando derrotas
    jogador.adicionarDerrota("R");
    jogador.adicionarDerrota("L");

    // Testando estatísticas de vitória e derrota
    // Não há método para checar estatísticas diretamente, então isso é mais um teste visual
    // Dependendo de como você implementa a visualização, talvez seja necessário capturar a saída padrão.
    // Exemplo:
    std::ostringstream output;
    std::streambuf* orig = std::cout.rdbuf(output.rdbuf());

    jogador.imprimirEstatisticas();

    std::cout.rdbuf(orig); // Restaurar a saída padrão
    std::string result = output.str();

    CHECK(result.find("REVERSI - V: 1 D: 1") != std::string::npos);
    CHECK(result.find("LIG4 - V: 1 D: 1") != std::string::npos);
}

