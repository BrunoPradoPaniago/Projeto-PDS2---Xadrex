#include<vector>
#include<pecas.hpp>

using std::vector;

class tabuleiro{
    public:
    //Construtor de tabuleiro. Aloca a memoria das pecas
    // e cria a matriz ja com as pecas no lugar certo. 
    tabuleiro();

    //destrutor de tabuleiro, desaloca a memoria das pecas.
    ~tabuleiro();

    bool estaEmXeque(int equipe);

    bool estaEmMate(int equipe);

    vector<vector<peca*>> matriz{8, vector<peca*>(8, nullptr)};
};