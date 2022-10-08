
#include <iostream>

using namespace std;


bool
iseven (int num)
{
  if (num % 2 != 0)
    {
      return 0;
    }

  else
    {
      return 1;
    }
}

int
main ()
{
  int n;
  cin >> n;

  int result = iseven (n);

  if (result)
    {
      cout << "even number";
    }
  else
    {
      cout << "odd number";
    }

  return 0;
}
