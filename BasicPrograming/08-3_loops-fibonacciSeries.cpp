#include <iostream>

using namespace std;

int
main ()
{
  int n;
  cin >> n;

  int i = 0;
  int j = 1;

  cout << i << " \n" << j << "\n";



  for (int k = 0; k <= n; k++)
    {

      int next = i + j;

      cout << next << endl;
      i = j;
      j = next;

    }
  return 0;
}
