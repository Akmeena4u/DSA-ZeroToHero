#include <iostream>

using namespace std;

int
main ()
{
  int N;
  cout << " Enter the number";
  cin >> N;
  

  int sum = 0;

/*
  for (int i= 0 ; i<=N ;i++){
      
      if (i%2==0){
          sum=sum+i;
      }
  }
  */
  int i=1;
  while( i<=N){
      if(i%2==0){
          sum=sum+i;
      }
      
      i++;
  }
  
  
  
  cout << " Sum of all even numbers from 1 to N IS:" << sum;



  return 0;
}
