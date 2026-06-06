#ifndef PECA_HPP
#define PECA_HPP
#include <string>






class peca{
    public:

    //Essa funcao deve verificar se o movimento eh valido (nao validar duas posicoes iguais, por exemplo),
    //o bool representa se o movimento é valido, ou não.
    virtual bool verificarMovimento(int linha_i, int coluna_i, int linha_f, int coluna_f)=0;

    virtual ~peca();

    virtual std::string getTipoPeca()=0;

    int getEquipe();

    //funcao para mudar o bool jaMoveu
    void SetJaMoveu();
    
    
    bool getJaMoveu();

    protected:

    //0 eh branco, 1 eh preto.
    int equipe;

    
    bool jaMoveu;
};


class peao: public peca{
    public:
    peao(int equipe);

    //Se equipe=branco, so anda pra frente, se equipe=preto, so anda pra tras.
    bool verificarMovimento(int linha_i, int coluna_i, int linha_f, int coluna_f) override;

    std::string getTipoPeca() override;
};


class bispo: public peca{
    public:
    bispo(int equipe);

    //Se |linha_f-linha_i|==|coluna_f-coluna_i| o movimento é valido
    bool verificarMovimento(int linha_i, int coluna_i, int linha_f, int coluna_f) override;

    std::string getTipoPeca() override;
};


class rei: public peca{
    public:
    rei(int equipe);

    bool verificarMovimento(int linha_i, int coluna_i, int linha_f, int coluna_f) override;

    std::string getTipoPeca() override;
};

class torre: public peca{
    public:
    torre(int equipe);

    //Se a coluna ou a linha forem fixas, mas não as duas, o movimento é valido.
    bool verificarMovimento(int linha_i, int coluna_i, int linha_f, int coluna_f) override;

    std::string getTipoPeca() override;
};

class cavalo: public peca{
    public:
    cavalo(int equipe);

     //Se |linha_f-linha_i|==2 && |coluna_f-coluna_i|==1, ou o contrario, o movimento é valido.
    bool verificarMovimento(int linha_i, int coluna_i, int linha_f, int coluna_f) override;

    std::string getTipoPeca() override;
};


class rainha: public peca{
    public:
    rainha(int equipe);

    bool verificarMovimento(int linha_i, int coluna_i, int linha_f, int coluna_f) override;

    std::string getTipoPeca() override;
};

#endif