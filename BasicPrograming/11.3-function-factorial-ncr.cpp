

// find  factorial
#include <iostream>

using namespace std;

int
fact (int num)
{

  int i = 1;
  int result = 1;
  while (i <= num)
    {

      result = result * i;
      i++;
    }

  return result;
}

int
main ()
{

  int n;
  cin >> n;

  int factorial = fact (n);

  cout << factorial;

  return 0;
}


// find ncr

#include<iostream>
using namespace std;

int factorial(int n) {

    int fact = 1;

    for(int i = 1; i<=n; i++ ) {
        fact = fact * i;
    }

    return fact;
}

int nCr(int n, int r) {

    int num = factorial(n);

    int denom = factorial(r) * factorial(n-r);

    return num/denom;
}


int main( ) {

    int n, r;

    cin>> n >> r ;

    cout <<" Answer is " << nCr(n,r) << endl;

    return 0;
}
