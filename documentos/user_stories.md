Relatório de Desenvolvimento - E5

1. User Stories (Requisitos Funcionais)

  US01 - Inicialização do Sistema: Como jogador, quero que o tabuleiro seja gerado com as peças nas posições corretas para que eu possa iniciar uma partida válida imediatamente.
  
  US02 - Movimentação e Validação: Como jogador, quero que o sistema valide se o meu movimento é legal pelas regras do xadrez para que eu não faça jogadas impossíveis por engano.
  
  US03 - Captura e Desempenho: Como jogador, quero que as peças adversárias capturadas sejam deletadas da memória para que o jogo continue leve e sem travamentos (prevenção de memory leaks).
  
  US04 - Condições de Fim de Jogo: Como jogador, quero ser notificado visualmente sobre situações de Xeque e Xeque-Mate para que eu saiba quando preciso defender meu Rei ou quando a partida acabou.
  
  US05 - Interface de Usuário: Como jogador, quero inserir comandos no terminal e receber um feedback em uma interface gráfica para que a minha experiência de jogo seja fluida e visualmente clara.


2. Modelagem CRC

  1. Peça:
  Responsabilidades: Saber se o movimento é valido, segundo sua forma de movimentação. 
  Colaboradores: -

  2. Tabuleiro:
  Responsabilidades: Matriz 8x8, peças nas posiçoes corretas, alocar e desalocar memória das peças.
  Colaboradores: peça

  3. Jogo:
  Responsabilidades: Controlar as jogadas, receber as jogadas do usuario, controlar as regras do Xadrez, condições de fim de jogo(vitoria, derrota, xeque mate)
  Colaboradores: tabuleiro, peça e interface.

  4. Interface:
  Responsabilidades: Controlar o display do tabuleiro e suas texturas. 
  Colaboradores: tabuleiro, peça


  5. Subclasses:
    Peao:
      Responsabilidade: Validar movimento (1 casa, 2 casas, capturar em diagonal)
      Colaboradores: -
    Cavalo:
      Responsabilidade:Movimento em L
      Colaboradores: -
    Rainha
      Responsabilidade: Movimento em diagonal, ou em linha reta.
      Colaboradores: -
    Bispo:
      Responsabilidade:Movimento em diagonal 
      Colaboradores: -
    Torre: 
      Responsabilidade:Movimentos em linha reta, guardar se a torre ja foi usada (Roque)
      Colaboradores: -
    Rei:
      Responsabilidade:Movimento de 1 casa, Roque
      Colaboradores: -

