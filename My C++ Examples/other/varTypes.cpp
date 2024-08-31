#include <iostream>
#include <limits>
using namespace std;

template <typename T>
void printTypeInfo(const string &typeName)
{
    cout << "Type: " << typeName << endl;
    cout << "Size: " << sizeof(T) << " bytes" << endl;
    cout << "Minimum value: " << +std::numeric_limits<T>::min() << endl;
    cout << "Maximum value: " << +std::numeric_limits<T>::max() << endl;
    cout << endl;
}

int main()
{
    printTypeInfo<bool>("bool");
    printTypeInfo<char>("char");
    printTypeInfo<unsigned char>("unsigned char");;
    printTypeInfo<short>("short");
    printTypeInfo<unsigned short>("unsigned short");
    printTypeInfo<int>("int");
    printTypeInfo<unsigned int>("unsigned int");
    printTypeInfo<long>("long");
    printTypeInfo<unsigned long>("unsigned long");
    printTypeInfo<long long>("long long");
    printTypeInfo<unsigned long long>("unsigned long long");
    printTypeInfo<float>("float");
    printTypeInfo<double>("double");
    printTypeInfo<long double>("long double");

    return 0;
}
