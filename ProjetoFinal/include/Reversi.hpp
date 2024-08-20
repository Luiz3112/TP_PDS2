#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "Jogo.hpp"
#include <vector>

/**
 * @class Reversi
 * @brief Classe responsável pelo gerenciamento do jogo Reverse, derivada da classe Jogo.
 * 
 * A classe Reversi gerencia o estado e as regras do jogo Reversi. Ela herda todos os métodos
 * da classe Jogo e implementa funcionalidades específicas para o jogo Reversi, como a 
 * alternância de jogadores, validação de jogadas, realização de jogadas e verificação 
 * de vitória.
 */
class Reversi : public Jogo {
public:

/**
 * @brief Inicia um novo jogo de Reversi.
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
 * @brief Verifica se o jogo terminou por falta de jogadas válidas.
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
* @brief Realiza a jogada da IA.
* 
* Este método é responsável por decidir e realizar uma jogada automática pela IA.
*/
   void realizarJogadaIA() override;

/**
* @brief Obtém a altura do tabuleiro do jogo Reversi.
* 
* @return A altura do tabuleiro.
*/
   int getAltura() const override;

/**
* @brief Obtém a largura do tabuleiro do jogo Reversi.
* 
* @return A largura do tabuleiro.
*/
   int getLargura() const override;

    
   
   bool empatePartida() override;


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

private:


/**
 * @brief Alterna o jogador que vai jogar.
 */
    void alternarJogador();

/**
 * @brief Valida a jogada na linha e coluna especificada.
 * 
 * @param linha A linha onde a jogada será realizada.
 * @param coluna A coluna onde a jogada será realizada.
 * @param jogador O jogador que está tentando realizar a jogada ('X' ou 'O').
 * @return 'true' se a jogada for válida, 'false' caso contrário. 
 */
    bool jogadaValida(int linha, int coluna, char jogador);

/**
 * @brief Vira as peças do tabuleiro de acordo com a jogada.
 * 
 * @param linha A linha onde a jogada foi realizada.
 * @param coluna A coluna onde a jogada foi realizada.
 * @param jogador O jogador que está realizando a jogada ('X' ou 'O').
 */
    void virarPecas(int linha, int coluna, char jogador);

/**
 * @brief Verifica se há peças para virar em uma direção específica.
 * 
 * Este método verifica, a partir de uma posição no tabuleiro, se há uma sequência de peças do oponente
 * que pode ser capturada. A verificação é feita em uma direção específica, definida pelos incrementos 
 * 'dLinha' e 'dColuna'.
 * 
 * @param linha A linha de início.
 * @param coluna A coluna de início.
 * @param dLinha A direção do movimento na linha.
 * @param dColuna A direção do movimento na coluna.
 * @param jogador O jogador que está realizando a jogada ('X' ou 'O').
 * @return `true` se há peças para virar, `false` caso contrário.
 */
    bool verificarDirecao(int linha, int coluna, int dLinha, int dColuna, char jogador);
    
/**
 * @brief Vira as peças em uma direção específica.
 * 
 * @param linha A linha de início.
 * @param coluna A coluna de início.
 * @param dLinha A direção do movimento na linha.
 * @param dColuna A direção do movimento na coluna.
 * @param jogador O jogador que está realizando a jogada ('X' ou 'O').
 */
    void virarDirecao(int linha, int coluna, int dLinha, int dColuna, char jogador);
};

#endif 


