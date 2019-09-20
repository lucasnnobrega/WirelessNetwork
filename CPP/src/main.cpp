
// TODO: Coisas A fazer
//// Coisas completamente erradoas
//? perguntas a serem solucionadas
//! possiveis erros de dar merda
// comentario normal
//* comentario mais claro

#include <iostream>
#include <math.h>

#include "../include/constantes.hpp"
#include "../include/argparser.hpp"
#include "../include/funcDistancia.hpp"
#include "../include/Cabecalho.hpp"

using namespace std;

int main(int argc, const char **argv)
{

    // Parser for the variable input
    ArgumentParser parser;
    parser.addArgument("-v", "--verbose", 1, false);

    // parse the command-line arguments
    parser.parse(argc, argv);

    string verbose = parser.retrieve<string>("verbose");

    char verbose_char = verbose[0];

    cout << GREEN << "\n\nInside the main function" << RESET << endl;
    cout << "  verbose:            " << verbose << endl;

    cout << "Alcance (Função distância): " << alcance(1, 1, 3, 2, 2) << endl;

    // Testando Cabeçalho
    Cabecalho Enlace = Cabecalho("ENLACE", 12, 23, 34, 0, 0, 0);
    Enlace.DebugCabecalho();

    cout << endl;

    Cabecalho Rede = Cabecalho("REDE", 0, 23, 34, 45, 56, 67);
    Rede.DebugCabecalho();

    // Testando Cabeçalho

    return 0;
}