#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include "CadastroJogadores.hpp"
#include "Jogo.hpp"
#include <string>

/**
 * @class Sistema
 * @brief Gerencia o sistema de jogos e cadastro de jogadores.
 * 
 * A classe Sistema é responsável por gerenciar todas as operações do sistema, 
 * incluindo o gerenciamento de jogos (iniciar e executar partidas), bem como o 
 * cadastro, remoção e listagem de jogadores.
 */
class Sistema {
public:

/**
 * @brief Executa o loop principal do sistema.
 * 
 * A implementação do loop principal está localizada no main.cpp.
 */
    void executar();

/**
 * @brief Cadastra um novo jogador.
 * 
 * @param apelido O apelido do jogador a ser cadastrado.
 * @param nome O nome do jogador a ser cadastrado.
 * @return 'true' se o jogador foi cadastrado com sucesso, 'false' se o jogador
 * já existe ou se houve algum problema no cadastro.
 */
    bool cadastrarJogador(const std::string& apelido, const std::string& nome);

/**
 * @brief Remove um jogador cadastrado.
 * 
 * @param apelido O apelido do jogador a ser removido. 
 * @return `true` se o jogador foi removido com sucesso, `false` se o jogador 
 * não existe ou se houve algum problema na remoção.
 */
    bool removerJogador(const std::string& apelido);

/**
 * @brief Lista os jogadores cadastrados.
 * 
 * @param criterio O critério de ordenação para a listagem de jogadores e suas informações.
 */
    void listarJogadores(char criterio);

/**
 * @brief Executa uma partida entre dois jogadores.
 * 
 * @param jogo Qual o tipo de jogo será jogado
 * @param apelido1 Apelido do jogador 1.
 * @param apelido2 Apelido do jogador 2. Se definido como "IA", o jogador 1 jogará contra o computador.
 * @return 'true' quando a partida foi executada com sucesso, 'false' se houve
 * algum problema na execução.
 */
    bool executarPartida(const std::string& jogo, const std::string& apelido1, const std::string& apelido2);

/**
 * @brief Imprime uma mensagem de finalição da partida.
 */
    void finalizarSistema();

private:

/**
 * @brief Objeto responsável pelo gerenciamento de jogadores cadastrados.
 */
    CadastroJogadores cadastro;

/**
 * @brief Cria um jogo com base no tipo especificado.
 * 
 * @param jogo O tipo de jogo a ser criado (por exemplo, "R" para Reversi, "L" para Lig4).
 * @return Um ponteiro para um objeto `Jogo` do tipo especificado, ou `nullptr` se 
 * o tipo de jogo não for reconhecido.
 */
    Jogo* criarJogo(const std::string& jogo);
};

#endif 
