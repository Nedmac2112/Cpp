#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  // creates the file if not already created and puts the file in the previous directory
  ofstream outfile("../MyFile.txt");
  // writes text to the file
  outfile << "Hi 123" << endl;
  // closes the file
  outfile.close();
  cout << "File Written!" << endl;
  return 0;
}
