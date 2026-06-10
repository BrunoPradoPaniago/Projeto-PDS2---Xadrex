\#Classes:
1- Peça
2- Tabuleiro
3- Jogo
4- Interface
5- Subclasses (Peao, cavalo, rainha, bispo, torre, rei)

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


