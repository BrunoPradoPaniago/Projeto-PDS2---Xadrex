#ifndef JOGO_HPP
#define JOGO_HPP

#include <string>
#include "tabuleiro.hpp"
#include "view.hpp"


class jogo{

    public:
    jogo();

    ~jogo();


    void inicializarJogo();    


    private:
    
    bool ProcessarCoordenadas(std::string movimentoDesejado, int& linha_i, int& linha_f, int& coluna_i, int& coluna_f);

    bool casaAtacada(int linha, int coluna, int equipe)

    bool validarMovimentoGeral(int linha_i,int linha_f,int coluna_i,int coluna_f, bool apenasFisica = false);

    bool MoverPeca(int linha_i,int linha_f,int coluna_i,int coluna_f);

    bool PromocaoPeao(int linha_f,int coluna_f);

    bool verificarXeque(int equipe);

    int verificarMate(int equipe);

    std::string nomeDaEquipe(std::string pertencimento);

    int numeroDaEquipe(std::string pertencimento);

   


    Tabuleiro tab;
    view v;
    int turno_bruto;
};


#endif