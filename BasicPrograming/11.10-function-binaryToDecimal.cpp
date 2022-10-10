


#include <iostream>

using namespace std;

int
binaryToDecimal (int n)
{

  int ans = 0;

  int x = 1;

  while (n > 0)
    {
      int y = n % 10;
      ans = ans + (x * y);
      x = x * 2;
      n = n / 10;


    }
  return ans;

}

int
main ()
{

  int x;
  cin >> x;



  cout << binaryToDecimal (x);

  return 0;
}
