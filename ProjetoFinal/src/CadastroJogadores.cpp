#include "CadastroJogadores.hpp"
#include <algorithm>
#include <iostream>

/**
 * @brief Cadastra um novo jogador.
 * 
 * Verifica se o jogador com o apelido fornecido já existe no cadastro. Se não existir, adiciona o jogador.
 * 
 * @param apelido O apelido do jogador a ser cadastrado.
 * @param nome O nome do jogador a ser cadastrado.
 * @return true Se o jogador foi cadastrado com sucesso.
 * @return false Se o jogador já existe no cadastro.
 */
bool CadastroJogadores::cadastrarJogador(const std::string& apelido, const std::string& nome) {
    for (const auto& jogador : jogadores) {
        if (jogador.getApelido() == apelido) {
            return false;
        }
    }
    jogadores.emplace_back(apelido, nome);
    return true;
}

/**
 * @brief Remove um jogador do cadastro.
 * 
 * Procura um jogador com o apelido fornecido e o remove do cadastro.
 * 
 * @param apelido O apelido do jogador a ser removido.
 * @return true Se o jogador foi removido com sucesso.
 * @return false Se o jogador não foi encontrado no cadastro.
 */
bool CadastroJogadores::removerJogador(const std::string& apelido) {
    auto it = std::remove_if(jogadores.begin(), jogadores.end(),
                             [&apelido](const Jogador& jogador) { return jogador.getApelido() == apelido; });
    if (it != jogadores.end()) {
        jogadores.erase(it, jogadores.end());
        return true;
    }
    return false;
}

/**
 * @brief Busca um jogador pelo apelido.
 * 
 * Procura um jogador com o apelido fornecido e retorna um ponteiro para ele.
 * 
 * @param apelido O apelido do jogador a ser buscado.
 * @return Jogador* Ponteiro para o jogador encontrado ou nullptr se não for encontrado.
 */
Jogador* CadastroJogadores::buscarJogador(const std::string& apelido) {
    for (auto& jogador : jogadores) {
        if (jogador.getApelido() == apelido) {
            return &jogador;
        }
    }
    return nullptr;
}

/**
 * @brief Lista todos os jogadores cadastrados.
 * 
 * Ordena os jogadores com base no critério fornecido e imprime as estatísticas de cada jogador.
 * 
 * @param criterio Critério de ordenação ('A' para ordenar por apelido, 'N' para ordenar por nome).
 */
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
