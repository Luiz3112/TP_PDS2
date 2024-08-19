#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>

/** 
 * @class Jogador
 * @brief Armazenar informações do jogador.
 * 
 * A classe Jogador armazena o Apelido, Nome, numero de Vitorias e Derrotas do jogador em cada jogo.
*/
class Jogador {
public:
/**
 * @brief Cria um jogador.
 * 
 * @param apelido O apelido atribuido ao jogador criado.
 * @param nome O nome atribuido ao jogador criado.
 */
    Jogador(const std::string& apelido, const std::string& nome);

/**
 * @brief Obtém o apelido do jogador.
 * 
 * @return Retorna o apelido do jogador.
 */
    std::string getApelido() const;

/**
 * @brief Obtém o nome do jogador.
 * 
 * @return Retorna o nome do jogador.
 */
    std::string getNome() const;

/**
 * @brief Adiciona uma vitoria ao jogo jogado.
 * 
 * @param jogo Define qual jogo foi jogado.
 */
    void adicionarVitoria(const std::string& jogo);

/**
 * @brief Adiciona uma derrota ao jogo jogado.
 * 
 * @param jogo Define qual jogo foi jogado.
 */
    void adicionarDerrota(const std::string& jogo);

/**
 * @brief Imprime todas as estatisticas de vitoria e derrota.
 */
    void imprimirEstatisticas() const;

private:

/**
 * @brief Apelido do jogador.
 */
    std::string apelido;

/**
 * @brief Nome do jogador.
 */
    std::string nome;

/**
 * @brief Armazena numero de vitorias no jogo Reversi.
 */
    int vitoriasReversi;

/**
 * @brief Armazena numero de derrotas no jogo Reversi.
 */
    int derrotasReversi;

/**
 * @brief Armazena numero de vitorias no jogo Lig4.
 */
    int vitoriasLig4;

/**
 * @brief Armazena numero de derrotas no jogo Lig4.
 */
    int derrotasLig4;
};

#endif 
