#include <iostream>
#include <fstream>
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
