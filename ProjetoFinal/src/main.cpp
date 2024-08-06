#include <iostream>
#include <string>
#include <sstream>
#include "Sistema.hpp"

int main() {
    Sistema sistema;
    std::string linha;

    while (true) {
        std::cout << "Digite um comando: ";
        std::getline(std::cin, linha);
        std::istringstream iss(linha);
        std::string comando;
        iss >> comando;

        if (comando == "FS") {
            sistema.finalizarSistema();
            break;
        } else if (comando == "CJ") {
            std::string apelido, nome;
            iss >> apelido >> nome;
            if (apelido.empty() || nome.empty()) {
                std::cout << "ERRO: dados incorretos" << std::endl;
            } else if (sistema.cadastrarJogador(apelido, nome)) {
                std::cout << "Jogador " << apelido << " cadastrado com sucesso" << std::endl;
            } else {
                std::cout << "ERRO: jogador repetido" << std::endl;
            }
        } else if (comando == "RJ") {
            std::string apelido;
            iss >> apelido;
            if (apelido.empty()) {
                std::cout << "ERRO: dados incorretos" << std::endl;
            } else if (sistema.removerJogador(apelido)) {
                std::cout << "Jogador " << apelido << " removido com sucesso" << std::endl;
            } else {
                std::cout << "ERRO: jogador inexistente" << std::endl;
            }
        } else if (comando == "LJ") {
            char criterio;
            iss >> criterio;
            if (criterio != 'A' && criterio != 'N') {
                std::cout << "ERRO: dados incorretos" << std::endl;
            } else {
                sistema.listarJogadores(criterio);
            }
        } else if (comando == "EP") {
            std::string jogo, apelido1, apelido2;
            iss >> jogo >> apelido1 >> apelido2;
            if (jogo.empty() || apelido1.empty() || apelido2.empty() || (jogo != "R" && jogo != "L")) {
                std::cout << "ERRO: dados incorretos" << std::endl;
            } else if (!sistema.executarPartida(jogo, apelido1, apelido2)) {
                std::cout << "ERRO: jogador inexistente" << std::endl;
            }
        } else {
            std::cout << "Comando não reconhecido. Tente novamente." << std::endl;
        }
    }

    return 0;
}
