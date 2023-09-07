
  
//  1. Using Initializer List
//To initialize an array in C/C++ with the same value, the naive way is to provide an initializer list like,

int arr[5] = { 1, 1, 1, 1, 1};
 
// or don't specify the size
int arr[] = { 1, 1, 1, 1, 1 };
 
//The array will be initialized to 0 if we provide the empty initializer list or just specify 0 in the initializer list.

int arr[5] = {};    // results in [0, 0, 0, 0, 0]
int arr[5] = { 0 };  // results in [0, 0, 0, 0, 0]

//2. Using Designated Initializers
//With GCC compilers, we can use designated initializers. To initialize a range of elements to the same value, we can write [first ... last] = value.

int arr[5] = {[0 ... 4] = 1};
 
// or don't specify the size
int arr[] = {[0 ... 4] = 1};
//3. Using Macros
//We can’t use the initializer list with large arrays, and designated initializers will only work with the GCC compilers. For initializing a huge array with the same value, we can use macros, as shown below:

#include <stdio.h>
#include <stdlib.h>
 
#define x1   1
#define x2   x1,  x1
#define x4   x2,  x2
#define x8   x4,  x4
#define x16  x8,  x8
#define x32  x16, x16
 
int main(void)
{
    int arr[] = { x32, x8, x4, x1 };
    int n = sizeof(arr)/sizeof(int);    // (32 + 8 + 4 + 1)
 
    printf("The size of the array is %d\n", n);
    printf("The value of any element is %d", arr[rand() % n]);
 
    return 0;
}

//4. Using For loop
//We can also use for-loop to initialize an array, but the initialization won’t happen in a single line.

#include <stdio.h>
 
int main(void)
{
    int n = 5;
    int val = 1;
 
    // declare array
    int arr[n];
 
    // initialize array
    for (int i = 0; i < n; i++) {
        arr[i] = val;
    }
 
    // rest of the code
 
    return 0;
}

//5. Using std::fill_n function
//Finally, we can use std::fill_n in C++, which assigns a value to the first n array elements.

#include <iostream>
#include <algorithm>
 
int main()
{
    int n = 5;
    int val = 1;
 
    int arr[n];
    std::fill_n (arr, n, val);
 
    // always prints 1
    std::cout << arr[rand() % n];
 
    return 0;
}
