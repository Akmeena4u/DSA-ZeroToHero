#include <iostream>

using namespace std;

int
main ()
{
  int n;
  cout << "Enter Number";
  cin >> n;

  bool isprime = true;

  for (int i = 2; i < n; i++)
    {

      if (n % i == 0)
	{
	  isprime = false;
	  break;
	}
    }

  if (isprime)
    {
      cout << "Given number is a prime number";
    }

  else
    {

      cout << "NOt prime";
    }
  return 0;
}
