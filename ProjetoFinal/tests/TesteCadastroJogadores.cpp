#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "CadastroJogadores.hpp"

// Testes para o método cadastrarJogador que verifica se o método cadastrarJogador adiciona corretamente novos jogadores e se impede o cadastro duplicado.
TEST_CASE("Teste de cadastro de jogador") {
    CadastroJogadores cadastro;

    CHECK(cadastro.cadastrarJogador("Jogador1", "Nome1") == true);  // Cadastro de novo jogador
    CHECK(cadastro.cadastrarJogador("Jogador1", "Nome1") == false); // Tentativa de cadastrar jogador já existente
    CHECK(cadastro.cadastrarJogador("Jogador2", "Nome2") == true);  // Cadastro de outro jogador
}

// Testes para o método removerJogador que avalia a remoção de um jogador existente e verifica se o método lida corretamente com tentativas de remover jogadores não cadastrados.
TEST_CASE("Teste de remoção de jogador") {
    CadastroJogadores cadastro;
    cadastro.cadastrarJogador("Jogador1", "Nome1");

    CHECK(cadastro.removerJogador("Jogador1") == true);  // Remoção de jogador existente
    CHECK(cadastro.removerJogador("Jogador1") == false); // Tentativa de remover jogador que não existe mais
    CHECK(cadastro.removerJogador("Jogador2") == false); // Remoção de jogador não cadastrado
}

// Teste para o método buscarJogador que verifica se o método buscarJogador retorna o jogador correto quando ele existe e nullptr quando o jogador não está cadastrado.
TEST_CASE("Teste de busca de jogador") {
    CadastroJogadores cadastro;
    cadastro.cadastrarJogador("Jogador1", "Nome1");

    CHECK(cadastro.buscarJogador("Jogador1") != nullptr); // Busca de jogador existente
    CHECK(cadastro.buscarJogador("Jogador2") == nullptr); // Busca de jogador não cadastrado
}

// Teste para o método listarJogadores que verifica a ordenação dos jogadores com base no apelido e no nome. Para capturar a saída de listarJogadores, o código redireciona o std::cout para uma string, o que permite comparar o resultado esperado.
TEST_CASE("Teste de listagem de jogadores") {
    CadastroJogadores cadastro;
    cadastro.cadastrarJogador("Jogador2", "Nome2");
    cadastro.cadastrarJogador("Jogador1", "Nome1");

    SUBCASE("Ordenação por apelido") {
        std::ostringstream output;
        std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());
        
        cadastro.listarJogadores('A');
        
        std::cout.rdbuf(oldCoutBuf);  // Restaurar o buffer original
        std::string expectedOutput = "Apelido: Jogador1 Nome: Nome1\nApelido: Jogador2 Nome: Nome2\n";
        CHECK(output.str() == expectedOutput);
    }

    SUBCASE("Ordenação por nome") {
        std::ostringstream output;
        std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());
        
        cadastro.listarJogadores('N');
        
        std::cout.rdbuf(oldCoutBuf);  // Restaurar o buffer original
        std::string expectedOutput = "Apelido: Jogador1 Nome: Nome1\nApelido: Jogador2 Nome: Nome2\n";
        CHECK(output.str() == expectedOutput);
    }
}

int main() {
    doctest::Context context;
    context.addFilter("test-case", "Teste de CadastroJogadores");
    return context.run();
}
