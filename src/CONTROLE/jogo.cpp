#include <iostream>
#include <limits>
#include <string>
#include "jogo.hpp"

int turno_bruto;//tirar
bool jogoAtivo;//tirar


bool ProcessarCoordenadas(std::string movimentoDesejado, int& linha_i, int& linha_f, int& coluna_i, int& coluna_f){
    return true;//temporario, so pra nao dar erro,TO DO
}

bool validarMovimentoGeral(int linha_i,int linha_f,int coluna_i,int coluna_f){
    return true;//temporario, so pra nao dar erro,TO DO
}

bool MoverPeca(int linha_i,int linha_f,int coluna_i,int coluna_f){
    return true;//temporario, so pra nao dar erro,TO DO
}

bool PromocaoPeao(int linha_f,int coluna_f){
    return true;//temporario, so pra nao dar erro,TO DO
}

bool verificarXeque(int numero){
    return true;//temporario, so pra nao dar erro,TO DO
}

bool verificarMate(int numero){
    return true;//temporario, so pra nao dar erro,TO DO
}

//jogo() Implementar


//jogo() Implementar



std::string nomeDaEquipe(std::string pertencimento){
    std::string nomes[2]={"Brancas","Pretas"};
    if(pertencimento=="proprio"){
        int indiceProprio = turno_bruto % 2;
        return nomes[indiceProprio];
    }
    else if(pertencimento=="adversario"){
        int indiceAdversario = (turno_bruto + 1) % 2; 
        return nomes[indiceAdversario];
    }
    else{
        return ("Erro");
    }
} 

int numeroDaEquipe(std::string pertencimento){
    if(pertencimento=="proprio"){
        return turno_bruto % 2;
    }
    else if(pertencimento=="adversario"){
        return (turno_bruto+1) % 2;
    }
    else{
        return -1;
    }

}


void inicializarJogo(){
    jogoAtivo=true;
    turno_bruto=0;
   

    std::cout<< "Bem vindo ao Xadrez Virtual!"<< std::endl << "Por favor decida qual Jogador controlará as peças Brancas, e qual controlará as peças Pretas. O Jogador das peças Brancas começa jogando." << std::endl;
    while(jogoAtivo!=0){
        int opcaoEscolhida;
        std::cout << "Jogador das peças "<< nomeDaEquipe("proprio")<<", escolha das opções de Jogada, pelo número:" << std::endl << "1 - Mover Peça" << std::endl << "2 - Propor Empate" << std::endl << "3 - Desistir" << std::endl;
        while(true){
        if (!(std::cin >> opcaoEscolhida)) { 
            std::cout << "Input Invalido. Escolha entre as opcoes 1, 2 ou 3." << std::endl;
            
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; 
        }
        if(opcaoEscolhida == 1 || opcaoEscolhida == 2 || opcaoEscolhida == 3){
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        std::cout<<"Opcao Invalida. Escolha entre as opcoes 1, 2 ou 3." << std::endl;
        }


        
        if(opcaoEscolhida==2){
            std::cout <<"O Jogador das peças " << nomeDaEquipe("proprio")<< " ofereceu um empate. Jogador das peças "<< nomeDaEquipe("adversario")<<", deseja aceitar? (1-Sim / 2-Nao )"<< std::endl;
            int aceitaEmpate;
            while(true){
                if (!(std::cin >> aceitaEmpate) || (aceitaEmpate!=1 && aceitaEmpate!=2)) { 
                    std::cout << "Input Invalido. Escolha entre 1 e 2" << std::endl;
                    
                    std::cin.clear(); 
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue; 
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break; 
            }
            if(aceitaEmpate==1){
                std::cout<<"O Jogo terminou em Empate!" << std::endl;
                jogoAtivo=false;
                continue;
            }
            else if(aceitaEmpate==2){
                std::cout<<"O Jogador das pecas " << nomeDaEquipe("adversario")<< " nao aceitou o empate! Escolha entre:"<< std::endl << "1 - Mover Peça" << std::endl << "3 - Desistir" << std::endl;
            }
            while(true){
                if (!(std::cin >> opcaoEscolhida) || (opcaoEscolhida!=1 && opcaoEscolhida!=3)) { 
                    std::cout << "Input Invalido. Escolha entre 1 ou 3" << std::endl;
                    
                    std::cin.clear(); 
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue; 
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break; 
            }
        }


        if(opcaoEscolhida==1){
            std::cout<<"Escolha o movimento desejado, no modelo \"C1 C2\""<<std::endl;
            std::string movimentoDesejado;
            int linha_i, linha_f, coluna_i, coluna_f;
            while(true){
                std::getline(std::cin, movimentoDesejado);
                bool coordenadasValidas = ProcessarCoordenadas(movimentoDesejado, linha_i, linha_f, coluna_i, coluna_f);
                if(coordenadasValidas==false){
                    std::cout<<"Movimento Invalido. Digite outro movimento."<<std::endl;
                    continue;
                }
                
                bool movimentoValidado = validarMovimentoGeral(linha_i, linha_f, coluna_i, coluna_f);
                if(movimentoValidado==false){
                    std::cout<<"Movimento Invalido. Digite outro movimento."<<std::endl;
                    continue;
                }

                bool pecaMovida = MoverPeca(linha_i, linha_f, coluna_i, coluna_f);
                if(pecaMovida==false){
                    std::cout<<"Movimento nao pode ser executado, pois deixa seu rei em xeque. Digite outro movimento."<<std::endl;
                    continue;
                }
                break;
                
            }

            tab.getMatriz()[linha_f][coluna_f]->SetJaMoveu();

            v.imprimirTabuleiro(tab);

            
            

            bool estaEmXeque = verificarXeque(numeroDaEquipe("adversario"));
            if(estaEmXeque==1){
                std::cout<<"O Rei das peças "<< nomeDaEquipe("adversario")<<" está em xeque!"<<std::endl;
            }

            bool estaEmMate = verificarMate(numeroDaEquipe("adversario"));
            if(estaEmMate==1){
            std::cout<<"O Rei das peças "<< nomeDaEquipe("adversario")<<" está em Xeque-Mate!. O Jogador das peças "<< nomeDaEquipe("proprio")<<" Ganhou!" << std::endl;
            jogoAtivo=false;
            continue;
            }

            if(PromocaoPeao(linha_f,coluna_f)){
            v.imprimirTabuleiro(tab);
        }

        }

        else if(opcaoEscolhida==3){
            std::cout<<"O Jogador das peças "<< nomeDaEquipe("proprio")<<" desistiu. O Jogador das peças "<< nomeDaEquipe("adversario")<<" Ganhou!" << std::endl;
            jogoAtivo=false;
            continue;
        }



        turno_bruto++;
        
    }

}