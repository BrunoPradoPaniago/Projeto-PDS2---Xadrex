#include "interface.hpp"
#include <iostream>

interface::interface() {
    // janela: 600x600 pixels, redimensionável
    janela.create(sf::VideoMode(600, 600), "Xadrez em C++", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
    
    //Esse trecho garante que a janela seja aberta do lado esquerdo do monitor, com espaço para o terminal, à direita.
    sf::VideoMode monitor = sf::VideoMode::getDesktopMode();
    int margemEsquerda = 50; // Deixa 50 pixels de respiro na margem esquerda
    int centroVertical = (monitor.height - 600) / 2; // Centraliza no eixo Y
    janela.setPosition(sf::Vector2i(margemEsquerda, centroVertical));
    
    // carrega a fonte, arquivo arial.ttf deve estar na pasta.
    if (!fonte.loadFromFile("arial.ttf")) {
        std::cout << "ERRO: Arquivo arial.ttf nao encontrado!" << std::endl;
    }

    carregarTexturas();
}

void interface::carregarTexturas() {
    //texturas das pecas brancas, baixadas de https://commons.wikimedia.org/wiki/Category:PNG_chess_pieces/Standard_transparent.
    texturas["peao_0"].loadFromFile("img/Chess_plt45.svg");
    texturas["torre_0"].loadFromFile("img/Chess_rlt45.svg");
    texturas["cavalo_0"].loadFromFile("img/Chess_nlt45.svg");
    texturas["bispo_0"].loadFromFile("img/Chess_blt45.svg");
    texturas["rainha_0"].loadFromFile("img/Chess_qlt45.svg");
    texturas["rei_0"].loadFromFile("img/Chess_klt45.svg");

    // textura das pecas pretas, baixadas de https://commons.wikimedia.org/wiki/Category:PNG_chess_pieces/Standard_transparent.
    texturas["peao_1"].loadFromFile("img/Chess_pdt45.svg");
    texturas["torre_1"].loadFromFile("img/Chess_rdt45.svg");
    texturas["cavalo_1"].loadFromFile("img/Chess_ndt45.svg");
    texturas["bispo_1"].loadFromFile("img/Chess_bdt45.svg");
    texturas["rainha_1"].loadFromFile("img/Chess_qdt45.svg");
    texturas["rei_1"].loadFromFile("img/Chess_kdt45.svg");
}

void interface::imprimirTabuleiro(tabuleiro& tab) {
    if (!janela.isOpen()) return;

    // mantem a janela responsiva
    sf::Event event;
    while (janela.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            janela.close();
        }
    }

    //fundo escuro para a margem
    janela.clear(sf::Color(40, 40, 40));

    // Tamanhos ajustados para janela de 600x600
    int tamanhoCasa = 75;      // 75*8 = 600
    int margemX = 0;           // sem margem horizontal
    int margemY = 0;           // sem margem vertical

    //desenha o tabuleiro e as pecas.
    for (int i = 0; i < 8; i++) {
        for (int i2 = 0; i2 < 8; i2++) {
            
            //calcula a posicao dos pixels na tela
            int x_pixel = margemX + (i2 * tamanhoCasa);
            int y_pixel = margemY + (i * tamanhoCasa);

            // desenha o quadrado da casa
            sf::RectangleShape casa(sf::Vector2f(tamanhoCasa, tamanhoCasa));
            casa.setPosition(x_pixel, y_pixel);

            // cores do tabuleiro
            if ((i + i2) % 2 == 0) {
                casa.setFillColor(sf::Color(238, 238, 210)); // Bege claro
            } else {
                casa.setFillColor(sf::Color(118, 150, 86));  // Verde musgo
            }
            janela.draw(casa);

            // desenha as pecas
            if (tab.getMatriz()[i][i2] != nullptr) {
                std::string tipo = tab.getMatriz()[i][i2]->getTipoPeca();
                int equipe = tab.getMatriz()[i][i2]->getEquipe();

                std::string chaveTextura = tipo + "_" + std::to_string(equipe);

                // aplica a textura no sprite e desenha
                sf::Sprite spritePeca;
                spritePeca.setTexture(texturas[chaveTextura]);
                
                // escala o png para a casa de 75x75
                spritePeca.setScale(
                    (float)tamanhoCasa / texturas[chaveTextura].getSize().x,
                    (float)tamanhoCasa / texturas[chaveTextura].getSize().y
                );

                spritePeca.setPosition(x_pixel, y_pixel);
                janela.draw(spritePeca);
            }
        }
    }

    //desenha as coordenadas (A a H, 1 a 8)
    for (int i = 0; i < 8; i++) {
        
        // letras A a H na parte debaixo
        sf::Text letra;
        letra.setFont(fonte);
        letra.setString(std::string(1, 'A' + i)); 
        letra.setCharacterSize(20); 
        letra.setFillColor(sf::Color::White);
        // Posiciona no meio da casa inferior (considerando 75px de largura)
        letra.setPosition(margemX + (i * tamanhoCasa) + 28, 580); // y = 580 (600-20)
        janela.draw(letra);

        // numeros 1 a 8 à esquerda
        sf::Text numero;
        numero.setFont(fonte);
        numero.setString(std::to_string(8 - i)); 
        numero.setCharacterSize(20);
        numero.setFillColor(sf::Color::White);
        numero.setPosition(5, margemY + (i * tamanhoCasa) + 28);
        janela.draw(numero);
    }

    //atualiza a tela
    janela.display(); 
}