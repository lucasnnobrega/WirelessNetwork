#ifndef PACOTE
#define PACOTE

#include <vector>
#include <iostream>
#include <string>
#include "Cabecalho.hpp"

class Pacote
{
protected:
    int id;                            //= -1;
    std::string dados;                 //= mensagem;
    int duracao;                       //= duracao;
    std::vector<Cabecalho> cabecalhos; // = {};

public:
    Pacote(int duracao, std::string mensagem);
    ~Pacote();
    static Pacote Pacote::CriaPacote(int duracao, std::string mensagem);
    Cabecalho Pacote::getCabecalho();
    int DebugPacote();
};

Pacote::Pacote(int duracao, std::string mensagem)
{
    //def __init__(self, mensagem, duracao):
    //        self._id = -1
    //        self._dados = mensagem
    //        self._duracao = duracao
    //        self._cabecalhos = []
    this->id = -1;           //= -1;
    this->dados = mensagem;  //= mensagem;
    this->duracao = duracao; //= duracao;
    this->cabecalhos = {};   // = {};
}

Pacote::~Pacote()
{
}

Pacote Pacote::CriaPacote(int duracao, std::string mensagem)
{
    //
    //# Retorna um pacote criado
    //   @staticmethod
    //   def criaPacote(mensage, duracao):
    //       return Pacote(mensage, duracao)
    ////   # Obtem cabeçalho da camada de rede

    return Pacote(duracao, mensagem);
}

Cabecalho Pacote::getCabecalho()
{
    //   def getCabecalhoRede(self):
    //       for cabecalho in self._cabecalhos:
    //           if(cabecalho._camada == "REDE"):
    //               return cabecalho
}

////   # Obtem cabeçalho da camada de enlace
//   def getCabecalhoEnlace(self):
//       for cabecalho in self._cabecalhos:
//           if(cabecalho._camada == "ENLACE"):
//               return cabecalho

Cabecalho Pacote::getCabecalhoEnlace()
{
}

////   # Adiciona novos cabeçalhos na lista
//   def addCabecalho(self, cabecalho):
//       self._cabecalhos.append(cabecalho)

void addCabecalho(Cabecalho cabecalho)
{
    this->cabecalhos = cabecalho;
}

void exibeInfoPacote()
{
    // Exibe as informações do pacote
    std::cout << "Dados" << dados;
}

////   #
//   def atualizaSequen(self, sequencia):
//       for cabecalho in self._cabecalhos:
//           if(cabecalho._camada == "REDE"):
//               cabecalho._sequenList = sequencia
//

void atualizaSequen(std::vector<int> sequencia)
{

    // Declaring iterator to a vector
    vector<int>::iterator ptr;

    // Displaying vector elements using begin() and end()
    for (ptr = cabecalhos.begin(); ptr < cabecalhos.end(); ptr++)
    {
        std::cout << ptr->camada << " ";

        if (strcmp(ptr->cabecalho, "REDE") == 0)
        {
            cabecalho
        }
    }

    return 0;
}

#endif //PACOTE
