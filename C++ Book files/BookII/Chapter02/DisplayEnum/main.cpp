#include <iostream>

using namespace std;

class Colors
{
public:
  enum ColorEnum
  {
    blue,
    red,
    green
  };

  Colors(ColorEnum init) : value(init) {}

  string AsString()
  {
    switch (value)
    {
    case blue:
      return "blue";
    case red:
      return "red";
    case green:
      return "green";
    default:
      return "Not Found";
    }
  }

protected:
  ColorEnum value;
};

int main()
{
  Colors InkColor(Colors::blue);
  cout << InkColor.AsString() << endl;
  return 0;
}
