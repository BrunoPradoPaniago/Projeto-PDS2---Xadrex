CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude/CONTROLE -Iinclude/MODELO -Iinclude/VIEW
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system


all: build/main.o build/jogo.o build/peca.o build/tabuleiro.o build/interface.o
	$(CXX) build/main.o build/jogo.o build/peca.o build/tabuleiro.o build/interface.o -o xadrez $(LDFLAGS)

build/main.o: main.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

build/jogo.o: src/CONTROLE/jogo.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c src/CONTROLE/jogo.cpp -o build/jogo.o

build/peca.o: src/MODELO/peca.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c src/MODELO/peca.cpp -o build/peca.o

build/tabuleiro.o: src/MODELO/tabuleiro.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c src/MODELO/tabuleiro.cpp -o build/tabuleiro.o

build/interface.o: src/VIEW/interface.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c src/VIEW/interface.cpp -o build/interface.o

# Regra para limpar os arquivos gerados
clean:
	rm -rf build/*.o xadrez