#include<bits/stdc++.h>

using namespace std;


int
hexaDecimalToDecimal (string n)
{

  int ans = 0;
  int x = 1;

  int size = n.size ();

  for (int i = size - 1; i >= 0; i--)
    {


      if (n[i] >= '0' && n[i] <= '9')
	{

	  ans = ans + x * (n[i] - '0');
	}

      else if (n[i] >= 'A' && n[i] <= 'F')
	{

	  ans = ans + x * (n[i] - 'A');

	}

      x = x * 16;
    }
  return ans;
}

int
main ()
{

  string n;
  cin >> n;
  cout << hexaDecimalToDecimal (n);

  return 0;
}
