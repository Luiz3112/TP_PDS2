#ifndef JOGO_HPP
#define JOGO_HPP

class Jogo {
public:
    virtual ~Jogo() = default;
    virtual int getAltura() const = 0;
    virtual int getLargura() const = 0;
    virtual void iniciar() = 0;
    virtual void imprimirTabuleiro() = 0;
    virtual bool validarJogada(int linha, int coluna) = 0;
    virtual bool verificarVitoria() = 0;
    virtual void realizarJogada(int linha, int coluna) = 0;
    virtual void realizarJogadaIA() = 0;
};

#endif 
