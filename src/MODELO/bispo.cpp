#include "pecas.hpp"
#include "tabuleiro.hpp"

using std::string;


peca::~peca(){

}
//equipe ta em protected, pega e le o valor da equipe, retorna a equipe
int peca::getEquipe(){
    return equipe;
}
//construtor de peao, da a equipe pra ele e diz que nao foi movido
bispo::bispo(int corDaequipe){
    equipe = corDaequipe;
    jaMoveu = false;
    bool VerificarMovimento(int linha_i, int coluna_i, int linha_f, int coluna_f){
        int linhasAndadas = linha_f - linha_i;
    int colunasAndadas = coluna_f - coluna_i; //esquerda -1 e direirta 1

//garante que os dois sera positivo, vai guardar a distanica percorrida pelo bispo ao inves de so a direçao
    if (linhasAndadas<0){
        linhasAndadas = linhasAndadas *(-1);
    }
     if (colunasAndadas<0){
        colunasAndadas = colunasAndadas *(-1);
    }
    if (linhasAndadas == colunasAndadas) {
    return true;  } }
    return false;  }