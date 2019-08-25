
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

using namespace std;

int main(int argc, const char **argv)
{

    // Parser for the variable input
    ArgumentParser parser;
    parser.addArgument("-v", "--verbose", 1, false);
    parser.addArgument("-i", "--input", 1, false);
    // parse the command-line arguments
    parser.parse(argc, argv);
    string verbose = parser.retrieve<string>("verbose");
    string relative_file_path = parser.retrieve<string>("input");
    char verbose_char_read_instances = verbose[0];
    char verbose_char_WFSP = verbose[1];

    cout << "Eu odieio minha vida" << endl;

    return 0;
}