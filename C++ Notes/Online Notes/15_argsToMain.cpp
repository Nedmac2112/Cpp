#include <iostream>
using namespace std;

int main(int argc, char *argv[]) // char **argv is equivalent to char *argv[]
{
    cout << "Number of arguments: " << argc << endl;
    for (int i = 0; i < argc; i++)
    {
        cout << "Argument " << i << ": " << argv[i] << endl;
    }

    // See "My C++ Examples\fun\calculator.cpp" for a more complex example
    return 0;
}