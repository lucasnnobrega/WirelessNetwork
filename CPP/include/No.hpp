#ifndef NO
#define NO

#include <string>

class No
{
private:
    int id;
    int tamanho;
    int x;
    int y;
    int duracao;
    int macDestino;
    std::string mensagem;

public:
    No(int id, int tamanho, int x, int y);
    ~No();
    void criarPacote(int duracao, int macDestino, std::string mensagem);
    void exibePacote(int macDestino, int id, std::string mensagem);
    int DebugNo();
};

#endif //NO
