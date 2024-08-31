#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    vector<string> MyData;
    MyData.push_back("One");
    MyData.push_back("Two");
    MyData.push_back("Three");

    ofstream outfile("MyData.txt");
    for (string x : MyData)
    {
        outfile << x << endl;
    }

    outfile.close();
    cout << "File Written!" << endl;
    return 0;
}