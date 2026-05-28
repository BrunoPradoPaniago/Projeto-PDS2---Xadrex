#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include<vector>
#include "peca.hpp"



class tabuleiro{
    public:

    
    //Construtor de tabuleiro. Aloca a memoria das pecas
    // e cria a matriz ja com as pecas no lugar certo. 
    tabuleiro();

    //destrutor de tabuleiro, desaloca a memoria das pecas.
    ~tabuleiro();

    std::vector<std::vector<peca*>>& getMatriz();



    private:

    std::vector<std::vector<peca*>> matriz{8, std::vector<peca*>(8, nullptr)}; //matriz de ponteiros inteiros para classe peça
    
    
};
#endif
