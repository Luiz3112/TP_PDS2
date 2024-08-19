#include "doctest.h"
#include "CadastroJogadores.hpp"
#include "Jogador.hpp"
#include <iostream>

TEST_CASE("Teste do método cadastrarJogador") {
    CadastroJogadores cadastro;

    // Testando cadastro de um jogador novo
    CHECK(cadastro.cadastrarJogador("apelido1", "Nome1") == true);

    // Testando cadastro de um jogador com o mesmo apelido (deve falhar)
    CHECK(cadastro.cadastrarJogador("apelido1", "Nome2") == false);

    // Testando cadastro de um segundo jogador
    CHECK(cadastro.cadastrarJogador("apelido2", "Nome2") == true);
}

TEST_CASE("Teste do método removerJogador") {
    CadastroJogadores cadastro;

    // Pré-cadastrando jogadores
    cadastro.cadastrarJogador("apelido1", "Nome1");
    cadastro.cadastrarJogador("apelido2", "Nome2");

    // Testando remoção de um jogador existente
    CHECK(cadastro.removerJogador("apelido1") == true);

    // Testando remoção de um jogador que não existe
    CHECK(cadastro.removerJogador("apelido3") == false);
}

TEST_CASE("Teste do método buscarJogador") {
    CadastroJogadores cadastro;

    // Pré-cadastrando jogadores
    cadastro.cadastrarJogador("apelido1", "Nome1");
    cadastro.cadastrarJogador("apelido2", "Nome2");

    // Testando a busca de um jogador existente
    CHECK(cadastro.buscarJogador("apelido1") != nullptr);

    // Testando a busca de um jogador inexistente
    CHECK(cadastro.buscarJogador("apelido3") == nullptr);
}

TEST_CASE("Teste do método listarJogadores") {
    CadastroJogadores cadastro;

    // Pré-cadastrando jogadores
    cadastro.cadastrarJogador("apelido1", "NomeB");
    cadastro.cadastrarJogador("apelido2", "NomeA");

    // Testando a listagem de jogadores por apelido (ordem alfabética)
    std::cout << "Listando jogadores por apelido:\n";
    cadastro.listarJogadores('A'); // Isso deve listar em ordem de apelido

    // Testando a listagem de jogadores por nome
    std::cout << "Listando jogadores por nome:\n";
    cadastro.listarJogadores('N'); // Isso deve listar em ordem de nome
}

