#include <iostream>
#include <limits>
#include <string>
#include "jogo.hpp"
#include <cmath>



bool jogo::ProcessarCoordenadas(std::string movimentoDesejado, int& linha_i, int& linha_f, int& coluna_i, int& coluna_f){
    return true;//temporario, so pra nao dar erro,TO DO
}


bool jogo::casaAtacada(int linha, int coluna, int equipe){
    for(int i=0; i<8; i++ ){
        for(int i2=0;i2<8;i2++){
            if(tab.getMatriz()[i][i2]!=nullptr){
                if(tab.getMatriz()[i][i2]->getEquipe()==equipe){
                    if(validarMovimentoGeral(i,linha,i2,coluna,true)){
                        return true;
                    }
                }
            }
            
        }
    }
    return false;
}

bool jogo::validarMovimentoGeral(int linha_i,int linha_f,int coluna_i,int coluna_f, bool apenasFisica){
    
    //impede que a peca fique no mesmo lugar
    if(linha_i==linha_f && coluna_i==coluna_f){
        return false;
    }

    peca* pecaOrigem = tab.getMatriz()[linha_i][coluna_i];
    peca* pecaDestino = tab.getMatriz()[linha_f][coluna_f];

    if (pecaOrigem == nullptr) {
        return false; 
    }

    bool ehRoque = false;

    //Impede fogo amigo, a nao ser que seja roque.
    if (pecaDestino != nullptr && pecaDestino->getEquipe() == pecaOrigem->getEquipe()) {    
        
        if (pecaOrigem->getTipoPeca() == "rei" && pecaDestino->getTipoPeca() == "torre") {
            
            if (!pecaOrigem->getJaMoveu() && !pecaDestino->getJaMoveu()) {
                ehRoque = true; 
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    
    //Verifica se o movimento eh permitido pela peca, a nao ser que seja roque.
    if(!ehRoque){
        if(!pecaOrigem->verificarMovimento(linha_i, coluna_i, linha_f, coluna_f)){
            return false;
        }
    }

    //Regras especiais do peao
    if(pecaOrigem->getTipoPeca()=="peao"){
        if(coluna_i==coluna_f){
            if(pecaDestino!=nullptr){
                return false;
            }
        }
        else{
            if(pecaDestino==nullptr){
                return false;
            }
        }
    }

    //detectacao de colisao.
    if(pecaOrigem->getTipoPeca()!="cavalo"){
        int step_l = 0;
        if (linha_f > linha_i) step_l = 1;
        else if (linha_f < linha_i) step_l = -1;

        int step_c = 0;
        if (coluna_f > coluna_i) step_c = 1;
        else if (coluna_f < coluna_i) step_c = -1;

        int l_atual = linha_i + step_l;
        int c_atual = coluna_i + step_c;

        while (l_atual != linha_f || c_atual != coluna_f) {
            if (tab.getMatriz()[l_atual][c_atual] != nullptr) {
                return false;
            }
            l_atual += step_l;
            c_atual += step_c;
        }
    }

    //Consideracoes especiais para o roque

    if(ehRoque){

        //dentro desse if usamos casaAtacada, mas como essa funcao tambem chama validarMovimentoGeral,
        //a proxima linha impede que haja um loop infinito.
        if (apenasFisica) return false;

        int equipeAdversaria = (pecaOrigem->getEquipe() + 1) % 2;

        //o rei nao pode fazer roque quando em xeque
        if (casaAtacada(linha_i, coluna_i, equipeAdversaria)) {
            return false; 
        }

        //achando a direcao para a qual o roque vai ser
        int direcao;
        if (coluna_f > coluna_i) {
            direcao = 1; 
        } else {
            direcao = -1;
        }
        
        //no roque o rei sempre anda 2 casas e nem a casa atravessada, nem a casa que se vai chegar, podem estar ameacadas.
        int casa_passagem = coluna_i + direcao;
        int casa_destino_rei = coluna_i + (direcao * 2);

        
        if (casaAtacada(linha_i, casa_passagem, equipeAdversaria)) {
            return false; 
        }
        if (casaAtacada(linha_i, casa_destino_rei, equipeAdversaria)) {
            return false; 
        }


    }

    return true;
}


bool jogo::MoverPeca(int linha_i,int linha_f,int coluna_i,int coluna_f){

    peca* backupMinhaPeca=tab.getMatriz()[linha_i][coluna_i];
    int minhaEquipe = tab.getMatriz()[linha_i][coluna_i]->getEquipe();

    peca* backupPecaDestino = tab.getMatriz()[linha_f][coluna_f];

    tab.getMatriz()[linha_f][coluna_f] = backupMinhaPeca;
    tab.getMatriz()[linha_i][coluna_i] = nullptr;

    //Consideracoes e operacao especial para o roque.
    if (backupMinhaPeca->getTipoPeca() == "rei" && 
        backupPecaDestino != nullptr && 
        backupPecaDestino->getTipoPeca() == "torre" && 
        minhaEquipe == backupPecaDestino->getEquipe()) {
        
        int direcao = (coluna_f > coluna_i) ? 1 : -1;
        
        int colunaReiFinal = coluna_i + (direcao * 2);
        int colunaTorreFinal = coluna_i + direcao;

        tab.getMatriz()[linha_i][coluna_i] = nullptr;
        tab.getMatriz()[linha_f][coluna_f] = nullptr;

        tab.getMatriz()[linha_i][colunaReiFinal] = backupMinhaPeca;
        tab.getMatriz()[linha_f][colunaTorreFinal] = backupPecaDestino;

        if (verificarXeque(minhaEquipe)) {
            tab.getMatriz()[linha_i][coluna_i] = backupMinhaPeca;
            tab.getMatriz()[linha_f][coluna_f] = backupPecaDestino;
            tab.getMatriz()[linha_i][colunaReiFinal] = nullptr;
            tab.getMatriz()[linha_f][colunaTorreFinal] = nullptr;
            return false;
        }

        backupMinhaPeca->SetJaMoveu();
        backupPecaDestino->SetJaMoveu();
        return true; 
    }

    if(verificarXeque(minhaEquipe)){
        tab.getMatriz()[linha_i][coluna_i]=backupMinhaPeca;
        tab.getMatriz()[linha_f][coluna_f]=backupPecaDestino;
        return false;
    }
    else{
        if (backupPecaDestino != nullptr) {
            delete backupPecaDestino; 
        }
    }

    backupMinhaPeca->SetJaMoveu();
    return true;
}

bool jogo::PromocaoPeao(int linha_f,int coluna_f){
    //guardar a casa do ultimo movimento do peao
    peca*p= tab.getMatriz()[linha_f][coluna_f];
    //se a ultima casa tiver vazia, retorna falso, pq nao tem nenhuma casa para ser promovida, tipo uma trava de segurnaça
    if(p==nullptr) return false;
    if(p->getTipoPeca()== "peao"){
        int equipePeao = p->getEquipe();
        //esse if vai testar se os peoes, branco ou preto, chegou na linha final (0 ou 7)
        if((equipePeao ==0 && linha_f ==0)|| (equipePeao ==1 && linha_f ==7)){
            std::cout << "Promoção de peão";
            std::cout << "Escolha a nova peça";
            std::cout <<"1- Rainha"<< std:endl;
            std::cout <<"2- Cavalo"<< std:endl;
            std::cout <<"3- Bispo"<< std:endl;
            std::cout <<"4- Torre"<< std:endl;
            int escolhaPeca;
            //loop para o usuario escolher a opçãp. so para quando escolher
            while(true){
                //parte para nao quebrar o codigo, se a pessoa escolher algo invalido, volta para o inicio do loop
                if(!(std::cin>>escolhaPeca)|| escolhaPeca < 1 || escolhaPeca>4){
                    std::cout << "Escolha invalida";
                    std::cin.clear();
                    std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n')
                    continue;

                }
                //limpa no caso de escolhas invalidas
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                break;
        

            }
            delete p;
            if(escolhaPeca==1){
                tab.getMatriz()[linha_f][coluna_f]= new rainha(equipePeao);
                std::cout << "Peao promovido"<<std::endl;
            }
            else if(escolhaPeca==2){
                tab.getMatriz()[linha_f][coluna_f]= new cavalo(equipePeao);
                std::cout << "Peao promovido"<<std::endl;

            }
            else if(escolhaPeca==3){
                tab.getMatriz()[linha_f][coluna_f]= new bispo(equipePeao);
                std::cout << "Peao promovido"<<std::endl;
        }
        else if(escolhaPeca==4){
                tab.getMatriz()[linha_f][coluna_f]= new torre(equipePeao);
                std::cout << "Peao promovido"<<std::endl;

    }
    return true;
    }
}
return false;
}
}

bool jogo::verificarXeque(int equipe){
    int linhaRei=0;
    int colunaRei=0;
    for(int i=0;i<8;i++){
        for(int i2=0; i2<8; i2++){
            if(tab.getMatriz()[i][i2]!=nullptr){
                if(tab.getMatriz()[i][i2]->getTipoPeca()=="rei" &&
                   tab.getMatriz()[i][i2]->getEquipe()==equipe){
                        linhaRei=i;
                        colunaRei=i2;
                   }
            }
        }
    }

    int equipe_adversaria = (equipe+1) % 2;
    if(casaAtacada(linhaRei,colunaRei,equipe_adversaria)){
        return true;
    }
    return false;
}

int jogo::verificarMate(int equipe){
    //Achar a posicao do rei.
    int linhaRei=0;
    int colunaRei=0;
    for(int i=0;i<8;i++){
        for(int i2=0; i2<8; i2++){
            if(tab.getMatriz()[i][i2]!=nullptr){
                if(tab.getMatriz()[i][i2]->getTipoPeca()=="rei" &&
                   tab.getMatriz()[i][i2]->getEquipe()==equipe){
                        linhaRei=i;
                        colunaRei=i2;
                   }
            }
        }
    }
    //Verificar nas 8 casas em volta do rei, se elas não estão sendo atacadas e, nesse caso, se não há ninguém 
    //naquela casa, ou se tem um inimigo. Nesse caso, o rei tem pra onde fugir, nao eh mate.
    
    for(int i = (linhaRei-1);i<=(linhaRei+1);i++){
        for(int i2 =(colunaRei-1);i2<=(colunaRei+1);i2++){
            if(i==linhaRei && i2==colunaRei){
                continue;
            }
            if(i>=0 && i<=7 && i2>=0 && i2<=7){
                
                if(!casaAtacada(i,i2,(equipe+1)%2)){
                    if(tab.getMatriz()[i][i2]==nullptr){
                        return 0;
                    }
                    else if(tab.getMatriz()[i][i2]->getEquipe()==(equipe+1)%2){
                        return 0;
                    }
                }
                
            }
        }
    }

    //Verificar Afogamento
    
    if(!casaAtacada(linhaRei,colunaRei,(equipe+1)%2)){
        bool afogamento=true;
        for(int i=0; i<8; i++ ){
            for(int i2=0;i2<8;i2++){
                if(tab.getMatriz()[i][i2]!=nullptr){
                    if(tab.getMatriz()[i][i2]->getEquipe()==equipe){
                        //Verificando se a peca achada tem algum movimento valido
                        for(int i3=0;i3<8;i3++){
                            for(int i4=0;i4<8;i4++){
                                if(validarMovimentoGeral(i,i3,i2,i4)){
                                    afogamento=false;
                                }
                            }
                        }

                    }
                }
                
            }
        }
        if(afogamento){
            return 2;
        }
    }

    else{
        //Nesse caso o rei esta sendo atacado, o unico jeito de nao ser mate eh se alguem conseguir bloquear.

        //Achando a posicao do agressor
        int linhaAgressor, colunaAgressor;
        for(int i=0;i<8;i++){
            for(int i2=0; i2<8; i2++){
                if(tab.getMatriz[i][i2]!=nullptr){
                    if(tab.getMatriz()[i][i2]->getEquipe()==(equipe+1)%2){
                        if(validarMovimentoGeral(i,linhaRei,i2,colunaRei)){
                            linhaAgressor=i;
                            colunaAgressor=i2;
                        }
                    }
                }
            }
        }

        //TODO: acabar a implementacao da funcao


    }
    return 1;
}

jogo::jogo(){
    turno_bruto = 0;
    jogoAtivo = true;
} 


bool jogo::materialInsuficiente(){
     //rei contra rei
     //rei e bispo contra rei 
     //rei e cavalo contra rei
     int totalPecas =0;
     int bisposBrancos=0;
     int bisposPretos=0;
     int cavalosPretos=0;
     int cavalosBrancos=0;

     //percorrer todas as casas do tabuleiro
     for(int i=0; i<8;i++){
        for(int i2=0;i2<8;i2++){
            peca*p=tab.getMatriz()[i][i2];
            //se a casa nao tiver vazia, tem que analisar qual peca esta na casa
            if (p!= nullptr){
                totalPecas++;
                //descobre de qual equipe é a peça
                int equipePeca = p->getEquipe();
                std::string tipo = p->getTipoPeca();
                if(tipo =="peao "||tipo== "torre" || tipo =="rainha"){
                    return false;
                }
            if (tipo == "bispo"){
                if(equipePeca==0) 
                bisposBrancos++
            else bisposPretos++;

            }
            if(tipo == "cavalo"){
                if(equipePeca==0) cavalosBrancos++;
                else cavalosPretos++;
            }
            }
        }
     }
     //se so sobrar duas peças no tabuleiro, sao rei, entao o jogo tem que acabar
     if(totalPecas == 2){
        return true;
     }
     if(totalPecas == 3){
        if(bisposBrancos ==1 || bisposPretos ==1){
            return true;
        }
        if(cavalosBrancos == 1 || cavalosPretos==1){
            return true;
        }
    
     }
     
    return false;
    //basicamente vai percorrer todo o tabuleiro procurando as peças ainda vivas
    //vai analisar as casas que nao estao vaizas e ver de quem é (preto ou branco)
    //e analisar qual tipo de peça é. Se nao for bispo ou cavalo, jogo segue normal
    // se for, entra no contador pra ver quantas dessas peças 
    //depois é analise de caso, se nao entrar em nenhum desses casos, return falso
}


std::string jogo::nomeDaEquipe(std::string pertencimento){
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

int jogo::numeroDaEquipe(std::string pertencimento){
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


void jogo::inicializarJogo(){
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


            v.imprimirTabuleiro(tab);

            
            

            int estaEmMate = verificarMate(numeroDaEquipe("adversario"));
            if(estaEmMate==1){
                std::cout<<"O Rei das peças "<< nomeDaEquipe("adversario")<<" está em Xeque-Mate!. O Jogador das peças "<< nomeDaEquipe("proprio")<<" Ganhou!" << std::endl;
                jogoAtivo=false;
                continue;
            }
            else if(estaEmMate==2){
                std::cout<<"Afogamento! O Jogador das peças " << nomeDaEquipe("adversario") << " não possui movimentos legais, mas seu Rei não está em xeque. O jogo terminou em Empate!"<<std::endl;
                jogoAtivo=false;
                continue;
            }



            if(materialInsuficiente()){
                std::cout<<"O jogo terminou em Empate, por material insuficiente! Nenhum dos jogadores possui peças suficientes no tabuleiro para forçar um Xeque-Mate."<<std::endl;
                jogoAtivo=false;
                continue;
            }


            bool estaEmXeque = verificarXeque(numeroDaEquipe("adversario"));
            if(estaEmXeque==1){
                std::cout<<"O Rei das peças "<< nomeDaEquipe("adversario")<<" está em xeque!"<<std::endl;
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
