#ifndef _READ_WRITE
#define _READ_WRITE

#include <vector>

#define GREEN "\e[32m"
#define RED "\e[31m"
#define RESET "\e[0m"

using namespace std;

int write(char verbose);

bool sortByH(const vector<int> &v1, const vector<int> &v2);

#endif // read_write