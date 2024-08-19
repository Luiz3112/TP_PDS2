#ifndef LIG4_HPP
#define LIG4_HPP

#include "Jogo.hpp"
#include <vector>

/**
 * @class Lig4
 * @brief Classe responsável pelo gerenciamento do jogo Lig4, derivada da classe Jogo.
 * 
 * A classe Lig4 gerencia o estado e as regras do jogo Lig4. Ela herda todos os métodos
 * da classe Jogo e implementa funcionalidades específicas para o jogo Lig4, como a 
 * alternância de jogadores, validação de jogadas, realização de jogadas e verificação 
 * de vitória.
 */
class Lig4 : public Jogo {
public:

/**
 * @brief Inicia um novo jogo de Lig4.
 */
    void iniciar() override;

/**
 * @brief Imprime o estado atual do tabuleiro.
 */
    void imprimirTabuleiro() override;

/**
 * @brief Valida se a posicao da jogada é possivel.
 * 
 * @param linha A linha onde a jogada será realizada.
 * @param coluna A coluna onde a jogada será realizada.
 * @return `true` se a jogada for válida, `false` caso contrário.
 */
    bool validarJogada(int linha, int coluna) override;

/**
 * @brief Verica se houve vitória.
 * 
 * @return 'true' se houve vitória,'false' caso contrário.
 */
    bool verificarVitoria() override;

/**
 * @brief Realiza a jogada no tabuleiro.
 * 
 * @param linha A linha onde a jogada será realizada.
 * @param coluna A coluna onde a jogada será realizada.
 */
    void realizarJogada(int linha, int coluna) override;

    /**
 * @brief Alterna o jogador que vai jogar.
 */
    void alternarJogador();

    /**
 * @brief Realiza uma jogada na coluna especificada.
 * 
 * @param coluna A coluna onde a jogada será realizada.
 */
    void realizarJogadaNaColuna(int coluna);

private:

/**
 * @brief Representação do tabuleiro do jogo lig4, com 6 linhas e 7 colunas.
 */
    std::vector<std::vector<char>> tabuleiro;

/**
 * @brief Armazena o jogador atual.
 * 
 * O jogador atual pode ser ou X ou O.
 */
    char jogadorAtual;

/**
 * @brief Valida a jogada na coluna especificada.
 * 
 * @param coluna A coluna onde a jogada será realizada.
 * @return `true` se a jogada for válida, `false` caso contrário. 
 */
    bool jogadaValida(int coluna);

/**
 * @brief Verifica as direções.
 */
    bool verificarDirecao(int linha, int coluna, int dLinha, int dColuna);

/**
 * @brief Verifica se há uma vitória em uma direção específica.
 *
 * Verifica se a jogada mais recente completou quatro peças consecutivas 
 * na direção especificada.
 *
 * @param linha A linha inicial para verificação.
 * @param coluna A coluna inicial para verificação.
 * @param dLinha A mudança de linha por verificação.
 * @param dColuna A mudança de coluna por verificação.
 * @return `true` se houver vitória nessa direção, `false` caso contrário.
 */
    bool verificarVitoriaNaDirecao(int linha, int coluna, int dLinha, int dColuna);
};

#endif 
