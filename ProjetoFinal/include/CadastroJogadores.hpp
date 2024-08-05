#ifndef CADASTROJOGADORES_HPP
#define CADASTROJOGADORES_HPP

#include "Jogador.hpp"
#include <vector>
#include <string>

class CadastroJogadores {
public:
    bool cadastrarJogador(const std::string& apelido, const std::string& nome);
    bool removerJogador(const std::string& apelido);
    Jogador* buscarJogador(const std::string& apelido);
    void listarJogadores(char criterio) const;

private:
    std::vector<Jogador> jogadores;
};

#endif 
