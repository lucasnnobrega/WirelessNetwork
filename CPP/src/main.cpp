
// TODO: Coisas A fazer
//// Coisas completamente erradoas
//? perguntas a serem solucionadas
//! possiveis erros de dar merda
// comentario normal
//* comentario mais claro

#include <iostream>
#include <math.h>

#include "../include/read_write.h"
#include "../include/argparser.hpp"
#include "../include/funcDistancia.hpp"

using namespace std;

int main(int argc, const char **argv)
{

    // Parser for the variable input
    ArgumentParser parser;
    parser.addArgument("-v", "--verbose", 1, false);
    parser.addArgument("-a", "--ator", 1, false);

    // parse the command-line arguments
    parser.parse(argc, argv);

    string verbose = parser.retrieve<string>("verbose");
    string ator = parser.retrieve<string>("ator");

    char verbose_char_read_instances = verbose[0];

    cout << GREEN << "\n\nInside the main function" << RESET << endl;
    cout << "  verbose:            " << verbose << endl;
    cout << "  ator:            " << ator << endl;
    cout << "Alcance: " << alcance(1, 1, 3, 2, 2) << endl;

    return 0;
}