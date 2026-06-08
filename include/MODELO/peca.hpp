#ifndef PECA_HPP
#define PECA_HPP
#include <string>

/**
 * @file peca.hpp
 * @brief Definição da classe Peça e de todas as suas classes derivadas.
 */

/**
 * @class peca
 * @brief Classe base para todas as peças de xadrez.
 *
 * Define o contrato que todas as peças específicas devem seguir, 
 * incluindo atributos comuns como equipe e controle de primeiro movimento.
 */
class peca {
    public:

    /**
     * @brief Verifica se o movimento da peça é válido segundo as regras daquela peça.
     * * Esta função analisa apenas a capacidade geométrica de movimento da peça (ex: Bispo em diagonal).
     * Não leva em conta colisões ou estado do tabuleiro.
     * @param linha_i Linha atual da peça.
     * @param coluna_i Coluna atual da peça.
     * @param linha_f Linha destino desejada.
     * @param coluna_f Coluna destino desejada.
     * @return true Se o movimento obedece o padrão da peça.
     * @return false Se o movimento for inválido ou se as posições inicial e final forem iguais.
     */
    virtual bool verificarMovimento(int linha_i, int coluna_i, int linha_f, int coluna_f) = 0;

    /**
     * @brief Destrutor virtual padrão.
     * * Garante que as classes derivadas sejam destruídas corretamente.
     */
    virtual ~peca();

    /**
     * @brief Retorna o tipo da peça em formato de string.
     * * @return std::string Nome da peça (ex: "peao", "cavalo").
     */
    virtual std::string getTipoPeca() = 0;

    /**
     * @brief Informa a qual equipe a peça pertence.
     * * @return int 0 para equipe Branca, 1 para equipe Preta.
     */
    int getEquipe();

    /**
     * @brief Sinaliza que a peça realizou o seu primeiro movimento.
     * * Crucial para regras especiais como Roque e avanço duplo do peão.
     */
    void SetJaMoveu();
    
    /**
     * @brief Verifica se a peça já foi movida na partida.
     * * @return true Se a peça já saiu da sua posição original.
     * @return false Se a peça nunca se moveu.
     */
    bool getJaMoveu();

    protected:

    /**
     * @brief Identificador da equipe: 0 é Branco, 1 é Preto.
     */
    int equipe;
    
    /**
     * @brief Flag de controle de primeiro movimento.
     */
    bool jaMoveu;
};

/**
 * @class peao
 * @brief Representa a peça Peão.
 */
class peao : public peca {
    public:
    peao(int equipe);

    /**
     * @brief Verifica o movimento do Peão.
     * * Peões Brancos (0) sobem a matriz (linhas diminuem). Peões Pretos (1) descem a matriz (linhas aumentam).
     * Pode andar duas casas no primeiro movimento ou capturar na diagonal.
     */
    bool verificarMovimento(int linha_i, int coluna_i, int linha_f, int coluna_f) override;

    std::string getTipoPeca() override;
};

/**
 * @class bispo
 * @brief Representa a peça Bispo.
 */
class bispo : public peca {
    public:
    bispo(int equipe);

    /**
     * @brief Verifica o movimento do Bispo.
     * * O movimento é válido se o deslocamento horizontal for igual ao vertical
     * (|linha_f - linha_i| == |coluna_f - coluna_i|).
     */
    bool verificarMovimento(int linha_i, int coluna_i, int linha_f, int coluna_f) override;

    std::string getTipoPeca() override;
};

/**
 * @class rei
 * @brief Representa a peça Rei.
 */
class rei : public peca {
    public:
    rei(int equipe);

    /**
     * @brief Verifica o movimento do Rei.
     * * O Rei move-se apenas uma casa em qualquer direção.
     */
    bool verificarMovimento(int linha_i, int coluna_i, int linha_f, int coluna_f) override;

    std::string getTipoPeca() override;
};

/**
 * @class torre
 * @brief Representa a peça Torre.
 */
class torre : public peca {
    public:
    torre(int equipe);

    /**
     * @brief Verifica o movimento da Torre.
     * * O movimento é válido se deslocar apenas na coluna (linha fixa) ou apenas na linha (coluna fixa),
     * mas nunca as duas simultaneamente.
     */
    bool verificarMovimento(int linha_i, int coluna_i, int linha_f, int coluna_f) override;

    std::string getTipoPeca() override;
};

/**
 * @class cavalo
 * @brief Representa a peça Cavalo.
 */
class cavalo : public peca {
    public:
    cavalo(int equipe);

    /**
     * @brief Verifica o movimento do Cavalo (movimento em "L").
     * * O movimento é válido se: |linha_f - linha_i| == 2 e |coluna_f - coluna_i| == 1,
     * ou vice-versa.
     */
    bool verificarMovimento(int linha_i, int coluna_i, int linha_f, int coluna_f) override;

    std::string getTipoPeca() override;
};

/**
 * @class rainha
 * @brief Representa a peça Rainha.
 */
class rainha : public peca {
    public:
    rainha(int equipe);

    /**
     * @brief Verifica o movimento da Rainha.
     * * Combina as capacidades da Torre (retas) e do Bispo (diagonais).
     */
    bool verificarMovimento(int linha_i, int coluna_i, int linha_f, int coluna_f) override;

    std::string getTipoPeca() override;
};

#endif