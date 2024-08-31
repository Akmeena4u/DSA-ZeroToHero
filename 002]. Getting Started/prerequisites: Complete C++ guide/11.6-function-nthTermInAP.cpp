#include <iostream>

using namespace std;

int
nTerm (int a)
{

  int nterm;

  nterm = (3 * a) + 7;

  return nterm;
}




int
main ()
{
  int n = 3;
  int ans = nTerm (3);
  cout << ans;
  return 0;
}
