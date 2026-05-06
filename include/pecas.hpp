#ifndef PECAS_HPP
#define PECAS_HPP
#include <string>


//FORWARD DECLARATION
class Tabuleiro;

using std::string;

class peca{
    public:

    //Essa funcao deve verificar se o movimento eh valido e executá-lo,
    //inclusive chamando a funcao tabuleiro.estaEmXeque, nao permitindo o movimento se resultar 1.
    //o bool representa se o movimento foi executado ou se não é valido.
    virtual bool mover(int x1, int y1, int x2, int y2, Tabuleiro& tab)=0;

    virtual ~peca(); // No arquivo pecas.hpp

    int getEquipe();

    protected:

    //0 eh branco, 1 eh preto.
    int equipe;

    bool jaMoveu;
};


class peao: public peca{
    public:
    peao(int equipe);

    bool mover(int x1, int y1, int x2, int y2, Tabuleiro& tab) override;
};


class bispo: public peca{
    public:
    bispo(int equipe);

    bool mover(int x1, int y1, int x2, int y2, Tabuleiro& tab) override;
};

class rainha: public peca{
    public:
    rainha(int equipe);

    bool mover(int x1, int y1, int x2, int y2, Tabuleiro& tab) override;
};

class rei: public peca{
    public:
    rei(int equipe);

    bool mover(int x1, int y1, int x2, int y2, Tabuleiro& tab) override;
};

class torre: public peca{
    public:
    torre(int equipe);

    bool mover(int x1, int y1, int x2, int y2, Tabuleiro& tab) override;
};

class cavalo: public peca{
    public:
    cavalo(int equipe);

    bool mover(int x1, int y1, int x2, int y2, Tabuleiro& tab) override;
};



#endif