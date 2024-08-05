#ifndef LIG4_HPP
#define LIG4_HPP

#include "Jogo.hpp"
#include <vector>

class Lig4 : public Jogo {
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
    bool jogadaValida(int coluna);
    bool verificarDirecao(int linha, int coluna, int dLinha, int dColuna);
    void realizarJogadaNaColuna(int coluna);
    bool verificarVitoriaNaDirecao(int linha, int coluna, int dLinha, int dColuna);
};

#endif 
