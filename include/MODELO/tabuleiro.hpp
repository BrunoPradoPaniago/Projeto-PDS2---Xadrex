#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include<vector>
#include<peca.hpp>

using std::vector;

class tabuleiro{
    public:

    
    //Construtor de tabuleiro. Aloca a memoria das pecas
    // e cria a matriz ja com as pecas no lugar certo. 
    tabuleiro();

    //destrutor de tabuleiro, desaloca a memoria das pecas.
    ~tabuleiro();

    vector<vector<peca*>>& getMatriz();

    bool estaEmXeque(int equipe);
    bool estaEmMate(int equipe);



    private:

    vector<vector<peca*>> matriz{8, vector<peca*>(8, nullptr)}; //matriz de ponteiros inteiros para classe peça
    
    
};
#endif
