/*
Loops in  C++
. Loops come into use when we need to repeatedly execute a block of statements.
  For example, let's say we want to show a message 100 times. Then instead of writing the print statement 100 times, we can use a loop.
  There are 3 types of loops in C++. */

  //1.for loop -- When you know exactly how many times you want to loop through a block of code
                for (initialization; condition; update) {
                 // body of-loop 
                  }

                
               // Example--C++ Program to display a text 5 times

                #include <iostream>

                using namespace std;

                int main() {
               for (int i = 1; i <= 5; ++i) {
                 cout <<  "Hello World! " << endl;
                }
               return 0;
           }  


              //C++ Infinite for loop -- If the condition in a for loop is always true, it runs forever (until memory is full). 


 // 2.while loop -- When you  don't know exactly how many times you want to loop through a block of code

              //  initialization expression;
                while (condition)
             {
                     // loop body
 
                // update_expression;
             }

            // Example-program to find the sum of positive numbers

            #include <iostream>
            using namespace std;

            int main() {
                  int number;
                  int sum = 0;

    
                 cout << "Enter a number: ";
                 cin >> number;

                while (number >= 0) {
                     // add all positive numbers
                    sum += number;

                    // take input again if the number is positive
                   cout << "Enter a number: ";
                   cin >> number;
                }

               // display the sum
               cout << "\nThe sum is " << sum << endl;
    
               return 0;
                   }

 // 3.do...while loop -  firstly, execute the body then condition check

             do {
                   // body of loop;
                }
               while (condition);
             

              // C program to illustrate do-while loop
               #include <stdio.h>
  
               int main()
               {
                 int i = 2; // Initialization expression
 
                do
             {
                // loop body
                printf( "Hello World\n");   
 
                // update expression
                i++;
 
            }  while (i < 1);   // test expression
 
                 return 0;
                                }

            //  In the above program, the test condition (i<1) evaluates to false. But still, as the loop is an exit – controlled the loop body will execute once.
  
