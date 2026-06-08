#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "tabuleiro.hpp"

/**
 * @file interface.hpp
 * @brief Definição da classe interface e gerenciamento gráfico do xadrez com a biblioteca SFML.
 */

/**
 * @class interface
 * @brief Responsável pela renderização gráfica do tabuleiro e das peças.
 *
 * A classe interface encapsula todas as operações de desenho na tela.
 * Ela gerencia a janela do sistema operacional, o armazenamento das 
 * texturas das peças na memória de vídeo e a atualização visual a cada 
 * turno da partida, utilizando a biblioteca externa SFML.
 */
class interface {
private:
    /**
     * @brief Janela principal de renderização do jogo.
     */
    sf::RenderWindow janela;
    
    /**
     * @brief Dicionário para armazenar as texturas (imagens) das peças.
     * * As chaves são strings compostas pelo nome da peça e sua equipe (ex: "peao_0").
     * Isso evita recarregar a mesma imagem múltiplas vezes.
     */
    std::map<std::string, sf::Texture> texturas;
    
    /**
     * @brief Fonte de texto utilizada para desenhar as coordenadas (A-H, 1-8).
     */
    sf::Font fonte;

    /**
     * @brief Carrega os arquivos de imagem para o dicionário de texturas.
     * * Método auxiliar privado chamado automaticamente durante a construção 
     * da classe para preparar o banco de imagens.
     */
    void carregarTexturas();

public:
    /**
     * @brief Construtor padrão da interface.
     * * Inicializa a janela com resolução 600x600, a centraliza de acordo com 
     * a resolução do monitor do usuário, carrega a fonte padrão e executa a 
     * função de carregar texturas.
     */
    interface();

    /**
     * @brief Desenha todo o estado atual do jogo na tela.
     * * Limpa a janela, redesenha as casas verdes e beges do tabuleiro, 
     * imprime as coordenadas nas margens e posiciona as peças nos seus 
     * respectivos pixels baseando-se na matriz de ponteiros.
     * @param tab Referência para o tabuleiro que contém as posições atuais das peças.
     */
    void imprimirTabuleiro(tabuleiro& tab);
};

#endif