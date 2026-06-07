#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "tabuleiro.hpp"

class interface {
private:
    sf::RenderWindow janela;
    std::map<std::string, sf::Texture> texturas;
    sf::Font fonte;

    
    void carregarTexturas();

public:
    interface();

    
    void imprimirTabuleiro(tabuleiro& tab);
};

#endif