#include <iostream>

using namespace std;

int
main ()
{
  char ch;
  cout << " enter your chracter";
  cin >> ch;

  if (ch >= 'a' && ch <= 'z')
    {
      cout << "this is lowercase";
    }
  else if (ch >= 'A' && ch <= 'Z')
    {
      cout << "this is uppercase";

    }

  else if (ch >= '0' && ch <= '9')
    {

      cout << "this is numeric";
    }
  return 0;
}
