#ifndef CAMADAFISICA
#define CAMADAFISICA

#include <iostream>
#include <vector>

class CamadaFisica
{
protected:
    int x;
    int y;
    int id;
    int tamanho;
    std::vector<int> vizinhos = {};
    std::vector<Pacote> pacotesEnviados = {};
    std::vector<Pacote> pacotesRecebidos = {};
    std::vector<Pacote> pacotesSalvos = {};

public:
    CamadaFisica(int x, int y, int id, int tamanho);
    ~CamadaFisica();
    encontraVizinhos();
    void recebePacote(int pacote);
    void enviaPacote();
    int DebugCamadaFisica();
};

CamadaFisica::CamadaFisica(int x, int y, int id, int tamanho)
{
    this->x = x;
    this->y = y;
    this->id = id;
    this->tamanho = tamanho;
}

CamadaFisica::~CamadaFisica()
{
}

CamadaFisica::DebugCamadaFisica()
{
    std::cout << "x" << x;
    std::cout << "y" << y;
    std::cout << "id" << id;
    std::cout << "tamanho" << tamanho;
    std::cout << "vizinhos" << vizinhos;
    std::cout << "pacotesEnviados" << pacotesEnviados;
    std::cout << "pacotesRecebidos" << pacotesRecebidos;
    std::cout << "pacotesSalvos" << pacotesSalvos;
}

#endif //CAMADAFISICA
