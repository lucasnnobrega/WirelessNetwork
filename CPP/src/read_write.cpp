#include <iostream>
//#include <fstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <memory>

#include "../include/read_write.h"

using namespace std;

// Driver function to sort the 2D vector
// on basis of a particular column
bool sortByH(const vector<int> &v1,
             const vector<int> &v2)
{
  return v1[2] < v2[2];
}

void draftToLogger(IloModel modelo,
                   IloArray<IloArray<IloBoolVarArray>> y,
                   IloCplex cplex,
                   int number_of_symbols,
                   int n,
                   int TMAX,
                   int *M,
                   int *priorities,
                   IloIntVarArray D,
                   char verbose)
{
  IloEnv env = modelo.getEnv();

  vector<vector<int>> sequence;
  int a = 0;

  for (int i = 0; i < n; i++)
  { // 2 == n
    for (int k = 0; k < M[i]; k++)
    {
      for (int h = 0; h < TMAX - k; h++)
      {
        //cplex.out() << " OUT = " << cplex.getValue(y[i][k][h]) << endl;
        // If the value is equal to 1, save in the sequence vector
        //if (verbose == 'v')
        //  cplex.out() << cplex.getValue(y[i][k][h]);
        if (cplex.getValue(y[i][k][h]) == 1)
        //if (a < 4)
        {
          vector<int> aux;
          aux.push_back(i);
          aux.push_back(k);
          aux.push_back(h);

          sequence.push_back(aux);
          a++;
        }
      }
    }
  }

  if (verbose == 'v')
    cout << endl
         << endl
         << endl;

  sort(sequence.begin(), sequence.end(), sortByH);

  Write_content content;

  content.objective = cplex.getObjValue();

  content.number_of_symbols = number_of_symbols; // OK

  content.TMAX = TMAX;

  int aux = 0;
  for (auto i = sequence.begin(); i < sequence.end(); i++)
  {
    aux++;
  }

  content.occupied_positions = aux; //OK sequence.size()

  content.total_positions = TMAX; // OK

  content.avaliable_copies = M; // OK Max number of copies of symbol x_i € X

  content.sequence = sequence;

  /***************************************************************************/
  // Array that storage the number of used copies of a symbol
  int used_copies[n];

  // First create a empty vector with only zeros
  for (int i = 0; i < n; i++)
  {
    used_copies[i] = 0;
  }

  // Add one to the usage value
  for (int i = 0; i < sequence.size(); i++)
  {
    // i = [i, k, h]
    // i = [x_i, k-th copy, h position]
    used_copies[sequence[i][0]]++;
  }
  content.used_copies = used_copies;
  /***************************************************************************/

  content.priorities = priorities; // OK

  /***************************************************************************/
  // Distância Inicial
  int Di[n];
  for (int i = 0; i < n; i++)
  {
    Di[i] = 0;
  }
  content.Di = Di; // Still a doubt
  /***************************************************************************/
  // Df == D_i ?
  // Maior distancia entre 2 copias consecutivas
  int Df[n];
  for (int i = 0; i < n; i++)
  {
    Df[i] = cplex.getValue(D[i]);
  }
  content.Df = Df;
  /***************************************************************************/

  writeOutput(verbose, content);
  writeOutputCustom(verbose, content);
}

