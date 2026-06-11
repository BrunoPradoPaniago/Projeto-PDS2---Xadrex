Markdown

## Sistema de Xadrez em C++

Este projeto consiste na implementação de um Jogo de Xadrez clássico em C++, seguindo os princípios de programação orientada a objetos, herança e polimorfismo. O jogo também utiliza a biblioteca SFML para implementar uma interface gráfica, com o display do tabuleiro em tempo real.


## Como compilar e executar
 
Para se compilar o programa, primeiramente deve-se garantir que todas as bibliotecas devidas estão instaladas. Assumindo que o usuário utiliza WSL (Subsistema do Windows para Linux), o seguinte comando, colocado no terminal do linux, garante a instalação das bibliotecas: “sudo apt update && sudo apt install build-essential libsfml-dev libgl1-mesa-dri libglx-mesa0 libgl1 -y”.  Após completar a instalação, o comando para compilar e executar, sequencialmente, o programa, com o display gráfico, é “DISPLAY=:0 make run”. O vídeo a seguir demonstra esse processo: [https://drive.google.com/drive/folders/198U9_2gTTZdehNllvH4LMlwPEDiaKZBa?usp=sharing].


## Arquitetura e organização do projeto

O projeto foi feito utilizando o padrão MVC (Model, View, Control), distribuído na seguinte estrutura:
├── img
├── include
	├── CONTROLE
		jogo.hpp
	├── Modelo
		peca.hpp
		tabuleiro.hpp
	├── View
		interface.hpp
├── src
	├── CONTROLE
		jogo.cpp
	├── Modelo
		peca.cpp
		tabuleiro.cpp
	├── View
		README.txt
		interface.cpp
├── documentos
	cartao_crc.md
	user_stories.md
.gitignore
Doxyfile
Makefile
README.md
arial.ttf
main.cpp


## Funcionalidades Implementadas

O projeto é dividido em Modelo, Controle e Visualização. 

A seção Modelo contém as classes “tabuleiro” e “peca”, além das subclasses de peca  “rainha”, “rei”, “peao”, “torre”, “bispo” e “cavalo”. Essas classes representam, no programa, os objetos físicos com os quais o jogo é jogado. 
Cada peça contém os dados privados “equipe” e “jaMoveu”, que podem ser acessados por funções públicas e a função virtual “verificarMovimento”, que valida, ou não, um movimento específico, segundo exclusivamente o modo como a peça específica se move. Além disso, o tipo da peça pode ser descoberto utilizando-se a função virtual “getTipoPeca”.
Já o tabuleiro contém o dado privado “matriz”, uma matriz 8x8 de ponteiros para peça, que representa o estado do tabuleiro em determinado instante, e que pode ser acessado por uma função pública. O construtor da classe é responsável por alocar a memória para as peças, já inicializando cada peça no seu lugar correto, e seu destrutor desaloca a memória.

Já a seção de visualização contém a classe interface, que encapsula todas as operações de desenho na tela. Seu construtor inicializa a janela, carrega a fonte padrão e as texturas, ambas presentes dentro do diretório padrão do projeto. A fonte é um dado privado da classe, assim como um mapa, que relaciona as strings de cada peça, a sua respectiva textura. Por último, a função pública “imprimirTabuleiro” imprime, na interface gráfica, o estado atual do tabuleiro.

A seção Controle atua como juiz do jogo, gerenciando os turnos de cada jogador, e a interação com o usuário, funcionalidades encapsuladas pela função pública “inicializarJogo”. Essa função utiliza diversas funções auxiliares,privadas, que, em geral, representam as regras do Xadrez. A função “ProcessarCoordenadas” transforma o input do usuário em coordenadas válidas, se possível. Se não for, retorna false.
 A função “casaAtacada” percorre a matriz do tabuleiro, verificando se alguma peça, de determinada equipe, tem um movimento válido para determinada casa, ou seja, se alguma peça “ataca” determinada casa, e retorna um bool. 
A função “validarMovimentoGeral” contém as regras gerais de movimentação do Xadrez, validando, ou não, determinado movimento. 
A função “MoverPeça” é responsável por executar determinado movimento, desalocando a memória se necessário, conforme as peças são capturadas. Contudo, uma validação ainda é feita nessa função, pois o movimento é revertido, se deixar o rei do próprio time em Xeque.
 A função “PromocaoPeao” gerencia a promoção de peões, “verificarXeque” verifica se o rei de determinada equipe está em xeque. A função “verificarMate” realiza simulações para verificar se o rei consegue, em caso de Xeque, fugir, ou se alguma peça amiga consegue bloquear o ataque. Se nenhum modo de evitar o ataque for encontrado, o Xeque-Mate foi atingido. Além disso, a função verifica possíveis afogamentos. A função “materialInsuficiente” avalia a condição de empate técnico por falta de peças para dar mate. Por último, as funções “nomeDaEquipe” e “numeroDaEquipe” retornam dados sobre uma equipe, com base no número turno_bruto, dado privado da classe. O bool “jogoAtivo” mantém o loop do jogo rodando, se verdadeiro. Se se torna falso, a partida termina.




## Instruções de uso e tratamento de exceções:

Após o processo de compilação e execução, o jogo começará. Seu funcionamento é híbrido, com o terminal e o display gráfico. O tabuleiro aparece, inicialmente, em seu estado padrão, na janela, e a seguinte mensagem aparece no terminal:

“Bem vindo ao Xadrez Virtual!
Por favor decida qual Jogador controlará as peças Brancas, e qual controlará as peças Pretas. O Jogador das peças Brancas começa jogando.
Jogador das peças Brancas, escolha das opções de Jogada, pelo número:
1 - Mover Peça
2 - Propor Empate
3 - Desistir” 

Após o aparecimento dessa mensagem, o jogador deve colocar o número 1, ou 2, ou 3, no terminal. Se qualquer outro input for colocado, a mensagem “Input Invalido. Escolha entre as opcoes 1, 2 ou 3.”, aparece, e outro input é pedido. Esse processo se repete, até o jogador colocar um input válido.
Se a opção 1 for a escolhida, a mensagem “Escolha o movimento desejado, no modelo "C1 C2" ”, aparece. Se o jogador colocar um input que não está nesse formato, a mensagem “Movimento Invalido. Digite outro movimento.” aparece. Se o input estiver neste formato, mas o movimento não for fisicamente possível no tabuleiro, a mensagem “Movimento Invalido. Essa casa esta vazia ou a peca pertence ao adversario.”, aparece. Além disso, em situações de possível Xeque, a mensagem "Movimento nao pode ser executado, pois deixa seu rei em xeque. Digite outro movimento." pode aparecer. Se o movimento é válido, a peça se movimenta no display do tabuleiro, e o turno passa para o jogador das peças pretas. A mensagem

“Jogador das peças Pretas, escolha das opções de Jogada, pelo número:
1 - Mover Peça
2 - Propor Empate
3 - Desistir”

aparece, e o processo descrito anteriormente é repetido para o outro jogador, em turnos, até o jogo acabar. Se um dos jogadores escolher a opção 3, a mensagem  “O Jogador das peças ______ desistiu. O Jogador das peças ______ Ganhou!” e o jogo se encerra. Se um dos jogadores escolher a opção do empate, a mensagem “O Jogador das peças ______ ofereceu um empate. Jogador das peças _____, deseja aceitar? (1-Sim / 2-Nao )” Se o jogador ao qual o empate foi pedido negar, a mensagem
 
“O Jogador das pecas Pretas nao aceitou o empate! Escolha entre:
1 - Mover Peça
3 - Desistir”

aparece, e um input é pedido. Se o jogador aceitar o empate, a mensagem “O Jogo terminou em Empate!” aparece, e o jogo termina. 
Durante o jogo, se o rei de algum dos jogadores for ameaçado, a mensagem "O Rei das peças _____ esta em xeque!”. Se um xeque-mate for atingido, a mensagem "O Rei das peças _____ esta em Xeque-Mate!. O Jogador das peças _____ Ganhou!", e o jogo se encerra. 
Além disso, outras situações são possíveis. Se em algum momento, as peças em campo não forem suficientes, para nenhum dos lados, para se chegar a um xeque mate, a mensagem "O jogo terminou em Empate, por material insuficiente! Nenhum dos jogadores possui peças suficientes no tabuleiro para forçar um Xeque-Mate.", e o jogo se encerra. O jogo também pode se encerrar por afogamento, com a mensagem "Afogamento! O Jogador das peças______ não possui movimentos legais, mas seu Rei não está em xeque. O jogo terminou em Empate!". Por último, se um dos jogadores chegar com o peão na primeira casa adversária, a seguinte mensagem aparece:

"Promoção de peão!
 Escolha a nova peça:
  1- Rainha
  2- Cavalo
  3- Bispo
  4- Torre", e um input é pedido.


## Documentação: 

Para se gerar a documentação Doxygen, deve-se garantir que o programa está instalado com o comando “sudo apt update && sudo apt install doxygen -y”. Após esse processo, o comando “doxygen Doxyfile” é inserido, para gerar a documentação. Para acessar a documentação, considerando-se WSL, o comando “explorer.exe .” deve ser inserido, e o arquivo principal pode ser acessado em “Projeto-PDS2---Xadrex\doc\html\index.html”



## Equipe: nomes e breve nota de contribuições

Davi Clark; Modelo (.cpp e .hpp) e Controle (.cpp), View (.cpp)
Bruno Prado:Modelo(.hpp) e Controle(.cpp e .hpp), View (.hpp e .cpp)

## Ciclo de Desenvolvimento (Sprints) e Aprendizados

Foi utilizado a metodologia SCRUM, maneira de organizar o que deve ser feito por meio de pequenos resultados chaves(Key results). Chamamos de sprint o período de desenvolvimento

 Linha do Tempo das Sprints

Sprint 1 (22/04 a 04/05) — Alinhamento inicial
Objetivo: Alinhamento, definição do tema do projeto e estruturação dos arquivos
Resultado chave: Criação do repositório no GitHub e definição das primeiras lógicas do jogo de xadrez.

Sprint 2 (05/05 a 11/05) — Modelagem e Contratos 
Objetivo: Estruturar a arquitetura abstrata do sistema antes de iniciar a codificação bruta.
Definição da divisão física das pastas (`include/` e `src/`).
Cartão CRC e levantamento de requisitos com User Stories.
Nessa etapa, a construção dos contratos foi feita de maneira conjunta de forma presencial (o que justifica termos commits concentrados em uma única conta da dupla nesta fase inicial).

Sprint 3 (12/05 a 18/05) — Arquitetura MVC
Objetivo:Organizar o código na nova arquitetura definida.
Marcos e Entregas:Após reunião com o professor, o escopo foi reajustado para adotar o padrão de arquitetura MVC (Model-View-Controller)

Sprint 4 (19/05 a 07/06) — Codificação e Ajustes Finais
Objetivo: Colocar o jogo para rodar com a interface gráfica e validar todas as regras difíceis do xadrez.
O que foi feito: Como dividimos o trabalho seguindo o padrão MVC, no começo cada um focou mais em uma parte (Modelo e Controle). Ambos contribuíram para a confecção de todos os arquivos, sendo feito a partir de encontros online e presencial, sendo corrigindo o código ou auxiliando na lógica por trás dos códigos. Após a finalização do código, iniciou-se a etapa de validação.

Sprint 5 (08/06 a 11/06)- Documentação.


## Planejamento x realizado 
Evolução da Arquitetura do Sistema:
  	Planejado: No início do projeto, a ideia era fazer um código mais direto, sem uma separação muito rígida de qual arquivo cuidaria de qual parte do jogo.
  	Realizado: Conforme o sistema foi crescendo, vimos que ia virar uma bagunça misturar regras com lógica visual. Além disso, após conversarmos com o professor, ficou definido que deveríamos seguir o padrão MVC (Model-View-Controller). Tivemos que reestruturar o projeto inteiro para separar o código estritamente em pastas de Modelo, Interface (View) e Controle.

Organização das Peças (Herança e Polimorfismo):
Planejado: A nossa primeira intenção era criar um arquivo separado para cada peça do jogo (um arquivo para o peão, um para o bispo, um para a torre, etc.).
Realizado:Percebemos que criar dezenas de arquivos `.h` e `.cpp` pequenos só para herdar da classe mãe ia deixar o gerenciamento do projeto confuso e o `Makefile` muito grande. Tomamos a decisão de centralizar a lógica e colocar as regras das subclasses dentro de arquivos unificados de Peça (`peca.h` e `peca.cpp`).Isso facilitou a aplicação do polimorfismo na matriz do tabuleiro.




