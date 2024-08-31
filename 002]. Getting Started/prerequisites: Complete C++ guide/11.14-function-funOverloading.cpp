/*

 Function overloading is a feature in C++ where two or more functions can have the same name but different parameters.
 Function overloading can be considered as an example of polymorphism feature in C++
 An Overloaded function must have:
1. Different type of parameters
2. Different number of parameters
3. Different sequence of parameters
Example of an overloaded function is: 
void print();
void print(int a);
void print(float a);
void print(int a, int b);
void print(int a, double b);
void print(double a, int b);

*/

#include <iostream>
using namespace std;

void display(int);
void display(float);
void display(int, float);

int main() {

    int a = 5;
    float b = 5.5;

    display(a);
    display(b);
    display(a, b);

    return 0;
}
void display(int var) {
    cout << "Integer number: " << var << endl;
}
void display(float var) {
    cout << "Float number: " << var << endl;
}
void display(int var1, float var2) {
    cout << "Integer number: " << var1;
    cout << " and float number:" << var2;
}