int write(char verbose)
{
  if (verbose == 'v')
    std::cout << "Criado o arquivo" << std::endl;

  ofstream myfile;
  myfile.open("./data/example.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();
  return 0;
}

//File_content *read_instances(const char *relative_file_path, char verbose)
File_content *read_instances(string relative_file_path, char verbose)
{
  string linhas[5];

  File_content *content;
  content = (File_content *)malloc(sizeof(File_content));

  //TODO: colocar o nome das instancias dinamico
  ifstream myfile(relative_file_path);
  if (myfile.is_open())
  {
    int count = 4;
    for (int i = 0; i < count; i++)
    {
      getline(myfile, linhas[i]);
      if (verbose == 'v')
        cout << "Linha: " << linhas[i] << '\n';
    }
    if (verbose == 'v')
      cout << "\n\n";

    int number_of_symbols = stoi(linhas[0]);
    int m = linhas[1][0] - '0';

    int *myarray = new int[sizeof(linhas[2]) * 2];
    int *myarray_clean = new int[sizeof(linhas[2]) * 2];
    int *myarray_final = new int[number_of_symbols];
    string to_compare = " ";

    for (int i = 0; i < linhas[2].length(); i++)
    {
      myarray[i] = linhas[2][i] - '0';
    }

    if (verbose == 'v')
    {
      cout << "\n\n\n";
      cout << "##########################################" << endl;
      cout << "linhas[2].length(): " << linhas[2].length() << endl;
    }

    int numDigits = 0;
    for (int i = 0; i < linhas[2].length(); i++)
    {
      if (verbose == 'v')
      {
        cout << "Iteration n: " << i << endl;
        cout << GREEN << "HEAD: " << RESET << myarray[i] << endl;
      }

      string compose_num_str;
      //bool bigger_number = false;
      while (myarray[i] >= 0)
      {
        //compose_num_str.push_back(myarray[numDigits]);
        compose_num_str.push_back(linhas[2][i]);
        if (verbose == 'v')
        {
          cout << "myarray[i]: " << myarray[i] << endl;
          cout << "i: " << i << " compose_num_str: " << compose_num_str << endl;
        }
        i++;
        numDigits++;
        //bigger_number = true;
      }
      myarray_clean[i - numDigits] = stoi(compose_num_str);

      if (verbose == 'v')
      {
        cout << "myarray_clean[i]: " << myarray_clean[i];
        cout << endl
             << endl;
      }
    }
    if (verbose == 'v')
    {
      cout << "##########################################" << endl;

      cout << "myarray_clean[i]: ";
      for (int i = 0; i < linhas[2].length(); i++)
      {
        cout << myarray_clean[i] << " ";
      }
      cout << "\nmyarray_final[i]: ";
    }
    for (int i = 0; i < number_of_symbols; i++)
    {
      myarray_final[i] = myarray_clean[i];

      if (verbose == 'v')
      {
        cout << myarray_clean[i] << " ";
      }
    }

    if (verbose == 'v')
      cout << "\nend iteration" << endl
           << endl
           << endl;

    for (int i = 0; i < linhas[2].length(); i++)
    {
      if (verbose == 'v')
        cout << "counter: " << i << " number: " << myarray[i] << " new " << myarray_clean[i] << '\n';
    }

    if (verbose == 'v')
    {
      cout << "\n\n############################\n\nLast For:\n";
      for (int i = 0; i < number_of_symbols; i++)
      {
        cout << "counter: " << i << " number: " << myarray[i] << " new " << myarray_clean[i] << '\n';
      }
    }

    free(myarray);
    free(myarray_clean);

    if (verbose == 'v')
    {
      cout << "\n\n############################\n\nOthers Values:\n";
      cout << "Number of symbols: " << number_of_symbols << endl;
      cout << "Number m: " << m << endl;
    }

    content->number_of_symbols = number_of_symbols;
    content->m = m;
    content->priorities = myarray_final;

    myfile.close();
  }
  else
  {
    cout << "Unable to open file";
    exit(1);
  }

  return content;
}

File_content *read_instances_clean(string relative_file_path, char verbose)
{
  int number_of_symbols;
  int m;

  ifstream entrada(relative_file_path);
  entrada >> number_of_symbols;
  entrada >> m;

  int priorities[number_of_symbols];

  for (int i = 0; i < number_of_symbols; i++)
  {
    entrada >> priorities[i];
  }

  std::cout << "\n\nTeste com função nova" << std::endl;

  for (int j = 0; j < number_of_symbols; j++)
  {
    cout << " |priority " << priorities[j];
  }

  cout << endl;

  File_content *content;
  content = (File_content *)malloc(sizeof(File_content));

  content->number_of_symbols = number_of_symbols;
  content->m = m;
  content->priorities = priorities;

  return content;
}

int writeOutput(char verbose, Write_content content_to_write)
{

  int objective = content_to_write.objective;
  int number_of_symbols = content_to_write.number_of_symbols;
  int TMAX = content_to_write.TMAX;
  int occupied_positions = content_to_write.occupied_positions;
  int total_positions = content_to_write.total_positions;
  vector<vector<int>> sequence = content_to_write.sequence;
  int *avaliable_copies = content_to_write.avaliable_copies;
  int *used_copies = content_to_write.used_copies;
  int *priorities = content_to_write.priorities;
  int *Di = content_to_write.Di;
  int *Df = content_to_write.Df;

  if (verbose == 'v')
  {
    std::cout << GREEN << "Inside Write function" << RESET << endl;
    std::cout << "Lista de variáveis:       " << endl;
    std::cout << " objective                " << objective << endl;
    std::cout << " number_of_symbols        " << number_of_symbols << endl;
    std::cout << " TMAX                     " << TMAX << endl;
    std::cout << " occupied_positions       " << occupied_positions << endl;
    std::cout << " total_positions          " << total_positions << endl;
    std::cout << " VECTOR: sequence         " << endl;
    std::cout << " ARRAY: avaliable_copies  " << avaliable_copies << endl;
    std::cout << " ARRAY: used_copies       " << used_copies << endl;
    std::cout << " ARRAY: priorities        " << priorities << endl;
    std::cout << " ARRAY: Di                " << Di << endl;
    std::cout << " ARRAY: Df                " << Df << endl;
  }

  ofstream myfile;
  myfile.open("./data/res_lnn.txt");

  for (int i = 1; i < number_of_symbols; i++)
  {
    myfile << "Number" << i << "\n";
  }

  myfile << "\n**********************************************\n";
  myfile << "Objective: " << objective << "\n\n";

  // HELP PLEASE
  myfile << "Sequence:\n";
  for (int i = 0; i < TMAX; i++)
  {
    if (i < sequence.size())
    {
      myfile << sequence[i][0] + 1 << " - ";
      if (verbose == 'v')
        cout << sequence[i][0] + 1 << "-";
    }
    else
    {
      myfile << "*"
             << " - ";
      if (verbose == 'v')
        cout << "*"
             << " - ";
    }
  }
  myfile << "\n\n";

  myfile << "Occupied positions: " << occupied_positions << " of " << total_positions << "\n\n";

  for (int i = 0; i < number_of_symbols; i++)
  {
    myfile << "symbol " << i + 1 << "--> Priority:  " << priorities[i]
           << ", Di:  " << Di[i] << ", Df:  " << Df[i] << ", Pi: " << priorities[i] * Di[i] << ", Pf: " << priorities[i] * Df[i] << "\n";
  }

  myfile << "\n(Available copies, Used copies)\n";

  for (int i = 0; i < number_of_symbols; i++)
  {
    myfile << "symbol " << i + 1 << " -->  " << avaliable_copies[i] << ",  " << used_copies[i] << "\n";
  }

  myfile << "\n**********************************************\n";
  myfile.close();
  return 0;
}

int writeOutputCustom(char verbose, Write_content content_to_write)
{

  int objective = content_to_write.objective;
  int number_of_symbols = content_to_write.number_of_symbols;
  int occupied_positions = content_to_write.occupied_positions;
  int total_positions = content_to_write.total_positions;
  vector<vector<int>> sequence = content_to_write.sequence;
  int *avaliable_copies = content_to_write.avaliable_copies;
  int *used_copies = content_to_write.used_copies;
  int *priorities = content_to_write.priorities;
  int *Di = content_to_write.Di;
  int *Df = content_to_write.Df;

  ofstream myfile;
  myfile.open("./data/custom_output.txt");
  myfile << "MY COMMENTS:\n\n";

  myfile << "Sequence in the program:\n";
  myfile << "i - k - h"
         << "\n";
  for (int i = 0; i < sequence.size(); i++)
  {
    myfile << sequence[i][0] << " - " << sequence[i][1] << " - " << sequence[i][2] << "\n";
  }

  myfile << "\nSequence in the mathematical format:\n";
  myfile << "(i+1) - (k+1) - (h+1)\n";
  for (int i = 0; i < sequence.size(); i++)
  {
    myfile << "  " << sequence[i][0] + 1 << "   -   " << sequence[i][1] + 1 << "   -   " << sequence[i][2] + 1 << "\n";
  }

  myfile << "\nSequence in the mathematical format for CSV:\n";
  myfile << "(i+1),(k+1),(h+1),\n";
  for (int i = 0; i < sequence.size(); i++)
  {
    myfile << sequence[i][0] + 1 << "," << sequence[i][1] + 1 << "," << sequence[i][2] + 1 << "\n";
  }

  myfile.close();
  return 0;
}