#include "pecas.hpp"
#include "tabuleiro.hpp"

#include <string>




using std::string;


peca::~peca(){

}
int peca::getEquipe(){
    return equipe;
}

peao::peao(int corDaequipe){
    equipe = corDaequipe;
    jaMoveu = false;
}

bool peao::VerificarMovimento(int linha_i, int coluna_i, int linha_f, int coluna_f){
    

    int linhasAndadas = linha_f - linha_i;
    int colunasAndadas = coluna_f - coluna_i; //esquerda -1 e direirta 1

    //logica para o peao mover 1 ou 2 casas no primeiro movimento. se jaMoveu= falso, pode andar 1 ou 2 casas, else uma casa so
    //tem que ser um numero negativo para branco e postiivo para preto 
    if(equipe == 0 && jaMoveu == false && (linhasAndadas == -1 || linhasAndadas == -2 ) && coluna_i == coluna_f){
        return true;
    } else if (equipe == 0 && linhasAndadas == -1 && coluna_i == coluna_f){
            return true;
        }
    
    //movimento de comer, tem que ler linha e coluna andadas (um pra frente e um pro lado)
    else if (equipe == 0 && linhasAndadas == -1 && (colunasAndadas == 1 || colunasAndadas == -1)){
    return true; }


    //logica para equipe 1 (preta)
    else if(equipe == 1 && jaMoveu == false && (linhasAndadas == 1 || linhasAndadas == 2 ) && coluna_i == coluna_f){
        return true;
}
else if (equipe == 1 && linhasAndadas == 1 && coluna_i == coluna_f){
    
            return true;
} 
 

 //movimento de comer, tem que ler linha e coluna andadas (um pra frente e um pro lado)
 else if (equipe == 1 && linhasAndadas == 1 && (colunasAndadas == 1 || colunasAndadas == -1)){
    return true;
 }
 return false;
  }