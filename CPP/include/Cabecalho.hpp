#ifndef CABECALHO
#define CABECALHO

#include <string>
#include <iostream>

class Cabecalho
{
protected:
    std::string camada = "";
    int macOrigem = 0;
    int macDestino = 0;
    int numero = 0;
    int requisicao = 0;
    int sequenNum = 0;
    int sequenList = 0;

public:
    Cabecalho(std::string camada, int macOrigem, int macDestino, int numero, int requisicao, int sequenNum, int sequenList);
    ~Cabecalho();
    int DebugCabecalho();
};

#endif // CABECALHO