
#include "utilities.hpp"

using namespace std;

void Clear()
{
    if (system("clear") != 0)
    {
        cout << "Clear failed" << endl;
        exit (-1);
    }
}