#include "Jogador.hpp"
#include <iostream>

Jogador::Jogador(const std::string& apelido, const std::string& nome)
    : apelido(apelido), nome(nome), vitoriasReversi(0), derrotasReversi(0), vitoriasLig4(0), derrotasLig4(0) {}

std::string Jogador::getApelido() const {
    return apelido;
}

std::string Jogador::getNome() const {
    return nome;
}

void Jogador::adicionarVitoria(const std::string& jogo) {
    if (jogo == "R") {
        vitoriasReversi++;
    } else if (jogo == "L") {
        vitoriasLig4++;
    }
}

void Jogador::adicionarDerrota(const std::string& jogo) {
    if (jogo == "R") {
        derrotasReversi++;
    } else if (jogo == "L") {
        derrotasLig4++;
    }
}

void Jogador::imprimirEstatisticas() const {
    std::cout << apelido << " " << nome << std::endl;
    std::cout << "REVERSI - V: " << vitoriasReversi << " D: " << derrotasReversi << std::endl;
    std::cout << "LIG4 - V: " << vitoriasLig4 << " D: " << derrotasLig4 << std::endl;
}
