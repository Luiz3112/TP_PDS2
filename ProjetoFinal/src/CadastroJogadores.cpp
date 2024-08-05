#include "CadastroJogadores.hpp"
#include <algorithm>
#include <iostream>

bool CadastroJogadores::cadastrarJogador(const std::string& apelido, const std::string& nome) {
    for (const auto& jogador : jogadores) {
        if (jogador.getApelido() == apelido) {
            return false;
        }
    }
    jogadores.emplace_back(apelido, nome);
    return true;
}

bool CadastroJogadores::removerJogador(const std::string& apelido) {
    auto it = std::remove_if(jogadores.begin(), jogadores.end(),
                             [&apelido](const Jogador& jogador) { return jogador.getApelido() == apelido; });
    if (it != jogadores.end()) {
        jogadores.erase(it, jogadores.end());
        return true;
    }
    return false;
}

Jogador* CadastroJogadores::buscarJogador(const std::string& apelido) {
    for (auto& jogador : jogadores) {
        if (jogador.getApelido() == apelido) {
            return &jogador;
        }
    }
    return nullptr;
}

void CadastroJogadores::listarJogadores(char criterio) const {
    std::vector<Jogador> copiaJogadores = jogadores;
    if (criterio == 'A') {
        std::sort(copiaJogadores.begin(), copiaJogadores.end(),
                  [](const Jogador& a, const Jogador& b) { return a.getApelido() < b.getApelido(); });
    } else if (criterio == 'N') {
        std::sort(copiaJogadores.begin(), copiaJogadores.end(),
                  [](const Jogador& a, const Jogador& b) { return a.getNome() < b.getNome(); });
    }

    for (const auto& jogador : copiaJogadores) {
        jogador.imprimirEstatisticas();
    }
}
