#include <iostream>
using namespace std;

// Global variables are accessible from anywhere in the program
int global = 100;

void incrementGlobal()
{
    global++;
    cout << global << endl;
}

int main()
{
    cout << global << endl;
    int outer = 10;
    int inner = 5;

    {
        cout << "Entering inner scope" << endl;
        // inner is only accessible in this scope
        int inner = 20;
        cout << inner << endl;
        cout << outer << endl;
        cout << global << endl;
        cout << "Leaving inner scope" << endl;
    }

    // Even though there is an inner variable in the inner scope, the outer variable is still accessible
    // This allows us to have variables with the same name in different scopes
    cout << inner << endl;
    incrementGlobal();

    return 0;
}