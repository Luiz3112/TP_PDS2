#include "Sistema.hpp"
#include "Reversi.hpp"
#include "Lig4.hpp"
#include <iostream>
#include <sstream>

void Sistema::executar() {
    // Implementação do loop principal já está no main.cpp ...
}

bool Sistema::cadastrarJogador(const std::string& apelido, const std::string& nome) {
    return cadastro.cadastrarJogador(apelido, nome);
}

bool Sistema::removerJogador(const std::string& apelido) {
    return cadastro.removerJogador(apelido);
}

void Sistema::listarJogadores(char criterio) {
    cadastro.listarJogadores(criterio);
}

bool Sistema::executarPartida(const std::string& jogo, const std::string& apelido1, const std::string& apelido2) {
    Jogador* jogador1 = cadastro.buscarJogador(apelido1);
    Jogador* jogador2 = cadastro.buscarJogador(apelido2);
    if (!jogador1 || !jogador2) {
        return false;
    }

    Jogo* partida = criarJogo(jogo);
    if (!partida) {
        return false;
    }

    partida->iniciar();
    std::string jogada;
    char jogadorAtual = 'X'; // Começa com o jogador 1
    while (!partida->verificarVitoria()) {
        std::string apelidoAtual = (jogadorAtual == 'X') ? apelido1 : apelido2;
        std::cout << "Turno de jogador " << apelidoAtual << ": ";
        std::getline(std::cin, jogada);
        std::istringstream iss(jogada);
        int linha, coluna;
        if (jogo == "R") { // Reversi
            if (!(iss >> linha >> coluna)) {
                std::cout << "ERRO: formato incorreto" << std::endl;
                continue;
            }
        } else if (jogo == "L") { // Lig4
            if (!(iss >> coluna)) {
                std::cout << "ERRO: formato incorreto" << std::endl;
                continue;
            }
            linha = 0; // Linha não é usada no Lig4
        }

        if (partida->validarJogada(linha, coluna)) {
            partida->realizarJogada(linha, coluna);
            jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X'; // Alterna o jogador
        } else {
            std::cout << "ERRO: jogada inválida" << std::endl;
        }
    }

    delete partida;
    return true;
}


void Sistema::finalizarSistema() {
    std::cout << "Sistema finalizado. Obrigado por jogar!" << std::endl;
    // extra: adicionar codigo para salvar sistema
}

Jogo* Sistema::criarJogo(const std::string& jogo) {
    if (jogo == "R") {
        return new Reversi();
    } else if (jogo == "L") {
        return new Lig4();
    }
    return nullptr;
}


