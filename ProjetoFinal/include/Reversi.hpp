#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "Jogo.hpp"
#include <vector>

class Reversi : public Jogo {
public:
    void iniciar() override;
    void imprimirTabuleiro() override;
    bool validarJogada(int linha, int coluna) override;
    bool verificarVitoria() override;
    void realizarJogada(int linha, int coluna) override;

private:
    std::vector<std::vector<char>> tabuleiro;
    char jogadorAtual;

    void alternarJogador();
    bool jogadaValida(int linha, int coluna, char jogador);
    void virarPecas(int linha, int coluna, char jogador);
    bool verificarDirecao(int linha, int coluna, int dLinha, int dColuna, char jogador);
    void virarDirecao(int linha, int coluna, int dLinha, int dColuna, char jogador);
};

#endif 


