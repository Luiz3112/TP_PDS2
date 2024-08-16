#include "Jogador.hpp"
#include <iostream>

/**
 * @brief Cria um jogador
 * 
 * Cria um jogador e inicia parametros de vitória e derrota com valor zero
 * 
 * @param apelido O apelido atribuido ao jogador criado
 * @param nome O nome atribuido ao jogador criado
 */
Jogador::Jogador(const std::string& apelido, const std::string& nome)
    : apelido(apelido), nome(nome), vitoriasReversi(0), derrotasReversi(0), vitoriasLig4(0), derrotasLig4(0) {}

/**
 * @brief Obtém o apelido do jogador
 * 
 * @return Retorna o apelido do jogador
 */
std::string Jogador::getApelido() const {
    return apelido;
}

/**
 * @brief Obtém o nome do jogador
 * 
 * @return Retorna o nome do jogador
 */
std::string Jogador::getNome() const {
    return nome;
}

/**
 * @brief Adiciona uma vitoria ao jogo jogado
 * 
 * Analisa o valor do parametro "jogo" para adicionar a vitoria ao tipo de jogo jogado
 * 
 * @param jogo Defini qual jogo foi jogado
 */
void Jogador::adicionarVitoria(const std::string& jogo) {
    if (jogo == "R") {
        vitoriasReversi++;
    } else if (jogo == "L") {
        vitoriasLig4++;
    }
}

/**
 * @brief Adiciona uma derrota ao jogo jogado
 * 
 * Analisa o valor do parametro "jogo" para adicionar a derrota ao tipo de jogo jogado
 * 
 * @param jogo Defini qual jogo foi jogado
 */
void Jogador::adicionarDerrota(const std::string& jogo) {
    if (jogo == "R") {
        derrotasReversi++;
    } else if (jogo == "L") {
        derrotasLig4++;
    }
}

/**
 * @brief Imprime todas as estatisticas de vitoria e derrota
 * 
 * Serpara as estatísticas de vitoria e derrota de acordo com o tipo de jogo
 */
void Jogador::imprimirEstatisticas() const {
    std::cout << apelido << " " << nome << std::endl;
    std::cout << "REVERSI - V: " << vitoriasReversi << " D: " << derrotasReversi << std::endl;
    std::cout << "LIG4 - V: " << vitoriasLig4 << " D: " << derrotasLig4 << std::endl;
}
