#include <iostream>
using namespace std;

int main()
{
  // single line comment

  /*multi
    line
    comment
  */

  cout << "Hello World!" << endl;

  int x = 25;
  double y = 30.5;
  char z = 'T';
  bool b = true;
  int age;

  cout << "Enter your age: ";
  cin >> age;
  cout << "You are " << age << " years old." << endl;

  cout << b << endl;              // when you print out a boolean, it will print out 1 for true and 0 for false
  cout << boolalpha << b << endl; // this will print out true or false instead of 1 or 0

  int a = 5 % 2; // a is equal to 1
  cout << a << endl;
  a += 3; // a is now equal to 4
  cout << a << endl;
  a++; // a is now equal to 5
  cout << a << endl;

  return 0;
}