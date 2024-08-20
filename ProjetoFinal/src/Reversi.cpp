#include "Reversi.hpp"
#include <iostream>
#include <cstdlib> 
#include <ctime>

/**
 * @brief Inicia um novo jogo de Reversi.
 *
 * Esta função inicializa o tabuleiro de Reversi com 8 linhas e 8 colunas,
 * preenchendo 4 espaços no meio (com X e O) e o resto com espaços em branco (' '). Ela também define o
 * jogador atual como 'X', dando uma breve descrição de como jogar e exibe o estado inicial do tabuleiro.
 *
 * @note Esta função deve ser chamada no início de cada nova partida.
 */
void Reversi::iniciar() {
    tabuleiro = std::vector<std::vector<char>>(8, std::vector<char>(8, ' '));
    tabuleiro[3][3] = 'O';
    tabuleiro[3][4] = 'X';
    tabuleiro[4][3] = 'X';
    tabuleiro[4][4] = 'O';
    jogadorAtual = 'X';
    std::cout << "\nCOMO JOGAR-> digite 'numero linha' 'numero coluna' da jogada" << std::endl;
    std::cout << "SAIR DO JOGO-> digite 'SAIR'\n";
    imprimirTabuleiro();
}

/**
 * @brief Obtém a altura do tabuleiro do jogo Reversi.
 * 
 * @return A altura do tabuleiro.
 */
int Reversi::getAltura() const {
    return 8; // O tabuleiro de Reversi tem 8 linhas
}

/**
 * @brief Obtém a largura do tabuleiro do jogo Reversi.
 * 
 * @return A largura do tabuleiro.
 */
int Reversi::getLargura() const {
    return 8; // O tabuleiro de Reversi tem 8 colunas
}

/**
 * @brief Imprime o estado atual do tabuleiro.
 * 
 * Este método percorre o tabuleiro e imprime cada célula, formatando o 
 * tabuleiro para que cada linha seja representada por uma linha de caracteres 
 * no console. Cada célula é delimitada por um pipe ('|'). No final, as colunas
 * e linhas do tabuleiro são numeradas de 0 a 7.
 */
void Reversi::imprimirTabuleiro() {
    std::cout << "\nEstado atual do tabuleiro de Reversi:" << std::endl;
    std::cout << "  0 1 2 3 4 5 6 7 " << std::endl;
    int i = 0;
    for (const auto& linha : tabuleiro) {
        std::cout << i;
        i++;
        for (const auto& celula : linha) {
            std::cout << "|" << (celula == ' ' ? ' ' : celula);
        }
        std::cout << "|" << std::endl;
    }
}

/**
 * @brief Valida se a posicao da jogada é possivel.
 * 
 * A funcao jodaValida retorna 'true' e 'false'
 * 
 * @param linha A linha onde a jogada será realizada.
 * @param coluna A coluna onde a jogada será realizada.
 * @return `true` se a jogada for válida, `false` caso contrário.
 */
bool Reversi::validarJogada(int linha, int coluna) {
    return jogadaValida(linha, coluna, jogadorAtual);
}

/**
 * @brief Verifica se o jogo terminou por falta de jogadas válidas.
 * 
 * Este método percorre todo o tabuleiro e verifica se ainda há jogadas válidas disponíveis 
 * para qualquer um dos jogadores ('X' ou 'O'). O jogo é considerado terminado se não houver 
 * jogadas válidas restantes para nenhum dos jogadores.
 * 
 * O método funciona da seguinte forma:
 * - Para cada posição do tabuleiro 8x8, verifica se a posição permite uma jogada válida para 'X' ou 'O'.
 * - Se for encontrada pelo menos uma jogada válida, o método retorna `false`, indicando que o jogo pode continuar.
 * - Se nenhuma jogada válida for encontrada em todo o tabuleiro, o método retorna `true`, indicando que o jogo terminou.
 * 
 * @return `true` se o jogo terminou (nenhuma jogada válida restante para qualquer jogador), 
 *         `false` caso contrário.
 */
