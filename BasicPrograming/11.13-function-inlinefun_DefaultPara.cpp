#include <iostream>
using namespace std;

inline int Max(int x, int y) {
   return (x > y)? x : y;
}
// Main function for the program
int main( ) {
   cout << "Max (20,10): " << Max(20,10) << endl;
   cout << "Max (0,200): " << Max(0,200) << endl;
   cout << "Max (100,1010): " << Max(100,1010) << endl;
	
   return 0;
}

/*

Inline Functions in C++ is a very important concept and feature. To understand this let us first understand how a typical function call works-

In a typical scenario , whenever a function is called, the program flow control is shifted to that function till it completes the execution and then returns back to where the function was called. This context switching mechanism many times causes an additional overhead leading to inefficiency. This overhead issue can be resolved by inlining the function (making the function inline).

Inline functions are actual functions, which are copied everywhere during compilation, like preprocessor macro, so the overhead of function calling is reduced.
If a function is inline, the compiler places a copy of the code of that function at each point where the function is called at compile time.


*/

//function argument

/*

A default argument is a value provided in a function declaration that is automatically assigned by the compiler if the calling function doesn’t provide a value for the argument. */

// CPP Program to demonstrate Default Arguments
#include <iostream>
using namespace std;

// A function with default arguments,
// it can be called with
// 2 arguments or 3 arguments or 4 arguments.
int sum(int x, int y, int z = 0, int w = 0) //assigning default values to z,w as 0
{
	return (x + y + z + w);
}

// Driver Code
int main()
{
	// Statement 1
	cout << sum(10, 15) << endl;

	// Statement 2
	cout << sum(10, 15, 25) << endl;

	// Statement 3
	cout << sum(10, 15, 25, 30) << endl;
	return 0;
}
