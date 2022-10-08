

//function with argument passing


#include <iostream>

using namespace std;


int
power (int a, int b)
{


  int ans = 1;
  for (int i = 1; i <= b; i++)
    {
      ans = ans * a;
    }

  return ans;
}

int
main ()
{



  int a, b;
  cin >> a >> b;

  int answer = power (a, b);
  cout << answer;
  return 0;
}



//power function without passing argument

#include <iostream>

using namespace std;


int
power ()
{

  int a, b;
  cin >> a >> b;
  int ans = 1;
  for (int i = 1; i <= b; i++)
    {
      ans = ans * a;
    }

  return ans;
}

int
main ()
{


  int answer = power ();
  cout << answer;
  return 0;
}

// we can change actual parameters in function it doesn't impact 


#include <iostream>

using namespace std;


int
power (int num1 ,int num2)
{

  
  int ans = 1;
  for (int i = 1; i <= num2; i++)
    {
      ans = ans * num1;
    }

  return ans;
}

int
main ()
{
int a, b;
  cin >> a >> b;

  int answer = power (a,b);
  cout << answer;
  return 0;
}
