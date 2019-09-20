#include "../include/Cabecalho.hpp"

Cabecalho::Cabecalho(std::string camada, int macOrigem, int macDestino, int numero, int requisicao, int sequenNum, int sequenList)
{
    //# Cabeçalho para a camada de enlace
    if (camada == "ENLACE")
    {
        this->camada = "ENLACE";
        this->macOrigem = macOrigem;
        this->macDestino = macDestino;
        this->numero = numero;
    }

    // # Cabeçario para a camada de rede
    if (camada == "REDE")
    {
        this->camada = "REDE";
        this->macDestino = macDestino;
        // # identifica tipos de pacote de controle, requisição
        this->requisicao = requisicao;
        //# numero do pacote
        this->sequenNum = sequenNum;
        //# endereço mac da camada fisica
        this->sequenList = sequenList;
    }
}

Cabecalho::~Cabecalho()
{
}

int Cabecalho::DebugCabecalho()
{
    std::cout << "Testando classe cabecalho: " << std::endl;
    std::cout << "  camada  " << camada << std::endl;
    std::cout << "  macOrigem  " << macOrigem << std::endl;
    std::cout << "  macDestino  " << macDestino << std::endl;
    std::cout << "  numero  " << numero << std::endl;
    std::cout << "  requisicao  " << requisicao << std::endl;
    std::cout << "  sequenNum  " << sequenNum << std::endl;
    std::cout << "  sequenList  " << sequenList << std::endl;
}