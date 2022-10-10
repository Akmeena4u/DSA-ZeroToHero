/*
 A Structure in C++ is a group of data elements grouped together under one name. These data elements, known as members, can have different types and different lengths. It is a user defined data type which allows you to combine data items of different kinds.
Structures are user-defined data types
Imagine you want to store details of a person for e.g. his name, age and salary. In a typical scenario you will have to create 3 variables to store these values, but what if you have to store details of 20 people. Then you will have to create 60 variables and that will be very tedious and inefficient. In such scenarios we can create a struct datatype named Person and include all the details as member variables of this datatype to create a custom datatype. We can then simply create 20 variables of this new structure datatype or a single array of size 20.

*/

#include <iostream>
using namespace std;

struct Person
{
char name[50];
int age;
float salary;
};

int main()
{
Person p1;

cout << "Enter Full name: ";
cin.get(p1.name, 50);
cout << "Enter age: ";
cin >> p1.age;
cout << "Enter salary: ";
cin >> p1.salary;

cout << "\nDisplaying Information." << endl;
cout << "Name: " << p1.name << endl;
cout <<"Age: " << p1.age << endl;
cout << "Salary: " << p1.salary;

return 0;
}
