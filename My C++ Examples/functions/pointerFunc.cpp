#include <iostream>
#include <sstream>
#include <random>
using namespace std;

string *getSecretCode()
{
    string *code = new string;
    ostringstream converter;

    code->append("CR");
    int randomNum = rand();
    converter << randomNum;
    code->append(converter.str());
    code->append("NQ");

    return code;
}

int main()
{
    srand(time(0));
    string *newCode;

    for (int i = 0; i < 10; i++)
    {
        newCode = getSecretCode();
        cout << *newCode << endl;
        delete newCode;
        newCode = nullptr;
    }

    return 0;
}