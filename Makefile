FLAGS = -std=c++17 -Iinclude/CONTROLE -Iinclude/MODELO -Iinclude/VIEW
LIBS = -lsfml-graphics -lsfml-window -lsfml-system


all: build/main.o build/jogo.o build/peca.o build/tabuleiro.o build/interface.o
	g++ build/main.o build/jogo.o build/peca.o build/tabuleiro.o build/interface.o -o xadrez $(LIBS)

build/main.o: main.cpp
	@mkdir -p build
	g++ $(FLAGS) -c main.cpp -o build/main.o

build/jogo.o: src/CONTROLE/jogo.cpp
	@mkdir -p build
	g++ $(FLAGS) -c src/CONTROLE/jogo.cpp -o build/jogo.o

build/peca.o: src/MODELO/peca.cpp
	@mkdir -p build
	g++ $(FLAGS) -c src/MODELO/peca.cpp -o build/peca.o

build/tabuleiro.o: src/MODELO/tabuleiro.cpp
	@mkdir -p build
	g++ $(FLAGS) -c src/MODELO/tabuleiro.cpp -o build/tabuleiro.o

build/interface.o: src/VIEW/interface.cpp
	@mkdir -p build
	g++ $(FLAGS) -c src/VIEW/interface.cpp -o build/interface.o

clean:
	rm -rf build/*.o xadrez

run: all
	./xadrez