bool Reversi::verificarVitoria() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (jogadaValida(i, j, 'X') || jogadaValida(i, j, 'O')) {
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief Realiza a jogada do jogador atual na posição especificada.
 * 
 * Este método verifica se a jogada na posição especificada (linha e coluna) é válida para o jogador atual. 
 * Se a jogada for válida, o método atualiza o tabuleiro, vira as peças do oponente que foram capturadas, 
 * alterna para o próximo jogador e imprime o estado atualizado do tabuleiro.
 * 
 * O método funciona da seguinte maneira:
 * - Verifica se a jogada é válida chamando o método 'jogadaValida' para a posição especificada.
 * - Se a jogada for válida:
 *   - A peça do jogador atual é colocada na posição indicada no tabuleiro.
 *   - O método 'virarPecas' é chamado para capturar as peças do oponente.
 *   - O jogador atual é alternado utilizando o método 'alternarJogador'.
 *   - O tabuleiro atualizado é impresso chamando o método 'imprimirTabuleiro'.
 * - Se a jogada não for válida, uma mensagem de erro é exibida no console.
 * 
 * @param linha A linha onde a jogada será realizada.
 * @param coluna A coluna onde a jogada será realizada.
 */
void Reversi::realizarJogada(int linha, int coluna) {
    if (jogadaValida(linha, coluna, jogadorAtual)) {
        tabuleiro[linha][coluna] = jogadorAtual;
        virarPecas(linha, coluna, jogadorAtual);
        alternarJogador();
        imprimirTabuleiro();
    } else {
        std::cout << "ERRO: jogada inválida\n" << std::endl;
    }
}

/**
 * @brief Realiza uma jogada automática pela IA.
 * 
 * A IA escolhe uma jogada com base na configuração atual do tabuleiro e realiza a jogada.
 */

void Reversi::realizarJogadaIA() {
    std::vector<std::pair<int, int>> jogadasValidas;

    for (int linha = 0; linha < getAltura(); ++linha) {
        for (int coluna = 0; coluna < getLargura(); ++coluna) {
            if (validarJogada(linha, coluna)) {
                jogadasValidas.emplace_back(linha, coluna);
            }
        }
    }

    if (!jogadasValidas.empty()) {
        std::srand(static_cast<unsigned>(std::time(0))); 
        int index = std::rand() % jogadasValidas.size();
        auto jogada = jogadasValidas[index];
        realizarJogada(jogada.first, jogada.second);
    }
}

/**
 * @brief Alterna o jogador que vai jogar.
 * 
 * Este método troca o jogador atual. Se o jogador atual for 'X', ele será alterado para 'O'. 
 * Se o jogador atual for 'O', ele será alterado para 'X'.
 */
void Reversi::alternarJogador() {
    jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
}

/**
 *@brief Valida a jogada na linha e coluna especificada.
 * 
 * Este método verifica se a jogada na posição especificada (linha e coluna) é válida de acordo 
 * com as regras do jogo Reversi. A jogada é considerada válida se:
 * - A posição está dentro dos limites do tabuleiro (0 a 8 para linha e coluna).
 * - A posição especificada está vazia.
 * - Existe pelo menos uma direção (horizontal, vertical ou diagonal) em que a jogada capturaria 
 *   as peças do oponente.
 * 
 * O método funciona da seguinte forma:
 * - Percorre todas as direções possíveis ao redor da posição (8 direções no total) e verifica, 
 *   usando o método `verificarDirecao`, se há peças do oponente que podem ser capturadas em 
 *   qualquer uma dessas direções.
 * 
 * @param linha A linha onde a jogada será realizada.
 * @param coluna A coluna onde a jogada será realizada.
 * @param jogador O jogador que está tentando realizar a jogada ('X' ou 'O').
 * @return `true` se a jogada for válida, `false` caso contrário.
 */
bool Reversi::jogadaValida(int linha, int coluna, char jogador) {
    if( linha < 0 || linha > 8 || coluna < 0 || coluna > 8){
        return false;
    }else if (tabuleiro[linha][coluna] != ' ') {
        return false;
    }
    for (int dLinha = -1; dLinha <= 1; ++dLinha) {
        for (int dColuna = -1; dColuna <= 1; ++dColuna) {
            if (dLinha != 0 || dColuna != 0) {
                if (verificarDirecao(linha, coluna, dLinha, dColuna, jogador)) {
                    return true;
                }
            }
        }
    }
    return false;
}

/**
 * @brief Verifica se há peças para virar em uma direção específica.
 * 
 * Este método verifica, a partir de uma posição no tabuleiro, se há uma sequência de peças do oponente
 * que pode ser capturada. A verificação é feita em uma direção específica, definida pelos incrementos 
 * 'dLinha' e 'dColuna'.
 * 
 * O método funciona da seguinte forma:
 * - Define o símbolo do oponente com base no jogador atual.
 * - Avança na direção especificada (dLinha, dColuna), procurando por peças do oponente.
 * - Se encontrar uma peça do oponente, continua avançando.
 * - Se encontrar uma peça do jogador atual após uma ou mais peças do oponente, retorna 'true', 
 *   indicando que as peças do oponente podem ser capturadas.
 * 
 * @param linha A linha de início para a verificação.
 * @param coluna A coluna de início para a verificação.
 * @param dLinha O incremento na linha para determinar a direção da verificação.
 * @param dColuna O incremento na coluna para determinar a direção da verificação.
 * @param jogador O jogador que está tentando realizar a jogada ('X' ou 'O').
 * @return 'true' se há peças do oponente para capturar nessa direção, 'false' caso contrário.
 */
bool Reversi::verificarDirecao(int linha, int coluna, int dLinha, int dColuna, char jogador) {
    char oponente = (jogador == 'X') ? 'O' : 'X';
    int i = linha + dLinha;
    int j = coluna + dColuna;
    bool encontrouOponente = false;

    while (i >= 0 && i < 8 && j >= 0 && j < 8) {
        if (tabuleiro[i][j] == oponente) {
            encontrouOponente = true;
        } else if (tabuleiro[i][j] == jogador) {
            return encontrouOponente;
        } else {
            break;
        }
        i += dLinha;
        j += dColuna;
    }
    return false;
}

/**
 * @brief Vira as peças do tabuleiro de acordo com a jogada.
 * 
 * Este método percorre todas as direções ao redor da posição onde a jogada foi realizada e, 
 * para cada direção, verifica se há peças do oponente que podem ser capturadas. Se uma direção 
 * contiver peças capturáveis, essas peças são viradas para o lado do jogador atual.
 * 
 * O método funciona da seguinte forma:
 * - Para cada direção, verifica se há peças do oponente que podem ser capturadas, utilizando 
 *   o método `verificarDirecao`.
 * - Se a verificação indicar que há peças para capturar, o método `virarDirecao` é chamado 
 *   para virar as peças do oponente na direção especificada.
 * 
 * @param linha A linha onde a jogada foi realizada.
 * @param coluna A coluna onde a jogada foi realizada.
 * @param jogador O jogador que realizou a jogada ('X' ou 'O').
 */
void Reversi::virarPecas(int linha, int coluna, char jogador) {
    for (int dLinha = -1; dLinha <= 1; ++dLinha) {
        for (int dColuna = -1; dColuna <= 1; ++dColuna) {
            if (dLinha != 0 || dColuna != 0) {
                if (verificarDirecao(linha, coluna, dLinha, dColuna, jogador)) {
                    virarDirecao(linha, coluna, dLinha, dColuna, jogador);
                }
            }
        }
    }
}

/**
 * @brief Vira as peças em uma direção específica.
 * 
 * Este método percorre o tabuleiro na direção especificada a partir de uma posição onde uma 
 * jogada foi realizada. Ele altera as peças do oponente para as peças do jogador atual, 
 * capturando-as.
 * 
 * O método funciona da seguinte forma:
 * - Define o símbolo do oponente com base no jogador atual.
 * - A partir da posição dada (linha, coluna), avança na direção especificada por 'dLinha' e 'dColuna'.
 * - Enquanto as peças na direção forem do oponente, elas são viradas (substituídas pelo símbolo do jogador atual).
 * - O loop termina ao encontrar uma peça do jogador atual ou ao sair dos limites do tabuleiro.
 * 
 * @param linha A linha de início para virar as peças.
 * @param coluna A coluna de início para virar as peças.
 * @param dLinha O incremento na linha que determina a direção da virada.
 * @param dColuna O incremento na coluna que determina a direção da virada.
 * @param jogador O jogador que realizou a jogada ('X' ou 'O').
 */
void Reversi::virarDirecao(int linha, int coluna, int dLinha, int dColuna, char jogador) {
    char oponente = (jogador == 'X') ? 'O' : 'X';
    int i = linha + dLinha;
    int j = coluna + dColuna;

    while (i >= 0 && i < 8 && j >= 0 && j < 8 && tabuleiro[i][j] == oponente) {
        tabuleiro[i][j] = jogador;
        i += dLinha;
        j += dColuna;
    }
}

bool Reversi::empatePartida(){
    return false;
}