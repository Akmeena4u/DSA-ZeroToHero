/*

Bubble sort is a simple sorting algorithm that repeatedly steps through a list of elements, compares adjacent elements, and swaps them if they are in the wrong order.

The basic idea of the bubble sort algorithm is as follows:

Start at the beginning of the list.
Compare the first and second elements. If they are in the wrong order, swap them.
Move to the next pair of elements (second and third) and continue comparing and swapping until you reach the end of the list.
Repeat the above steps for each pass until no more swaps are needed. Each pass will "bubble" the largest element to its correct position.
The list is now sorted.

  */

#include<vector>
using namespace std;
void bubbleSort(vector<int>& arr, int n)
{   
    for(int i = 1; i<n; i++) {
        //for round 1 to n-1
        bool swapped = false;
        
        for(int j =0; j<n-i; j++) {
            
            //process element till n-i th index
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
            
        }
        
        if(swapped == false) {
            //already sorted
            break;
        }
           
    }
}
