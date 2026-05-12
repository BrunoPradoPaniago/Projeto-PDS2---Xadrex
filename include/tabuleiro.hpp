#ifndef TABULEIRO_H
#define TABULEIRO_H

#include<vector>
#include<pecas.hpp>

using std::vector;

class tabuleiro{
    public:
vector<vector<pecas*>>matriz; //matriz de ponteiros inteiros para classe peça
    //Construtor de tabuleiro. Aloca a memoria das pecas
    // e cria a matriz ja com as pecas no lugar certo. 
    tabuleiro();

    //destrutor de tabuleiro, desaloca a memoria das pecas.
    ~tabuleiro();
    bool moverpeca(int x1, int y1, int x2, int y2);
    bool estaEmXeque(int equipe);
    bool estaEmMate(int equipe);
};
#endif
