#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // fstream f("f.txt", ios::in | ios::out | ios::app);
    ofstream o("f.txt");

    o.write("abcdef", 6);
    long pos = o.tellp();
    o.seekp(pos - 3);
    o.write(" kop", 4);

    o.close();

    return 0;
}

// position in output stream
// #include <fstream> // std::ofstream

// int main()
// {

//     std::ofstream outfile;
//     outfile.open("test.txt");

//     outfile.write("This is an apple", 16);
//     long pos = outfile.tellp();
//     outfile.seekp(pos - 7);
//     outfile.write(" sam", 4);

//     outfile.close();

//     return 0;
// }