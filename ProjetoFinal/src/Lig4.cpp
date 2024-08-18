#include "Lig4.hpp"
#include <iostream>

/**
 * @brief Inicia um novo jogo de Lig4.
 *
 * Esta função inicializa o tabuleiro de Lig4 com 6 linhas e 7 colunas,
 * todas preenchidas com espaços em branco (' '). Ela também define o
 * jogador atual como 'X' e exibe o estado inicial do tabuleiro.
 *
 * @note Esta função deve ser chamada no início de cada nova partida.
 */
void Lig4::iniciar() {
    tabuleiro = std::vector<std::vector<char>>(6, std::vector<char>(7, ' '));
    jogadorAtual = 'X';
    std::cout << "\nCOMO JOGAR-> digite 'numero coluna' da jogada" << std::endl;
    std::cout << "SAIR DO JOGO-> digite 'SAIR'\n";
    imprimirTabuleiro();
}

/**
 * @brief Imprime o estado atual do tabuleiro.
 * 
 * Este método percorre o tabuleiro e imprime cada célula, formatando o 
 * tabuleiro para que cada linha seja representada por uma linha de caracteres 
 * no console. Cada célula é delimitada por um pipe ('|'). No final, as colunas 
 * do tabuleiro são numeradas de 0 a 6.
 */
void Lig4::imprimirTabuleiro() {

    std::cout << "\nEstado atual do tabuleiro de Lig4:" << std::endl;
    for (const auto& linha : tabuleiro) {
        for (const auto& celula : linha) {
            std::cout << "|" << celula;
        }
        std::cout << "|" << std::endl;
    }
    std::cout << " 0 1 2 3 4 5 6 " << std::endl;  //locazar a coluna
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
bool Lig4::validarJogada(int linha, int coluna) {
    return jogadaValida(coluna);
}


/**
 * @brief Verifica se houve vitória no jogo.
 * 
 * Este método percorre todo o tabuleiro de Lig4. Para cada célula que não está vazia,
 * ele verifica se há uma sequência de quatro peças consecutivas em qualquer uma das
 * direções possíveis (horizontal, vertical, diagonal para cima, ou diagonal para baixo).
 * Se for encontrada uma sequência vencedora, a função retorna 'true'.
 * 
 * @return `true` se houve vitória, `false` caso contrário.
 */
bool Lig4::verificarVitoria() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (tabuleiro[i][j] != ' ' && (
                verificarVitoriaNaDirecao(i, j, 1, 0) || 
                verificarVitoriaNaDirecao(i, j, 0, 1) || 
                verificarVitoriaNaDirecao(i, j, 1, 1) || 
                verificarVitoriaNaDirecao(i, j, 1, -1)   
            )) {
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief Realiza a jogada no tabuleiro.
 * 
 * Este método verifica se a jogada na coluna especificada é válida. Se for válida, 
 * a jogada é realizada naquela coluna, o jogador atual é alternado, e o estado 
 * atualizado do tabuleiro é impresso. Caso a jogada seja inválida, uma mensagem 
 * de erro é exibida.
 * 
 * @param linha A linha onde a jogada seria realizada (não utilizada diretamente, 
 * pois a jogada ocorre na coluna mais baixa disponível).
 * @param coluna A coluna onde a jogada será realizada.
 */
void Lig4::realizarJogada(int linha, int coluna) {
    if (jogadaValida(coluna)) {
        realizarJogadaNaColuna(coluna);
        alternarJogador();
        imprimirTabuleiro();
    } else {
        std::cout << "ERRO: jogada inválida\n" << std::endl;
    }
}

/**
 * @brief Alterna o jogador atual.
 * 
 * Este método troca o jogador atual, alternando entre 'X' e 'O'. Se o jogador atual
 * for 'X', ele será alterado para 'O'. Caso contrário, será alterado para 'X'.
 */
void Lig4::alternarJogador() {
    jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
}

/**
 * @brief Valida a jogada na coluna especificada.
 * 
 * Este método verifica se há espaço disponível na coluna especificada para 
 * alocar mais uma peça. A validação é feita verificando se a célula no topo 
 * da coluna (linha 0) está vazia.
 * 
 * @param coluna A coluna onde a jogada será realizada.
 * @return `true` se a jogada for válida, `false` caso contrário. 
 */
bool Lig4::jogadaValida(int coluna) {
    return tabuleiro[0][coluna] == ' ';
}

/**
 * @brief Realiza uma jogada na coluna especificada.
 * 
 *  Este método insere a peça do jogador atual na primeira posição disponível (de baixo 
 * para cima) na coluna especificada. A jogada é realizada preenchendo a primeira célula 
 * vazia encontrada na coluna.
 * 
 * @param coluna A coluna onde a jogada será realizada.
 */
void Lig4::realizarJogadaNaColuna(int coluna) {
    for (int i = 5; i >= 0; --i) {
        if (tabuleiro[i][coluna] == ' ') {
            tabuleiro[i][coluna] = jogadorAtual;
            break;
        }
    }
}

/**
 * @brief Verifica se há uma vitória em uma direção específica.
 * 
 * Este método verifica se há uma sequência de quatro peças consecutivas do jogador
 * atual em uma direção específica, começando na posição dada pela linha e coluna.
 * A direção da verificação é determinada pelos incrementos fornecidos para linha 
 * (`dLinha`) e coluna (`dColuna`).
 *
 * @param linha A linha inicial para verificação.
 * @param coluna A coluna inicial para verificação.
 * @param dLinha A mudança de linha por verificação.
 * @param dColuna A mudança de coluna por verificação.
 * @return `true` se houver vitória nessa direção, `false` caso contrário.
 */
bool Lig4::verificarVitoriaNaDirecao(int linha, int coluna, int dLinha, int dColuna) {
    char jogador = tabuleiro[linha][coluna];
    int contagem = 0;

    for (int i = 0; i < 4; ++i) {
        int novaLinha = linha + i * dLinha;
        int novaColuna = coluna + i * dColuna;

        if (novaLinha >= 0 && novaLinha < 6 && novaColuna >= 0 && novaColuna < 7 && tabuleiro[novaLinha][novaColuna] == jogador) {
            contagem++;
        } else {
            break;
        }
    }

    return contagem == 4;
}
