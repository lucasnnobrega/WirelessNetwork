#ifndef CABECALHO
#define CABECALHO

#include <string>

class Cabecalho
{
private:
    std::string camada;
    int macOrigem;
    int macDestino;
    int numero;

public:
    Cabecalho(std::string camada, int macOrigem, int, macDestino, int numero, int requisicao, int sequenNum, int sequenList);
    ~Cabecalho();
};

Cabecalho::Cabecalho(std::string camada, int macOrigem, int, macDestino, int numero, int requisicao, int sequenNum, int sequenList)
{
    //# Cabeçario para a camada de enlace
    if (camada == "ENLACE")
    {
        self._camada = "ENLACE";
        self._macOrigem = macOrigem;
        self._macDestino = macDestino;
        self._numero = numero;

        // # Cabeçario para a camada de rede
        if (camada == "REDE"):
            self._camada = "REDE"
            self._macDestino = macDestino
           // # identifica tipos de pacote de controle, requisição
            self._requisicao = requisicao
            //# numero do pacote
            self._sequenNum = sequenNum
            //# endereço mac da camada fisica
            self._sequenList = sequenList
    }

    Cabecalho::~Cabecalho()
    {
    }

#endif // CABECALHO