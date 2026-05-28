#include "tabuleiro.hpp"
#include "peca.hpp"


tabuleiro::tabuleiro(){

    matriz[0][0]=new torre(0);
    matriz[0][7]=new torre(0);
    matriz[7][0]=new torre(1);
    matriz[7][7]=new torre(1);

    matriz[0][1]=new cavalo(0);
    matriz[0][6]=new cavalo(0);
    matriz[7][1]=new cavalo(1);
    matriz[7][6]=new cavalo(1);

    matriz[0][2]=new bispo(0);
    matriz[0][5]=new bispo(0);
    matriz[7][2]=new bispo(1);
    matriz[7][5]=new bispo(1);

    matriz[0][3]=new rainha(0);
    matriz[7][3]=new rainha(1);

    matriz[0][4]=new rei(0);
    matriz[7][4]=new rei(1);

    for(int i=0;i<8;i++){
        matriz[1][i]=new peao(0);
        matriz[6][i]=new peao(1);
    }

}


tabuleiro::~tabuleiro(){
    for (auto& x: matriz){
        for(auto y: x)
        delete y;
    }

}


std::vector<std::vector<peca*>>& tabuleiro::getMatriz(){
    return this->matriz;
}