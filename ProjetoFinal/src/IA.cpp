#include "IA.hpp"

/**
 * @brief Construtor da classe IA.
 * @param nome O nome da IA.
 * @param apelido O apelido da IA.
 */
IA::IA(const std::string& nome, const std::string& apelido)
    : Jogador(nome, apelido) {}

/**
 * @brief Calcula a próxima jogada com base no estado atual do jogo.
 * @param jogo Ponteiro para o jogo atual.
 * @return Um par de inteiros representando a linha e a coluna da jogada escolhida.
 */
std::pair<int, int> IA::calcularJogada(Jogo* jogo) {
    // Implementação de exemplo: seleciona a primeira jogada válida encontrada.
    for (int i = 0; i < jogo->getAltura(); ++i) {
        for (int j = 0; j < jogo->getLargura(); ++j) {
            if (jogo->validarJogada(i, j)) {
                return {i, j};
            }
        }
    }
    return {-1, -1}; // Nenhuma jogada válida encontrada
}
