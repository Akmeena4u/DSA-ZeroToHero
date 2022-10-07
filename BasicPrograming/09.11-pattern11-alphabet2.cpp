/*
ABCD
BCDE
CDEF
DEFG
*/

#include <iostream>

using namespace std;

int
main ()
{
    int n;
    cin>>n;
  
  int i = 1;


  while (i <= n)
    {
      int j = 1;

char start = i+j+'A'-2;

      while (j <= n)
	{
	  cout << start;
	  start++;

	  j++;
	}

      cout << endl;
      i++;

    }


  return 0;
}
