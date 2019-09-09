#ifndef NO
#define NO

#include <string>

class No
{
private:
    /* data */
public:
    No(int id, int tamanho, int x, int y);
    ~No();
    void criarPacote(int duracao, int macDestino, std::string mensagem);
    void exibePacote(int macDestino, int id, int mensagem);
};

#endif //NO
