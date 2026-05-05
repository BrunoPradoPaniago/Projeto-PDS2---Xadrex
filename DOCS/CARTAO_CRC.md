#Classes: 
1- Peça
2- Tabuleiro
3- Jogo 
4- Subclasses (Peao, cavalo, rainha, bispo, torre, rei)

##1-Peça: 
	Responsabilidades: Saber posiçao, saber se o movimento é valido
	Colaboradores: tabuleiro

##2-Tabuleiro:
	Responsabilidades: Matriz 8x8, peças nas posiçoes corretas, movimento, eliminar peças deletadas
	Colaboradores: peça
##3-Jogo:
	Responsabilidades: Controlar as jogadas, receber as jogadas do usuario, condiçoes de fim de jogo(vitoria, derrota, xeque mate)
	Colaboradores: tabuleiro e peça
##4-Subclasses:
	Peao: 
	Responsabilidade: Validar movimento (1 casa, 2 casas, capturar em diagonal, promoçao de peça)
	Colaboradores: Tabuleiro 

	Cavalo:
	Responsabilidade:Movimento em L, pular peças
	Colaboradores: Tabuleiro

	Rainha
	Responsabilidade: Torre + Bispo (movimento)
	Colaboradores: Tabuleiro

	Bispo:
	Responsabilidade:Movimento em diagonal 
	Colaboradores: Tabuleiro

	Torre: 
	Responsabilidade:Movimentos em linha reta, guardar se a torre ja foi usada (Roque)
	Colaboradores: Tabuleiro

	Rei:
	Responsabilidade:Movimento de 1 casa, armazenar se ja foi usado (Roque)
	Colaboradores: Tabuleiro
