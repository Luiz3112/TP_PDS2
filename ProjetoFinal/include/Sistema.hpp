#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include "CadastroJogadores.hpp"
#include "Jogo.hpp"
#include <string>

class Sistema {
public:
    void executar();
    bool cadastrarJogador(const std::string& apelido, const std::string& nome);
    bool removerJogador(const std::string& apelido);
    void listarJogadores(char criterio);
    bool executarPartida(const std::string& jogo, const std::string& apelido1, const std::string& apelido2);
    void finalizarSistema();

private:
    CadastroJogadores cadastro;
    Jogo* criarJogo(const std::string& jogo);
};

#endif 
