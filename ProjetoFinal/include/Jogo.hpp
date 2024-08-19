#ifndef JOGO_HPP
#define JOGO_HPP

/**
 * @class Jogo
 * @brief Classe base abstrata para jogos.
 *
 * Esta classe define a interface para os jogos, fornecendo métodos
 * que devem ser implementados por qualquer classe derivada que represente
 * um jogo específico. Inclui métodos para iniciar o jogo, validar e realizar jogadas,
 * imprimir o tabuleiro e verificar a vitória.
 */
class Jogo {
public:
    /**
     * @brief Destrutor virtual.
     *
     * O destrutor é virtual para garantir que o destruidor da classe derivada
     * seja chamado corretamente quando um objeto da classe derivada for destruído
     * através de um ponteiro para a classe base.
     */
    virtual ~Jogo() = default;

    /**
     * @brief Obtém a altura do tabuleiro.
     * @return A altura do tabuleiro.
     */
    virtual int getAltura() const = 0;

    /**
     * @brief Obtém a largura do tabuleiro.
     * @return A largura do tabuleiro.
     */
    virtual int getLargura() const = 0;

    /**
     * @brief Inicializa o jogo.
     *
     * Este método deve preparar o jogo para o início, configurando o estado
     * inicial do tabuleiro e quaisquer outras variáveis necessárias.
     */
    virtual void iniciar() = 0;

    /**
     * @brief Imprime o tabuleiro do jogo.
     *
     * Este método deve exibir o estado atual do tabuleiro na saída padrão,
     * permitindo que os jogadores visualizem a disposição dos elementos no tabuleiro.
     */
    virtual void imprimirTabuleiro() = 0;

    /**
     * @brief Valida uma jogada.
     * @param linha Linha onde a jogada será realizada.
     * @param coluna Coluna onde a jogada será realizada.
     * @return Verdadeiro se a jogada for válida, falso caso contrário.
     */
    virtual bool validarJogada(int linha, int coluna) = 0;

    /**
     * @brief Verifica se há um vencedor.
     * @return Verdadeiro se houver um vencedor, falso caso contrário.
     */
    virtual bool verificarVitoria() = 0;

    /**
     * @brief Realiza uma jogada.
     * @param linha Linha onde a jogada será realizada.
     * @param coluna Coluna onde a jogada será realizada.
     *
     * Este método deve atualizar o estado do tabuleiro com a jogada realizada
     * na posição especificada.
     */
    virtual void realizarJogada(int linha, int coluna) = 0;

    /**
     * @brief Realiza uma jogada automática pela IA.
     *
     * Este método deve ser implementado para permitir que a IA faça uma jogada
     * automática com base na configuração atual do tabuleiro.
     */
    virtual void realizarJogadaIA() = 0;
};

#endif
