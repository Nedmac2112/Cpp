#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // creates a file stream for input and output. The trunc opeartor deletes previous text in the file.
    fstream outfile("fstream.txt", ios::in | ios::out | ios::trunc);
    outfile << "hello" << endl;
    // empties the buffer to make sure the text is displayed
    outfile.flush();
    // Data will hold the string read from the file
    string Data;
    // seekg (off-set by 0, and start at the beginning of the file)
    outfile.seekg(0, ios::beg);
    // reads text from the file
    outfile >> Data;
    // closes the file
    outfile.close();

    cout << "File Written!" << endl;
    cout << Data << endl;

       outfile.close();
    return 0;
}