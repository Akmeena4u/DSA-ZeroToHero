#include <iostream>

using namespace std;

int
octalToDecimal (int n)
{

  int ans = 0;

  int x = 1;

  while (n > 0)
    {
      int y = n % 10;
      ans = ans + (x * y);
      x = x * 8;
      n = n / 10;


    }
  return ans;

}

int
main ()
{

  int x;
  cin >> x;



  cout << octalToDecimal (x);

  return 0;
}
