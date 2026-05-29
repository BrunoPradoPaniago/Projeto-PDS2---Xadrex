#include "pecas.hpp"
#include "tabuleiro.hpp"

#include <string>



                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
using std::string;


peca::~peca(){

}
int peca::getEquipe(){
    return equipe;
}



//PEAO


peao::peao(int corDaequipe){
    equipe = corDaequipe;
    jaMoveu = false;
}

bool peao::VerificarMovimento(int linha_i, int coluna_i, int linha_f, int coluna_f){
    

    int linhasAndadas = linha_f - linha_i;
    int colunasAndadas = coluna_f - coluna_i; //esquerda -1 e direirta 1

    //logica para o peao mover 1 ou 2 casas no primeiro movimento. se jaMoveu= falso, pode andar 1 ou 2 casas, else uma casa so
    //tem que ser um numero negativo para preto  e postiivo para  branco
    if(equipe == 1 && jaMoveu == false && (linhasAndadas == -1 || linhasAndadas == -2 ) && coluna_i == coluna_f){
        return true;
    } else if (equipe == 1 && linhasAndadas == -1 && coluna_i == coluna_f){
            return true;
        }
    
    //movimento de comer, tem que ler linha e coluna andadas (um pra frente e um pro lado)
    else if (equipe == 1 && linhasAndadas == -1 && (colunasAndadas == 1 || colunasAndadas == -1)){
    return true; }


    //logica para equipe 0 (branco)
    else if(equipe == 0 && jaMoveu == false && (linhasAndadas == 1 || linhasAndadas == 2 ) && coluna_i == coluna_f){
        return true;
}
else if (equipe == 0 && linhasAndadas == 1 && coluna_i == coluna_f){
    
            return true;
} 
 

 //movimento de comer, tem que ler linha e coluna andadas (um pra frente e um pro lado)
 else if (equipe == 0 && linhasAndadas == 1 && (colunasAndadas == 1 || colunasAndadas == -1)){
    return true;
 }
 return false;
  }



  //BISPO

  //construtor de bispp, da a equipe pra ele e diz que nao foi movido
bispo::bispo(int corDaequipe){
    equipe = corDaequipe;
    jaMoveu = false;
    bool bispo::VerificarMovimento(int linha_i, int coluna_i, int linha_f, int coluna_f){
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



    //REI
//construtor rei
    rei::rei(int corDaequipe){
        equipe = corDaequipe;
        jaMoveu = false;

    }

    bool rei::VerificarMovimento(int linha_i, int coluna_i, int linha_f, int coluna_f){
    int linhasAndadas = linha_f - linha_i;
    int colunasAndadas = coluna_f - coluna_i; 

    //cliclou no mesmo lugar que o rei ja tava
    if(linhasAndadas ==0 && colunasAndadas == 0){
return false;
    }
    if(linhasAndadas < 0){
        linhasAndadas= linhasAndadas *(-1)
    }
    if(colunasAndadas < 0){
        colunasAndadas= colunasAndadas *(-1) }

    if(linhasAndadas<=1 && colunasAndadas <=1){
        return true;
    }
    return false;
     }


     //TORRE
     torre::torre(int corDaequipe){
        equipe= corDaequipe;
        jaMoveu= false;
     }


     bool torre::VerificarMovimento(int linha_i, int coluna_i, int linha_f, int coluna_f){
        int linhasAndadas = linha_f - linha_i;
    int colunasAndadas = coluna_f - coluna_i; 

     if(linhasAndadas ==0 && colunasAndadas == 0){
return false;
    }
    if(linhasAndadas < 0){
        linhasAndadas= linhasAndadas *(-1)
    }
    if(colunasAndadas < 0){
        colunasAndadas= colunasAndadas *(-1) }


        //vai andar pra frente, pra tras ou pros lados. Como em cima coloquei o modulo, deixar >0 ja funcionma, nao precisa fazer uma funçao para branco ou preto
        if((linhasAndadas> 0 && colunasAndadas== 0)|| linhasAndadas == 0 && colunasAndadas> 0 ){
            return true;
        }
        return false;
         }
