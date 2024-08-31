#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    cout << "Number of command-line arguments: " << argc << endl;

    cout << "The arguments are:" << endl;
    for (int i = 0; i < argc; i++)
    {
        cout << "Argument " << i << ": " << argv[i] << endl;
    }

    return 0;
}
