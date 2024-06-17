#include <iostream>
#include <direct.h>
using namespace std;

int main()
{
    char curPath[100];

    getcwd(curPath, 100);
    // outputs the current working directory
    cout << curPath << endl;
    return 0;
}
