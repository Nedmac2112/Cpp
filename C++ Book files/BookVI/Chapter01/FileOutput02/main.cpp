#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  string filename = "MyFile123.txt";
  ifstream check(filename);
  if (!check)
  {
    cout << "File doesn't exist.";
    return -1;
  }
  else
  {
    check.close();
  }

  fstream datafile(filename, ios::app);
  datafile << " There" << endl;
  datafile.close();
  cout << "File Written!" << endl;
  return 0;
}
