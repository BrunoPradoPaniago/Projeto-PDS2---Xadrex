#ifndef JOGO_HPP
#define JOGO_HPP

#include <string>
#include "tabuleiro.hpp"
#include "interface.hpp"

/**
 * @file jogo.hpp
 * @brief Definição da classe jogo e controle da lógica e regras da partida.
 */

/**
 * @class jogo
 * @brief Gerenciador central das regras e turnos do xadrez.
 *
 * A classe jogo atua como o juiz da partida, controlando o turno
 * de cada jogador e as regras específicas do Xadrez (Roque, Xeque-mate, etc.).
 * Ela também faz a ponte do terminal para a interface gráfica, imprimindo o estado
 * atual do tabuleiro após qualquer alteração.
 */
class jogo {
    public:
    
    /**
     * @brief Construtor padrão do jogo.
     * * Inicializa o estado do jogo como ativo e zera o contador de turnos.
     */
    jogo();

    /**
     * @brief Destrutor padrão do jogo.
     */
    ~jogo();

    /**
     * @brief Inicia o loop principal da partida.
     * * Controla o fluxo de turnos, recebe os inputs do jogador via terminal 
     * e chama a interface gráfica para atualizar a tela a cada jogada.
     */
    void inicializarJogo();    

    private:
    
    /**
     * @brief Converte a string de entrada do jogador para coordenadas da matriz, retorna false se não for possível.
     * * @param movimentoDesejado String no formato de xadrez (ex: "C1 C2").
     * @param linha_i Referência do Int que guarda a linha de origem.
     * @param linha_f Referência do Int que guarda a linha de destino.
     * @param coluna_i Referência do Int que guarda a coluna de origem.
     * @param coluna_f Referência do Int que guarda a coluna de destino.
     * @return true Se a formatação da string for válida e estiver dentro do tabuleiro.
     * @return false Se o input for inválido.
     */
    bool ProcessarCoordenadas(std::string movimentoDesejado, int& linha_i, int& linha_f, int& coluna_i, int& coluna_f);

    /**
     * @brief Verifica se uma casa está sob ataque por uma equipe específica.
     * * Usado para verificar Xeques e impedir o Roque irregular.
     * @param linha Linha da casa a ser avaliada.
     * @param coluna Coluna da casa a ser avaliada.
     * @param equipe A equipe que está possivelmente atacando a casa.
     * @return true Se a casa está sendo ameaçada por pelo menos uma peça da equipe.
     * @return false Se a casa está segura.
     */
    bool casaAtacada(int linha, int coluna, int equipe);

    /**
     * @brief Validador geral de regras de movimento e colisão.
     * * Avalia fogo amigo, bloqueios no caminho, regras exclusivas (como peão) e Roque.
     * @param linha_i Linha inicial da peça.
     * @param linha_f Linha destino da peça.
     * @param coluna_i Coluna inicial da peça.
     * @param coluna_f Coluna destino da peça.
     * @param apenasFisica Flag opcional (padrão: false) que evita loops recursivos, principalmente quando a funcao é chamada dentro de casaAtacada.
     * @return true Se o movimento obedece a todas as regras do Xadrez.
     * @return false Se o movimento for ilegal.
     */
    bool validarMovimentoGeral(int linha_i, int linha_f, int coluna_i, int coluna_f, bool apenasFisica = false);

    /**
     * @brief Executa a movimentação da peça na matriz e verifica se o movimento deixará o próprio rei em xeque.
     * * @param linha_i Linha inicial.
     * @param linha_f Linha destino.
     * @param coluna_i Coluna inicial.
     * @param coluna_f Coluna destino.
     * @return true Se a peça foi movida com sucesso (não deixou o próprio rei em xeque).
     * @return false Se o movimento foi desfeito por colocar o próprio rei em xeque.
     */
    bool MoverPeca(int linha_i, int linha_f, int coluna_i, int coluna_f);

    /**
     * @brief Verifica e executa a promoção de um peão que chegou à última fileira.
     * * @param linha_f Linha em que a peça parou.
     * @param coluna_f Coluna em que a peça parou.
     * @return true Se houve promoção (o menu de escolha foi ativado).
     * @return false Se a peça não é um peão elegível para promoção.
     */
    bool PromocaoPeao(int linha_f, int coluna_f);

    /**
     * @brief Verifica se o rei de uma equipe está em xeque.
     * * @param equipe Equipe do rei que será avaliado (0 ou 1).
     * @return true Se o rei está sob ataque de alguma peça adversária.
     * @return false Se o rei está seguro.
     */
    bool verificarXeque(int equipe);

    /**
     * @brief Avalia condição de empate técnico por falta de peças para dar mate.
     * * @return true Se só restam peças insuficientes (ex: Rei e Bispo vs Rei).
     * @return false Se ainda há material suficiente para vencer o jogo.
     */
    bool materialInsuficiente();

    /**
     * @brief Analisa todas as fugas e defesas do rei para determinar Xeque-Mate, verifica afogamento.
     * * @param equipe Equipe a ser avaliada.
     * @return int 0 se o rei possui fuga ou defesa.
     * @return int 1 se é Xeque-Mate (derrota).
     * @return int 2 se é Afogamento (empate).
     */
    int verificarMate(int equipe);

    /**
     * @brief Traduz a referência interna de turno para o nome legível da equipe.
     * * @param pertencimento "proprio" ou "adversario".
     * @return std::string "Brancas" ou "Pretas".
     */
    std::string nomeDaEquipe(std::string pertencimento);

    /**
     * @brief Traduz a referência interna de turno para o ID numérico da equipe.
     * * @param pertencimento "proprio" ou "adversario".
     * @return int 0 para equipe Branca, 1 para equipe Preta.
     */
    int numeroDaEquipe(std::string pertencimento);

    /**
     * @brief Objeto que guarda o estado atual das peças no tabuleiro.
     */
    tabuleiro tab;

    /**
     * @brief Objeto responsável por gerenciar a janela gráfica do jogo.
     */
    interface v;

    /**
     * @brief Contador absoluto de jogadas. Define de quem é o turno.
     */
    int turno_bruto;

    /**
     * @brief Flag que mantém o loop do jogo rodando. Falsa quando a partida acaba.
     */
    bool jogoAtivo;
};

#endif