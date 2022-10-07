
/*

1
21
321
4321

*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int i=1;
    
    
    while(i<=n){
        int j=1;
        int value=i;  //row ko hm read kar sakte h write yaa modify nahi
        while(j<=i){
            cout<<value;
            value--;
            j++;
        }
        
        cout<<endl;
        i++;
        
    }
    

    return 0;
}


//approch 2

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

      while (j <= i)
	{
	  cout << i - j + 1;

	  j++;
	}

      cout << endl;
      i++;

    }


  return 0;
}
