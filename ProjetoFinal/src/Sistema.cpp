#include "Sistema.hpp"
#include "Reversi.hpp"
#include "Lig4.hpp"
#include <iostream>
#include <sstream>

/**
 * @brief Executa o loop principal do sistema.
 * 
 * A implementação do loop principal está localizada no main.cpp.
 */
void Sistema::executar() {
    // Implementação do loop principal já está no main.cpp ...
}

/**
 * @brief Cadastra um novo jogador.
 * 
 * Este método chama a função `cadastrarJogador` da classe `CadastroJogadores` 
 * para registrar um novo jogador no sistema.
 * 
 * @param apelido O apelido do jogador a ser cadastrado.
 * @param nome O nome do jogador a ser cadastrado.
 * @return 'true' se o jogador foi cadastrado com sucesso, 'false' se o jogador
 * já existe ou se houve algum problema no cadastro.
 */
bool Sistema::cadastrarJogador(const std::string& apelido, const std::string& nome) {
    return cadastro.cadastrarJogador(apelido, nome);
}

/**
 * @brief Remove um jogador cadastrado.
 * 
 * Este método chama a função `removerJogador` da classe `CadastroJogadores` 
 * para remover um jogador existente do sistema.
 * 
 * @param apelido O apelido do jogador a ser removido. 
 * @return `true` se o jogador foi removido com sucesso, `false` se o jogador 
 * não existe ou se houve algum problema na remoção.
 */
bool Sistema::removerJogador(const std::string& apelido) {
    return cadastro.removerJogador(apelido);
}

/**
 * @brief Lista os jogadores cadastrados.
 * 
 * Este método chama a função `listarJogadores` da classe `CadastroJogadores` 
 * para listar os jogadores cadastrados, de acordo com o critério especificado.
 * 
 * @param criterio O critério de ordenação para a listagem de jogadores. 
 */
void Sistema::listarJogadores(char criterio) {
    cadastro.listarJogadores(criterio);
}

/**
 * @brief Executa uma partida entre dois jogadores.
 * 
 * Este método faz o seguinte:
 * - Verifica se ambos os jogadores estão cadastrados.
 * - Cria o jogo especificado (Reversi ou Lig4).
 * - Gerencia os turnos dos jogadores, validando e executando jogadas.
 * - Permite que os jogadores saiam no meio do jogo digitando "SAIR".
 * - Detecta se houve uma saida de jogador e determina o vencedor.
 * - Adiciona vitria e derrota nas estatísticas dos jogares.
 * 
 * @param jogo O tipo de jogo a ser jogado ("R" para Reversi, "L" para Lig4).
 * @param apelido1 O apelido do jogador 1.
 * @param apelido2 O apelido do jogador 2. Caso seja definido como "IA", o jogador 1 joga contra o computador.
 * @return `true` se a partida foi concluída com sucesso, `false` se houve algum 
 * problema na execução, como jogadores não encontrados ou jogo inválido.
 */
bool Sistema::executarPartida(const std::string& jogo, const std::string& apelido1, const std::string& apelido2) {
    Jogador* jogador1 = cadastro.buscarJogador(apelido1);
    Jogador* jogador2 = (apelido2 == "IA") ? nullptr : cadastro.buscarJogador(apelido2);

    if (!jogador1 || (!jogador2 && apelido2 != "IA")) {
        return false;
    }

    Jogo* partida = criarJogo(jogo);
    if (!partida) {
        return false;
    }

    partida->iniciar();
    std::string jogada;
    bool turnoJogador1 = true; 
    std::string apelidoAtual;
    char simboloAtual;

    while (!partida->verificarVitoria() && jogada != "SAIR") {
        apelidoAtual = turnoJogador1 ? apelido1 : apelido2;
        simboloAtual = (apelidoAtual == apelido1) ? 'X' : 'O';

        if (apelidoAtual == "IA") {
            std::cout << "Turno da IA (" << simboloAtual << "):\n";
            if (jogo == "R") {
                static_cast<Reversi*>(partida)->realizarJogadaIA(); 
            } else if (jogo == "L") {
                static_cast<Lig4*>(partida)->realizarJogadaIA(); 
            }
            turnoJogador1 = !turnoJogador1; 
        } else {
            std::cout << "Turno de jogador " << apelidoAtual << " (" << simboloAtual << "): ";
            std::getline(std::cin >> std::ws, jogada);

            if (jogada == "SAIR") {
                break;
            }

            std::istringstream iss(jogada);
            int linha, coluna;

            if (jogo == "R") { // Reversi
                if (!(iss >> linha >> coluna)) {
                    std::cout << "ERRO: formato incorreto\n" << std::endl;
                    continue;
                }
            } else if (jogo == "L") { 
                if (!(iss >> coluna)) {
                    std::cout << "ERRO: formato incorreto\n" << std::endl;
                    continue;
                }
                linha = 0;
            }

            if (partida->validarJogada(linha, coluna)) {
                partida->realizarJogada(linha, coluna);
                turnoJogador1 = !turnoJogador1; 
            } else {
                std::cout << "ERRO: jogada inválida\n" << std::endl;
            }
        }
    }

    if (jogada == "SAIR") {
        std::cout << "\n  " << apelidoAtual << " SAIU DO JOGO" << std::endl;
        apelidoAtual = !turnoJogador1 ? apelido1 : apelido2;
        std::cout << "  VITÓRIA " << apelidoAtual << "!\n" << std::endl;
    } else if (!partida->empatePartida()){
        std::cout << "\n VITÓRIA " << apelidoAtual << "!\n" << std::endl;
    }
    
    if (!partida->empatePartida()){
        if(apelidoAtual != "IA"){
            cadastro.buscarJogador(apelidoAtual)->adicionarVitoria(jogo);
            apelidoAtual = turnoJogador1 ? apelido1 : apelido2;
        }
    
        if(apelidoAtual != "IA"){
            cadastro.buscarJogador(apelidoAtual)->adicionarDerrota(jogo);
        }
    }

     if (partida->empatePartida()){
        std::cout << "\n  EMPATE\n" << std::endl;
     }
    

    delete partida;
    return true;
}


/**
 * @brief Imprime uma mensagem de finalição da partida.
 */
void Sistema::finalizarSistema() {
    std::cout << "Sistema finalizado. Obrigado por jogar!" << std::endl;
    // extra: adicionar codigo para salvar sistema
}

/**
 * @brief Cria uma instância de um jogo especificado.
 * 
 * Este método verifica o tipo de jogo solicitado e cria uma instância correspondente.
 * 
 * - Se `jogo` for "R", uma nova instância de `Reversi` é criada e retornada.
 * - Se `jogo` for "L", uma nova instância de `Lig4` é criada e retornada.
 * - Se o tipo de jogo não for reconhecido, o método retorna `nullptr`.
 * 
 * @param jogo O tipo de jogo a ser criado ("R" para Reversi, "L" para Lig4).
 * @return Um ponteiro para um objeto `Jogo` do tipo especificado, ou `nullptr` 
 * se o tipo de jogo não for reconhecido.
 */
Jogo* Sistema::criarJogo(const std::string& jogo) {
    if (jogo == "R") {
        return new Reversi();
    } else if (jogo == "L") {
        return new Lig4();
    }
    return nullptr;
}
