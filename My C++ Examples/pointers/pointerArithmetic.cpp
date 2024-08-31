#include <iostream>

using namespace std;

int main()
{
  int Numbers[10];
  int SNumbers = sizeof(Numbers) / sizeof(*Numbers);

  for (int i = 0; i < SNumbers; i++)
  {
    Numbers[i] = i * 10;
  }

  for (int i = 0; i < SNumbers; i++)
  {
    cout << Numbers[i] << endl;
  }

  cout << endl
       << endl;

  // You can use pointer arithmetic to navigate through an array
  // cur points to the first element of the array
  int *cur = Numbers;
  cout << *cur << endl;
  // cur points to the second element of the array
  cur++;
  cout << *cur << endl;
  // cur points to the fifth element of the array
  cur += 3;
  cout << *cur << endl;
  // cur points to the fourth element of the array
  cur--;
  cout << *cur << endl;
  return 0;
}
