#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Sistema.hpp"

// Verifica se o método cadastrarJogador adiciona corretamente novos jogadores e impede o cadastro de jogadores duplicados.
TEST_CASE("Teste de cadastro de jogador no sistema") {
    Sistema sistema;

    CHECK(sistema.cadastrarJogador("Jogador1", "Nome1") == true);  // Cadastro de novo jogador
    CHECK(sistema.cadastrarJogador("Jogador1", "Nome1") == false); // Tentativa de cadastrar jogador já existente
    CHECK(sistema.cadastrarJogador("Jogador2", "Nome2") == true);  // Cadastro de outro jogador
}

// Verifica se o método removerJogador remove corretamente um jogador existente e lida com tentativas de remover jogadores que não estão cadastrados.
TEST_CASE("Teste de remoção de jogador no sistema") {
    Sistema sistema;
    sistema.cadastrarJogador("Jogador1", "Nome1");

    CHECK(sistema.removerJogador("Jogador1") == true);  // Remoção de jogador existente
    CHECK(sistema.removerJogador("Jogador1") == false); // Tentativa de remover jogador que não existe mais
    CHECK(sistema.removerJogador("Jogador2") == false); // Remoção de jogador não cadastrado
}

// Testa a ordenação de jogadores por apelido e nome, capturando a saída de listarJogadores para verificar se está correta.
TEST_CASE("Teste de listagem de jogadores no sistema") {
    Sistema sistema;
    sistema.cadastrarJogador("Jogador2", "Nome2");
    sistema.cadastrarJogador("Jogador1", "Nome1");

    SUBCASE("Ordenação por apelido") {
        std::ostringstream output;
        std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());
        
        sistema.listarJogadores('A');
        
        std::cout.rdbuf(oldCoutBuf);  // Restaurar o buffer original
        std::string expectedOutput = "Apelido: Jogador1 Nome: Nome1\nApelido: Jogador2 Nome: Nome2\n";
        CHECK(output.str() == expectedOutput);
    }

    SUBCASE("Ordenação por nome") {
        std::ostringstream output;
        std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());
        
        sistema.listarJogadores('N');
        
        std::cout.rdbuf(oldCoutBuf);  // Restaurar o buffer original
        std::string expectedOutput = "Apelido: Jogador1 Nome: Nome1\nApelido: Jogador2 Nome: Nome2\n";
        CHECK(output.str() == expectedOutput);
    }
}

// Verifica se o método criarJogo cria instâncias dos jogos Reversi e Lig4 corretamente e retorna nullptr para jogos inválidos.
TEST_CASE("Teste de criação de jogos no sistema") {
    Sistema sistema;

    CHECK(dynamic_cast<Reversi*>(sistema.criarJogo("R")) != nullptr);  // Criação de jogo Reversi
    CHECK(dynamic_cast<Lig4*>(sistema.criarJogo("L")) != nullptr);     // Criação de jogo Lig4
    CHECK(sistema.criarJogo("X") == nullptr);  // Tipo de jogo inválido
}

// Testa o fluxo de uma partida, incluindo a verificação de jogadores cadastrados, o tipo de jogo, e se o sistema lida corretamente com cenários de erro.
TEST_CASE("Teste de execução de partida no sistema") {
    Sistema sistema;
    sistema.cadastrarJogador("Jogador1", "Nome1");
    sistema.cadastrarJogador("Jogador2", "Nome2");

    CHECK(sistema.executarPartida("R", "Jogador1", "Jogador2") == true);  // Partida de Reversi
    CHECK(sistema.executarPartida("L", "Jogador1", "Jogador2") == true);  // Partida de Lig4
    CHECK(sistema.executarPartida("R", "Jogador1", "Jogador3") == false); // Jogador não cadastrado
    CHECK(sistema.executarPartida("X", "Jogador1", "Jogador2") == false); // Jogo inválido
}

int main() {
    doctest::Context context;
    context.addFilter("test-case", "Teste de Sistema");
    return context.run();
}
