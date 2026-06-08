#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include <vector>
#include "peca.hpp"

/**
 * @file tabuleiro.hpp
 * @brief Definição da classe tabuleiro e gerenciamento das posições do jogo.
 */

/**
 * @class tabuleiro
 * @brief Representa o tabuleiro de xadrez e controla a matriz de peças.
 *
 * Esta classe gerencia uma matriz 8x8 de ponteiros para peças, que representa
 * o estado atual do jogo. É responsável por alocar dinamicamente a memória das
 * peças no início do jogo, e desalocar a memória ao final do jogo.
 */
class tabuleiro {
    public:
    
    /**
     * @brief Construtor de tabuleiro.
     * * Aloca dinamicamente a memória das peças e constrói a matriz, 
     * já inicializando cada peça no seu lugar correto, de acordo com as regras.
     */
    tabuleiro();

    /**
     * @brief Destrutor do tabuleiro.
     * * Percorre a matriz e desaloca a memória de todas as peças vivas,
     * garantindo que não ocorra vazamento de memória.
     */
    ~tabuleiro();

    /**
     * @brief Retorna o estado atual da matriz do tabuleiro.
     * * @return std::vector<std::vector<peca*>>& Referência para a matriz 8x8 contendo ponteiros para as peças.
     */
    std::vector<std::vector<peca*>>& getMatriz();

    private:

    /**
     * @brief Estrutura de dados principal de tabuleiro.
     * * Matriz 8x8 de ponteiros para a classe peca. As casas sem peça
     * presente são inicializadas com ponteiro nulo (nullptr).
     */
    std::vector<std::vector<peca*>> matriz{8, std::vector<peca*>(8, nullptr)}; 
    
};
#endif