#ifndef CADASTROJOGADORES_HPP
#define CADASTROJOGADORES_HPP

#include "Jogador.hpp"
#include <vector>
#include <string>

/**
 * @class CadastroJogadores
 * @brief Classe responsável pelo gerenciamento de jogadores.
 *
 * A classe CadastroJogadores permite o cadastro, remoção, busca e listagem de jogadores.
 */
class CadastroJogadores {
public:
    /**
     * @brief Cadastra um novo jogador.
     * 
     * @param apelido O apelido do jogador a ser cadastrado.
     * @param nome O nome do jogador a ser cadastrado.
     * @return true Se o jogador foi cadastrado com sucesso.
     * @return false Se o jogador já existe ou se houve algum problema no cadastro.
     */
    bool cadastrarJogador(const std::string& apelido, const std::string& nome);

    /**
     * @brief Remove um jogador do cadastro.
     * 
     * @param apelido O apelido do jogador a ser removido.
     * @return true Se o jogador foi removido com sucesso.
     * @return false Se o jogador não foi encontrado no cadastro.
     */
    bool removerJogador(const std::string& apelido);

    /**
     * @brief Busca um jogador pelo apelido.
     * 
     * @param apelido O apelido do jogador a ser buscado.
     * @return Jogador* Ponteiro para o jogador encontrado ou nullptr se não for encontrado.
     */
    Jogador* buscarJogador(const std::string& apelido);

    /**
     * @brief Lista todos os jogadores cadastrados.
     * 
     * @param criterio Critério de ordenação ('a' para apelido, 'n' para nome).
     */
    void listarJogadores(char criterio) const;

private:
    /**
     * @brief Vetor de jogadores cadastrados.
     */
    std::vector<Jogador> jogadores;
};

#endif 
