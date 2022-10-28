/*

Pair is used to combine together two values that may be of different data types. Pair provides a way to store two heterogeneous objects as a single unit
The pair container is a simple container defined in <utility> header consisting of two data elements or objects. 

The first element is referenced as ‘first’ and the second element as ‘second’ and the order is fixed (first, second)

To access the elements, we use variable name followed by dot operator followed by the keyword first or second.

pair (data_type1, data_type2) Pair_name

initializing a Pair: We can also initialize a pair. 

Syntax:

pair (data_type1, data_type2) Pair_name (value1, value2) ;
Different ways to initialize pair:  

pair  g1;         //default
pair  g2(1, 'a');  //initialized,  different data type
pair  g3(1, 10);   //initialized,  same data type
pair  g4(g3);    //copy of g3

*/

// CPP Program to demonstrate make_pair()
// function in pair
#include <iostream>
#include <utility>
using namespace std;

// Driver Code
int main()
{
	pair<int, char> PAIR1;
	pair<string, double> PAIR2("GeeksForGeeks", 1.23);
	pair<string, double> PAIR3;

	PAIR1.first = 100;
	PAIR1.second = 'G';

	PAIR3 = make_pair("GeeksForGeeks is Best", 4.56);

	cout << PAIR1.first << " ";
	cout << PAIR1.second << endl;

	cout << PAIR2.first << " ";
	cout << PAIR2.second << endl;

	cout << PAIR3.first << " ";
	cout << PAIR3.second << endl;

	return 0;
}
