/*

Pointer stores the address of another variable. Pointer has no data type. * is the operator called as pointer.

Syntax:
data_type * pointer_name;

Example: Pass Pointers to Functions in C++
To pass pointers to functions the arguments of the function should be pointers. Then only the function will be able to accept pointers.*/





#include<iostream>
using namespace std;

void swap (int *x, int *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int main()
{
  int a, b;
  a = 10;
  b = 20;
  
  int *ptr1, *ptr2;
  ptr1 = &a;
  ptr2 = &b;
  
  cout << "Before calling swap function " << endl;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  
  swap (ptr1, ptr2);
  
  cout << "\nAfter calling swap function " << endl;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  
  return 0;
}


/*

In main(), we created two int type variables a and b. We also created two pointers ptr1 and ptr2 to point to a and b. Use the & operator to get the address of a variable. Assign the addresses of a and b to ptr1 and ptr2 respectively.

We passed these pointers to the function swap. In the function swap, we swapped these two values. The changes made in the swap function get reflected in the main. In the output, we can observe that the values of a and b before and after calling the swap function are different. This happens because we used pointers.

*/
