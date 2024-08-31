/*

Jump statements are used to manipulate the flow of the program if some conditions are met. 
 In C++ there is four jump statement: continue, break, return, and goto. 
 
 Continue: It is used to execute other parts of the loop while skipping some parts declared inside the condition, rather than terminating the loop
 Break: It is used to terminate the whole loop if the condition is met. Unlike the continue statement after the condition is met, it breaks the loop and the remaining part of the loop is not executed
 Goto: This statement is used to jump directly to that part of the program to which it is being called by using lables.
 Return: It takes control out of the function itself.

SYNTAX-->

 break;
continue;
return [expression];
goto identifier;

*/

//continue statement

#include <iostream>
using namespace std;
  
int main()
{
    for (int i = 1; i < 10; i++) {
  
        if (i == 5)
            continue; //skip the iteration when i becomes 5
        cout << i << " ";
    }
    return 0;
  
  // break statement
  
  #include <iostream>
using namespace std;
  
int main()
{
    for (int i = 1; i < 10; i++) {
  
        // Breaking Condition
        if (i == 5)
            break; // when i becomes 5 this loop will stop execution
        cout << i << " ";
    }
    return 0;
}

  //goto statement
  
  #include<iostream>
  using namespace std;
  int main()
{
    int n = 4;
  
    if (n % 2 == 0)
        goto label1;
    else
        goto label2;
  
label1:
    cout << "Even" << endl;
    return 0;
  
label2:
    cout << "Odd" << endl;
}
