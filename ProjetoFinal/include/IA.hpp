#ifndef IA_HPP
#define IA_HPP

#include "Jogador.hpp"
#include "Jogo.hpp"

/**
 * @class IA
 * @brief Classe responsável por representar um jogador controlado por inteligência artificial.
 * 
 * A classe IA pode substituir um jogador humano e fazer jogadas baseadas em estratégias definidas.
 */
class IA : public Jogador {
public:
    /**
     * @brief Construtor da classe IA.
     * @param nome O nome da IA.
     * @param apelido O apelido da IA.
     */
    IA(const std::string& nome, const std::string& apelido);

    /**
     * @brief Calcula a próxima jogada com base no estado atual do jogo.
     * @param jogo Ponteiro para o jogo atual.
     * @return Um par de inteiros representando a linha e a coluna da jogada escolhida.
     */
    std::pair<int, int> calcularJogada(Jogo* jogo);
};

#endif
