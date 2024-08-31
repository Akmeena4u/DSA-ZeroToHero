

/*
C/C++ has many built-in operators and can be classified into 6 types:

Arithmetic Operators --(+, -, *, /, %,++,–).
Relational Operators -- (==, >= , <= )
Logical Operators - ( && ,|| ,!)
Bitwise Operators -- & ,| , 
Assignment Operators -- ( = ,+=,-=,*=,\=)
Other Operators  -- ( sizeof , Condition ? X : Y , . (dot) and -> (arrow) ,  comma operator , Cast ,& ,*

*/

//1. Assignment operator

#include<iostream>
using namespace std;

int main()
{
    int x=10;
				x+=3; //13
				x-=3; //10
		    	x&=3; //80
		        x<<=3;//16
		        x>>=3; //2
		        x^=3; //1
				cout<<x;
				
    return 0;
}


//logical operator
#include<iostream>
using namespace std;

int main() {
  int a = 2, b = 3;
  int res = 0;
  res = (a > b) && (a == b);
  cout << res << "\n";

  res = (a != b) || (a >= b);
  cout << res << "\n";

  res = !(a < b);
  cout << res << "\n";
  
  return 0;
}


 //bitwise operator
 
 #include<iostream>
 using namespace std;
 
 int main(){
 
 int a=5;
 int b=9;
 cout<<" a&b "<<(a&b)<<endl;  //AND operator returns 1 only when both the bits are set i.e. equal to 1 in the numbers.
 cout<<" a|b "<<(a|b)<<endl;  //OR Operation returns 1 if either of the two or both bits are set i.e. equal to 1.
 cout<<" ~a "<<(~a)<<endl;   //just opposite
 cout<<" a^b "<<endl; //XOR Operator returns 1 only when both bits are conjugate to each other
   //LEFT SHIFT OPERATOR (<<)-It can be used to shift bits to the left up to a certain number of significant bits.
   //RIGHT SHIFT Operator (>>)-It can be used to shift the bits to the right up to a certain number of significant bits.


}


/

//ternary operator

#include<iostream>
using namespace std;

int main()
{
    int a,b,max;
    cout<<"Enter two numbers";
    cin>>a>>b;

    max=(a>b)?a:b;
    cout<<max;
    return 0;
}
