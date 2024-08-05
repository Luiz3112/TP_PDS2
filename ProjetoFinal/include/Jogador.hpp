#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>

class Jogador {
public:
    Jogador(const std::string& apelido, const std::string& nome);

    std::string getApelido() const;
    std::string getNome() const;
    void adicionarVitoria(const std::string& jogo);
    void adicionarDerrota(const std::string& jogo);
    void imprimirEstatisticas() const;

private:
    std::string apelido;
    std::string nome;
    int vitoriasReversi;
    int derrotasReversi;
    int vitoriasLig4;
    int derrotasLig4;
};

#endif 
