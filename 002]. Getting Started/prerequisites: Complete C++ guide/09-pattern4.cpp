/*

pattern 5

12345
12345
12345
12345
12345
  
  */

#include <iostream>
using namespace std;

int
main ()
{
  int n;
  cin >> n;

  int i = 1;

  while (i <= n)
    {
      int j = 1;
      while (j <= n)
	{
	  cout << j;
	  j++;
	}

      cout << endl;
      i++;
    }

  return 0;
}


//2nd approch

#include <iostream>
using namespace std;



int main()
{
    
    int n;
    cin>>n;
    int i=1;
    
    int count=0;
    
    while(i<=n){
        int j=1;
        
        while(j<=n){
            cout<<count+j;
            
            j++;
        }
        
        cout<<endl;
        i++;
    }

    return 0;
}
