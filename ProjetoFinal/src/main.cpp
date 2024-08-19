/**
 * @file main.cpp
 * @brief Ponto de entrada para o sistema de gerenciamento de jogos.
 * 
 * Este arquivo contém o ponto de entrada principal para o sistema. Ele permite que o usuário
 * interaja com o sistema por meio de comandos para cadastrar jogadores, remover jogadores,
 * listar jogadores, e iniciar jogos de Reversi ou Lig4. O programa continua executando até 
 * que o comando "FS" seja digitado, momento em que o sistema é finalizado.
 */
#include <iostream>
#include <string>
#include <sstream>
#include "Sistema.hpp"

/**
 * @brief Função principal do programa.
 * 
 * Esta função é o ponto de entrada do programa e fornece uma interface de linha de comando 
 * para o usuário interagir com o sistema. Os comandos aceitos são:
 * - CJ 'apelido' 'nome' : Cadastra um novo jogador.
 * - RJ 'apelido' : Remove um jogador existente.
 * - LJ 'criterio' : Lista os jogadores cadastrados com base no critério ('N' para nome, 'A' para apelido).
 * - EP 'jogo' 'apelido1' 'apelido2' : Inicia um jogo entre dois jogadores (R para Reversi, L para Lig4).
 * - EP 'jogo' 'apelido1' 'IA' : Inicia um jogo entre um jogador e a IA.
 * - FS : Finaliza o sistema.
 * 
 * O programa continua em execução até que o comando "FS" seja inserido.
 * 
 * @return Retorna 0 após o sistema ser finalizado.
 */
int main() {
    Sistema sistema;
    std::string linha;

    std::cout << "\n(CJ 'apelido' 'nome') CADASTRO JOGADOR\n" 
              << "(RJ 'apelido') REMOCAO JOGADOR\n"
              << "(LJ 'criterio') LISTAR ESTATISTICAS {N-> ordem por nome; A-> ordem por apelido}\n"
              << "(EP 'jogo' 'apelido1' 'apelido2') INICIAR JOGO {L-> Lig4; R-> Reversi}\n"
              << "(EP 'jogo' 'apelido1' 'IA') INICIAR JOGO CONTRA IA {L-> Lig4; R-> Reversi}\n"
              << "(FS) FINALIZA O SISTEMA\n" << std::endl;

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
                std::cout << "ERRO: dados incorretos\n" << std::endl;
            } else if (sistema.cadastrarJogador(apelido, nome)) {
                std::cout << "Jogador " << apelido << " cadastrado com sucesso\n" << std::endl;
            } else {
                std::cout << "ERRO: jogador repetido\n" << std::endl;
            }
        } else if (comando == "RJ") {
            std::string apelido;
            iss >> apelido;
            if (apelido.empty()) {
                std::cout << "ERRO: dados incorretos\n" << std::endl;
            } else if (sistema.removerJogador(apelido)) {
                std::cout << "Jogador " << apelido << " removido com sucesso\n" << std::endl;
            } else {
                std::cout << "ERRO: jogador inexistente\n" << std::endl;
            }
        } else if (comando == "LJ") {
            char criterio;
            iss >> criterio;
            if (criterio != 'A' && criterio != 'N') {
                std::cout << "ERRO: dados incorretos\n" << std::endl;
            } else {
                sistema.listarJogadores(criterio);
            }
        } else if (comando == "EP") {
            std::string jogo, apelido1, apelido2;
            iss >> jogo >> apelido1 >> apelido2;

            if (jogo.empty() || apelido1.empty() || (jogo != "R" && jogo != "L")) {
                std::cout << "ERRO: dados incorretos\n" << std::endl;
            } else if (apelido2 == "IA") {
                // Jogar contra IA
                if (!sistema.executarPartida(jogo, apelido1, "IA")) {
                    std::cout << "ERRO: jogador inexistente ou jogo inválido\n" << std::endl;
                }
            } else {
                // Jogar contra outro jogador
                if (apelido2.empty() || apelido1 == apelido2) {
                    std::cout << "ERRO: dados incorretos\n" << std::endl;
                } else if (!sistema.executarPartida(jogo, apelido1, apelido2)) {
                    std::cout << "ERRO: jogador inexistente\n" << std::endl;
                }
            }
        } else {
            std::cout << "Comando não reconhecido. Tente novamente.\n" << std::endl;
        }
    }

    return 0;
}
